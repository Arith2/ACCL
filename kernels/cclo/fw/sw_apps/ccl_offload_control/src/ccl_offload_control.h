/*******************************************************************************
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

#ifndef _CCL_OFFLOAD_CONTROL_H_
#define _CCL_OFFLOAD_CONTROL_H_

#ifdef __cplusplus
extern "C" {
#endif

#define KERNEL_NAME    "ccl_offload"
#define KERNEL_VENDOR  "Xilinx"
#define KERNEL_LIBRARY "XCCL"

//AXIS interfaces to/from MB 

#define CMD_DMA0_TX  0
#define CMD_DMA0_RX  1
#define CMD_DMA1_TX  2
#define CMD_DMA1_RX  3
#define CMD_DMA2_TX  4
#define CMD_DMA2_RX  5
#define CMD_UDP_TX   6
#define CMD_TCP_PORT 7
#define CMD_TCP_CON  8
#define CMD_TCP_TX   9
#define CMD_HOST    10

#define STS_DMA0_RX  0
#define STS_DMA0_TX  1
#define STS_DMA1_RX  2
#define STS_DMA1_TX  3
#define STS_DMA2_RX  4
#define STS_DMA2_TX  5
#define STS_UDP_RX   6
#define STS_TCP_PORT 7
#define STS_TCP_CON  8
#define STS_TCP_RX   9
#define STS_HOST     10 
#define STS_TCP_PKT  11 
#define STS_UDP_PKT  12

//MAIN SWITCH

#define DATAPATH_DMA_LOOPBACK          1
#define DATAPATH_DMA_REDUCTION         2
#define DATAPATH_OFFCHIP_TX_UDP        3
#define DATAPATH_OFFCHIP_TX_TCP        4
#define DATAPATH_OFFCHIP_UDP_REDUCTION 5
#define DATAPATH_OFFCHIP_TCP_REDUCTION 6
#define DATAPATH_DMA_EXT_LOOPBACK      7
//#define DATAPATH_OFFCHIP_RX_UDP      8 not used up to now since DMA are physically linked to depacketizer
//#define DATAPATH_OFFCHIP_RX_TCP      9 not used up to now since DMA are physically linked to depacketizer

#define SWITCH_M_UDP_TX    0
#define SWITCH_M_TCP_TX    1
#define SWITCH_M_DMA1_TX   2
#define SWITCH_M_ARITH_OP0 3
#define SWITCH_M_ARITH_OP1 4
#define SWITCH_M_EXT_KRNL  5

#define SWITCH_S_DMA0_RX   0
#define SWITCH_S_DMA1_RX   1
#define SWITCH_S_DMA2_RX   2
#define SWITCH_S_ARITH_RES 3
#define SWITCH_S_EXT_KRNL  4

//PACKT CONST
#define MAX_PACKETSIZE 1536
#define MAX_SEG_SIZE 1048576
//DMA CONST 
#define DMA_MAX_BTT              0x7FFFFF
#define DMA_MAX_TRANSACTIONS     20
#define DMA_TRANSACTION_SIZE     4194304 //info: can correspond to MAX_BTT

//******************************
//**  XCC Operations          **
//******************************
//Housekeeping
#define XCCL_CONFIG               0
//Primitives
#define XCCL_COPY                 1
#define XCCL_REDUCE               2
#define XCCL_SEND                 3 
#define XCCL_RECV                 4
//Collectives
#define XCCL_COLL_BCAST           5
#define XCCL_COLL_SCATTER         6
#define XCCL_COLL_GATHER          7
#define XCCL_COLL_REDUCE          8
#define XCCL_COLL_ALLGATHER       9
#define XCCL_COLL_ALLREDUCE       10
#define XCCL_COLL_REDUCE_SCATTER  11

//XCCL_CONFIG SUBFUNCTIONS
#define HOUSEKEEP_IRQEN           0
#define HOUSEKEEP_IRQDIS          1
#define HOUSEKEEP_SWRST           2
#define HOUSEKEEP_PKTEN           3
#define HOUSEKEEP_TIMEOUT         4
#define INIT_CONNECTION           5 
#define OPEN_PORT                 6
#define OPEN_CON                  7
#define USE_TCP_STACK             8
#define USE_UDP_STACK             9
#define START_PROFILING           10
#define END_PROFILING             11
#define SET_DMA_TRANSACTION_SIZE  12
#define SET_MAX_DMA_TRANSACTIONS  13

//AXI MMAP address
#define CONTROL_OFFSET          0x0000
#define ARG00_OFFSET            0x0010
#define AXI00_PTR0_OFFSET       0x0018
#define AXI01_PTR0_OFFSET       0x0024
#define END_OF_REG_OFFSET       0x0030
#define TIME_TO_ACCESS_EXCH_MEM 0x1FF4
#define HWID_OFFSET       0x1FF8
#define RETVAL_OFFSET     0x1FFC
#define END_OF_EXCHMEM    0x2000

#define HOSTCTRL_BASEADDR     0x0        
#define EXCHMEM_BASEADDR      0x1000
#define UDP_RXPKT_BASEADDR    0x30000
#define UDP_TXPKT_BASEADDR    0x40000
#define TCP_RXPKT_BASEADDR    0x50000
#define TCP_TXPKT_BASEADDR    0x60000
#define GPIO_BASEADDR         0x40000000
#define GPIO_TDEST_BASEADDR   0x40010000
#define SWITCH_BASEADDR       0x44A00000
#define IRQCTRL_BASEADDR      0x44A10000
#define TIMER_BASEADDR        0x44A20000
//https://www.xilinx.com/html_docs/xilinx2020_2/vitis_doc/managing_interface_synthesis.html#tzw1539734223235
#define CONTROL_START_MASK      0x00000001
#define CONTROL_DONE_MASK       0x00000001 << 1
#define CONTROL_IDLE_MASK       0x00000001 << 2 
#define CONTROL_READY_MASK      0x00000001 << 3
#define CONTROL_REPEAT_MASK     0x00000001 << 7

#define GPIO_DATA_REG      GPIO_BASEADDR + 0x0000
#define GPIO2_DATA_REG     GPIO_BASEADDR + 0x0008
#define GPIO_READY_MASK       0x00000001
#define GPIO_SWRST_MASK       0x00000002

//from AXI interrupt controller v4.1 LogiCORE IP product guide
//https://www.xilinx.com/support/documentation/ip_documentation/axi_intc/v4_1/pg099-axi-intc.pdf
#define IRQCTRL_INTERRUPT_STATUS_REGISTER_OFFSET                  0x00
#define IRQCTRL_INTERRUPT_PENDING_REGISTER_OFFSET                 0x04
#define IRQCTRL_INTERRUPT_ENABLE_REGISTER_OFFSET                  0x08
#define IRQCTRL_INTERRUPT_ACKNOWLEDGE_REGISTER_OFFSET             0x0C
#define IRQCTRL_SET_INTERRUPT_ENABLES_OFFSET                      0x10
#define IRQCTRL_CLEAR_INTERRUPT_ENABLES_OFFSET                    0x14
#define IRQCTRL_INTERRUPT_VECTOR_REGISTER_OFFSET                  0x18
#define IRQCTRL_MASTER_ENABLE_REGISTER_OFFSET                     0x1C
#define IRQCTRL_INTERRUPT_MODE_REGISTER_OFFSET                    0x20
#define IRQCTRL_INTERRUPT_LEVEL_REGISTER_OFFSET                   0x24
#define IRQCTRL_INTERRUPT_VECTOR_ADDRESS_REGISTER_OFFSET          0x100
#define IRQCTRL_INTERRUPT_VECTOR_EXTENDED_ADDRESS_REGISTER_OFFSET 0x200
#define IRQCTRL_SIZE                                              0x300

#define IRQCTRL_TIMER_ENABLE                   0x0001
#define IRQCTRL_DMA0_CMD_QUEUE_EMPTY           0x0002
#define IRQCTRL_DMA0_STS_QUEUE_NON_EMPTY       0x0004
#define IRQCTRL_DMA2_CMD_QUEUE_EMPTY           0x0008
#define IRQCTRL_DMA2_STS_QUEUE_NON_EMPTY       0x0010

#define IRQCTRL_MASTER_ENABLE_REGISTER_HARDWARE_INTERRUPT_ENABLE 0x0002
#define IRQCTRL_MASTER_ENABLE_REGISTER_MASTER_ENABLE             0x0001

//from AXI Timer v2.0 LogiCORE IP Product Guide
//https://www.xilinx.com/support/documentation/ip_documentation/axi_timer/v2_0/pg079-axi-timer.pdf
#define TIMER0_CONTROL_AND_STATUS_REGISTER_OFFSET                 0x00
#define TIMER0_LOAD_REGISTER_OFFSET                               0x04
#define TIMER0_COUNTER_REGISTER_OFFSET                            0x08
#define TIMER1_CONTROL_AND_STATUS_REGISTER_OFFSET                 0x10
#define TIMER1_LOAD_REGISTER_OFFSET                               0x14
#define TIMER1_COUNTER_REGISTER_OFFSET                            0x18
#define TIMER_SIZE                                                0x20
//TIMERX_CONTROL_AND_STATUS_REGISTER
#define CONTROL_AND_STATUS_REGISTER_CASC_MASK                     0x0001 <<11
#define CONTROL_AND_STATUS_REGISTER_ENABLE_ALL_MASK               0x0001 <<10 
#define CONTROL_AND_STATUS_REGISTER_PWMX_ENABLE_MASK              0x0001 << 9 
#define CONTROL_AND_STATUS_REGISTER_INTERRUPT_MASK                0x0001 << 8 
#define CONTROL_AND_STATUS_REGISTER_ENABLE_MASK                   0x0001 << 7 
#define CONTROL_AND_STATUS_REGISTER_INTERRUPT_ENABLE_MASK         0x0001 << 6
#define CONTROL_AND_STATUS_REGISTER_LOAD_TIMER_MASK               0x0001 << 5
#define CONTROL_AND_STATUS_REGISTER_AUTO_RELOAD_TIMER_MASK        0x0001 << 4
#define CONTROL_AND_STATUS_REGISTER_CAPTURE_MASK                  0x0001 << 3
#define CONTROL_AND_STATUS_REGISTER_GENERATE_MASK                 0x0001 << 2
#define CONTROL_AND_STATUS_REGISTER_UP_DOWN_MASK                  0x0001 << 1
#define CONTROL_AND_STATUS_REGISTER_MODE_TIMER_MASK               0x0001 << 0

//EXCEPTIONS
#define COLLECTIVE_OP_SUCCESS                         0    
#define DMA_MISMATCH_ERROR                            1     
#define DMA_INTERNAL_ERROR                            2     
#define DMA_DECODE_ERROR                              3  
#define DMA_SLAVE_ERROR                               4 
#define DMA_NOT_OKAY_ERROR                            5     
#define DMA_NOT_END_OF_PACKET_ERROR                   6             
#define DMA_NOT_EXPECTED_BTT_ERROR                    7
#define DMA_TIMEOUT_ERROR                             8             
#define CONFIG_SWITCH_ERROR                           9
#define DEQUEUE_BUFFER_TIMEOUT_ERROR                  10
#define DEQUEUE_BUFFER_SPARE_BUFFER_STATUS_ERROR      11
#define RECEIVE_TIMEOUT_ERROR                         12
#define DEQUEUE_BUFFER_SPARE_BUFFER_DMATAG_MISMATCH   13
#define DEQUEUE_BUFFER_SPARE_BUFFER_INDEX_ERROR       14
#define COLLECTIVE_NOT_IMPLEMENTED                    15
#define RECEIVE_OFFCHIP_SPARE_BUFF_ID_NOT_VALID       16
#define OPEN_PORT_NOT_SUCCEEDED                       17
#define OPEN_COM_NOT_SUCCEEDED                        18
#define DMA_SIZE_ERROR                                19
#define ARITH_ERROR                                   20 
#define PACK_TIMEOUT_STS_ERROR                        21
#define PACK_SEQ_NUMBER_ERROR                         22
#define COMPRESSION_ERROR                             23

//blocks used for data movement
#define USE_NONE    0
#define USE_OP0_DMA 1
#define USE_OP1_DMA 2
#define USE_RES_DMA 4
#define USE_OP2_DMA 8
#define USE_RES_DMA_WITHOUT_TLAST 16
#define USE_PACKETIZER 32

#define S_AXI_CONTROL -1

#define Xil_Out32(offset, value) (*((volatile unsigned int *)(offset))) = (value)
#define Xil_In32(offset) ({unsigned int value = *((volatile unsigned int *)(offset)); value; })
#define SET(offset, mask) Xil_Out32(offset, Xil_In32(offset) | (mask))
#define CLR(offset, mask) Xil_Out32(offset, Xil_In32(offset) & ~(mask))

//push data to stream
#define putd(channel, value) asm volatile ("putd\t%0,%1" :: "d" (value), "d" (channel))
//push data to stream and set control bit
#define cputd(channel, value) asm volatile ("cputd\t%0,%1" :: "d" (value), "d" (channel))
//test-only non-blocking get from stream channel
#define tngetd(channel) ({unsigned int value; asm volatile ("tngetd\tr0,%1\n\taddic\t%0,r0,0" : "=d" (value) : "d" (channel)); value; })
//blocking get from stream channel
#define getd(channel) ({unsigned int value; asm volatile ("getd\t%0,%1" : "=d" (value) : "d" (channel)); value; })

typedef enum {
    type_control,
    type_int,
    type_bool,
    type_char,
    type_uchar,
    type_short,
    type_ushort,
    type_uint,
    type_long,
    type_ulong, 
    type_float,
    type_double,
    type_half,
    type_intptr,
} type_t;

typedef struct {
    char   *name;
    type_t type;
    int    interface;
} arg_t;

typedef struct {
    unsigned int addrl;
    unsigned int addrh;
    unsigned int max_len;
    unsigned int dma_tag;
    unsigned int status;
    unsigned int rx_tag;
    unsigned int rx_len;
    unsigned int rx_src;
    unsigned int sequence_number;
} rx_buffer;
#define STATUS_IDLE     0x00
#define STATUS_ENQUEUED 0x01
#define STATUS_RESERVED 0x02

#define RX_BUFFER_COUNT_OFFSET 0x1000

#define COMM_OFFSET (RX_BUFFER_COUNT_OFFSET+4*(1 + Xil_In32(RX_BUFFER_COUNT_OFFSET)*9))

typedef struct {
    unsigned int ip;
    unsigned int port;
    unsigned int inbound_seq;
    unsigned int outbound_seq;
    unsigned int session;
} comm_rank;

typedef struct {
    unsigned int size;
    unsigned int local_rank;
    comm_rank* ranks;
} communicator;

//structure defining arithmetic config parameters
//TODO: make unsigned char to save on space
#define MAX_REDUCE_FUNCTIONS 10

typedef struct {
    unsigned int uncompressed_elem_bits;//bitwidth of one element of uncompressed data
    unsigned int compressed_elem_bits;  //bitwidth of one element of compressed data
    unsigned int elem_ratio;            //how many uncompressed elements per compressed element
    unsigned int compressor_tdest;      //clane TDEST for targeting the compressor
    unsigned int decompressor_tdest;    //clane TDEST for targeting the compressor
    unsigned int arith_nfunctions;      //number of supported functions (<= MAX_REDUCE_FUNCTIONS)
    unsigned int arith_is_compressed;   //perform arithmetic on compressed (1) or uncompressed (0) values
    unsigned int arith_tdest[MAX_REDUCE_FUNCTIONS]; //arithmetic TDEST
} datapath_arith_config;

//define compression flags
#define NO_COMPRESSION 0
#define OP0_COMPRESSED 1
#define OP1_COMPRESSED 2
#define RES_COMPRESSED 4
#define ETH_COMPRESSED 8

//Tag definitions
#define TAG_ANY 0xFFFFFFFF

//circular buffer
#define MAX_CIRCULAR_BUFFER_SIZE 20
typedef struct circular_buffer
{
    unsigned int buffer[MAX_CIRCULAR_BUFFER_SIZE];     // data buffer
    unsigned int capacity;      //real desired capacity of buffer
    unsigned int occupancy;     //current occupancy
    unsigned int write_idx;          // where we put data
    unsigned int read_idx;          // where we get data from
} circular_buffer;

#ifdef __cplusplus
}
#endif
#endif // _CCL_OFFLOAD_CONTROL_H_