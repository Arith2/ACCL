
# /*******************************************************************************
#  Copyright (C) 2021 Xilinx, Inc
#
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.
#
# *******************************************************************************/

import pynq
from pynq import DefaultIP
import os
import sys
import numpy as np
import struct
import warnings
import numpy as np
import ipaddress
from enum import IntEnum

class CCLOp(IntEnum):
    config      = 0
    send        = 1
    recv        = 2
    bcast       = 3
    scatter     = 4
    gather      = 5
    reduce      = 6
    allgather   = 7
    allreduce   = 8
    accumulate  = 9
    copy        = 10
    reduce_ring = 11
    allreduce_fused_ring = 12
    gather_ring = 13
    allgather_ring = 14
    ext_stream_krnl = 15
    ext_reduce  = 16
    nop         = 255

class CCLOCfgFunc(IntEnum):
    enable_irq  = 0
    disable_irq = 1
    reset_periph= 2
    enable_pkt  = 3
    set_timeout = 4
    init_connection = 5
    open_port   = 6
    open_con    = 7
    use_tcp_stack = 8
    use_udp_stack = 9
    start_profiling= 10
    end_profiling= 11

class CCLOReduceFunc(IntEnum):
    fp          = 0
    dp          = 1
    i32         = 2
    i64         = 3

def np_type_2_cclo_type(np_type):
    if   (np_type == np.float32 ):
        return CCLOReduceFunc.fp
    elif (np_type == np.float64 ):
        return CCLOReduceFunc.dp
    elif (np_type == np.int32   ):
        return CCLOReduceFunc.i32
    elif (np_type == np.int64   ):
        return CCLOReduceFunc.i64

class ErrorCode(IntEnum):
    COLLECTIVE_OP_SUCCESS             = 0  
    DMA_MISMATCH_ERROR                = 1     
    DMA_INTERNAL_ERROR                = 2     
    DMA_DECODE_ERROR                  = 3  
    DMA_SLAVE_ERROR                   = 4 
    DMA_NOT_OKAY_ERROR                = 5     
    DMA_NOT_END_OF_PACKET_ERROR       = 6             
    DMA_NOT_EXPECTED_BTT_ERROR        = 7
    DMA_TIMEOUT_ERROR                 = 8             
    CONFIG_SWITCH_ERROR               = 9
    DEQUEUE_BUFFER_TIMEOUT_ERROR      = 10
    RECEIVE_TIMEOUT_ERROR             = 12
    DEQUEUE_BUFFER_SPARE_BUFFER_STATUS_ERROR = 11
    DEQUEUE_BUFFER_SPARE_BUFFER_DMATAG_MISMATCH =             13
    DEQUEUE_BUFFER_SPARE_BUFFER_INDEX_ERROR = 14
    COLLECTIVE_NOT_IMPLEMENTED        = 15
    RECEIVE_OFFCHIP_SPARE_BUFF_ID_NOT_VALID = 16
    OPEN_PORT_NOT_SUCCEEDED           = 17
    OPEN_COM_NOT_SUCCEEDED            = 18

class dummy_address_class:
    def __init__(self):
        self.device_address = 0x0000_0000_0000_0000
dummy_address = dummy_address_class()

TAG_ANY = 0xFFFF_FFFF

def compatible_size(nbytes,type):
        if   (type == CCLOReduceFunc.fp or type == CCLOReduceFunc.i32 ):
            return True if (nbytes % 4) == 0 else False
        elif   (type == CCLOReduceFunc.dp or type == CCLOReduceFunc.i64 ):
            return True if (nbytes % 8) == 0 else False

def repeat(objects, times=None):
    
    if times is None:
        while True:
            for object in objects:
                yield object
    else:
        i=0
        while(i < times):
            for object in objects:
                yield object
                i+=1
                if(i >= times):
                    break

        

class cclo(DefaultIP):
    """
    This class wrapps the common function of the collectives offload kernel
    """

    bindto = ["Xilinx:ACCL:ccl_offload:1.0"]

    def __init__(self, description):
        super().__init__(description=description)
        self._fullpath = description['fullpath']
        #define an empty list of RX spare buffers
        self.rx_buffer_spares = []
        self.rx_buffer_size = 0
        self.rx_buffers_adr = 0x800
        #define another spare for general use (e.g. as accumulator for reduce/allreduce)
        self.utility_spare = None
        #define an empty list of communicators, to which users will add
        self.communicators = []
        self.communicators_addr = self.rx_buffers_adr
        self.check_return_value_flag = True
        
    def deinit(self):
        print("Removing CCLO object at ",hex(self.mmio.base_addr))
        self.call(scenario=CCLOp.config, function=CCLOCfgFunc.reset_periph)

        for buf in self.rx_buffer_spares:
            buf.freebuffer()
        del self.rx_buffer_spares
        self.rx_buffer_spares = []

        if self.utility_spare is not None:
            self.utility_spare.freebuffer()
        del self.utility_spare
        self.utility_spare = None

    def setup_rx_buffers(self, nbufs, bufsize, devicemem):
        addr = self.rx_buffers_adr
        self.rx_buffer_size = bufsize
        self.write(addr,nbufs)
        if not isinstance(devicemem, list):
            devicemem = [devicemem]
        for i, devicemem_i in enumerate(repeat(devicemem, nbufs)):

            self.rx_buffer_spares.append(pynq.allocate((bufsize,), dtype=np.int8, target=devicemem_i))
            #program this buffer into the accelerator
            addr += 4
            self.write(addr, self.rx_buffer_spares[-1].physical_address & 0xffffffff)
            addr += 4
            self.write(addr, (self.rx_buffer_spares[-1].physical_address>>32) & 0xffffffff)
            addr += 4
            self.write(addr, bufsize)
            # clear remaining fields
            for i in range(3,9):
                addr += 4
                self.write(addr, 0)

        self.communicators_addr = addr+4
        self.utility_spare = pynq.allocate((bufsize,), dtype=np.int8, target=devicemem[0])

        #Start irq-driven RX buffer scheduler and (de)packetizer
        #self.call(scenario=CCLOp.config, function=CCLOCfgFunc.reset_periph)
        self.call(scenario=CCLOp.config, function=CCLOCfgFunc.enable_irq)
        self.call(scenario=CCLOp.config, function=CCLOCfgFunc.enable_pkt)
    
    def dump_rx_buffers_spares(self, nbufs=None):
        addr = self.rx_buffers_adr
        if nbufs is None:
            assert self.read(addr) == len(self.rx_buffer_spares)
            nbufs = len(self.rx_buffer_spares)
        print(f"CCLO address:{hex(self.mmio.base_addr)}")
        nbufs = min(len(self.rx_buffer_spares), nbufs)
        for i in range(nbufs):
            addr   += 4
            addrl   =self.read(addr)
            addr   += 4
            addrh   = self.read(addr)
            addr   += 4
            maxsize = self.read(addr)
            #assert self.read(addr) == self.rx_buffer_size
            addr   += 4
            dmatag  = self.read(addr)
            addr   += 4
            rstatus  = self.read(addr)
            addr   += 4
            rxtag   = self.read(addr)
            addr   += 4
            rxlen   = self.read(addr)
            addr   += 4
            rxsrc   = self.read(addr)
            addr   += 4
            seq     = self.read(addr)
            
            if rstatus == 0 :
                status =  "NOT USED"
            elif rstatus == 1:
                status = "ENQUEUED"
            elif rstatus == 2:
                status = "RESERVED"
            else :
                status = "UNKNOWN"

            try:
                self.rx_buffer_spares[i].sync_from_device()
                content = str(self.rx_buffer_spares[i])
            except Exception :
                content= "xxread failedxx"
            print(f"SPARE RX BUFFER{i}:\t ADDR: {hex(int(str(addrh)+str(addrl)))} \t STATUS: {status} \t OCCUPACY: {rxlen}/{maxsize} \t DMA TAG: {hex(dmatag)} \t  MPI TAG:{hex(rxtag)} \t SEQ: {seq} \t SRC:{rxsrc} \t content {content}")

    def start(self, scenario=CCLOp.nop, len=1, comm=0, root_src_dst=0, function=0, tag=TAG_ANY, buf_0_type=0, buf_1_type=0, buf_2_type=0, addr_0=dummy_address, addr_1=dummy_address, addr_2=dummy_address, waitfor=[] ):
        #placeholder for kernel filled with default values
        #comm = self.communicators[comm_id]["addr"]
        return DefaultIP.start(self, scenario, len, comm, root_src_dst, function, tag, buf_0_type, buf_1_type, buf_2_type, addr_0, addr_1, addr_2, waitfor=waitfor)        

    def call(self, scenario=CCLOp.nop, len=1, comm=0, root_src_dst=0, function=0, tag=TAG_ANY, buf_0_type=0, buf_1_type=0, buf_2_type=0, addr_0=dummy_address, addr_1=dummy_address, addr_2=dummy_address ):
        #placeholder for kernel filled with default values
        #comm = self.communicators[comm_id]["addr"]
        #call_type
        #byte_count or len
        #comm
        #root_src_dest
        #function
        #tag
        #3xbuf_x_type
        #x3buf_x_ptr
        return DefaultIP.call(self, scenario, len, comm, root_src_dst, function, tag, buf_0_type, buf_1_type, buf_2_type, addr_0, addr_1, addr_2)        

    def get_retcode(self):
        return self.read(0xFFC)

    def self_check_return_value(call):
        def wrapper(self, *args, **kwargs):
            handle = call(self, *args, **kwargs)
            if self.check_return_value_flag and handle is None: # if handle is none it means that the execution was synchronous
                self.check_return_value()
            else: #not possible to check return code if invoked async
                pass
            return handle
        return wrapper
    
    def check_return_value(self):
        retcode = self.get_retcode()
        if retcode != 0:
            raise Exception(f"CCLO @{hex(self.mmio.base_addr)}: {ErrorCode(retcode).name} you should consider resetting mpi_offload")

    def get_hwid(self):
        #TODO: add check
        return self.read(0xFF8)

    def set_timeout(self, value, run_asynch=False, waitfor=[]):
        handle = self.start(scenario=CCLOp.config, len=value, function=CCLOCfgFunc.set_timeout, waitfor=waitfor)
        if run_asynch:
            return handle
        else:
            handle.wait()

    def start_profiling(self, run_asynch=False, waitfor=[]):
        handle = self.start(scenario=CCLOp.config, waitfor=waitfor)
        if run_asynch:
            return handle
        else:
            handle.wait()

    def end_profiling(self, run_asynch=False, waitfor=[]):
        handle = self.start(scenario=CCLOp.config, waitfor=waitfor)
        if run_asynch:
            return handle
        else:
            handle.wait()     

    def init_connection (self, comm_id=0):
        self.call(scenario=CCLOp.config, comm=self.communicators[comm_id]["addr"], function=CCLOCfgFunc.init_connection)
    
    @self_check_return_value
    def open_port(self, comm_id=0):
        self.call(scenario=CCLOp.config, comm=self.communicators[comm_id]["addr"], function=CCLOCfgFunc.open_port)
    
    @self_check_return_value
    def open_con(self, comm_id=0):
        self.call(scenario=CCLOp.config, comm=self.communicators[comm_id]["addr"], function=CCLOCfgFunc.open_con)
    
    @self_check_return_value
    def use_udp(self, comm_id=0):
        self.call(scenario=CCLOp.config, function=CCLOCfgFunc.use_udp_stack)
    
    @self_check_return_value
    def use_tcp(self, comm_id=0):
        self.call(scenario=CCLOp.config, function=CCLOCfgFunc.use_tcp_stack)   

    def configure_communicator(self, ranks, local_rank, vnx=False):
        assert len(self.rx_buffer_spares) > 0, "RX buffers unconfigured, please call setup_rx_buffers() first"
        if len(self.communicators) == 0:
            addr = self.communicators_addr
        else:
            addr = self.communicators[-1]["addr"]
        communicator = {"local_rank": local_rank, "addr": addr, "ranks": ranks, "inbound_seq_number_addr":[0 for _ in ranks], "outbound_seq_number_addr":[0 for _ in ranks], "session_addr":[0 for _ in ranks]}
        self.write(addr,len(ranks))
        addr += 4
        self.write(addr,local_rank)
        for i in range(len(ranks)):
            addr += 4
            #ip string to int conversion from here:
            #https://stackoverflow.com/questions/5619685/conversion-from-ip-string-to-integer-and-backward-in-python
            self.write(addr, int(ipaddress.IPv4Address(ranks[i]["ip"])))
            addr += 4
            #when using the UDP stack, write the rank number into the port register
            #the actual port is programmed into the stack itself
            if vnx:
                self.write(addr,i)
            else:
                self.write(addr,ranks[i]["port"])
            #leave 2 32 bit space for inbound/outbound_seq_number
            addr += 4
            self.write(addr,0)
            communicator["inbound_seq_number_addr"][i]  = addr
            addr +=4
            self.write(addr,0)
            communicator["outbound_seq_number_addr"][i] = addr
            #a 32 bit number is reserved for session id
            # sessions are initialized to 0xFFFFFFFF
            addr += 4
            self.write(addr, 0xFFFFFFFF)
            communicator["session_addr"][i] = addr
        self.communicators.append(communicator)
        
    def dump_communicator(self):
        if len(self.communicators) == 0:
            addr    = self.communicators_addr
        else:
            addr    = self.communicators[-1]["addr"]
        nr_ranks    = self.read(addr)
        addr +=4
        local_rank  = self.read(addr)
        print(f"Communicator. local_rank: {local_rank} \t number of ranks: {nr_ranks}.")
        for i in range(nr_ranks):
            addr +=4
            #ip string to int conversion from here:
            #https://stackoverflow.com/questions/5619685/conversion-from-ip-string-to-integer-and-backward-in-python
            ip_addr_rank = str(ipaddress.IPv4Address(self.read(addr)))
            addr += 4
            #when using the UDP stack, write the rank number into the port register
            #the actual port is programmed into the stack itself
            port                = self.read(addr)
            #leave 2 32 bit space for inbound/outbound_seq_number
            addr += 4
            inbound_seq_number  = self.read(addr)
            addr +=4
            outbound_seq_number = self.read(addr)
            #a 32 bit integer is dedicated to session id 
            addr += 4
            session = self.read(addr)
            print(f"> rank {i} (ip {ip_addr_rank}:{port} ; session {session}) : <- inbound_seq_number {inbound_seq_number}, -> outbound_seq_number {outbound_seq_number}")
   

    @self_check_return_value
    def nop(self, run_async=False, waitfor=[]):
        #calls the accelerator with no work. Useful for measuring call latency
        handle = self.start(scenario=CCLOp.nop, waitfor=waitfor)
        if run_async:
            return handle 
        else:
            handle.wait()

    @self_check_return_value
    def send(self, comm_id, srcbuf, dst, tag=TAG_ANY, from_fpga=False, run_async=False, waitfor=[]):
        if srcbuf.nbytes == 0:
            return
        if not from_fpga:
            srcbuf.sync_to_device()
        handle = self.start(scenario=CCLOp.send, len=srcbuf.nbytes, comm=self.communicators[comm_id]["addr"], root_src_dst=dst, tag=tag, addr_0=srcbuf, waitfor=waitfor)
        if run_async:
            return handle 
        else:
            handle.wait()
    
    @self_check_return_value
    def recv(self, comm_id, dstbuf, src, tag=TAG_ANY, to_fpga=False, run_async=False, waitfor=[]):
        if not to_fpga and run_async:
            warnings.warn("ACCL: async run returns data on FPGA, user must sync_from_device() after waiting")
        if dstbuf.nbytes == 0:
            return
        handle = self.start(scenario=CCLOp.recv, len=dstbuf.nbytes, comm=self.communicators[comm_id]["addr"], root_src_dst=src, tag=tag, addr_0=dstbuf, waitfor=waitfor)
        if run_async:
            return handle
        else:
            handle.wait()
        if not to_fpga:
            dstbuf.sync_from_device()

    @self_check_return_value
    def copy(self, srcbuf, dstbuf,  from_fpga=False,  to_fpga=False, run_async=False, waitfor=[]):
        if not to_fpga and run_async:
            warnings.warn("ACCL: async run returns data on FPGA, user must sync_from_device() after waiting")
        if srcbuf.nbytes == 0:
            return
        # performs dstbuf = srcbuf
        if not from_fpga:
            srcbuf.sync_to_device()
        handle = self.start(scenario=CCLOp.copy, len=srcbuf.nbytes,addr_0=srcbuf, addr_1=dstbuf, waitfor=waitfor)
        if run_async:
            return handle
        
        handle.wait()
        if not to_fpga:
            dstbuf.sync_from_device()

    @self_check_return_value
    def accumulate(self, func, val, acc, val_from_fpga=False, acc_from_fpga=False, to_fpga=False, run_async=False, waitfor=[]):
        if not to_fpga and run_async:
            warnings.warn("ACCL: async run returns data on FPGA, user must sync_from_device() after waiting")
        if val.nbytes == 0:
            return
        if not compatible_size(val.nbytes,func):
            return
        # performs acc = val + acc
        if not val_from_fpga:
            val.sync_to_device()
        if not acc_from_fpga:
            acc.sync_to_device()
        handle = self.start(scenario=CCLOp.accumulate, len=val.nbytes, function=func, addr_0=val, addr_1=acc, waitfor=waitfor)
        if run_async:
            return handle
        
        handle.wait()
        if not to_fpga:
            acc.sync_from_device()
  
    @self_check_return_value
    def external_reduce(self, op1, op2, res, op1_from_fpga=False, op2_from_fpga=False, to_fpga=False, run_async=False, waitfor=[]):
        if not to_fpga and run_async:
            warnings.warn("ACCL: async run returns data on FPGA, user must sync_from_device() after waiting")
        if op1.nbytes == 0 or op2.nbytes == 0:
            return


        if not op1_from_fpga:
            op1.sync_to_device()
        if not op2_from_fpga:
            op2.sync_to_device()
        #check dimensions
        assert(op1.nbytes == op2.nbytes)
 
        handle = self.start(scenario=CCLOp.ext_reduce, len=op1.nbytes, addr_0=op1, addr_1=op2, addr_2=res, waitfor=waitfor)
        if run_async:
            return handle
        
        handle.wait()
        if not to_fpga:
            res.sync_from_device()
    
    @self_check_return_value
    def external_stream_kernel(self, src_buf, dst_buf, from_fpga=False, to_fpga=False, run_async=False, waitfor=[]):
        if not to_fpga and run_async:
            warnings.warn("ACCL: async run returns data on FPGA, user must sync_from_device() after waiting")
        if src_buf.nbytes <= 4:
            return

        if not from_fpga:
            src_buf.sync_to_device()

        handle = self.start(scenario=CCLOp.ext_stream_krnl, len=src_buf.nbytes, addr_0=src_buf, addr_1=dst_buf, waitfor=waitfor)
        if run_async:
            return handle
        
        handle.wait()
        if not to_fpga:
            dst_buf.sync_from_device()

    @self_check_return_value
    def bcast(self, comm_id, buf, root, sw=False, from_fpga=False, to_fpga=False, run_async=False, waitfor=[]):
        comm = self.communicators[comm_id]
        is_root = comm["local_rank"] == root
        if not to_fpga and not(is_root) and run_async:
            warnings.warn("ACCL: async run returns data on FPGA, user must sync_from_device() after waiting")
        if buf.nbytes == 0:
            return
        # sync the transmit source in one go
        if not from_fpga and is_root:
                buf.sync_to_device()
        if sw: #sw implementation of broadcast from send/recv
            if is_root:
                #send repeatedly if we're the source
                prevcall    = waitfor
                other_ranks = filter(lambda x: x != root,  range(len(comm["ranks"])))
                for dst_rank in other_ranks:
                    prevcall = [self.send(comm_id, buf, dst_rank, from_fpga=True, run_async=True, waitfor=prevcall)]
            else:
                #receive once if we're a destination
                prevcall = [    self.recv(comm_id, buf, root    , to_fpga=True, run_async=True, waitfor=waitfor)]
        else:#hw implementation
            prevcall = [self.start(scenario=CCLOp.bcast, len=buf.nbytes, comm=self.communicators[comm_id]["addr"], root_src_dst=root, addr_0=buf, waitfor=waitfor)]
        
        if run_async:
            return prevcall[0]
        
        prevcall[0].wait()
        if not to_fpga and not is_root:
            buf.sync_from_device()

    @self_check_return_value
    def scatter(self, comm_id, sbuf, rbuf, count, root, sw=True, from_fpga=False, to_fpga=False, run_async=False, waitfor=[]):
        if not to_fpga and run_async:
            warnings.warn("ACCL: async run returns data on FPGA, user must sync_from_device() after waiting")
        if count == 0:
            return
        comm        = self.communicators[comm_id]
        local_rank  = comm["local_rank"]
        p           = len(comm["ranks"])


        if not from_fpga and local_rank == root:
                sbuf[:count*p].sync_to_device()

        if sw: #sw implementation: scatter from send/recv
            if local_rank == root:
                #send repeatedly (or copy) if we're the source
                prevcall = waitfor
                for i in range(p):
                    if i != root:
                        prevcall = [self.send(  comm_id, sbuf[count*i:count*(i+1)]  , dst=i     , from_fpga=True, run_async=True, waitfor=prevcall)]
                    else:
                        prevcall = [self.copy(sbuf[count*i:count*(i+1)], rbuf[0:count],             from_fpga=True,  to_fpga=True, run_async=True, waitfor=prevcall)]
            else: #if we're not a root (i.e. we are a destination) receive once 
                prevcall = [self.recv(          comm_id, rbuf[0:count]              , src=root  , to_fpga=True, run_async=True, waitfor=waitfor)]
            
        else:
            prevcall = [self.start(scenario=CCLOp.scatter, len=rbuf[0:count].nbytes, comm=comm["addr"], root_src_dst=root, addr_0=sbuf, addr_1=rbuf[0:count], waitfor=waitfor)]

        if run_async:
            return prevcall[0]

        prevcall[0].wait()
        if not to_fpga:
            rbuf[0:count].sync_from_device()
    @self_check_return_value
    def gather(self, comm_id, sbuf, rbuf, count, root, sw=True, shift=True, from_fpga=False, to_fpga=False, run_async=False, waitfor=[]):
        #print(hex(self.mmio.base_addr), count, root, sw, shift)
        if not to_fpga and run_async:
            warnings.warn("ACCL: async run returns data on FPGA, user must sync_from_device() after waiting")
        if count == 0:
            return
        comm        = self.communicators[comm_id]
        local_rank  = comm["local_rank"]
        p           = len(comm["ranks"])
        
        if not from_fpga:
            sbuf[0:count].sync_to_device()

        if sw:#implement shift gather from send/recv
            #pass from one rank into the next until root
            #use rbuf[0:count] as intermediate storage
            #root will assemble its rbuf from receives (does not send)
            if shift:
                next_in_ring =  (local_rank+1)%p
                prev_in_ring =  (local_rank+p-1)%p
                if local_rank != root:
                    nshifts = (p+local_rank-root)%p-1
                    #send our own data
                    prevcall     = [self.send(comm_id, sbuf[0:count], dst=next_in_ring   , from_fpga=True , run_async=True, waitfor=waitfor)]
                    for i in range(nshifts):
                        #recv and forward data at next rank it will do the same till the end of the rank
                        prevcall = [self.recv(comm_id, rbuf[0:count], src=prev_in_ring   , to_fpga=True   , run_async=True, waitfor=prevcall)]
                        prevcall = [self.send(comm_id, rbuf[0:count], dst=next_in_ring   , from_fpga=True , run_async=True, waitfor=prevcall)]
                else:
                    prevcall = [self.copy(sbuf[0:count], rbuf[count*local_rank:count*(local_rank+1)], from_fpga=True, to_fpga=True, run_async=True, waitfor=waitfor)]
                    for i in range(p-1):
                        target = (local_rank+p-i-1)%p
                        prevcall = [self.recv(comm_id,   rbuf[count*target:count*(target+1)], src=prev_in_ring, to_fpga=True, run_async=True, waitfor=prevcall)]
            else: #implement non-shift normal gather from send/recv
                warnings.warn("Non-shift gather not handled at packetizer level at the moment.")
                warnings.warn("Non-shift SW gather not implemented")
                return
        else: #hw implementation
            
            if shift:
                cclop = CCLOp.gather_ring
            else:
                warnings.warn("Non-shift gather not handled at packetizer level at the moment.")
                return
                cclop = CCLOp.gather
                
            prevcall = [self.start(scenario=cclop, len=rbuf[0:count].nbytes, comm=comm["addr"], root_src_dst=root, addr_0=sbuf, addr_1=rbuf, waitfor=waitfor)]
            
        if run_async:
            return prevcall[0]
        
        prevcall[0].wait()
        if not to_fpga and local_rank == root:
            rbuf[:count*p].sync_from_device()

    @self_check_return_value
    def allgather(self, comm_id, sbuf, rbuf, count, fused=False, sw=True, ring=True, from_fpga=False, to_fpga=False, run_async=False, waitfor=[]):
        if not to_fpga and run_async:
            warnings.warn("ACCL: async run returns data on FPGA, user must sync_from_device() after waiting")
        if count == 0:
            return
        comm    = self.communicators[comm_id]
        p       = len(comm["ranks"])
        
        if not from_fpga:
            sbuf[0:count].sync_to_device()

        if sw:
            local_rank = comm["local_rank"]
            if ring and fused:
                next_in_ring = (local_rank+1)%p
                prev_in_ring = (local_rank+p-1)%p
                
                buf = sbuf[0:count]
                prevcall = waitfor
                for i in range(p-1):
                    prevcall = [self.send(comm_id, buf, dst=next_in_ring, from_fpga=True, run_async=True, waitfor=prevcall)]
                    target = (local_rank+p-i-1)%p
                    buf = rbuf[count*target:count*(target+1)]
                    prevcall = [self.recv(comm_id, buf, src=prev_in_ring, to_fpga=True, run_async=True, waitfor=prevcall)]
                #finally just copy over the local data from input into output
                prevcall = [self.copy(sbuf[0:count], rbuf[count*local_rank:count*(local_rank+1)], from_fpga=True,  to_fpga=True, run_async=True, waitfor=prevcall)]
                
            elif not fused:
                if not ring:
                    warnings.warn("Non-ring gather not handled at packetizer level at the moment.")
                    return
                #implement allgather from gather+broadcast (root=0, intermediate results stay on FPGA)
                prevcall = [self.gather(comm_id, sbuf, rbuf, count, 0, sw=False, shift=ring, from_fpga=from_fpga, to_fpga=True, run_async=True, waitfor=waitfor)]
                prevcall = [self.bcast(comm_id, rbuf, 0, sw=False, from_fpga=True, to_fpga=True, run_async=True, waitfor=prevcall)]

            else :
                warnings.warn("sw", "ring" if ring else "non ring", "fused" if fused else "non fused" ,"allgather not implemented")
                return

        else: #hw implementation
            
            if fused and ring:
                cclop = CCLOp.allgather_ring
            elif not fused and not ring:
                warnings.warn("Non-ring gather not handled at packetizer level at the moment.")
                return
            elif not fused and ring:
                cclop = CCLOp.allgather
            else:
                warnings.warn("hw", "ring" if ring else "non ring", "fused" if fused else "non fused" ,"allgather not implemented")
                return

            prevcall = [self.start(scenario=cclop, len=rbuf[0:count].nbytes, comm=comm["addr"], addr_0=sbuf, addr_1=rbuf, waitfor=waitfor)]
            
            
        if run_async:
            return prevcall[0]

        prevcall[0].wait()
        if not to_fpga:
            rbuf[:count*p].sync_from_device()

    #TODO: figure out if we need to mess with the datatypes
    # https://stackoverflow.com/questions/49135350/how-to-create-a-uint16-numpy-array-from-a-uint8-raw-image-data-array
    @self_check_return_value
    def reduce(self, comm_id, sbuf, rbuf, count, root, func, sw=False, shift=True, from_fpga=False, to_fpga=False, run_async=False, waitfor=[]):
        if not to_fpga and run_async:
            warnings.warn("ACCL: async run returns data on FPGA, user must sync_from_device() after waiting")
        if count == 0:
            return
        if not compatible_size(count,func):
            return
        if func > 3:
            warnings.warn("Non-add reduce not implemented")
            return
        comm        = self.communicators[comm_id]
        p           = len(comm["ranks"])
        local_rank  = comm["local_rank"]

        if not from_fpga:
            sbuf[0:count].sync_to_device()

        if sw:
            
            #implement shift gather from send/recv
            #pass from one rank into the next until root
            #use self.utility_spare as intermediate storage when needed
            #root will receive and accumulate in its rbuf from receives (does not send)
            if shift:
                prev_in_ring = (local_rank+p-1)%p
                next_in_ring = (local_rank+1)%p
                if local_rank != root:
                    nshifts = (p+local_rank-root)%p-1
                    #send our own data
                    prevcall     = [self.send(comm_id, sbuf[0:count], dst=next_in_ring , from_fpga=from_fpga            , run_async=True, waitfor=waitfor)]
                    for i in range(nshifts):
                        prevcall = [self.recv(comm_id, rbuf[0:count], src=prev_in_ring                 , to_fpga=True   , run_async=True, waitfor=prevcall)]
                        prevcall = [self.send(comm_id, rbuf[0:count], dst=next_in_ring , from_fpga=True                 , run_async=True, waitfor=prevcall)]

                else:#in case of the root
                    
                    spare_buf= self.utility_spare
                    accum_buf= rbuf[0:count]

                    prevcall = [self.copy(sbuf[0:count], accum_buf[0:count], from_fpga=from_fpga,  to_fpga=True, run_async=True, waitfor=waitfor)]
                    for i in range(p-1):
                        prevcall =  [self.recv( comm_id, spare_buf[0:count], src=prev_in_ring,                                       to_fpga=True, run_async=True, waitfor=prevcall)]
                        prevcall =  [self.accumulate(func, val=spare_buf, acc=accum_buf , val_from_fpga=True   , acc_from_fpga=True, to_fpga=True, run_async=True, waitfor=prevcall)]
            
            else: #implement non-shift reduce from send/recv
                warnings.warn("non-shift SW reduce not implemented")
                return
        
        else:#hw implementation
            # performs acc = val + acc
            cclop = None
            if shift:
                cclop = CCLOp.reduce_ring
            else:
                warnings.warn("Non-ring reduce are not handled at packetizer level at the moment.")
                return
                cclop = CCLOp.reduce
            
            prevcall = [self.start(scenario=cclop , len=count, comm=self.communicators[comm_id]["addr"], root_src_dst=root, function=func, addr_0=sbuf, addr_1=rbuf, waitfor=waitfor)]

        if run_async:
            return prevcall[0]
        
        prevcall[0].wait()
        if not to_fpga and local_rank == root:
            rbuf[0:count].sync_from_device()

    @self_check_return_value
    def allreduce(self, comm_id, sbuf, rbuf, count, func, fused=False, sw=True, ring=True, from_fpga=False, to_fpga=False, run_async=False, waitfor=[]):
        if not to_fpga and run_async:
            warnings.warn("ACCL: async run returns data on FPGA, user must sync_from_device() after waiting")
        if count == 0:
            return
        if not compatible_size(count,func):
            return
        if func > 3:
            warnings.warn("Non-add reduce not implemented")
            return
        if not from_fpga:
            sbuf[0:count].sync_to_device()

        if sw: #sw collectives implement all reduce on top of send/recv functionality exposed by mpi_offload
                    
            if       fused and ring:
                comm        = self.communicators[comm_id]
                p           = len(comm["ranks"])
                local_rank  = comm["local_rank"]

                next_in_ring = (local_rank + 1     )%p
                prev_in_ring = (local_rank - 1 + p )%p
                
                buf         = sbuf[0:count]
                accum_buf   = rbuf[0:count]
                spare_buf   = self.utility_spare[0:count]
                #initalize dest_buff with your data
                prevcall    = [self.copy(sbuf, accum_buf, from_fpga=True,  to_fpga=True, run_async=True, waitfor=waitfor)]
                #send your data to the next in the queue
                prevcall    = [self.send(comm_id, sbuf, dst=next_in_ring, from_fpga=True, run_async=True, waitfor=prevcall)]
                #receive p-2 data, accumulate and relay to the next in the ring
                for _ in range(p-2):
                    prevcall = [self.recv(comm_id,        spare_buf, src=prev_in_ring,    to_fpga=True, run_async=True, waitfor=prevcall)]
                    prevcall = [self.accumulate(func, val=spare_buf, acc=accum_buf, val_from_fpga=True, acc_from_fpga=True, to_fpga=True, run_async=True, waitfor=prevcall)]
                    prevcall = [self.send(comm_id,        spare_buf, dst=next_in_ring,  from_fpga=True, run_async=True, waitfor=prevcall)]
                #receive last and accumulate
                prevcall = [self.recv    (comm_id,    spare_buf, src=prev_in_ring, to_fpga  =True, run_async=True, waitfor=prevcall)]
                prevcall = [self.accumulate( func,val=spare_buf, acc=accum_buf, val_from_fpga=True, acc_from_fpga=True, to_fpga=True, run_async=True, waitfor=prevcall)]
                   
            elif     fused and not ring:
                warnings.warn("Non-ring collectives are not handled at packetizer level at the moment.")
                warnings.warn("sw non ring based fused allreduce not implemented")
                return
            elif not fused:
                #implement allgather from gather+broadcast (root=0)
                prevcall = [self.reduce(comm_id, sbuf, rbuf, count, root=0, func=func, sw=sw, shift=ring, from_fpga=from_fpga , to_fpga=True, run_async=True, waitfor=waitfor )]
                prevcall = [self.bcast( comm_id, rbuf,              root=0,            sw=sw,             from_fpga=True      , to_fpga=True, run_async=True, waitfor=prevcall)]
            
            
        else: #hw implementations
            # performs acc = val + acc on each cclo

            cclop = None
            if   fused and ring:
                cclop = CCLOp.allreduce_fused_ring
            elif fused and not ring:
                warnings.warn("Non-ring collectives are not handled at packetizer level at the moment.")
                warnings.warn("sw non ring based fused allreduce not implemented")
                return
            else:
                ccl_op = CCLOp.allreduce
            
            prevcall = [self.start(scenario=cclop, len=count, comm=self.communicators[comm_id]["addr"], function=func, addr_0=sbuf, addr_1=rbuf, waitfor=waitfor)]

        if run_async:
                return prevcall[0]

        prevcall[0].wait()
        if not to_fpga:
            rbuf[0:count].sync_from_device()
            
