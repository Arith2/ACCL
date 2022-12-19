#include <hls_stream.h>
#include <iostream>
#include <dlrm.h>

namespace dlrm_reduce_root_ns {

void recvDataTransform(STREAM<ap_uint<512> > & s_data_in, STREAM<ap_uint<512> > & s_feature_in, STREAM<ap_uint<512> > & s_feature_send_out, STREAM<ap_uint<512> > & s_data_in_zero);

void load_access_idx(
    STREAM<int>& start_flag,
    STREAM<int>& s_idx_buffer_HBM0, STREAM<int>& s_idx_buffer_HBM1, 
    STREAM<int>& s_idx_buffer_HBM2, STREAM<int>& s_idx_buffer_HBM3, 
    STREAM<int>& s_idx_buffer_HBM4, STREAM<int>& s_idx_buffer_HBM5, 
    STREAM<int>& s_idx_buffer_HBM6, STREAM<int>& s_idx_buffer_HBM7, 
    STREAM<int>& s_idx_buffer_HBM8, STREAM<int>& s_idx_buffer_HBM9, 
    STREAM<int>& s_idx_buffer_HBM10, STREAM<int>& s_idx_buffer_HBM11, 
    STREAM<int>& s_idx_buffer_HBM12, STREAM<int>& s_idx_buffer_HBM13, 
    STREAM<int>& s_idx_buffer_HBM14, STREAM<int>& s_idx_buffer_HBM15, 
    STREAM<int>& s_idx_buffer_HBM16, STREAM<int>& s_idx_buffer_HBM17, 
    STREAM<int>& s_idx_buffer_HBM18, STREAM<int>& s_idx_buffer_HBM19, 
    STREAM<int>& s_idx_buffer_HBM20, STREAM<int>& s_idx_buffer_HBM21, 
    STREAM<int>& s_idx_buffer_HBM22, STREAM<int>& s_idx_buffer_HBM23, 
    STREAM<int>& s_idx_buffer_HBM24, STREAM<int>& s_idx_buffer_HBM25, 
    STREAM<int>& s_idx_buffer_HBM26, STREAM<int>& s_idx_buffer_HBM27,
    STREAM<int>& s_idx_buffer_HBM28, STREAM<int>& s_idx_buffer_HBM29);

template<
    const int START_ADDR_0, const int AXI_PADDED_SIZE_0, 
    const int START_ADDR_1, const int AXI_PADDED_SIZE_1,
    const int ROW_PER_PE>
void load_single_embedding_2_tables(
    STREAM<int>& s_idx_buffer, const t_axi* table_RAM, 
    STREAM<t_axi>& s_embedding_buffer);
    
template<typename T, const int VECTOR_LENGTH, const int ROW_PER_PE>
void int_to_wide(
    STREAM<T>& s_embedding_buffer, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_1);

template<const int VECTOR_LENGTH_0, const int VECTOR_LENGTH_1, const int VECTOR_LENGTH_2, const int VECTOR_LENGTH_3, const int VECTOR_LENGTH_4, const int VECTOR_LENGTH_5, const int VECTOR_LENGTH_6, const int VECTOR_LENGTH_7, const int ROW_PER_PE>
void gather_embeddings_8(
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM0_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM1_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM2_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM3_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM4_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM5_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM6_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM7_1,
    STREAM<ap_uint<512> >& s_feature_in
);

template<const int VECTOR_LENGTH_0, const int VECTOR_LENGTH_1, const int VECTOR_LENGTH_2, const int VECTOR_LENGTH_3, const int VECTOR_LENGTH_4, const int VECTOR_LENGTH_5, const int VECTOR_LENGTH_6, const int ROW_PER_PE>
void gather_embeddings_7(
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM0_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM1_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM2_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM3_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM4_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM5_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM6_1, 
    STREAM<ap_uint<512> >& s_feature_in
);

template<const int ROW_PER_PE>
void gather_embeddings(
    STREAM<ap_uint<512> >& s_embedding_0,
    STREAM<ap_uint<512> >& s_embedding_1,
    STREAM<ap_uint<512> >& s_embedding_2,
    STREAM<ap_uint<512> >& s_embedding_3,
    STREAM<ap_uint<512> >& s_feature_in
);

template<const int FEATURE_SIZE, const int ROW_PER_PE>
void store_features(
    STREAM<ap_uint<512> >& s_feature_in,
    STREAM<ap_uint<512> >& s_feature_out);

void replicate_feature_in(STREAM<ap_uint<512> > & s_feature_in, STREAM<ap_uint<512> > & s_feature_in_0, STREAM<ap_uint<512> > & s_feature_in_1, STREAM<ap_uint<512> > & s_embedding_table);

void replicate_feature_in_4(
    STREAM<ap_uint<512> > & s_feature_in, 
    STREAM<ap_uint<512> > & s_feature_in_0, STREAM<ap_uint<512> > & s_feature_in_1, 
    STREAM<ap_uint<512> > & s_feature_in_2, STREAM<ap_uint<512> > & s_feature_in_3, 
    STREAM<ap_uint<512> > & s_embedding_table);

void replicate_feature_in_6(
    STREAM<ap_uint<512> > & s_feature_in, 
    STREAM<ap_uint<512> > & s_feature_in_0, STREAM<ap_uint<512> > & s_feature_in_1, 
    STREAM<ap_uint<512> > & s_feature_in_2, STREAM<ap_uint<512> > & s_feature_in_3, 
    STREAM<ap_uint<512> > & s_feature_in_4, STREAM<ap_uint<512> > & s_feature_in_5, 
    STREAM<ap_uint<512> > & s_embedding_table);

void replicate_feature_in_7(
    STREAM<ap_uint<512> > & s_feature_in, 
    STREAM<ap_uint<512> > & s_feature_in_0, STREAM<ap_uint<512> > & s_feature_in_1, 
    STREAM<ap_uint<512> > & s_feature_in_2, STREAM<ap_uint<512> > & s_feature_in_3, 
    STREAM<ap_uint<512> > & s_feature_in_4, STREAM<ap_uint<512> > & s_feature_in_5, 
    STREAM<ap_uint<512> > & s_feature_in_6, 
    STREAM<ap_uint<512> > & s_embedding_table);


void replicate_feature_in_8(
    STREAM<ap_uint<512> > & s_feature_in, 
    STREAM<ap_uint<512> > & s_feature_in_0, STREAM<ap_uint<512> > & s_feature_in_1, 
    STREAM<ap_uint<512> > & s_feature_in_2, STREAM<ap_uint<512> > & s_feature_in_3, 
    STREAM<ap_uint<512> > & s_feature_in_4, STREAM<ap_uint<512> > & s_feature_in_5, 
    STREAM<ap_uint<512> > & s_feature_in_6, STREAM<ap_uint<512> > & s_feature_in_7, 
    STREAM<ap_uint<512> > & s_embedding_table);

void replicate_feature_in_13(
    STREAM<ap_uint<512> > & s_feature_in, 
    STREAM<ap_uint<512> > & s_feature_in_0, STREAM<ap_uint<512> > & s_feature_in_1, 
    STREAM<ap_uint<512> > & s_feature_in_2, STREAM<ap_uint<512> > & s_feature_in_3, 
    STREAM<ap_uint<512> > & s_feature_in_4, STREAM<ap_uint<512> > & s_feature_in_5, 
    STREAM<ap_uint<512> > & s_feature_in_6, STREAM<ap_uint<512> > & s_feature_in_7, 
    STREAM<ap_uint<512> > & s_feature_in_8, STREAM<ap_uint<512> > & s_feature_in_9, 
    STREAM<ap_uint<512> > & s_feature_in_10, STREAM<ap_uint<512> > & s_feature_in_11, 
    STREAM<ap_uint<512> > & s_feature_in_12, 
    STREAM<ap_uint<512> > & s_embedding_table);

void replicate_feature_in_26(
    STREAM<ap_uint<512> > & s_feature_in, 
    STREAM<ap_uint<512> > & s_feature_in_0, STREAM<ap_uint<512> > & s_feature_in_1, 
    STREAM<ap_uint<512> > & s_feature_in_2, STREAM<ap_uint<512> > & s_feature_in_3, 
    STREAM<ap_uint<512> > & s_feature_in_4, STREAM<ap_uint<512> > & s_feature_in_5, 
    STREAM<ap_uint<512> > & s_feature_in_6, STREAM<ap_uint<512> > & s_feature_in_7, 
    STREAM<ap_uint<512> > & s_feature_in_8, STREAM<ap_uint<512> > & s_feature_in_9, 
    STREAM<ap_uint<512> > & s_feature_in_10, STREAM<ap_uint<512> > & s_feature_in_11, 
    STREAM<ap_uint<512> > & s_feature_in_12, STREAM<ap_uint<512> > & s_feature_in_13, 
    STREAM<ap_uint<512> > & s_feature_in_14, STREAM<ap_uint<512> > & s_feature_in_15,
    STREAM<ap_uint<512> > & s_feature_in_16, STREAM<ap_uint<512> > & s_feature_in_17,
    STREAM<ap_uint<512> > & s_feature_in_18, STREAM<ap_uint<512> > & s_feature_in_19,
    STREAM<ap_uint<512> > & s_feature_in_20, STREAM<ap_uint<512> > & s_feature_in_21,
    STREAM<ap_uint<512> > & s_feature_in_22, STREAM<ap_uint<512> > & s_feature_in_23,
    STREAM<ap_uint<512> > & s_feature_in_24, STREAM<ap_uint<512> > & s_feature_in_25,
    STREAM<ap_uint<512> > & s_embedding_table);

template<const int FEATURE_SIZE, const int ROW_PER_PE>
void replicate_feature_in_16(
    STREAM<ap_uint<512> > & s_feature_in, 
    STREAM<ap_uint<512> > & s_feature_in_0, STREAM<ap_uint<512> > & s_feature_in_1, 
    STREAM<ap_uint<512> > & s_feature_in_2, STREAM<ap_uint<512> > & s_feature_in_3, 
    STREAM<ap_uint<512> > & s_feature_in_4, STREAM<ap_uint<512> > & s_feature_in_5, 
    STREAM<ap_uint<512> > & s_feature_in_6, STREAM<ap_uint<512> > & s_feature_in_7 
    // STREAM<ap_uint<512> > & s_feature_in_8, STREAM<ap_uint<512> > & s_feature_in_9, 
    // STREAM<ap_uint<512> > & s_feature_in_10, STREAM<ap_uint<512> > & s_feature_in_11, 
    // STREAM<ap_uint<512> > & s_feature_in_12, STREAM<ap_uint<512> > & s_feature_in_13, 
    // STREAM<ap_uint<512> > & s_feature_in_14, STREAM<ap_uint<512> > & s_feature_in_15
    );


template<const int FEATURE_SIZE, const int ROW_PER_PE, const int WEIGHT_RAM>
void matmul_PE_UNROLL8(
    STREAM<W_TYPE>& s_feature_PE_0,
    STREAM<W_TYPE>& s_feature_PE_1,
    STREAM<D_TYPE>& s_result_PE);

template<>
void matmul_PE_UNROLL8<ROOT_HIDDEN_SIZE1, ROOT_ROW_PER_PE2, WEIGHT_BRAM>(
    STREAM<W_TYPE>& s_feature_PE_0,
    STREAM<W_TYPE>& s_feature_PE_1,
    STREAM<D_TYPE>& s_result_PE);

template<>
void matmul_PE_UNROLL8<ROOT_HIDDEN_SIZE1, ROOT_ROW_PER_PE2, WEIGHT_URAM>(
    STREAM<W_TYPE>& s_feature_PE_0,
    STREAM<W_TYPE>& s_feature_PE_1,
    STREAM<D_TYPE>& s_result_PE);

template<const int FEATURE_SIZE, const int ROW_PER_PE, const int INDEX_ROW>
void init_weights(W_TYPE* weights_transpose); 

template<>
void init_weights<ROOT_HIDDEN_SIZE1, ROOT_ROW_PER_PE2, WEIGHT_BRAM>(W_TYPE* weights_transpose_local);

template<>
void init_weights<ROOT_HIDDEN_SIZE1, ROOT_ROW_PER_PE2, WEIGHT_URAM>(W_TYPE* weights_transpose_local);

template<const int FEATURE_SIZE>
void replicate_feature_512PEs_216PE(
    STREAM<ap_uint<512> >& s_feature_in, 
    STREAM<ap_uint<512> >& s_embedding_table,
    STREAM<W_TYPE>& s_feature_PE0_0, STREAM<W_TYPE>& s_feature_PE0_1,
    STREAM<W_TYPE>& s_feature_PE0_2, STREAM<W_TYPE>& s_feature_PE0_3,
    STREAM<W_TYPE>& s_feature_PE1_0, STREAM<W_TYPE>& s_feature_PE1_1,
    STREAM<W_TYPE>& s_feature_PE1_2, STREAM<W_TYPE>& s_feature_PE1_3,
    STREAM<W_TYPE>& s_feature_PE2_0, STREAM<W_TYPE>& s_feature_PE2_1,
    STREAM<W_TYPE>& s_feature_PE2_2, STREAM<W_TYPE>& s_feature_PE2_3,
    STREAM<W_TYPE>& s_feature_PE3_0, STREAM<W_TYPE>& s_feature_PE3_1,
    STREAM<W_TYPE>& s_feature_PE3_2, STREAM<W_TYPE>& s_feature_PE3_3,
    STREAM<W_TYPE>& s_feature_PE4_0, STREAM<W_TYPE>& s_feature_PE4_1,
    STREAM<W_TYPE>& s_feature_PE4_2, STREAM<W_TYPE>& s_feature_PE4_3,
    STREAM<W_TYPE>& s_feature_PE5_0, STREAM<W_TYPE>& s_feature_PE5_1,
    STREAM<W_TYPE>& s_feature_PE5_2, STREAM<W_TYPE>& s_feature_PE5_3,
    STREAM<W_TYPE>& s_feature_PE6_0, STREAM<W_TYPE>& s_feature_PE6_1,
    STREAM<W_TYPE>& s_feature_PE6_2, STREAM<W_TYPE>& s_feature_PE6_3,
    STREAM<W_TYPE>& s_feature_PE7_0, STREAM<W_TYPE>& s_feature_PE7_1,
    STREAM<W_TYPE>& s_feature_PE7_2, STREAM<W_TYPE>& s_feature_PE7_3,
    STREAM<W_TYPE>& s_feature_PE8_0, STREAM<W_TYPE>& s_feature_PE8_1,
    STREAM<W_TYPE>& s_feature_PE8_2, STREAM<W_TYPE>& s_feature_PE8_3,
    STREAM<W_TYPE>& s_feature_PE9_0, STREAM<W_TYPE>& s_feature_PE9_1,
    STREAM<W_TYPE>& s_feature_PE9_2, STREAM<W_TYPE>& s_feature_PE9_3,
    STREAM<W_TYPE>& s_feature_PE10_0, STREAM<W_TYPE>& s_feature_PE10_1,
    STREAM<W_TYPE>& s_feature_PE10_2, STREAM<W_TYPE>& s_feature_PE10_3,
    STREAM<W_TYPE>& s_feature_PE11_0, STREAM<W_TYPE>& s_feature_PE11_1,
    STREAM<W_TYPE>& s_feature_PE11_2, STREAM<W_TYPE>& s_feature_PE11_3,
    STREAM<W_TYPE>& s_feature_PE12_0, STREAM<W_TYPE>& s_feature_PE12_1,
    STREAM<W_TYPE>& s_feature_PE12_2, STREAM<W_TYPE>& s_feature_PE12_3,
    STREAM<W_TYPE>& s_feature_PE13_0, STREAM<W_TYPE>& s_feature_PE13_1,
    STREAM<W_TYPE>& s_feature_PE13_2, STREAM<W_TYPE>& s_feature_PE13_3,
    STREAM<W_TYPE>& s_feature_PE14_0, STREAM<W_TYPE>& s_feature_PE14_1,
    STREAM<W_TYPE>& s_feature_PE14_2, STREAM<W_TYPE>& s_feature_PE14_3,
    STREAM<W_TYPE>& s_feature_PE15_0, STREAM<W_TYPE>& s_feature_PE15_1,
    STREAM<W_TYPE>& s_feature_PE15_2, STREAM<W_TYPE>& s_feature_PE15_3,
    STREAM<W_TYPE>& s_feature_PE16_0, STREAM<W_TYPE>& s_feature_PE16_1,
    STREAM<W_TYPE>& s_feature_PE16_2, STREAM<W_TYPE>& s_feature_PE16_3,
    STREAM<W_TYPE>& s_feature_PE17_0, STREAM<W_TYPE>& s_feature_PE17_1,
    STREAM<W_TYPE>& s_feature_PE17_2, STREAM<W_TYPE>& s_feature_PE17_3,
    STREAM<W_TYPE>& s_feature_PE18_0, STREAM<W_TYPE>& s_feature_PE18_1,
    STREAM<W_TYPE>& s_feature_PE18_2, STREAM<W_TYPE>& s_feature_PE18_3,
    STREAM<W_TYPE>& s_feature_PE19_0, STREAM<W_TYPE>& s_feature_PE19_1,
    STREAM<W_TYPE>& s_feature_PE19_2, STREAM<W_TYPE>& s_feature_PE19_3,
    STREAM<W_TYPE>& s_feature_PE20_0, STREAM<W_TYPE>& s_feature_PE20_1,
    STREAM<W_TYPE>& s_feature_PE20_2, STREAM<W_TYPE>& s_feature_PE20_3,
    STREAM<W_TYPE>& s_feature_PE21_0, STREAM<W_TYPE>& s_feature_PE21_1,
    STREAM<W_TYPE>& s_feature_PE21_2, STREAM<W_TYPE>& s_feature_PE21_3,
    STREAM<W_TYPE>& s_feature_PE22_0, STREAM<W_TYPE>& s_feature_PE22_1,
    STREAM<W_TYPE>& s_feature_PE22_2, STREAM<W_TYPE>& s_feature_PE22_3,
    STREAM<W_TYPE>& s_feature_PE23_0, STREAM<W_TYPE>& s_feature_PE23_1,
    STREAM<W_TYPE>& s_feature_PE23_2, STREAM<W_TYPE>& s_feature_PE23_3,
    STREAM<W_TYPE>& s_feature_PE24_0, STREAM<W_TYPE>& s_feature_PE24_1,
    STREAM<W_TYPE>& s_feature_PE24_2, STREAM<W_TYPE>& s_feature_PE24_3,
    STREAM<W_TYPE>& s_feature_PE25_0, STREAM<W_TYPE>& s_feature_PE25_1,
    STREAM<W_TYPE>& s_feature_PE25_2, STREAM<W_TYPE>& s_feature_PE25_3,
    STREAM<W_TYPE>& s_feature_PE26_0, STREAM<W_TYPE>& s_feature_PE26_1,
    STREAM<W_TYPE>& s_feature_PE26_2, STREAM<W_TYPE>& s_feature_PE26_3,
    STREAM<W_TYPE>& s_feature_PE27_0, STREAM<W_TYPE>& s_feature_PE27_1,
    STREAM<W_TYPE>& s_feature_PE27_2, STREAM<W_TYPE>& s_feature_PE27_3,
    STREAM<W_TYPE>& s_feature_PE28_0, STREAM<W_TYPE>& s_feature_PE28_1,
    STREAM<W_TYPE>& s_feature_PE28_2, STREAM<W_TYPE>& s_feature_PE28_3,
    STREAM<W_TYPE>& s_feature_PE29_0, STREAM<W_TYPE>& s_feature_PE29_1,
    STREAM<W_TYPE>& s_feature_PE29_2, STREAM<W_TYPE>& s_feature_PE29_3,
    STREAM<W_TYPE>& s_feature_PE30_0, STREAM<W_TYPE>& s_feature_PE30_1,
    STREAM<W_TYPE>& s_feature_PE30_2, STREAM<W_TYPE>& s_feature_PE30_3,
    STREAM<W_TYPE>& s_feature_PE31_0, STREAM<W_TYPE>& s_feature_PE31_1,
    STREAM<W_TYPE>& s_feature_PE31_2, STREAM<W_TYPE>& s_feature_PE31_3,
    STREAM<W_TYPE>& s_feature_PE32_0, STREAM<W_TYPE>& s_feature_PE32_1,
    STREAM<W_TYPE>& s_feature_PE32_2, STREAM<W_TYPE>& s_feature_PE32_3,
    STREAM<W_TYPE>& s_feature_PE33_0, STREAM<W_TYPE>& s_feature_PE33_1,
    STREAM<W_TYPE>& s_feature_PE33_2, STREAM<W_TYPE>& s_feature_PE33_3,
    STREAM<W_TYPE>& s_feature_PE34_0, STREAM<W_TYPE>& s_feature_PE34_1,
    STREAM<W_TYPE>& s_feature_PE34_2, STREAM<W_TYPE>& s_feature_PE34_3,
    STREAM<W_TYPE>& s_feature_PE35_0, STREAM<W_TYPE>& s_feature_PE35_1,
    STREAM<W_TYPE>& s_feature_PE35_2, STREAM<W_TYPE>& s_feature_PE35_3,
    STREAM<W_TYPE>& s_feature_PE36_0, STREAM<W_TYPE>& s_feature_PE36_1,
    STREAM<W_TYPE>& s_feature_PE36_2, STREAM<W_TYPE>& s_feature_PE36_3,
    STREAM<W_TYPE>& s_feature_PE37_0, STREAM<W_TYPE>& s_feature_PE37_1,
    STREAM<W_TYPE>& s_feature_PE37_2, STREAM<W_TYPE>& s_feature_PE37_3,
    STREAM<W_TYPE>& s_feature_PE38_0, STREAM<W_TYPE>& s_feature_PE38_1,
    STREAM<W_TYPE>& s_feature_PE38_2, STREAM<W_TYPE>& s_feature_PE38_3,
    STREAM<W_TYPE>& s_feature_PE39_0, STREAM<W_TYPE>& s_feature_PE39_1,
    STREAM<W_TYPE>& s_feature_PE39_2, STREAM<W_TYPE>& s_feature_PE39_3,
    STREAM<W_TYPE>& s_feature_PE40_0, STREAM<W_TYPE>& s_feature_PE40_1,
    STREAM<W_TYPE>& s_feature_PE40_2, STREAM<W_TYPE>& s_feature_PE40_3,
    STREAM<W_TYPE>& s_feature_PE41_0, STREAM<W_TYPE>& s_feature_PE41_1,
    STREAM<W_TYPE>& s_feature_PE41_2, STREAM<W_TYPE>& s_feature_PE41_3,
    STREAM<W_TYPE>& s_feature_PE42_0, STREAM<W_TYPE>& s_feature_PE42_1,
    STREAM<W_TYPE>& s_feature_PE42_2, STREAM<W_TYPE>& s_feature_PE42_3,
    STREAM<W_TYPE>& s_feature_PE43_0, STREAM<W_TYPE>& s_feature_PE43_1,
    STREAM<W_TYPE>& s_feature_PE43_2, STREAM<W_TYPE>& s_feature_PE43_3,
    STREAM<W_TYPE>& s_feature_PE44_0, STREAM<W_TYPE>& s_feature_PE44_1,
    STREAM<W_TYPE>& s_feature_PE44_2, STREAM<W_TYPE>& s_feature_PE44_3,
    STREAM<W_TYPE>& s_feature_PE45_0, STREAM<W_TYPE>& s_feature_PE45_1,
    STREAM<W_TYPE>& s_feature_PE45_2, STREAM<W_TYPE>& s_feature_PE45_3,
    STREAM<W_TYPE>& s_feature_PE46_0, STREAM<W_TYPE>& s_feature_PE46_1,
    STREAM<W_TYPE>& s_feature_PE46_2, STREAM<W_TYPE>& s_feature_PE46_3,
    STREAM<W_TYPE>& s_feature_PE47_0, STREAM<W_TYPE>& s_feature_PE47_1,
    STREAM<W_TYPE>& s_feature_PE47_2, STREAM<W_TYPE>& s_feature_PE47_3,
    STREAM<W_TYPE>& s_feature_PE48_0, STREAM<W_TYPE>& s_feature_PE48_1,
    STREAM<W_TYPE>& s_feature_PE48_2, STREAM<W_TYPE>& s_feature_PE48_3,
    STREAM<W_TYPE>& s_feature_PE49_0, STREAM<W_TYPE>& s_feature_PE49_1,
    STREAM<W_TYPE>& s_feature_PE49_2, STREAM<W_TYPE>& s_feature_PE49_3,
    STREAM<W_TYPE>& s_feature_PE50_0, STREAM<W_TYPE>& s_feature_PE50_1,
    STREAM<W_TYPE>& s_feature_PE50_2, STREAM<W_TYPE>& s_feature_PE50_3,
    STREAM<W_TYPE>& s_feature_PE51_0, STREAM<W_TYPE>& s_feature_PE51_1,
    STREAM<W_TYPE>& s_feature_PE51_2, STREAM<W_TYPE>& s_feature_PE51_3,
    STREAM<W_TYPE>& s_feature_PE52_0, STREAM<W_TYPE>& s_feature_PE52_1,
    STREAM<W_TYPE>& s_feature_PE52_2, STREAM<W_TYPE>& s_feature_PE52_3,
    STREAM<W_TYPE>& s_feature_PE53_0, STREAM<W_TYPE>& s_feature_PE53_1,
    STREAM<W_TYPE>& s_feature_PE53_2, STREAM<W_TYPE>& s_feature_PE53_3,
    STREAM<W_TYPE>& s_feature_PE54_0, STREAM<W_TYPE>& s_feature_PE54_1,
    STREAM<W_TYPE>& s_feature_PE54_2, STREAM<W_TYPE>& s_feature_PE54_3,
    STREAM<W_TYPE>& s_feature_PE55_0, STREAM<W_TYPE>& s_feature_PE55_1,
    STREAM<W_TYPE>& s_feature_PE55_2, STREAM<W_TYPE>& s_feature_PE55_3,
    STREAM<W_TYPE>& s_feature_PE56_0, STREAM<W_TYPE>& s_feature_PE56_1,
    STREAM<W_TYPE>& s_feature_PE56_2, STREAM<W_TYPE>& s_feature_PE56_3,
    STREAM<W_TYPE>& s_feature_PE57_0, STREAM<W_TYPE>& s_feature_PE57_1,
    STREAM<W_TYPE>& s_feature_PE57_2, STREAM<W_TYPE>& s_feature_PE57_3,
    STREAM<W_TYPE>& s_feature_PE58_0, STREAM<W_TYPE>& s_feature_PE58_1,
    STREAM<W_TYPE>& s_feature_PE58_2, STREAM<W_TYPE>& s_feature_PE58_3,
    STREAM<W_TYPE>& s_feature_PE59_0, STREAM<W_TYPE>& s_feature_PE59_1,
    STREAM<W_TYPE>& s_feature_PE59_2, STREAM<W_TYPE>& s_feature_PE59_3,
    STREAM<W_TYPE>& s_feature_PE60_0, STREAM<W_TYPE>& s_feature_PE60_1,
    STREAM<W_TYPE>& s_feature_PE60_2, STREAM<W_TYPE>& s_feature_PE60_3,
    STREAM<W_TYPE>& s_feature_PE61_0, STREAM<W_TYPE>& s_feature_PE61_1,
    STREAM<W_TYPE>& s_feature_PE61_2, STREAM<W_TYPE>& s_feature_PE61_3,
    STREAM<W_TYPE>& s_feature_PE62_0, STREAM<W_TYPE>& s_feature_PE62_1,
    STREAM<W_TYPE>& s_feature_PE62_2, STREAM<W_TYPE>& s_feature_PE62_3,
    STREAM<W_TYPE>& s_feature_PE63_0, STREAM<W_TYPE>& s_feature_PE63_1,
    STREAM<W_TYPE>& s_feature_PE63_2, STREAM<W_TYPE>& s_feature_PE63_3,
    STREAM<W_TYPE>& s_feature_PE64_0, STREAM<W_TYPE>& s_feature_PE64_1,
    STREAM<W_TYPE>& s_feature_PE64_2, STREAM<W_TYPE>& s_feature_PE64_3,
    STREAM<W_TYPE>& s_feature_PE65_0, STREAM<W_TYPE>& s_feature_PE65_1,
    STREAM<W_TYPE>& s_feature_PE65_2, STREAM<W_TYPE>& s_feature_PE65_3,
    STREAM<W_TYPE>& s_feature_PE66_0, STREAM<W_TYPE>& s_feature_PE66_1,
    STREAM<W_TYPE>& s_feature_PE66_2, STREAM<W_TYPE>& s_feature_PE66_3,
    STREAM<W_TYPE>& s_feature_PE67_0, STREAM<W_TYPE>& s_feature_PE67_1,
    STREAM<W_TYPE>& s_feature_PE67_2, STREAM<W_TYPE>& s_feature_PE67_3,
    STREAM<W_TYPE>& s_feature_PE68_0, STREAM<W_TYPE>& s_feature_PE68_1,
    STREAM<W_TYPE>& s_feature_PE68_2, STREAM<W_TYPE>& s_feature_PE68_3,
    STREAM<W_TYPE>& s_feature_PE69_0, STREAM<W_TYPE>& s_feature_PE69_1,
    STREAM<W_TYPE>& s_feature_PE69_2, STREAM<W_TYPE>& s_feature_PE69_3,
    STREAM<W_TYPE>& s_feature_PE70_0, STREAM<W_TYPE>& s_feature_PE70_1,
    STREAM<W_TYPE>& s_feature_PE70_2, STREAM<W_TYPE>& s_feature_PE70_3,
    STREAM<W_TYPE>& s_feature_PE71_0, STREAM<W_TYPE>& s_feature_PE71_1,
    STREAM<W_TYPE>& s_feature_PE71_2, STREAM<W_TYPE>& s_feature_PE71_3,
    STREAM<W_TYPE>& s_feature_PE72_0, STREAM<W_TYPE>& s_feature_PE72_1,
    STREAM<W_TYPE>& s_feature_PE72_2, STREAM<W_TYPE>& s_feature_PE72_3,
    STREAM<W_TYPE>& s_feature_PE73_0, STREAM<W_TYPE>& s_feature_PE73_1,
    STREAM<W_TYPE>& s_feature_PE73_2, STREAM<W_TYPE>& s_feature_PE73_3,
    STREAM<W_TYPE>& s_feature_PE74_0, STREAM<W_TYPE>& s_feature_PE74_1,
    STREAM<W_TYPE>& s_feature_PE74_2, STREAM<W_TYPE>& s_feature_PE74_3,
    STREAM<W_TYPE>& s_feature_PE75_0, STREAM<W_TYPE>& s_feature_PE75_1,
    STREAM<W_TYPE>& s_feature_PE75_2, STREAM<W_TYPE>& s_feature_PE75_3,
    STREAM<W_TYPE>& s_feature_PE76_0, STREAM<W_TYPE>& s_feature_PE76_1,
    STREAM<W_TYPE>& s_feature_PE76_2, STREAM<W_TYPE>& s_feature_PE76_3,
    STREAM<W_TYPE>& s_feature_PE77_0, STREAM<W_TYPE>& s_feature_PE77_1,
    STREAM<W_TYPE>& s_feature_PE77_2, STREAM<W_TYPE>& s_feature_PE77_3,
    STREAM<W_TYPE>& s_feature_PE78_0, STREAM<W_TYPE>& s_feature_PE78_1,
    STREAM<W_TYPE>& s_feature_PE78_2, STREAM<W_TYPE>& s_feature_PE78_3,
    STREAM<W_TYPE>& s_feature_PE79_0, STREAM<W_TYPE>& s_feature_PE79_1,
    STREAM<W_TYPE>& s_feature_PE79_2, STREAM<W_TYPE>& s_feature_PE79_3,
    STREAM<W_TYPE>& s_feature_PE80_0, STREAM<W_TYPE>& s_feature_PE80_1,
    STREAM<W_TYPE>& s_feature_PE80_2, STREAM<W_TYPE>& s_feature_PE80_3,
    STREAM<W_TYPE>& s_feature_PE81_0, STREAM<W_TYPE>& s_feature_PE81_1,
    STREAM<W_TYPE>& s_feature_PE81_2, STREAM<W_TYPE>& s_feature_PE81_3,
    STREAM<W_TYPE>& s_feature_PE82_0, STREAM<W_TYPE>& s_feature_PE82_1,
    STREAM<W_TYPE>& s_feature_PE82_2, STREAM<W_TYPE>& s_feature_PE82_3,
    STREAM<W_TYPE>& s_feature_PE83_0, STREAM<W_TYPE>& s_feature_PE83_1,
    STREAM<W_TYPE>& s_feature_PE83_2, STREAM<W_TYPE>& s_feature_PE83_3,
    STREAM<W_TYPE>& s_feature_PE84_0, STREAM<W_TYPE>& s_feature_PE84_1,
    STREAM<W_TYPE>& s_feature_PE84_2, STREAM<W_TYPE>& s_feature_PE84_3,
    STREAM<W_TYPE>& s_feature_PE85_0, STREAM<W_TYPE>& s_feature_PE85_1,
    STREAM<W_TYPE>& s_feature_PE85_2, STREAM<W_TYPE>& s_feature_PE85_3,
    STREAM<W_TYPE>& s_feature_PE86_0, STREAM<W_TYPE>& s_feature_PE86_1,
    STREAM<W_TYPE>& s_feature_PE86_2, STREAM<W_TYPE>& s_feature_PE86_3,
    STREAM<W_TYPE>& s_feature_PE87_0, STREAM<W_TYPE>& s_feature_PE87_1,
    STREAM<W_TYPE>& s_feature_PE87_2, STREAM<W_TYPE>& s_feature_PE87_3,
    STREAM<W_TYPE>& s_feature_PE88_0, STREAM<W_TYPE>& s_feature_PE88_1,
    STREAM<W_TYPE>& s_feature_PE88_2, STREAM<W_TYPE>& s_feature_PE88_3,
    STREAM<W_TYPE>& s_feature_PE89_0, STREAM<W_TYPE>& s_feature_PE89_1,
    STREAM<W_TYPE>& s_feature_PE89_2, STREAM<W_TYPE>& s_feature_PE89_3,
    STREAM<W_TYPE>& s_feature_PE90_0, STREAM<W_TYPE>& s_feature_PE90_1,
    STREAM<W_TYPE>& s_feature_PE90_2, STREAM<W_TYPE>& s_feature_PE90_3,
    STREAM<W_TYPE>& s_feature_PE91_0, STREAM<W_TYPE>& s_feature_PE91_1,
    STREAM<W_TYPE>& s_feature_PE91_2, STREAM<W_TYPE>& s_feature_PE91_3,
    STREAM<W_TYPE>& s_feature_PE92_0, STREAM<W_TYPE>& s_feature_PE92_1,
    STREAM<W_TYPE>& s_feature_PE92_2, STREAM<W_TYPE>& s_feature_PE92_3,
    STREAM<W_TYPE>& s_feature_PE93_0, STREAM<W_TYPE>& s_feature_PE93_1,
    STREAM<W_TYPE>& s_feature_PE93_2, STREAM<W_TYPE>& s_feature_PE93_3,
    STREAM<W_TYPE>& s_feature_PE94_0, STREAM<W_TYPE>& s_feature_PE94_1,
    STREAM<W_TYPE>& s_feature_PE94_2, STREAM<W_TYPE>& s_feature_PE94_3,
    STREAM<W_TYPE>& s_feature_PE95_0, STREAM<W_TYPE>& s_feature_PE95_1,
    STREAM<W_TYPE>& s_feature_PE95_2, STREAM<W_TYPE>& s_feature_PE95_3,
    STREAM<W_TYPE>& s_feature_PE96_0, STREAM<W_TYPE>& s_feature_PE96_1,
    STREAM<W_TYPE>& s_feature_PE96_2, STREAM<W_TYPE>& s_feature_PE96_3,
    STREAM<W_TYPE>& s_feature_PE97_0, STREAM<W_TYPE>& s_feature_PE97_1,
    STREAM<W_TYPE>& s_feature_PE97_2, STREAM<W_TYPE>& s_feature_PE97_3,
    STREAM<W_TYPE>& s_feature_PE98_0, STREAM<W_TYPE>& s_feature_PE98_1,
    STREAM<W_TYPE>& s_feature_PE98_2, STREAM<W_TYPE>& s_feature_PE98_3,
    STREAM<W_TYPE>& s_feature_PE99_0, STREAM<W_TYPE>& s_feature_PE99_1,
    STREAM<W_TYPE>& s_feature_PE99_2, STREAM<W_TYPE>& s_feature_PE99_3,
    STREAM<W_TYPE>& s_feature_PE100_0, STREAM<W_TYPE>& s_feature_PE100_1,
    STREAM<W_TYPE>& s_feature_PE100_2, STREAM<W_TYPE>& s_feature_PE100_3,
    STREAM<W_TYPE>& s_feature_PE101_0, STREAM<W_TYPE>& s_feature_PE101_1,
    STREAM<W_TYPE>& s_feature_PE101_2, STREAM<W_TYPE>& s_feature_PE101_3,
    STREAM<W_TYPE>& s_feature_PE102_0, STREAM<W_TYPE>& s_feature_PE102_1,
    STREAM<W_TYPE>& s_feature_PE102_2, STREAM<W_TYPE>& s_feature_PE102_3,
    STREAM<W_TYPE>& s_feature_PE103_0, STREAM<W_TYPE>& s_feature_PE103_1,
    STREAM<W_TYPE>& s_feature_PE103_2, STREAM<W_TYPE>& s_feature_PE103_3,
    STREAM<W_TYPE>& s_feature_PE104_0, STREAM<W_TYPE>& s_feature_PE104_1,
    STREAM<W_TYPE>& s_feature_PE104_2, STREAM<W_TYPE>& s_feature_PE104_3,
    STREAM<W_TYPE>& s_feature_PE105_0, STREAM<W_TYPE>& s_feature_PE105_1,
    STREAM<W_TYPE>& s_feature_PE105_2, STREAM<W_TYPE>& s_feature_PE105_3,
    STREAM<W_TYPE>& s_feature_PE106_0, STREAM<W_TYPE>& s_feature_PE106_1,
    STREAM<W_TYPE>& s_feature_PE106_2, STREAM<W_TYPE>& s_feature_PE106_3,
    STREAM<W_TYPE>& s_feature_PE107_0, STREAM<W_TYPE>& s_feature_PE107_1,
    STREAM<W_TYPE>& s_feature_PE107_2, STREAM<W_TYPE>& s_feature_PE107_3,
    STREAM<W_TYPE>& s_feature_PE108_0, STREAM<W_TYPE>& s_feature_PE108_1,
    STREAM<W_TYPE>& s_feature_PE108_2, STREAM<W_TYPE>& s_feature_PE108_3,
    STREAM<W_TYPE>& s_feature_PE109_0, STREAM<W_TYPE>& s_feature_PE109_1,
    STREAM<W_TYPE>& s_feature_PE109_2, STREAM<W_TYPE>& s_feature_PE109_3,
    STREAM<W_TYPE>& s_feature_PE110_0, STREAM<W_TYPE>& s_feature_PE110_1,
    STREAM<W_TYPE>& s_feature_PE110_2, STREAM<W_TYPE>& s_feature_PE110_3,
    STREAM<W_TYPE>& s_feature_PE111_0, STREAM<W_TYPE>& s_feature_PE111_1,
    STREAM<W_TYPE>& s_feature_PE111_2, STREAM<W_TYPE>& s_feature_PE111_3,
    STREAM<W_TYPE>& s_feature_PE112_0, STREAM<W_TYPE>& s_feature_PE112_1,
    STREAM<W_TYPE>& s_feature_PE112_2, STREAM<W_TYPE>& s_feature_PE112_3,
    STREAM<W_TYPE>& s_feature_PE113_0, STREAM<W_TYPE>& s_feature_PE113_1,
    STREAM<W_TYPE>& s_feature_PE113_2, STREAM<W_TYPE>& s_feature_PE113_3,
    STREAM<W_TYPE>& s_feature_PE114_0, STREAM<W_TYPE>& s_feature_PE114_1,
    STREAM<W_TYPE>& s_feature_PE114_2, STREAM<W_TYPE>& s_feature_PE114_3,
    STREAM<W_TYPE>& s_feature_PE115_0, STREAM<W_TYPE>& s_feature_PE115_1,
    STREAM<W_TYPE>& s_feature_PE115_2, STREAM<W_TYPE>& s_feature_PE115_3,
    STREAM<W_TYPE>& s_feature_PE116_0, STREAM<W_TYPE>& s_feature_PE116_1,
    STREAM<W_TYPE>& s_feature_PE116_2, STREAM<W_TYPE>& s_feature_PE116_3,
    STREAM<W_TYPE>& s_feature_PE117_0, STREAM<W_TYPE>& s_feature_PE117_1,
    STREAM<W_TYPE>& s_feature_PE117_2, STREAM<W_TYPE>& s_feature_PE117_3,
    STREAM<W_TYPE>& s_feature_PE118_0, STREAM<W_TYPE>& s_feature_PE118_1,
    STREAM<W_TYPE>& s_feature_PE118_2, STREAM<W_TYPE>& s_feature_PE118_3,
    STREAM<W_TYPE>& s_feature_PE119_0, STREAM<W_TYPE>& s_feature_PE119_1,
    STREAM<W_TYPE>& s_feature_PE119_2, STREAM<W_TYPE>& s_feature_PE119_3,
    STREAM<W_TYPE>& s_feature_PE120_0, STREAM<W_TYPE>& s_feature_PE120_1,
    STREAM<W_TYPE>& s_feature_PE120_2, STREAM<W_TYPE>& s_feature_PE120_3,
    STREAM<W_TYPE>& s_feature_PE121_0, STREAM<W_TYPE>& s_feature_PE121_1,
    STREAM<W_TYPE>& s_feature_PE121_2, STREAM<W_TYPE>& s_feature_PE121_3,
    STREAM<W_TYPE>& s_feature_PE122_0, STREAM<W_TYPE>& s_feature_PE122_1,
    STREAM<W_TYPE>& s_feature_PE122_2, STREAM<W_TYPE>& s_feature_PE122_3,
    STREAM<W_TYPE>& s_feature_PE123_0, STREAM<W_TYPE>& s_feature_PE123_1,
    STREAM<W_TYPE>& s_feature_PE123_2, STREAM<W_TYPE>& s_feature_PE123_3,
    STREAM<W_TYPE>& s_feature_PE124_0, STREAM<W_TYPE>& s_feature_PE124_1,
    STREAM<W_TYPE>& s_feature_PE124_2, STREAM<W_TYPE>& s_feature_PE124_3,
    STREAM<W_TYPE>& s_feature_PE125_0, STREAM<W_TYPE>& s_feature_PE125_1,
    STREAM<W_TYPE>& s_feature_PE125_2, STREAM<W_TYPE>& s_feature_PE125_3,
    STREAM<W_TYPE>& s_feature_PE126_0, STREAM<W_TYPE>& s_feature_PE126_1,
    STREAM<W_TYPE>& s_feature_PE126_2, STREAM<W_TYPE>& s_feature_PE126_3,
    STREAM<W_TYPE>& s_feature_PE127_0, STREAM<W_TYPE>& s_feature_PE127_1,
    STREAM<W_TYPE>& s_feature_PE127_2, STREAM<W_TYPE>& s_feature_PE127_3,
    STREAM<W_TYPE>& s_feature_PE128_0, STREAM<W_TYPE>& s_feature_PE128_1,
    STREAM<W_TYPE>& s_feature_PE128_2, STREAM<W_TYPE>& s_feature_PE128_3,
    STREAM<W_TYPE>& s_feature_PE129_0, STREAM<W_TYPE>& s_feature_PE129_1,
    STREAM<W_TYPE>& s_feature_PE129_2, STREAM<W_TYPE>& s_feature_PE129_3,
    STREAM<W_TYPE>& s_feature_PE130_0, STREAM<W_TYPE>& s_feature_PE130_1,
    STREAM<W_TYPE>& s_feature_PE130_2, STREAM<W_TYPE>& s_feature_PE130_3,
    STREAM<W_TYPE>& s_feature_PE131_0, STREAM<W_TYPE>& s_feature_PE131_1,
    STREAM<W_TYPE>& s_feature_PE131_2, STREAM<W_TYPE>& s_feature_PE131_3,
    STREAM<W_TYPE>& s_feature_PE132_0, STREAM<W_TYPE>& s_feature_PE132_1,
    STREAM<W_TYPE>& s_feature_PE132_2, STREAM<W_TYPE>& s_feature_PE132_3,
    STREAM<W_TYPE>& s_feature_PE133_0, STREAM<W_TYPE>& s_feature_PE133_1,
    STREAM<W_TYPE>& s_feature_PE133_2, STREAM<W_TYPE>& s_feature_PE133_3,
    STREAM<W_TYPE>& s_feature_PE134_0, STREAM<W_TYPE>& s_feature_PE134_1,
    STREAM<W_TYPE>& s_feature_PE134_2, STREAM<W_TYPE>& s_feature_PE134_3,
    STREAM<W_TYPE>& s_feature_PE135_0, STREAM<W_TYPE>& s_feature_PE135_1,
    STREAM<W_TYPE>& s_feature_PE135_2, STREAM<W_TYPE>& s_feature_PE135_3,
    STREAM<W_TYPE>& s_feature_PE136_0, STREAM<W_TYPE>& s_feature_PE136_1,
    STREAM<W_TYPE>& s_feature_PE136_2, STREAM<W_TYPE>& s_feature_PE136_3,
    STREAM<W_TYPE>& s_feature_PE137_0, STREAM<W_TYPE>& s_feature_PE137_1,
    STREAM<W_TYPE>& s_feature_PE137_2, STREAM<W_TYPE>& s_feature_PE137_3,
    STREAM<W_TYPE>& s_feature_PE138_0, STREAM<W_TYPE>& s_feature_PE138_1,
    STREAM<W_TYPE>& s_feature_PE138_2, STREAM<W_TYPE>& s_feature_PE138_3,
    STREAM<W_TYPE>& s_feature_PE139_0, STREAM<W_TYPE>& s_feature_PE139_1,
    STREAM<W_TYPE>& s_feature_PE139_2, STREAM<W_TYPE>& s_feature_PE139_3,
    STREAM<W_TYPE>& s_feature_PE140_0, STREAM<W_TYPE>& s_feature_PE140_1,
    STREAM<W_TYPE>& s_feature_PE140_2, STREAM<W_TYPE>& s_feature_PE140_3,
    STREAM<W_TYPE>& s_feature_PE141_0, STREAM<W_TYPE>& s_feature_PE141_1,
    STREAM<W_TYPE>& s_feature_PE141_2, STREAM<W_TYPE>& s_feature_PE141_3,
    STREAM<W_TYPE>& s_feature_PE142_0, STREAM<W_TYPE>& s_feature_PE142_1,
    STREAM<W_TYPE>& s_feature_PE142_2, STREAM<W_TYPE>& s_feature_PE142_3,
    STREAM<W_TYPE>& s_feature_PE143_0, STREAM<W_TYPE>& s_feature_PE143_1,
    STREAM<W_TYPE>& s_feature_PE143_2, STREAM<W_TYPE>& s_feature_PE143_3,
    STREAM<W_TYPE>& s_feature_PE144_0, STREAM<W_TYPE>& s_feature_PE144_1,
    STREAM<W_TYPE>& s_feature_PE144_2, STREAM<W_TYPE>& s_feature_PE144_3,
    STREAM<W_TYPE>& s_feature_PE145_0, STREAM<W_TYPE>& s_feature_PE145_1,
    STREAM<W_TYPE>& s_feature_PE145_2, STREAM<W_TYPE>& s_feature_PE145_3,
    STREAM<W_TYPE>& s_feature_PE146_0, STREAM<W_TYPE>& s_feature_PE146_1,
    STREAM<W_TYPE>& s_feature_PE146_2, STREAM<W_TYPE>& s_feature_PE146_3,
    STREAM<W_TYPE>& s_feature_PE147_0, STREAM<W_TYPE>& s_feature_PE147_1,
    STREAM<W_TYPE>& s_feature_PE147_2, STREAM<W_TYPE>& s_feature_PE147_3,
    STREAM<W_TYPE>& s_feature_PE148_0, STREAM<W_TYPE>& s_feature_PE148_1,
    STREAM<W_TYPE>& s_feature_PE148_2, STREAM<W_TYPE>& s_feature_PE148_3,
    STREAM<W_TYPE>& s_feature_PE149_0, STREAM<W_TYPE>& s_feature_PE149_1,
    STREAM<W_TYPE>& s_feature_PE149_2, STREAM<W_TYPE>& s_feature_PE149_3,
    STREAM<W_TYPE>& s_feature_PE150_0, STREAM<W_TYPE>& s_feature_PE150_1,
    STREAM<W_TYPE>& s_feature_PE150_2, STREAM<W_TYPE>& s_feature_PE150_3,
    STREAM<W_TYPE>& s_feature_PE151_0, STREAM<W_TYPE>& s_feature_PE151_1,
    STREAM<W_TYPE>& s_feature_PE151_2, STREAM<W_TYPE>& s_feature_PE151_3,
    STREAM<W_TYPE>& s_feature_PE152_0, STREAM<W_TYPE>& s_feature_PE152_1,
    STREAM<W_TYPE>& s_feature_PE152_2, STREAM<W_TYPE>& s_feature_PE152_3,
    STREAM<W_TYPE>& s_feature_PE153_0, STREAM<W_TYPE>& s_feature_PE153_1,
    STREAM<W_TYPE>& s_feature_PE153_2, STREAM<W_TYPE>& s_feature_PE153_3,
    STREAM<W_TYPE>& s_feature_PE154_0, STREAM<W_TYPE>& s_feature_PE154_1,
    STREAM<W_TYPE>& s_feature_PE154_2, STREAM<W_TYPE>& s_feature_PE154_3,
    STREAM<W_TYPE>& s_feature_PE155_0, STREAM<W_TYPE>& s_feature_PE155_1,
    STREAM<W_TYPE>& s_feature_PE155_2, STREAM<W_TYPE>& s_feature_PE155_3,
    STREAM<W_TYPE>& s_feature_PE156_0, STREAM<W_TYPE>& s_feature_PE156_1,
    STREAM<W_TYPE>& s_feature_PE156_2, STREAM<W_TYPE>& s_feature_PE156_3,
    STREAM<W_TYPE>& s_feature_PE157_0, STREAM<W_TYPE>& s_feature_PE157_1,
    STREAM<W_TYPE>& s_feature_PE157_2, STREAM<W_TYPE>& s_feature_PE157_3,
    STREAM<W_TYPE>& s_feature_PE158_0, STREAM<W_TYPE>& s_feature_PE158_1,
    STREAM<W_TYPE>& s_feature_PE158_2, STREAM<W_TYPE>& s_feature_PE158_3,
    STREAM<W_TYPE>& s_feature_PE159_0, STREAM<W_TYPE>& s_feature_PE159_1,
    STREAM<W_TYPE>& s_feature_PE159_2, STREAM<W_TYPE>& s_feature_PE159_3,
    STREAM<W_TYPE>& s_feature_PE160_0, STREAM<W_TYPE>& s_feature_PE160_1,
    STREAM<W_TYPE>& s_feature_PE160_2, STREAM<W_TYPE>& s_feature_PE160_3,
    STREAM<W_TYPE>& s_feature_PE161_0, STREAM<W_TYPE>& s_feature_PE161_1,
    STREAM<W_TYPE>& s_feature_PE161_2, STREAM<W_TYPE>& s_feature_PE161_3,
    STREAM<W_TYPE>& s_feature_PE162_0, STREAM<W_TYPE>& s_feature_PE162_1,
    STREAM<W_TYPE>& s_feature_PE162_2, STREAM<W_TYPE>& s_feature_PE162_3,
    STREAM<W_TYPE>& s_feature_PE163_0, STREAM<W_TYPE>& s_feature_PE163_1,
    STREAM<W_TYPE>& s_feature_PE163_2, STREAM<W_TYPE>& s_feature_PE163_3,
    STREAM<W_TYPE>& s_feature_PE164_0, STREAM<W_TYPE>& s_feature_PE164_1,
    STREAM<W_TYPE>& s_feature_PE164_2, STREAM<W_TYPE>& s_feature_PE164_3,
    STREAM<W_TYPE>& s_feature_PE165_0, STREAM<W_TYPE>& s_feature_PE165_1,
    STREAM<W_TYPE>& s_feature_PE165_2, STREAM<W_TYPE>& s_feature_PE165_3,
    STREAM<W_TYPE>& s_feature_PE166_0, STREAM<W_TYPE>& s_feature_PE166_1,
    STREAM<W_TYPE>& s_feature_PE166_2, STREAM<W_TYPE>& s_feature_PE166_3,
    STREAM<W_TYPE>& s_feature_PE167_0, STREAM<W_TYPE>& s_feature_PE167_1,
    STREAM<W_TYPE>& s_feature_PE167_2, STREAM<W_TYPE>& s_feature_PE167_3,
    STREAM<W_TYPE>& s_feature_PE168_0, STREAM<W_TYPE>& s_feature_PE168_1,
    STREAM<W_TYPE>& s_feature_PE168_2, STREAM<W_TYPE>& s_feature_PE168_3,
    STREAM<W_TYPE>& s_feature_PE169_0, STREAM<W_TYPE>& s_feature_PE169_1,
    STREAM<W_TYPE>& s_feature_PE169_2, STREAM<W_TYPE>& s_feature_PE169_3,
    STREAM<W_TYPE>& s_feature_PE170_0, STREAM<W_TYPE>& s_feature_PE170_1,
    STREAM<W_TYPE>& s_feature_PE170_2, STREAM<W_TYPE>& s_feature_PE170_3,
    STREAM<W_TYPE>& s_feature_PE171_0, STREAM<W_TYPE>& s_feature_PE171_1,
    STREAM<W_TYPE>& s_feature_PE171_2, STREAM<W_TYPE>& s_feature_PE171_3,
    STREAM<W_TYPE>& s_feature_PE172_0, STREAM<W_TYPE>& s_feature_PE172_1,
    STREAM<W_TYPE>& s_feature_PE172_2, STREAM<W_TYPE>& s_feature_PE172_3,
    STREAM<W_TYPE>& s_feature_PE173_0, STREAM<W_TYPE>& s_feature_PE173_1,
    STREAM<W_TYPE>& s_feature_PE173_2, STREAM<W_TYPE>& s_feature_PE173_3,
    STREAM<W_TYPE>& s_feature_PE174_0, STREAM<W_TYPE>& s_feature_PE174_1,
    STREAM<W_TYPE>& s_feature_PE174_2, STREAM<W_TYPE>& s_feature_PE174_3,
    STREAM<W_TYPE>& s_feature_PE175_0, STREAM<W_TYPE>& s_feature_PE175_1,
    STREAM<W_TYPE>& s_feature_PE175_2, STREAM<W_TYPE>& s_feature_PE175_3,
    STREAM<W_TYPE>& s_feature_PE176_0, STREAM<W_TYPE>& s_feature_PE176_1,
    STREAM<W_TYPE>& s_feature_PE176_2, STREAM<W_TYPE>& s_feature_PE176_3,
    STREAM<W_TYPE>& s_feature_PE177_0, STREAM<W_TYPE>& s_feature_PE177_1,
    STREAM<W_TYPE>& s_feature_PE177_2, STREAM<W_TYPE>& s_feature_PE177_3,
    STREAM<W_TYPE>& s_feature_PE178_0, STREAM<W_TYPE>& s_feature_PE178_1,
    STREAM<W_TYPE>& s_feature_PE178_2, STREAM<W_TYPE>& s_feature_PE178_3,
    STREAM<W_TYPE>& s_feature_PE179_0, STREAM<W_TYPE>& s_feature_PE179_1,
    STREAM<W_TYPE>& s_feature_PE179_2, STREAM<W_TYPE>& s_feature_PE179_3,
    STREAM<W_TYPE>& s_feature_PE180_0, STREAM<W_TYPE>& s_feature_PE180_1,
    STREAM<W_TYPE>& s_feature_PE180_2, STREAM<W_TYPE>& s_feature_PE180_3,
    STREAM<W_TYPE>& s_feature_PE181_0, STREAM<W_TYPE>& s_feature_PE181_1,
    STREAM<W_TYPE>& s_feature_PE181_2, STREAM<W_TYPE>& s_feature_PE181_3,
    STREAM<W_TYPE>& s_feature_PE182_0, STREAM<W_TYPE>& s_feature_PE182_1,
    STREAM<W_TYPE>& s_feature_PE182_2, STREAM<W_TYPE>& s_feature_PE182_3,
    STREAM<W_TYPE>& s_feature_PE183_0, STREAM<W_TYPE>& s_feature_PE183_1,
    STREAM<W_TYPE>& s_feature_PE183_2, STREAM<W_TYPE>& s_feature_PE183_3,
    STREAM<W_TYPE>& s_feature_PE184_0, STREAM<W_TYPE>& s_feature_PE184_1,
    STREAM<W_TYPE>& s_feature_PE184_2, STREAM<W_TYPE>& s_feature_PE184_3,
    STREAM<W_TYPE>& s_feature_PE185_0, STREAM<W_TYPE>& s_feature_PE185_1,
    STREAM<W_TYPE>& s_feature_PE185_2, STREAM<W_TYPE>& s_feature_PE185_3,
    STREAM<W_TYPE>& s_feature_PE186_0, STREAM<W_TYPE>& s_feature_PE186_1,
    STREAM<W_TYPE>& s_feature_PE186_2, STREAM<W_TYPE>& s_feature_PE186_3,
    STREAM<W_TYPE>& s_feature_PE187_0, STREAM<W_TYPE>& s_feature_PE187_1,
    STREAM<W_TYPE>& s_feature_PE187_2, STREAM<W_TYPE>& s_feature_PE187_3,
    STREAM<W_TYPE>& s_feature_PE188_0, STREAM<W_TYPE>& s_feature_PE188_1,
    STREAM<W_TYPE>& s_feature_PE188_2, STREAM<W_TYPE>& s_feature_PE188_3,
    STREAM<W_TYPE>& s_feature_PE189_0, STREAM<W_TYPE>& s_feature_PE189_1,
    STREAM<W_TYPE>& s_feature_PE189_2, STREAM<W_TYPE>& s_feature_PE189_3,
    STREAM<W_TYPE>& s_feature_PE190_0, STREAM<W_TYPE>& s_feature_PE190_1,
    STREAM<W_TYPE>& s_feature_PE190_2, STREAM<W_TYPE>& s_feature_PE190_3,
    STREAM<W_TYPE>& s_feature_PE191_0, STREAM<W_TYPE>& s_feature_PE191_1,
    STREAM<W_TYPE>& s_feature_PE191_2, STREAM<W_TYPE>& s_feature_PE191_3,
    STREAM<W_TYPE>& s_feature_PE192_0, STREAM<W_TYPE>& s_feature_PE192_1,
    STREAM<W_TYPE>& s_feature_PE192_2, STREAM<W_TYPE>& s_feature_PE192_3,
    STREAM<W_TYPE>& s_feature_PE193_0, STREAM<W_TYPE>& s_feature_PE193_1,
    STREAM<W_TYPE>& s_feature_PE193_2, STREAM<W_TYPE>& s_feature_PE193_3,
    STREAM<W_TYPE>& s_feature_PE194_0, STREAM<W_TYPE>& s_feature_PE194_1,
    STREAM<W_TYPE>& s_feature_PE194_2, STREAM<W_TYPE>& s_feature_PE194_3,
    STREAM<W_TYPE>& s_feature_PE195_0, STREAM<W_TYPE>& s_feature_PE195_1,
    STREAM<W_TYPE>& s_feature_PE195_2, STREAM<W_TYPE>& s_feature_PE195_3,
    STREAM<W_TYPE>& s_feature_PE196_0, STREAM<W_TYPE>& s_feature_PE196_1,
    STREAM<W_TYPE>& s_feature_PE196_2, STREAM<W_TYPE>& s_feature_PE196_3,
    STREAM<W_TYPE>& s_feature_PE197_0, STREAM<W_TYPE>& s_feature_PE197_1,
    STREAM<W_TYPE>& s_feature_PE197_2, STREAM<W_TYPE>& s_feature_PE197_3,
    STREAM<W_TYPE>& s_feature_PE198_0, STREAM<W_TYPE>& s_feature_PE198_1,
    STREAM<W_TYPE>& s_feature_PE198_2, STREAM<W_TYPE>& s_feature_PE198_3,
    STREAM<W_TYPE>& s_feature_PE199_0, STREAM<W_TYPE>& s_feature_PE199_1,
    STREAM<W_TYPE>& s_feature_PE199_2, STREAM<W_TYPE>& s_feature_PE199_3,
    STREAM<W_TYPE>& s_feature_PE200_0, STREAM<W_TYPE>& s_feature_PE200_1,
    STREAM<W_TYPE>& s_feature_PE200_2, STREAM<W_TYPE>& s_feature_PE200_3,
    STREAM<W_TYPE>& s_feature_PE201_0, STREAM<W_TYPE>& s_feature_PE201_1,
    STREAM<W_TYPE>& s_feature_PE201_2, STREAM<W_TYPE>& s_feature_PE201_3,
    STREAM<W_TYPE>& s_feature_PE202_0, STREAM<W_TYPE>& s_feature_PE202_1,
    STREAM<W_TYPE>& s_feature_PE202_2, STREAM<W_TYPE>& s_feature_PE202_3,
    STREAM<W_TYPE>& s_feature_PE203_0, STREAM<W_TYPE>& s_feature_PE203_1,
    STREAM<W_TYPE>& s_feature_PE203_2, STREAM<W_TYPE>& s_feature_PE203_3,
    STREAM<W_TYPE>& s_feature_PE204_0, STREAM<W_TYPE>& s_feature_PE204_1,
    STREAM<W_TYPE>& s_feature_PE204_2, STREAM<W_TYPE>& s_feature_PE204_3,
    STREAM<W_TYPE>& s_feature_PE205_0, STREAM<W_TYPE>& s_feature_PE205_1,
    STREAM<W_TYPE>& s_feature_PE205_2, STREAM<W_TYPE>& s_feature_PE205_3,
    STREAM<W_TYPE>& s_feature_PE206_0, STREAM<W_TYPE>& s_feature_PE206_1,
    STREAM<W_TYPE>& s_feature_PE206_2, STREAM<W_TYPE>& s_feature_PE206_3,
    STREAM<W_TYPE>& s_feature_PE207_0, STREAM<W_TYPE>& s_feature_PE207_1,
    STREAM<W_TYPE>& s_feature_PE207_2, STREAM<W_TYPE>& s_feature_PE207_3,
    STREAM<W_TYPE>& s_feature_PE208_0, STREAM<W_TYPE>& s_feature_PE208_1,
    STREAM<W_TYPE>& s_feature_PE208_2, STREAM<W_TYPE>& s_feature_PE208_3,
    STREAM<W_TYPE>& s_feature_PE209_0, STREAM<W_TYPE>& s_feature_PE209_1,
    STREAM<W_TYPE>& s_feature_PE209_2, STREAM<W_TYPE>& s_feature_PE209_3,
    STREAM<W_TYPE>& s_feature_PE210_0, STREAM<W_TYPE>& s_feature_PE210_1,
    STREAM<W_TYPE>& s_feature_PE210_2, STREAM<W_TYPE>& s_feature_PE210_3,
    STREAM<W_TYPE>& s_feature_PE211_0, STREAM<W_TYPE>& s_feature_PE211_1,
    STREAM<W_TYPE>& s_feature_PE211_2, STREAM<W_TYPE>& s_feature_PE211_3,
    STREAM<W_TYPE>& s_feature_PE212_0, STREAM<W_TYPE>& s_feature_PE212_1,
    STREAM<W_TYPE>& s_feature_PE212_2, STREAM<W_TYPE>& s_feature_PE212_3,
    STREAM<W_TYPE>& s_feature_PE213_0, STREAM<W_TYPE>& s_feature_PE213_1,
    STREAM<W_TYPE>& s_feature_PE213_2, STREAM<W_TYPE>& s_feature_PE213_3,
    STREAM<W_TYPE>& s_feature_PE214_0, STREAM<W_TYPE>& s_feature_PE214_1,
    STREAM<W_TYPE>& s_feature_PE214_2, STREAM<W_TYPE>& s_feature_PE214_3,
    STREAM<W_TYPE>& s_feature_PE215_0, STREAM<W_TYPE>& s_feature_PE215_1,
    STREAM<W_TYPE>& s_feature_PE215_2, STREAM<W_TYPE>& s_feature_PE215_3
);

template<const int FEATURE_SIZE>
void replicate_feature_512PEs_108PE(
    STREAM<ap_uint<512> >& s_feature_in, 
    STREAM<W_TYPE>& s_feature_PE0_0, STREAM<W_TYPE>& s_feature_PE0_1,
    STREAM<W_TYPE>& s_feature_PE0_2, STREAM<W_TYPE>& s_feature_PE0_3,
    STREAM<W_TYPE>& s_feature_PE1_0, STREAM<W_TYPE>& s_feature_PE1_1,
    STREAM<W_TYPE>& s_feature_PE1_2, STREAM<W_TYPE>& s_feature_PE1_3,
    STREAM<W_TYPE>& s_feature_PE2_0, STREAM<W_TYPE>& s_feature_PE2_1,
    STREAM<W_TYPE>& s_feature_PE2_2, STREAM<W_TYPE>& s_feature_PE2_3,
    STREAM<W_TYPE>& s_feature_PE3_0, STREAM<W_TYPE>& s_feature_PE3_1,
    STREAM<W_TYPE>& s_feature_PE3_2, STREAM<W_TYPE>& s_feature_PE3_3,
    STREAM<W_TYPE>& s_feature_PE4_0, STREAM<W_TYPE>& s_feature_PE4_1,
    STREAM<W_TYPE>& s_feature_PE4_2, STREAM<W_TYPE>& s_feature_PE4_3,
    STREAM<W_TYPE>& s_feature_PE5_0, STREAM<W_TYPE>& s_feature_PE5_1,
    STREAM<W_TYPE>& s_feature_PE5_2, STREAM<W_TYPE>& s_feature_PE5_3,
    STREAM<W_TYPE>& s_feature_PE6_0, STREAM<W_TYPE>& s_feature_PE6_1,
    STREAM<W_TYPE>& s_feature_PE6_2, STREAM<W_TYPE>& s_feature_PE6_3,
    STREAM<W_TYPE>& s_feature_PE7_0, STREAM<W_TYPE>& s_feature_PE7_1,
    STREAM<W_TYPE>& s_feature_PE7_2, STREAM<W_TYPE>& s_feature_PE7_3,
    STREAM<W_TYPE>& s_feature_PE8_0, STREAM<W_TYPE>& s_feature_PE8_1,
    STREAM<W_TYPE>& s_feature_PE8_2, STREAM<W_TYPE>& s_feature_PE8_3,
    STREAM<W_TYPE>& s_feature_PE9_0, STREAM<W_TYPE>& s_feature_PE9_1,
    STREAM<W_TYPE>& s_feature_PE9_2, STREAM<W_TYPE>& s_feature_PE9_3,
    STREAM<W_TYPE>& s_feature_PE10_0, STREAM<W_TYPE>& s_feature_PE10_1,
    STREAM<W_TYPE>& s_feature_PE10_2, STREAM<W_TYPE>& s_feature_PE10_3,
    STREAM<W_TYPE>& s_feature_PE11_0, STREAM<W_TYPE>& s_feature_PE11_1,
    STREAM<W_TYPE>& s_feature_PE11_2, STREAM<W_TYPE>& s_feature_PE11_3,
    STREAM<W_TYPE>& s_feature_PE12_0, STREAM<W_TYPE>& s_feature_PE12_1,
    STREAM<W_TYPE>& s_feature_PE12_2, STREAM<W_TYPE>& s_feature_PE12_3,
    STREAM<W_TYPE>& s_feature_PE13_0, STREAM<W_TYPE>& s_feature_PE13_1,
    STREAM<W_TYPE>& s_feature_PE13_2, STREAM<W_TYPE>& s_feature_PE13_3,
    STREAM<W_TYPE>& s_feature_PE14_0, STREAM<W_TYPE>& s_feature_PE14_1,
    STREAM<W_TYPE>& s_feature_PE14_2, STREAM<W_TYPE>& s_feature_PE14_3,
    STREAM<W_TYPE>& s_feature_PE15_0, STREAM<W_TYPE>& s_feature_PE15_1,
    STREAM<W_TYPE>& s_feature_PE15_2, STREAM<W_TYPE>& s_feature_PE15_3,
    STREAM<W_TYPE>& s_feature_PE16_0, STREAM<W_TYPE>& s_feature_PE16_1,
    STREAM<W_TYPE>& s_feature_PE16_2, STREAM<W_TYPE>& s_feature_PE16_3,
    STREAM<W_TYPE>& s_feature_PE17_0, STREAM<W_TYPE>& s_feature_PE17_1,
    STREAM<W_TYPE>& s_feature_PE17_2, STREAM<W_TYPE>& s_feature_PE17_3,
    STREAM<W_TYPE>& s_feature_PE18_0, STREAM<W_TYPE>& s_feature_PE18_1,
    STREAM<W_TYPE>& s_feature_PE18_2, STREAM<W_TYPE>& s_feature_PE18_3,
    STREAM<W_TYPE>& s_feature_PE19_0, STREAM<W_TYPE>& s_feature_PE19_1,
    STREAM<W_TYPE>& s_feature_PE19_2, STREAM<W_TYPE>& s_feature_PE19_3,
    STREAM<W_TYPE>& s_feature_PE20_0, STREAM<W_TYPE>& s_feature_PE20_1,
    STREAM<W_TYPE>& s_feature_PE20_2, STREAM<W_TYPE>& s_feature_PE20_3,
    STREAM<W_TYPE>& s_feature_PE21_0, STREAM<W_TYPE>& s_feature_PE21_1,
    STREAM<W_TYPE>& s_feature_PE21_2, STREAM<W_TYPE>& s_feature_PE21_3,
    STREAM<W_TYPE>& s_feature_PE22_0, STREAM<W_TYPE>& s_feature_PE22_1,
    STREAM<W_TYPE>& s_feature_PE22_2, STREAM<W_TYPE>& s_feature_PE22_3,
    STREAM<W_TYPE>& s_feature_PE23_0, STREAM<W_TYPE>& s_feature_PE23_1,
    STREAM<W_TYPE>& s_feature_PE23_2, STREAM<W_TYPE>& s_feature_PE23_3,
    STREAM<W_TYPE>& s_feature_PE24_0, STREAM<W_TYPE>& s_feature_PE24_1,
    STREAM<W_TYPE>& s_feature_PE24_2, STREAM<W_TYPE>& s_feature_PE24_3,
    STREAM<W_TYPE>& s_feature_PE25_0, STREAM<W_TYPE>& s_feature_PE25_1,
    STREAM<W_TYPE>& s_feature_PE25_2, STREAM<W_TYPE>& s_feature_PE25_3,
    STREAM<W_TYPE>& s_feature_PE26_0, STREAM<W_TYPE>& s_feature_PE26_1,
    STREAM<W_TYPE>& s_feature_PE26_2, STREAM<W_TYPE>& s_feature_PE26_3,
    STREAM<W_TYPE>& s_feature_PE27_0, STREAM<W_TYPE>& s_feature_PE27_1,
    STREAM<W_TYPE>& s_feature_PE27_2, STREAM<W_TYPE>& s_feature_PE27_3,
    STREAM<W_TYPE>& s_feature_PE28_0, STREAM<W_TYPE>& s_feature_PE28_1,
    STREAM<W_TYPE>& s_feature_PE28_2, STREAM<W_TYPE>& s_feature_PE28_3,
    STREAM<W_TYPE>& s_feature_PE29_0, STREAM<W_TYPE>& s_feature_PE29_1,
    STREAM<W_TYPE>& s_feature_PE29_2, STREAM<W_TYPE>& s_feature_PE29_3,
    STREAM<W_TYPE>& s_feature_PE30_0, STREAM<W_TYPE>& s_feature_PE30_1,
    STREAM<W_TYPE>& s_feature_PE30_2, STREAM<W_TYPE>& s_feature_PE30_3,
    STREAM<W_TYPE>& s_feature_PE31_0, STREAM<W_TYPE>& s_feature_PE31_1,
    STREAM<W_TYPE>& s_feature_PE31_2, STREAM<W_TYPE>& s_feature_PE31_3,
    STREAM<W_TYPE>& s_feature_PE32_0, STREAM<W_TYPE>& s_feature_PE32_1,
    STREAM<W_TYPE>& s_feature_PE32_2, STREAM<W_TYPE>& s_feature_PE32_3,
    STREAM<W_TYPE>& s_feature_PE33_0, STREAM<W_TYPE>& s_feature_PE33_1,
    STREAM<W_TYPE>& s_feature_PE33_2, STREAM<W_TYPE>& s_feature_PE33_3,
    STREAM<W_TYPE>& s_feature_PE34_0, STREAM<W_TYPE>& s_feature_PE34_1,
    STREAM<W_TYPE>& s_feature_PE34_2, STREAM<W_TYPE>& s_feature_PE34_3,
    STREAM<W_TYPE>& s_feature_PE35_0, STREAM<W_TYPE>& s_feature_PE35_1,
    STREAM<W_TYPE>& s_feature_PE35_2, STREAM<W_TYPE>& s_feature_PE35_3,
    STREAM<W_TYPE>& s_feature_PE36_0, STREAM<W_TYPE>& s_feature_PE36_1,
    STREAM<W_TYPE>& s_feature_PE36_2, STREAM<W_TYPE>& s_feature_PE36_3,
    STREAM<W_TYPE>& s_feature_PE37_0, STREAM<W_TYPE>& s_feature_PE37_1,
    STREAM<W_TYPE>& s_feature_PE37_2, STREAM<W_TYPE>& s_feature_PE37_3,
    STREAM<W_TYPE>& s_feature_PE38_0, STREAM<W_TYPE>& s_feature_PE38_1,
    STREAM<W_TYPE>& s_feature_PE38_2, STREAM<W_TYPE>& s_feature_PE38_3,
    STREAM<W_TYPE>& s_feature_PE39_0, STREAM<W_TYPE>& s_feature_PE39_1,
    STREAM<W_TYPE>& s_feature_PE39_2, STREAM<W_TYPE>& s_feature_PE39_3,
    STREAM<W_TYPE>& s_feature_PE40_0, STREAM<W_TYPE>& s_feature_PE40_1,
    STREAM<W_TYPE>& s_feature_PE40_2, STREAM<W_TYPE>& s_feature_PE40_3,
    STREAM<W_TYPE>& s_feature_PE41_0, STREAM<W_TYPE>& s_feature_PE41_1,
    STREAM<W_TYPE>& s_feature_PE41_2, STREAM<W_TYPE>& s_feature_PE41_3,
    STREAM<W_TYPE>& s_feature_PE42_0, STREAM<W_TYPE>& s_feature_PE42_1,
    STREAM<W_TYPE>& s_feature_PE42_2, STREAM<W_TYPE>& s_feature_PE42_3,
    STREAM<W_TYPE>& s_feature_PE43_0, STREAM<W_TYPE>& s_feature_PE43_1,
    STREAM<W_TYPE>& s_feature_PE43_2, STREAM<W_TYPE>& s_feature_PE43_3,
    STREAM<W_TYPE>& s_feature_PE44_0, STREAM<W_TYPE>& s_feature_PE44_1,
    STREAM<W_TYPE>& s_feature_PE44_2, STREAM<W_TYPE>& s_feature_PE44_3,
    STREAM<W_TYPE>& s_feature_PE45_0, STREAM<W_TYPE>& s_feature_PE45_1,
    STREAM<W_TYPE>& s_feature_PE45_2, STREAM<W_TYPE>& s_feature_PE45_3,
    STREAM<W_TYPE>& s_feature_PE46_0, STREAM<W_TYPE>& s_feature_PE46_1,
    STREAM<W_TYPE>& s_feature_PE46_2, STREAM<W_TYPE>& s_feature_PE46_3,
    STREAM<W_TYPE>& s_feature_PE47_0, STREAM<W_TYPE>& s_feature_PE47_1,
    STREAM<W_TYPE>& s_feature_PE47_2, STREAM<W_TYPE>& s_feature_PE47_3,
    STREAM<W_TYPE>& s_feature_PE48_0, STREAM<W_TYPE>& s_feature_PE48_1,
    STREAM<W_TYPE>& s_feature_PE48_2, STREAM<W_TYPE>& s_feature_PE48_3,
    STREAM<W_TYPE>& s_feature_PE49_0, STREAM<W_TYPE>& s_feature_PE49_1,
    STREAM<W_TYPE>& s_feature_PE49_2, STREAM<W_TYPE>& s_feature_PE49_3,
    STREAM<W_TYPE>& s_feature_PE50_0, STREAM<W_TYPE>& s_feature_PE50_1,
    STREAM<W_TYPE>& s_feature_PE50_2, STREAM<W_TYPE>& s_feature_PE50_3,
    STREAM<W_TYPE>& s_feature_PE51_0, STREAM<W_TYPE>& s_feature_PE51_1,
    STREAM<W_TYPE>& s_feature_PE51_2, STREAM<W_TYPE>& s_feature_PE51_3,
    STREAM<W_TYPE>& s_feature_PE52_0, STREAM<W_TYPE>& s_feature_PE52_1,
    STREAM<W_TYPE>& s_feature_PE52_2, STREAM<W_TYPE>& s_feature_PE52_3,
    STREAM<W_TYPE>& s_feature_PE53_0, STREAM<W_TYPE>& s_feature_PE53_1,
    STREAM<W_TYPE>& s_feature_PE53_2, STREAM<W_TYPE>& s_feature_PE53_3,
    STREAM<W_TYPE>& s_feature_PE54_0, STREAM<W_TYPE>& s_feature_PE54_1,
    STREAM<W_TYPE>& s_feature_PE54_2, STREAM<W_TYPE>& s_feature_PE54_3,
    STREAM<W_TYPE>& s_feature_PE55_0, STREAM<W_TYPE>& s_feature_PE55_1,
    STREAM<W_TYPE>& s_feature_PE55_2, STREAM<W_TYPE>& s_feature_PE55_3,
    STREAM<W_TYPE>& s_feature_PE56_0, STREAM<W_TYPE>& s_feature_PE56_1,
    STREAM<W_TYPE>& s_feature_PE56_2, STREAM<W_TYPE>& s_feature_PE56_3,
    STREAM<W_TYPE>& s_feature_PE57_0, STREAM<W_TYPE>& s_feature_PE57_1,
    STREAM<W_TYPE>& s_feature_PE57_2, STREAM<W_TYPE>& s_feature_PE57_3,
    STREAM<W_TYPE>& s_feature_PE58_0, STREAM<W_TYPE>& s_feature_PE58_1,
    STREAM<W_TYPE>& s_feature_PE58_2, STREAM<W_TYPE>& s_feature_PE58_3,
    STREAM<W_TYPE>& s_feature_PE59_0, STREAM<W_TYPE>& s_feature_PE59_1,
    STREAM<W_TYPE>& s_feature_PE59_2, STREAM<W_TYPE>& s_feature_PE59_3,
    STREAM<W_TYPE>& s_feature_PE60_0, STREAM<W_TYPE>& s_feature_PE60_1,
    STREAM<W_TYPE>& s_feature_PE60_2, STREAM<W_TYPE>& s_feature_PE60_3,
    STREAM<W_TYPE>& s_feature_PE61_0, STREAM<W_TYPE>& s_feature_PE61_1,
    STREAM<W_TYPE>& s_feature_PE61_2, STREAM<W_TYPE>& s_feature_PE61_3,
    STREAM<W_TYPE>& s_feature_PE62_0, STREAM<W_TYPE>& s_feature_PE62_1,
    STREAM<W_TYPE>& s_feature_PE62_2, STREAM<W_TYPE>& s_feature_PE62_3,
    STREAM<W_TYPE>& s_feature_PE63_0, STREAM<W_TYPE>& s_feature_PE63_1,
    STREAM<W_TYPE>& s_feature_PE63_2, STREAM<W_TYPE>& s_feature_PE63_3,
    STREAM<W_TYPE>& s_feature_PE64_0, STREAM<W_TYPE>& s_feature_PE64_1,
    STREAM<W_TYPE>& s_feature_PE64_2, STREAM<W_TYPE>& s_feature_PE64_3,
    STREAM<W_TYPE>& s_feature_PE65_0, STREAM<W_TYPE>& s_feature_PE65_1,
    STREAM<W_TYPE>& s_feature_PE65_2, STREAM<W_TYPE>& s_feature_PE65_3,
    STREAM<W_TYPE>& s_feature_PE66_0, STREAM<W_TYPE>& s_feature_PE66_1,
    STREAM<W_TYPE>& s_feature_PE66_2, STREAM<W_TYPE>& s_feature_PE66_3,
    STREAM<W_TYPE>& s_feature_PE67_0, STREAM<W_TYPE>& s_feature_PE67_1,
    STREAM<W_TYPE>& s_feature_PE67_2, STREAM<W_TYPE>& s_feature_PE67_3,
    STREAM<W_TYPE>& s_feature_PE68_0, STREAM<W_TYPE>& s_feature_PE68_1,
    STREAM<W_TYPE>& s_feature_PE68_2, STREAM<W_TYPE>& s_feature_PE68_3,
    STREAM<W_TYPE>& s_feature_PE69_0, STREAM<W_TYPE>& s_feature_PE69_1,
    STREAM<W_TYPE>& s_feature_PE69_2, STREAM<W_TYPE>& s_feature_PE69_3,
    STREAM<W_TYPE>& s_feature_PE70_0, STREAM<W_TYPE>& s_feature_PE70_1,
    STREAM<W_TYPE>& s_feature_PE70_2, STREAM<W_TYPE>& s_feature_PE70_3,
    STREAM<W_TYPE>& s_feature_PE71_0, STREAM<W_TYPE>& s_feature_PE71_1,
    STREAM<W_TYPE>& s_feature_PE71_2, STREAM<W_TYPE>& s_feature_PE71_3,
    STREAM<W_TYPE>& s_feature_PE72_0, STREAM<W_TYPE>& s_feature_PE72_1,
    STREAM<W_TYPE>& s_feature_PE72_2, STREAM<W_TYPE>& s_feature_PE72_3,
    STREAM<W_TYPE>& s_feature_PE73_0, STREAM<W_TYPE>& s_feature_PE73_1,
    STREAM<W_TYPE>& s_feature_PE73_2, STREAM<W_TYPE>& s_feature_PE73_3,
    STREAM<W_TYPE>& s_feature_PE74_0, STREAM<W_TYPE>& s_feature_PE74_1,
    STREAM<W_TYPE>& s_feature_PE74_2, STREAM<W_TYPE>& s_feature_PE74_3,
    STREAM<W_TYPE>& s_feature_PE75_0, STREAM<W_TYPE>& s_feature_PE75_1,
    STREAM<W_TYPE>& s_feature_PE75_2, STREAM<W_TYPE>& s_feature_PE75_3,
    STREAM<W_TYPE>& s_feature_PE76_0, STREAM<W_TYPE>& s_feature_PE76_1,
    STREAM<W_TYPE>& s_feature_PE76_2, STREAM<W_TYPE>& s_feature_PE76_3,
    STREAM<W_TYPE>& s_feature_PE77_0, STREAM<W_TYPE>& s_feature_PE77_1,
    STREAM<W_TYPE>& s_feature_PE77_2, STREAM<W_TYPE>& s_feature_PE77_3,
    STREAM<W_TYPE>& s_feature_PE78_0, STREAM<W_TYPE>& s_feature_PE78_1,
    STREAM<W_TYPE>& s_feature_PE78_2, STREAM<W_TYPE>& s_feature_PE78_3,
    STREAM<W_TYPE>& s_feature_PE79_0, STREAM<W_TYPE>& s_feature_PE79_1,
    STREAM<W_TYPE>& s_feature_PE79_2, STREAM<W_TYPE>& s_feature_PE79_3,
    STREAM<W_TYPE>& s_feature_PE80_0, STREAM<W_TYPE>& s_feature_PE80_1,
    STREAM<W_TYPE>& s_feature_PE80_2, STREAM<W_TYPE>& s_feature_PE80_3,
    STREAM<W_TYPE>& s_feature_PE81_0, STREAM<W_TYPE>& s_feature_PE81_1,
    STREAM<W_TYPE>& s_feature_PE81_2, STREAM<W_TYPE>& s_feature_PE81_3,
    STREAM<W_TYPE>& s_feature_PE82_0, STREAM<W_TYPE>& s_feature_PE82_1,
    STREAM<W_TYPE>& s_feature_PE82_2, STREAM<W_TYPE>& s_feature_PE82_3,
    STREAM<W_TYPE>& s_feature_PE83_0, STREAM<W_TYPE>& s_feature_PE83_1,
    STREAM<W_TYPE>& s_feature_PE83_2, STREAM<W_TYPE>& s_feature_PE83_3,
    STREAM<W_TYPE>& s_feature_PE84_0, STREAM<W_TYPE>& s_feature_PE84_1,
    STREAM<W_TYPE>& s_feature_PE84_2, STREAM<W_TYPE>& s_feature_PE84_3,
    STREAM<W_TYPE>& s_feature_PE85_0, STREAM<W_TYPE>& s_feature_PE85_1,
    STREAM<W_TYPE>& s_feature_PE85_2, STREAM<W_TYPE>& s_feature_PE85_3,
    STREAM<W_TYPE>& s_feature_PE86_0, STREAM<W_TYPE>& s_feature_PE86_1,
    STREAM<W_TYPE>& s_feature_PE86_2, STREAM<W_TYPE>& s_feature_PE86_3,
    STREAM<W_TYPE>& s_feature_PE87_0, STREAM<W_TYPE>& s_feature_PE87_1,
    STREAM<W_TYPE>& s_feature_PE87_2, STREAM<W_TYPE>& s_feature_PE87_3,
    STREAM<W_TYPE>& s_feature_PE88_0, STREAM<W_TYPE>& s_feature_PE88_1,
    STREAM<W_TYPE>& s_feature_PE88_2, STREAM<W_TYPE>& s_feature_PE88_3,
    STREAM<W_TYPE>& s_feature_PE89_0, STREAM<W_TYPE>& s_feature_PE89_1,
    STREAM<W_TYPE>& s_feature_PE89_2, STREAM<W_TYPE>& s_feature_PE89_3,
    STREAM<W_TYPE>& s_feature_PE90_0, STREAM<W_TYPE>& s_feature_PE90_1,
    STREAM<W_TYPE>& s_feature_PE90_2, STREAM<W_TYPE>& s_feature_PE90_3,
    STREAM<W_TYPE>& s_feature_PE91_0, STREAM<W_TYPE>& s_feature_PE91_1,
    STREAM<W_TYPE>& s_feature_PE91_2, STREAM<W_TYPE>& s_feature_PE91_3,
    STREAM<W_TYPE>& s_feature_PE92_0, STREAM<W_TYPE>& s_feature_PE92_1,
    STREAM<W_TYPE>& s_feature_PE92_2, STREAM<W_TYPE>& s_feature_PE92_3,
    STREAM<W_TYPE>& s_feature_PE93_0, STREAM<W_TYPE>& s_feature_PE93_1,
    STREAM<W_TYPE>& s_feature_PE93_2, STREAM<W_TYPE>& s_feature_PE93_3,
    STREAM<W_TYPE>& s_feature_PE94_0, STREAM<W_TYPE>& s_feature_PE94_1,
    STREAM<W_TYPE>& s_feature_PE94_2, STREAM<W_TYPE>& s_feature_PE94_3,
    STREAM<W_TYPE>& s_feature_PE95_0, STREAM<W_TYPE>& s_feature_PE95_1,
    STREAM<W_TYPE>& s_feature_PE95_2, STREAM<W_TYPE>& s_feature_PE95_3,
    STREAM<W_TYPE>& s_feature_PE96_0, STREAM<W_TYPE>& s_feature_PE96_1,
    STREAM<W_TYPE>& s_feature_PE96_2, STREAM<W_TYPE>& s_feature_PE96_3,
    STREAM<W_TYPE>& s_feature_PE97_0, STREAM<W_TYPE>& s_feature_PE97_1,
    STREAM<W_TYPE>& s_feature_PE97_2, STREAM<W_TYPE>& s_feature_PE97_3,
    STREAM<W_TYPE>& s_feature_PE98_0, STREAM<W_TYPE>& s_feature_PE98_1,
    STREAM<W_TYPE>& s_feature_PE98_2, STREAM<W_TYPE>& s_feature_PE98_3,
    STREAM<W_TYPE>& s_feature_PE99_0, STREAM<W_TYPE>& s_feature_PE99_1,
    STREAM<W_TYPE>& s_feature_PE99_2, STREAM<W_TYPE>& s_feature_PE99_3,
    STREAM<W_TYPE>& s_feature_PE100_0, STREAM<W_TYPE>& s_feature_PE100_1,
    STREAM<W_TYPE>& s_feature_PE100_2, STREAM<W_TYPE>& s_feature_PE100_3,
    STREAM<W_TYPE>& s_feature_PE101_0, STREAM<W_TYPE>& s_feature_PE101_1,
    STREAM<W_TYPE>& s_feature_PE101_2, STREAM<W_TYPE>& s_feature_PE101_3,
    STREAM<W_TYPE>& s_feature_PE102_0, STREAM<W_TYPE>& s_feature_PE102_1,
    STREAM<W_TYPE>& s_feature_PE102_2, STREAM<W_TYPE>& s_feature_PE102_3,
    STREAM<W_TYPE>& s_feature_PE103_0, STREAM<W_TYPE>& s_feature_PE103_1,
    STREAM<W_TYPE>& s_feature_PE103_2, STREAM<W_TYPE>& s_feature_PE103_3,
    STREAM<W_TYPE>& s_feature_PE104_0, STREAM<W_TYPE>& s_feature_PE104_1,
    STREAM<W_TYPE>& s_feature_PE104_2, STREAM<W_TYPE>& s_feature_PE104_3,
    STREAM<W_TYPE>& s_feature_PE105_0, STREAM<W_TYPE>& s_feature_PE105_1,
    STREAM<W_TYPE>& s_feature_PE105_2, STREAM<W_TYPE>& s_feature_PE105_3,
    STREAM<W_TYPE>& s_feature_PE106_0, STREAM<W_TYPE>& s_feature_PE106_1,
    STREAM<W_TYPE>& s_feature_PE106_2, STREAM<W_TYPE>& s_feature_PE106_3,
    STREAM<W_TYPE>& s_feature_PE107_0, STREAM<W_TYPE>& s_feature_PE107_1,
    STREAM<W_TYPE>& s_feature_PE107_2, STREAM<W_TYPE>& s_feature_PE107_3
);

template<const int FEATURE_SIZE>
void replicate_feature_512PEs_54PE(
    STREAM<ap_uint<512> >& s_feature_in, 
    STREAM<W_TYPE>& s_feature_PE0_0, STREAM<W_TYPE>& s_feature_PE0_1,
    STREAM<W_TYPE>& s_feature_PE0_2, STREAM<W_TYPE>& s_feature_PE0_3,
    STREAM<W_TYPE>& s_feature_PE1_0, STREAM<W_TYPE>& s_feature_PE1_1,
    STREAM<W_TYPE>& s_feature_PE1_2, STREAM<W_TYPE>& s_feature_PE1_3,
    STREAM<W_TYPE>& s_feature_PE2_0, STREAM<W_TYPE>& s_feature_PE2_1,
    STREAM<W_TYPE>& s_feature_PE2_2, STREAM<W_TYPE>& s_feature_PE2_3,
    STREAM<W_TYPE>& s_feature_PE3_0, STREAM<W_TYPE>& s_feature_PE3_1,
    STREAM<W_TYPE>& s_feature_PE3_2, STREAM<W_TYPE>& s_feature_PE3_3,
    STREAM<W_TYPE>& s_feature_PE4_0, STREAM<W_TYPE>& s_feature_PE4_1,
    STREAM<W_TYPE>& s_feature_PE4_2, STREAM<W_TYPE>& s_feature_PE4_3,
    STREAM<W_TYPE>& s_feature_PE5_0, STREAM<W_TYPE>& s_feature_PE5_1,
    STREAM<W_TYPE>& s_feature_PE5_2, STREAM<W_TYPE>& s_feature_PE5_3,
    STREAM<W_TYPE>& s_feature_PE6_0, STREAM<W_TYPE>& s_feature_PE6_1,
    STREAM<W_TYPE>& s_feature_PE6_2, STREAM<W_TYPE>& s_feature_PE6_3,
    STREAM<W_TYPE>& s_feature_PE7_0, STREAM<W_TYPE>& s_feature_PE7_1,
    STREAM<W_TYPE>& s_feature_PE7_2, STREAM<W_TYPE>& s_feature_PE7_3,
    STREAM<W_TYPE>& s_feature_PE8_0, STREAM<W_TYPE>& s_feature_PE8_1,
    STREAM<W_TYPE>& s_feature_PE8_2, STREAM<W_TYPE>& s_feature_PE8_3,
    STREAM<W_TYPE>& s_feature_PE9_0, STREAM<W_TYPE>& s_feature_PE9_1,
    STREAM<W_TYPE>& s_feature_PE9_2, STREAM<W_TYPE>& s_feature_PE9_3,
    STREAM<W_TYPE>& s_feature_PE10_0, STREAM<W_TYPE>& s_feature_PE10_1,
    STREAM<W_TYPE>& s_feature_PE10_2, STREAM<W_TYPE>& s_feature_PE10_3,
    STREAM<W_TYPE>& s_feature_PE11_0, STREAM<W_TYPE>& s_feature_PE11_1,
    STREAM<W_TYPE>& s_feature_PE11_2, STREAM<W_TYPE>& s_feature_PE11_3,
    STREAM<W_TYPE>& s_feature_PE12_0, STREAM<W_TYPE>& s_feature_PE12_1,
    STREAM<W_TYPE>& s_feature_PE12_2, STREAM<W_TYPE>& s_feature_PE12_3,
    STREAM<W_TYPE>& s_feature_PE13_0, STREAM<W_TYPE>& s_feature_PE13_1,
    STREAM<W_TYPE>& s_feature_PE13_2, STREAM<W_TYPE>& s_feature_PE13_3,
    STREAM<W_TYPE>& s_feature_PE14_0, STREAM<W_TYPE>& s_feature_PE14_1,
    STREAM<W_TYPE>& s_feature_PE14_2, STREAM<W_TYPE>& s_feature_PE14_3,
    STREAM<W_TYPE>& s_feature_PE15_0, STREAM<W_TYPE>& s_feature_PE15_1,
    STREAM<W_TYPE>& s_feature_PE15_2, STREAM<W_TYPE>& s_feature_PE15_3,
    STREAM<W_TYPE>& s_feature_PE16_0, STREAM<W_TYPE>& s_feature_PE16_1,
    STREAM<W_TYPE>& s_feature_PE16_2, STREAM<W_TYPE>& s_feature_PE16_3,
    STREAM<W_TYPE>& s_feature_PE17_0, STREAM<W_TYPE>& s_feature_PE17_1,
    STREAM<W_TYPE>& s_feature_PE17_2, STREAM<W_TYPE>& s_feature_PE17_3,
    STREAM<W_TYPE>& s_feature_PE18_0, STREAM<W_TYPE>& s_feature_PE18_1,
    STREAM<W_TYPE>& s_feature_PE18_2, STREAM<W_TYPE>& s_feature_PE18_3,
    STREAM<W_TYPE>& s_feature_PE19_0, STREAM<W_TYPE>& s_feature_PE19_1,
    STREAM<W_TYPE>& s_feature_PE19_2, STREAM<W_TYPE>& s_feature_PE19_3,
    STREAM<W_TYPE>& s_feature_PE20_0, STREAM<W_TYPE>& s_feature_PE20_1,
    STREAM<W_TYPE>& s_feature_PE20_2, STREAM<W_TYPE>& s_feature_PE20_3,
    STREAM<W_TYPE>& s_feature_PE21_0, STREAM<W_TYPE>& s_feature_PE21_1,
    STREAM<W_TYPE>& s_feature_PE21_2, STREAM<W_TYPE>& s_feature_PE21_3,
    STREAM<W_TYPE>& s_feature_PE22_0, STREAM<W_TYPE>& s_feature_PE22_1,
    STREAM<W_TYPE>& s_feature_PE22_2, STREAM<W_TYPE>& s_feature_PE22_3,
    STREAM<W_TYPE>& s_feature_PE23_0, STREAM<W_TYPE>& s_feature_PE23_1,
    STREAM<W_TYPE>& s_feature_PE23_2, STREAM<W_TYPE>& s_feature_PE23_3,
    STREAM<W_TYPE>& s_feature_PE24_0, STREAM<W_TYPE>& s_feature_PE24_1,
    STREAM<W_TYPE>& s_feature_PE24_2, STREAM<W_TYPE>& s_feature_PE24_3,
    STREAM<W_TYPE>& s_feature_PE25_0, STREAM<W_TYPE>& s_feature_PE25_1,
    STREAM<W_TYPE>& s_feature_PE25_2, STREAM<W_TYPE>& s_feature_PE25_3,
    STREAM<W_TYPE>& s_feature_PE26_0, STREAM<W_TYPE>& s_feature_PE26_1,
    STREAM<W_TYPE>& s_feature_PE26_2, STREAM<W_TYPE>& s_feature_PE26_3,
    STREAM<W_TYPE>& s_feature_PE27_0, STREAM<W_TYPE>& s_feature_PE27_1,
    STREAM<W_TYPE>& s_feature_PE27_2, STREAM<W_TYPE>& s_feature_PE27_3,
    STREAM<W_TYPE>& s_feature_PE28_0, STREAM<W_TYPE>& s_feature_PE28_1,
    STREAM<W_TYPE>& s_feature_PE28_2, STREAM<W_TYPE>& s_feature_PE28_3,
    STREAM<W_TYPE>& s_feature_PE29_0, STREAM<W_TYPE>& s_feature_PE29_1,
    STREAM<W_TYPE>& s_feature_PE29_2, STREAM<W_TYPE>& s_feature_PE29_3,
    STREAM<W_TYPE>& s_feature_PE30_0, STREAM<W_TYPE>& s_feature_PE30_1,
    STREAM<W_TYPE>& s_feature_PE30_2, STREAM<W_TYPE>& s_feature_PE30_3,
    STREAM<W_TYPE>& s_feature_PE31_0, STREAM<W_TYPE>& s_feature_PE31_1,
    STREAM<W_TYPE>& s_feature_PE31_2, STREAM<W_TYPE>& s_feature_PE31_3,
    STREAM<W_TYPE>& s_feature_PE32_0, STREAM<W_TYPE>& s_feature_PE32_1,
    STREAM<W_TYPE>& s_feature_PE32_2, STREAM<W_TYPE>& s_feature_PE32_3,
    STREAM<W_TYPE>& s_feature_PE33_0, STREAM<W_TYPE>& s_feature_PE33_1,
    STREAM<W_TYPE>& s_feature_PE33_2, STREAM<W_TYPE>& s_feature_PE33_3,
    STREAM<W_TYPE>& s_feature_PE34_0, STREAM<W_TYPE>& s_feature_PE34_1,
    STREAM<W_TYPE>& s_feature_PE34_2, STREAM<W_TYPE>& s_feature_PE34_3,
    STREAM<W_TYPE>& s_feature_PE35_0, STREAM<W_TYPE>& s_feature_PE35_1,
    STREAM<W_TYPE>& s_feature_PE35_2, STREAM<W_TYPE>& s_feature_PE35_3,
    STREAM<W_TYPE>& s_feature_PE36_0, STREAM<W_TYPE>& s_feature_PE36_1,
    STREAM<W_TYPE>& s_feature_PE36_2, STREAM<W_TYPE>& s_feature_PE36_3,
    STREAM<W_TYPE>& s_feature_PE37_0, STREAM<W_TYPE>& s_feature_PE37_1,
    STREAM<W_TYPE>& s_feature_PE37_2, STREAM<W_TYPE>& s_feature_PE37_3,
    STREAM<W_TYPE>& s_feature_PE38_0, STREAM<W_TYPE>& s_feature_PE38_1,
    STREAM<W_TYPE>& s_feature_PE38_2, STREAM<W_TYPE>& s_feature_PE38_3,
    STREAM<W_TYPE>& s_feature_PE39_0, STREAM<W_TYPE>& s_feature_PE39_1,
    STREAM<W_TYPE>& s_feature_PE39_2, STREAM<W_TYPE>& s_feature_PE39_3,
    STREAM<W_TYPE>& s_feature_PE40_0, STREAM<W_TYPE>& s_feature_PE40_1,
    STREAM<W_TYPE>& s_feature_PE40_2, STREAM<W_TYPE>& s_feature_PE40_3,
    STREAM<W_TYPE>& s_feature_PE41_0, STREAM<W_TYPE>& s_feature_PE41_1,
    STREAM<W_TYPE>& s_feature_PE41_2, STREAM<W_TYPE>& s_feature_PE41_3,
    STREAM<W_TYPE>& s_feature_PE42_0, STREAM<W_TYPE>& s_feature_PE42_1,
    STREAM<W_TYPE>& s_feature_PE42_2, STREAM<W_TYPE>& s_feature_PE42_3,
    STREAM<W_TYPE>& s_feature_PE43_0, STREAM<W_TYPE>& s_feature_PE43_1,
    STREAM<W_TYPE>& s_feature_PE43_2, STREAM<W_TYPE>& s_feature_PE43_3,
    STREAM<W_TYPE>& s_feature_PE44_0, STREAM<W_TYPE>& s_feature_PE44_1,
    STREAM<W_TYPE>& s_feature_PE44_2, STREAM<W_TYPE>& s_feature_PE44_3,
    STREAM<W_TYPE>& s_feature_PE45_0, STREAM<W_TYPE>& s_feature_PE45_1,
    STREAM<W_TYPE>& s_feature_PE45_2, STREAM<W_TYPE>& s_feature_PE45_3,
    STREAM<W_TYPE>& s_feature_PE46_0, STREAM<W_TYPE>& s_feature_PE46_1,
    STREAM<W_TYPE>& s_feature_PE46_2, STREAM<W_TYPE>& s_feature_PE46_3,
    STREAM<W_TYPE>& s_feature_PE47_0, STREAM<W_TYPE>& s_feature_PE47_1,
    STREAM<W_TYPE>& s_feature_PE47_2, STREAM<W_TYPE>& s_feature_PE47_3,
    STREAM<W_TYPE>& s_feature_PE48_0, STREAM<W_TYPE>& s_feature_PE48_1,
    STREAM<W_TYPE>& s_feature_PE48_2, STREAM<W_TYPE>& s_feature_PE48_3,
    STREAM<W_TYPE>& s_feature_PE49_0, STREAM<W_TYPE>& s_feature_PE49_1,
    STREAM<W_TYPE>& s_feature_PE49_2, STREAM<W_TYPE>& s_feature_PE49_3,
    STREAM<W_TYPE>& s_feature_PE50_0, STREAM<W_TYPE>& s_feature_PE50_1,
    STREAM<W_TYPE>& s_feature_PE50_2, STREAM<W_TYPE>& s_feature_PE50_3,
    STREAM<W_TYPE>& s_feature_PE51_0, STREAM<W_TYPE>& s_feature_PE51_1,
    STREAM<W_TYPE>& s_feature_PE51_2, STREAM<W_TYPE>& s_feature_PE51_3,
    STREAM<W_TYPE>& s_feature_PE52_0, STREAM<W_TYPE>& s_feature_PE52_1,
    STREAM<W_TYPE>& s_feature_PE52_2, STREAM<W_TYPE>& s_feature_PE52_3,
    STREAM<W_TYPE>& s_feature_PE53_0, STREAM<W_TYPE>& s_feature_PE53_1,
    STREAM<W_TYPE>& s_feature_PE53_2, STREAM<W_TYPE>& s_feature_PE53_3
);

template<const int FEATURE_SIZE>
void replicate_feature_512PEs_36PE(
    STREAM<ap_uint<512> >& s_feature_in, 
    STREAM<W_TYPE>& s_feature_PE0_0, STREAM<W_TYPE>& s_feature_PE0_1,
    STREAM<W_TYPE>& s_feature_PE0_2, STREAM<W_TYPE>& s_feature_PE0_3,
    STREAM<W_TYPE>& s_feature_PE1_0, STREAM<W_TYPE>& s_feature_PE1_1,
    STREAM<W_TYPE>& s_feature_PE1_2, STREAM<W_TYPE>& s_feature_PE1_3,
    STREAM<W_TYPE>& s_feature_PE2_0, STREAM<W_TYPE>& s_feature_PE2_1,
    STREAM<W_TYPE>& s_feature_PE2_2, STREAM<W_TYPE>& s_feature_PE2_3,
    STREAM<W_TYPE>& s_feature_PE3_0, STREAM<W_TYPE>& s_feature_PE3_1,
    STREAM<W_TYPE>& s_feature_PE3_2, STREAM<W_TYPE>& s_feature_PE3_3,
    STREAM<W_TYPE>& s_feature_PE4_0, STREAM<W_TYPE>& s_feature_PE4_1,
    STREAM<W_TYPE>& s_feature_PE4_2, STREAM<W_TYPE>& s_feature_PE4_3,
    STREAM<W_TYPE>& s_feature_PE5_0, STREAM<W_TYPE>& s_feature_PE5_1,
    STREAM<W_TYPE>& s_feature_PE5_2, STREAM<W_TYPE>& s_feature_PE5_3,
    STREAM<W_TYPE>& s_feature_PE6_0, STREAM<W_TYPE>& s_feature_PE6_1,
    STREAM<W_TYPE>& s_feature_PE6_2, STREAM<W_TYPE>& s_feature_PE6_3,
    STREAM<W_TYPE>& s_feature_PE7_0, STREAM<W_TYPE>& s_feature_PE7_1,
    STREAM<W_TYPE>& s_feature_PE7_2, STREAM<W_TYPE>& s_feature_PE7_3,
    STREAM<W_TYPE>& s_feature_PE8_0, STREAM<W_TYPE>& s_feature_PE8_1,
    STREAM<W_TYPE>& s_feature_PE8_2, STREAM<W_TYPE>& s_feature_PE8_3,
    STREAM<W_TYPE>& s_feature_PE9_0, STREAM<W_TYPE>& s_feature_PE9_1,
    STREAM<W_TYPE>& s_feature_PE9_2, STREAM<W_TYPE>& s_feature_PE9_3,
    STREAM<W_TYPE>& s_feature_PE10_0, STREAM<W_TYPE>& s_feature_PE10_1,
    STREAM<W_TYPE>& s_feature_PE10_2, STREAM<W_TYPE>& s_feature_PE10_3,
    STREAM<W_TYPE>& s_feature_PE11_0, STREAM<W_TYPE>& s_feature_PE11_1,
    STREAM<W_TYPE>& s_feature_PE11_2, STREAM<W_TYPE>& s_feature_PE11_3,
    STREAM<W_TYPE>& s_feature_PE12_0, STREAM<W_TYPE>& s_feature_PE12_1,
    STREAM<W_TYPE>& s_feature_PE12_2, STREAM<W_TYPE>& s_feature_PE12_3,
    STREAM<W_TYPE>& s_feature_PE13_0, STREAM<W_TYPE>& s_feature_PE13_1,
    STREAM<W_TYPE>& s_feature_PE13_2, STREAM<W_TYPE>& s_feature_PE13_3,
    STREAM<W_TYPE>& s_feature_PE14_0, STREAM<W_TYPE>& s_feature_PE14_1,
    STREAM<W_TYPE>& s_feature_PE14_2, STREAM<W_TYPE>& s_feature_PE14_3,
    STREAM<W_TYPE>& s_feature_PE15_0, STREAM<W_TYPE>& s_feature_PE15_1,
    STREAM<W_TYPE>& s_feature_PE15_2, STREAM<W_TYPE>& s_feature_PE15_3,
    STREAM<W_TYPE>& s_feature_PE16_0, STREAM<W_TYPE>& s_feature_PE16_1,
    STREAM<W_TYPE>& s_feature_PE16_2, STREAM<W_TYPE>& s_feature_PE16_3,
    STREAM<W_TYPE>& s_feature_PE17_0, STREAM<W_TYPE>& s_feature_PE17_1,
    STREAM<W_TYPE>& s_feature_PE17_2, STREAM<W_TYPE>& s_feature_PE17_3,
    STREAM<W_TYPE>& s_feature_PE18_0, STREAM<W_TYPE>& s_feature_PE18_1,
    STREAM<W_TYPE>& s_feature_PE18_2, STREAM<W_TYPE>& s_feature_PE18_3,
    STREAM<W_TYPE>& s_feature_PE19_0, STREAM<W_TYPE>& s_feature_PE19_1,
    STREAM<W_TYPE>& s_feature_PE19_2, STREAM<W_TYPE>& s_feature_PE19_3,
    STREAM<W_TYPE>& s_feature_PE20_0, STREAM<W_TYPE>& s_feature_PE20_1,
    STREAM<W_TYPE>& s_feature_PE20_2, STREAM<W_TYPE>& s_feature_PE20_3,
    STREAM<W_TYPE>& s_feature_PE21_0, STREAM<W_TYPE>& s_feature_PE21_1,
    STREAM<W_TYPE>& s_feature_PE21_2, STREAM<W_TYPE>& s_feature_PE21_3,
    STREAM<W_TYPE>& s_feature_PE22_0, STREAM<W_TYPE>& s_feature_PE22_1,
    STREAM<W_TYPE>& s_feature_PE22_2, STREAM<W_TYPE>& s_feature_PE22_3,
    STREAM<W_TYPE>& s_feature_PE23_0, STREAM<W_TYPE>& s_feature_PE23_1,
    STREAM<W_TYPE>& s_feature_PE23_2, STREAM<W_TYPE>& s_feature_PE23_3,
    STREAM<W_TYPE>& s_feature_PE24_0, STREAM<W_TYPE>& s_feature_PE24_1,
    STREAM<W_TYPE>& s_feature_PE24_2, STREAM<W_TYPE>& s_feature_PE24_3,
    STREAM<W_TYPE>& s_feature_PE25_0, STREAM<W_TYPE>& s_feature_PE25_1,
    STREAM<W_TYPE>& s_feature_PE25_2, STREAM<W_TYPE>& s_feature_PE25_3,
    STREAM<W_TYPE>& s_feature_PE26_0, STREAM<W_TYPE>& s_feature_PE26_1,
    STREAM<W_TYPE>& s_feature_PE26_2, STREAM<W_TYPE>& s_feature_PE26_3,
    STREAM<W_TYPE>& s_feature_PE27_0, STREAM<W_TYPE>& s_feature_PE27_1,
    STREAM<W_TYPE>& s_feature_PE27_2, STREAM<W_TYPE>& s_feature_PE27_3,
    STREAM<W_TYPE>& s_feature_PE28_0, STREAM<W_TYPE>& s_feature_PE28_1,
    STREAM<W_TYPE>& s_feature_PE28_2, STREAM<W_TYPE>& s_feature_PE28_3,
    STREAM<W_TYPE>& s_feature_PE29_0, STREAM<W_TYPE>& s_feature_PE29_1,
    STREAM<W_TYPE>& s_feature_PE29_2, STREAM<W_TYPE>& s_feature_PE29_3,
    STREAM<W_TYPE>& s_feature_PE30_0, STREAM<W_TYPE>& s_feature_PE30_1,
    STREAM<W_TYPE>& s_feature_PE30_2, STREAM<W_TYPE>& s_feature_PE30_3,
    STREAM<W_TYPE>& s_feature_PE31_0, STREAM<W_TYPE>& s_feature_PE31_1,
    STREAM<W_TYPE>& s_feature_PE31_2, STREAM<W_TYPE>& s_feature_PE31_3,
    STREAM<W_TYPE>& s_feature_PE32_0, STREAM<W_TYPE>& s_feature_PE32_1,
    STREAM<W_TYPE>& s_feature_PE32_2, STREAM<W_TYPE>& s_feature_PE32_3,
    STREAM<W_TYPE>& s_feature_PE33_0, STREAM<W_TYPE>& s_feature_PE33_1,
    STREAM<W_TYPE>& s_feature_PE33_2, STREAM<W_TYPE>& s_feature_PE33_3,
    STREAM<W_TYPE>& s_feature_PE34_0, STREAM<W_TYPE>& s_feature_PE34_1,
    STREAM<W_TYPE>& s_feature_PE34_2, STREAM<W_TYPE>& s_feature_PE34_3,
    STREAM<W_TYPE>& s_feature_PE35_0, STREAM<W_TYPE>& s_feature_PE35_1,
    STREAM<W_TYPE>& s_feature_PE35_2, STREAM<W_TYPE>& s_feature_PE35_3);    

template<const int FEATURE_SIZE, const int ROW_PER_PE>
void replicate_feature_512PEs_32PE(
    STREAM<ap_uint<512> >& s_feature_in, 
    STREAM<W_TYPE>& s_feature_PE0_0, STREAM<W_TYPE>& s_feature_PE0_1,
    STREAM<W_TYPE>& s_feature_PE1_0, STREAM<W_TYPE>& s_feature_PE1_1,
    STREAM<W_TYPE>& s_feature_PE2_0, STREAM<W_TYPE>& s_feature_PE2_1,
    STREAM<W_TYPE>& s_feature_PE3_0, STREAM<W_TYPE>& s_feature_PE3_1,
    STREAM<W_TYPE>& s_feature_PE4_0, STREAM<W_TYPE>& s_feature_PE4_1,
    STREAM<W_TYPE>& s_feature_PE5_0, STREAM<W_TYPE>& s_feature_PE5_1,
    STREAM<W_TYPE>& s_feature_PE6_0, STREAM<W_TYPE>& s_feature_PE6_1,
    STREAM<W_TYPE>& s_feature_PE7_0, STREAM<W_TYPE>& s_feature_PE7_1,
    STREAM<W_TYPE>& s_feature_PE8_0, STREAM<W_TYPE>& s_feature_PE8_1,
    STREAM<W_TYPE>& s_feature_PE9_0, STREAM<W_TYPE>& s_feature_PE9_1,
    STREAM<W_TYPE>& s_feature_PE10_0, STREAM<W_TYPE>& s_feature_PE10_1,
    STREAM<W_TYPE>& s_feature_PE11_0, STREAM<W_TYPE>& s_feature_PE11_1,
    STREAM<W_TYPE>& s_feature_PE12_0, STREAM<W_TYPE>& s_feature_PE12_1,
    STREAM<W_TYPE>& s_feature_PE13_0, STREAM<W_TYPE>& s_feature_PE13_1,
    STREAM<W_TYPE>& s_feature_PE14_0, STREAM<W_TYPE>& s_feature_PE14_1,
    STREAM<W_TYPE>& s_feature_PE15_0, STREAM<W_TYPE>& s_feature_PE15_1,
    STREAM<W_TYPE>& s_feature_PE16_0, STREAM<W_TYPE>& s_feature_PE16_1,
    STREAM<W_TYPE>& s_feature_PE17_0, STREAM<W_TYPE>& s_feature_PE17_1,
    STREAM<W_TYPE>& s_feature_PE18_0, STREAM<W_TYPE>& s_feature_PE18_1,
    STREAM<W_TYPE>& s_feature_PE19_0, STREAM<W_TYPE>& s_feature_PE19_1,
    STREAM<W_TYPE>& s_feature_PE20_0, STREAM<W_TYPE>& s_feature_PE20_1,
    STREAM<W_TYPE>& s_feature_PE21_0, STREAM<W_TYPE>& s_feature_PE21_1,
    STREAM<W_TYPE>& s_feature_PE22_0, STREAM<W_TYPE>& s_feature_PE22_1,
    STREAM<W_TYPE>& s_feature_PE23_0, STREAM<W_TYPE>& s_feature_PE23_1,
    STREAM<W_TYPE>& s_feature_PE24_0, STREAM<W_TYPE>& s_feature_PE24_1,
    STREAM<W_TYPE>& s_feature_PE25_0, STREAM<W_TYPE>& s_feature_PE25_1,
    STREAM<W_TYPE>& s_feature_PE26_0, STREAM<W_TYPE>& s_feature_PE26_1,
    STREAM<W_TYPE>& s_feature_PE27_0, STREAM<W_TYPE>& s_feature_PE27_1,
    STREAM<W_TYPE>& s_feature_PE28_0, STREAM<W_TYPE>& s_feature_PE28_1,
    STREAM<W_TYPE>& s_feature_PE29_0, STREAM<W_TYPE>& s_feature_PE29_1,
    STREAM<W_TYPE>& s_feature_PE30_0, STREAM<W_TYPE>& s_feature_PE30_1,
    STREAM<W_TYPE>& s_feature_PE31_0, STREAM<W_TYPE>& s_feature_PE31_1);

template<const int FEATURE_SIZE>
void replicate_feature_512PEs_16PE(
    STREAM<ap_uint<512> >& s_feature_in, 
    STREAM<W_TYPE>& s_feature_PE0_0, STREAM<W_TYPE>& s_feature_PE0_1,
    STREAM<W_TYPE>& s_feature_PE1_0, STREAM<W_TYPE>& s_feature_PE1_1,
    STREAM<W_TYPE>& s_feature_PE2_0, STREAM<W_TYPE>& s_feature_PE2_1,
    STREAM<W_TYPE>& s_feature_PE3_0, STREAM<W_TYPE>& s_feature_PE3_1,
    STREAM<W_TYPE>& s_feature_PE4_0, STREAM<W_TYPE>& s_feature_PE4_1,
    STREAM<W_TYPE>& s_feature_PE5_0, STREAM<W_TYPE>& s_feature_PE5_1,
    STREAM<W_TYPE>& s_feature_PE6_0, STREAM<W_TYPE>& s_feature_PE6_1,
    STREAM<W_TYPE>& s_feature_PE7_0, STREAM<W_TYPE>& s_feature_PE7_1,
    STREAM<W_TYPE>& s_feature_PE8_0, STREAM<W_TYPE>& s_feature_PE8_1,
    STREAM<W_TYPE>& s_feature_PE9_0, STREAM<W_TYPE>& s_feature_PE9_1,
    STREAM<W_TYPE>& s_feature_PE10_0, STREAM<W_TYPE>& s_feature_PE10_1,
    STREAM<W_TYPE>& s_feature_PE11_0, STREAM<W_TYPE>& s_feature_PE11_1,
    STREAM<W_TYPE>& s_feature_PE12_0, STREAM<W_TYPE>& s_feature_PE12_1,
    STREAM<W_TYPE>& s_feature_PE13_0, STREAM<W_TYPE>& s_feature_PE13_1,
    STREAM<W_TYPE>& s_feature_PE14_0, STREAM<W_TYPE>& s_feature_PE14_1,
    STREAM<W_TYPE>& s_feature_PE15_0, STREAM<W_TYPE>& s_feature_PE15_1);

template<const int FEATURE_SIZE>
void replicate_feature_512PEs_29PE(
    STREAM<ap_uint<512> >& s_feature_in, 
    STREAM<W_TYPE>& s_feature_PE0_0, STREAM<W_TYPE>& s_feature_PE0_1,
    STREAM<W_TYPE>& s_feature_PE0_2, STREAM<W_TYPE>& s_feature_PE0_3,
    STREAM<W_TYPE>& s_feature_PE1_0, STREAM<W_TYPE>& s_feature_PE1_1,
    STREAM<W_TYPE>& s_feature_PE1_2, STREAM<W_TYPE>& s_feature_PE1_3,
    STREAM<W_TYPE>& s_feature_PE2_0, STREAM<W_TYPE>& s_feature_PE2_1,
    STREAM<W_TYPE>& s_feature_PE2_2, STREAM<W_TYPE>& s_feature_PE2_3,
    STREAM<W_TYPE>& s_feature_PE3_0, STREAM<W_TYPE>& s_feature_PE3_1,
    STREAM<W_TYPE>& s_feature_PE3_2, STREAM<W_TYPE>& s_feature_PE3_3,
    STREAM<W_TYPE>& s_feature_PE4_0, STREAM<W_TYPE>& s_feature_PE4_1,
    STREAM<W_TYPE>& s_feature_PE4_2, STREAM<W_TYPE>& s_feature_PE4_3,
    STREAM<W_TYPE>& s_feature_PE5_0, STREAM<W_TYPE>& s_feature_PE5_1,
    STREAM<W_TYPE>& s_feature_PE5_2, STREAM<W_TYPE>& s_feature_PE5_3,
    STREAM<W_TYPE>& s_feature_PE6_0, STREAM<W_TYPE>& s_feature_PE6_1,
    STREAM<W_TYPE>& s_feature_PE6_2, STREAM<W_TYPE>& s_feature_PE6_3,
    STREAM<W_TYPE>& s_feature_PE7_0, STREAM<W_TYPE>& s_feature_PE7_1,
    STREAM<W_TYPE>& s_feature_PE7_2, STREAM<W_TYPE>& s_feature_PE7_3,
    STREAM<W_TYPE>& s_feature_PE8_0, STREAM<W_TYPE>& s_feature_PE8_1,
    STREAM<W_TYPE>& s_feature_PE8_2, STREAM<W_TYPE>& s_feature_PE8_3,
    STREAM<W_TYPE>& s_feature_PE9_0, STREAM<W_TYPE>& s_feature_PE9_1,
    STREAM<W_TYPE>& s_feature_PE9_2, STREAM<W_TYPE>& s_feature_PE9_3,
    STREAM<W_TYPE>& s_feature_PE10_0, STREAM<W_TYPE>& s_feature_PE10_1,
    STREAM<W_TYPE>& s_feature_PE10_2, STREAM<W_TYPE>& s_feature_PE10_3,
    STREAM<W_TYPE>& s_feature_PE11_0, STREAM<W_TYPE>& s_feature_PE11_1,
    STREAM<W_TYPE>& s_feature_PE11_2, STREAM<W_TYPE>& s_feature_PE11_3,
    STREAM<W_TYPE>& s_feature_PE12_0, STREAM<W_TYPE>& s_feature_PE12_1,
    STREAM<W_TYPE>& s_feature_PE12_2, STREAM<W_TYPE>& s_feature_PE12_3,
    STREAM<W_TYPE>& s_feature_PE13_0, STREAM<W_TYPE>& s_feature_PE13_1,
    STREAM<W_TYPE>& s_feature_PE13_2, STREAM<W_TYPE>& s_feature_PE13_3,
    STREAM<W_TYPE>& s_feature_PE14_0, STREAM<W_TYPE>& s_feature_PE14_1,
    STREAM<W_TYPE>& s_feature_PE14_2, STREAM<W_TYPE>& s_feature_PE14_3,
    STREAM<W_TYPE>& s_feature_PE15_0, STREAM<W_TYPE>& s_feature_PE15_1,
    STREAM<W_TYPE>& s_feature_PE15_2, STREAM<W_TYPE>& s_feature_PE15_3,
    STREAM<W_TYPE>& s_feature_PE16_0, STREAM<W_TYPE>& s_feature_PE16_1,
    STREAM<W_TYPE>& s_feature_PE16_2, STREAM<W_TYPE>& s_feature_PE16_3,
    STREAM<W_TYPE>& s_feature_PE17_0, STREAM<W_TYPE>& s_feature_PE17_1,
    STREAM<W_TYPE>& s_feature_PE17_2, STREAM<W_TYPE>& s_feature_PE17_3,
    STREAM<W_TYPE>& s_feature_PE18_0, STREAM<W_TYPE>& s_feature_PE18_1,
    STREAM<W_TYPE>& s_feature_PE18_2, STREAM<W_TYPE>& s_feature_PE18_3,
    STREAM<W_TYPE>& s_feature_PE19_0, STREAM<W_TYPE>& s_feature_PE19_1,
    STREAM<W_TYPE>& s_feature_PE19_2, STREAM<W_TYPE>& s_feature_PE19_3,
    STREAM<W_TYPE>& s_feature_PE20_0, STREAM<W_TYPE>& s_feature_PE20_1,
    STREAM<W_TYPE>& s_feature_PE20_2, STREAM<W_TYPE>& s_feature_PE20_3,
    STREAM<W_TYPE>& s_feature_PE21_0, STREAM<W_TYPE>& s_feature_PE21_1,
    STREAM<W_TYPE>& s_feature_PE21_2, STREAM<W_TYPE>& s_feature_PE21_3,
    STREAM<W_TYPE>& s_feature_PE22_0, STREAM<W_TYPE>& s_feature_PE22_1,
    STREAM<W_TYPE>& s_feature_PE22_2, STREAM<W_TYPE>& s_feature_PE22_3,
    STREAM<W_TYPE>& s_feature_PE23_0, STREAM<W_TYPE>& s_feature_PE23_1,
    STREAM<W_TYPE>& s_feature_PE23_2, STREAM<W_TYPE>& s_feature_PE23_3,
    STREAM<W_TYPE>& s_feature_PE24_0, STREAM<W_TYPE>& s_feature_PE24_1,
    STREAM<W_TYPE>& s_feature_PE24_2, STREAM<W_TYPE>& s_feature_PE24_3,
    STREAM<W_TYPE>& s_feature_PE25_0, STREAM<W_TYPE>& s_feature_PE25_1,
    STREAM<W_TYPE>& s_feature_PE25_2, STREAM<W_TYPE>& s_feature_PE25_3,
    STREAM<W_TYPE>& s_feature_PE26_0, STREAM<W_TYPE>& s_feature_PE26_1,
    STREAM<W_TYPE>& s_feature_PE26_2, STREAM<W_TYPE>& s_feature_PE26_3,
    STREAM<W_TYPE>& s_feature_PE27_0, STREAM<W_TYPE>& s_feature_PE27_1,
    STREAM<W_TYPE>& s_feature_PE27_2, STREAM<W_TYPE>& s_feature_PE27_3,
    STREAM<W_TYPE>& s_feature_PE28_0, STREAM<W_TYPE>& s_feature_PE28_1,
    STREAM<W_TYPE>& s_feature_PE28_2, STREAM<W_TYPE>& s_feature_PE28_3);

template<const int ROW_PER_PE>
void gather_results_512PEs_216PE(
    STREAM<D_TYPE>& s_result_PE0, STREAM<D_TYPE>& s_result_PE1, 
    STREAM<D_TYPE>& s_result_PE2, STREAM<D_TYPE>& s_result_PE3, 
    STREAM<D_TYPE>& s_result_PE4, STREAM<D_TYPE>& s_result_PE5, 
    STREAM<D_TYPE>& s_result_PE6, STREAM<D_TYPE>& s_result_PE7, 
    STREAM<D_TYPE>& s_result_PE8, STREAM<D_TYPE>& s_result_PE9, 
    STREAM<D_TYPE>& s_result_PE10, STREAM<D_TYPE>& s_result_PE11, 
    STREAM<D_TYPE>& s_result_PE12, STREAM<D_TYPE>& s_result_PE13, 
    STREAM<D_TYPE>& s_result_PE14, STREAM<D_TYPE>& s_result_PE15, 
    STREAM<D_TYPE>& s_result_PE16, STREAM<D_TYPE>& s_result_PE17, 
    STREAM<D_TYPE>& s_result_PE18, STREAM<D_TYPE>& s_result_PE19, 
    STREAM<D_TYPE>& s_result_PE20, STREAM<D_TYPE>& s_result_PE21, 
    STREAM<D_TYPE>& s_result_PE22, STREAM<D_TYPE>& s_result_PE23, 
    STREAM<D_TYPE>& s_result_PE24, STREAM<D_TYPE>& s_result_PE25, 
    STREAM<D_TYPE>& s_result_PE26, STREAM<D_TYPE>& s_result_PE27, 
    STREAM<D_TYPE>& s_result_PE28, STREAM<D_TYPE>& s_result_PE29, 
    STREAM<D_TYPE>& s_result_PE30, STREAM<D_TYPE>& s_result_PE31, 
    STREAM<D_TYPE>& s_result_PE32, STREAM<D_TYPE>& s_result_PE33, 
    STREAM<D_TYPE>& s_result_PE34, STREAM<D_TYPE>& s_result_PE35, 
    STREAM<D_TYPE>& s_result_PE36, STREAM<D_TYPE>& s_result_PE37, 
    STREAM<D_TYPE>& s_result_PE38, STREAM<D_TYPE>& s_result_PE39, 
    STREAM<D_TYPE>& s_result_PE40, STREAM<D_TYPE>& s_result_PE41, 
    STREAM<D_TYPE>& s_result_PE42, STREAM<D_TYPE>& s_result_PE43, 
    STREAM<D_TYPE>& s_result_PE44, STREAM<D_TYPE>& s_result_PE45, 
    STREAM<D_TYPE>& s_result_PE46, STREAM<D_TYPE>& s_result_PE47, 
    STREAM<D_TYPE>& s_result_PE48, STREAM<D_TYPE>& s_result_PE49, 
    STREAM<D_TYPE>& s_result_PE50, STREAM<D_TYPE>& s_result_PE51, 
    STREAM<D_TYPE>& s_result_PE52, STREAM<D_TYPE>& s_result_PE53, 
    STREAM<D_TYPE>& s_result_PE54, STREAM<D_TYPE>& s_result_PE55, 
    STREAM<D_TYPE>& s_result_PE56, STREAM<D_TYPE>& s_result_PE57, 
    STREAM<D_TYPE>& s_result_PE58, STREAM<D_TYPE>& s_result_PE59, 
    STREAM<D_TYPE>& s_result_PE60, STREAM<D_TYPE>& s_result_PE61, 
    STREAM<D_TYPE>& s_result_PE62, STREAM<D_TYPE>& s_result_PE63, 
    STREAM<D_TYPE>& s_result_PE64, STREAM<D_TYPE>& s_result_PE65, 
    STREAM<D_TYPE>& s_result_PE66, STREAM<D_TYPE>& s_result_PE67, 
    STREAM<D_TYPE>& s_result_PE68, STREAM<D_TYPE>& s_result_PE69, 
    STREAM<D_TYPE>& s_result_PE70, STREAM<D_TYPE>& s_result_PE71, 
    STREAM<D_TYPE>& s_result_PE72, STREAM<D_TYPE>& s_result_PE73, 
    STREAM<D_TYPE>& s_result_PE74, STREAM<D_TYPE>& s_result_PE75, 
    STREAM<D_TYPE>& s_result_PE76, STREAM<D_TYPE>& s_result_PE77, 
    STREAM<D_TYPE>& s_result_PE78, STREAM<D_TYPE>& s_result_PE79, 
    STREAM<D_TYPE>& s_result_PE80, STREAM<D_TYPE>& s_result_PE81, 
    STREAM<D_TYPE>& s_result_PE82, STREAM<D_TYPE>& s_result_PE83, 
    STREAM<D_TYPE>& s_result_PE84, STREAM<D_TYPE>& s_result_PE85, 
    STREAM<D_TYPE>& s_result_PE86, STREAM<D_TYPE>& s_result_PE87, 
    STREAM<D_TYPE>& s_result_PE88, STREAM<D_TYPE>& s_result_PE89, 
    STREAM<D_TYPE>& s_result_PE90, STREAM<D_TYPE>& s_result_PE91, 
    STREAM<D_TYPE>& s_result_PE92, STREAM<D_TYPE>& s_result_PE93, 
    STREAM<D_TYPE>& s_result_PE94, STREAM<D_TYPE>& s_result_PE95, 
    STREAM<D_TYPE>& s_result_PE96, STREAM<D_TYPE>& s_result_PE97, 
    STREAM<D_TYPE>& s_result_PE98, STREAM<D_TYPE>& s_result_PE99, 
    STREAM<D_TYPE>& s_result_PE100, STREAM<D_TYPE>& s_result_PE101, 
    STREAM<D_TYPE>& s_result_PE102, STREAM<D_TYPE>& s_result_PE103, 
    STREAM<D_TYPE>& s_result_PE104, STREAM<D_TYPE>& s_result_PE105, 
    STREAM<D_TYPE>& s_result_PE106, STREAM<D_TYPE>& s_result_PE107, 
    STREAM<D_TYPE>& s_result_PE108, STREAM<D_TYPE>& s_result_PE109, 
    STREAM<D_TYPE>& s_result_PE110, STREAM<D_TYPE>& s_result_PE111, 
    STREAM<D_TYPE>& s_result_PE112, STREAM<D_TYPE>& s_result_PE113, 
    STREAM<D_TYPE>& s_result_PE114, STREAM<D_TYPE>& s_result_PE115, 
    STREAM<D_TYPE>& s_result_PE116, STREAM<D_TYPE>& s_result_PE117, 
    STREAM<D_TYPE>& s_result_PE118, STREAM<D_TYPE>& s_result_PE119, 
    STREAM<D_TYPE>& s_result_PE120, STREAM<D_TYPE>& s_result_PE121, 
    STREAM<D_TYPE>& s_result_PE122, STREAM<D_TYPE>& s_result_PE123, 
    STREAM<D_TYPE>& s_result_PE124, STREAM<D_TYPE>& s_result_PE125, 
    STREAM<D_TYPE>& s_result_PE126, STREAM<D_TYPE>& s_result_PE127,
    STREAM<D_TYPE>& s_result_PE128, STREAM<D_TYPE>& s_result_PE129,
    STREAM<D_TYPE>& s_result_PE130, STREAM<D_TYPE>& s_result_PE131,
    STREAM<D_TYPE>& s_result_PE132, STREAM<D_TYPE>& s_result_PE133,
    STREAM<D_TYPE>& s_result_PE134, STREAM<D_TYPE>& s_result_PE135,
    STREAM<D_TYPE>& s_result_PE136, STREAM<D_TYPE>& s_result_PE137,
    STREAM<D_TYPE>& s_result_PE138, STREAM<D_TYPE>& s_result_PE139,
    STREAM<D_TYPE>& s_result_PE140, STREAM<D_TYPE>& s_result_PE141,
    STREAM<D_TYPE>& s_result_PE142, STREAM<D_TYPE>& s_result_PE143,
    STREAM<D_TYPE>& s_result_PE144, STREAM<D_TYPE>& s_result_PE145,
    STREAM<D_TYPE>& s_result_PE146, STREAM<D_TYPE>& s_result_PE147,
    STREAM<D_TYPE>& s_result_PE148, STREAM<D_TYPE>& s_result_PE149,
    STREAM<D_TYPE>& s_result_PE150, STREAM<D_TYPE>& s_result_PE151,
    STREAM<D_TYPE>& s_result_PE152, STREAM<D_TYPE>& s_result_PE153,
    STREAM<D_TYPE>& s_result_PE154, STREAM<D_TYPE>& s_result_PE155,
    STREAM<D_TYPE>& s_result_PE156, STREAM<D_TYPE>& s_result_PE157,
    STREAM<D_TYPE>& s_result_PE158, STREAM<D_TYPE>& s_result_PE159,
    STREAM<D_TYPE>& s_result_PE160, STREAM<D_TYPE>& s_result_PE161,
    STREAM<D_TYPE>& s_result_PE162, STREAM<D_TYPE>& s_result_PE163,
    STREAM<D_TYPE>& s_result_PE164, STREAM<D_TYPE>& s_result_PE165,
    STREAM<D_TYPE>& s_result_PE166, STREAM<D_TYPE>& s_result_PE167,
    STREAM<D_TYPE>& s_result_PE168, STREAM<D_TYPE>& s_result_PE169,
    STREAM<D_TYPE>& s_result_PE170, STREAM<D_TYPE>& s_result_PE171,
    STREAM<D_TYPE>& s_result_PE172, STREAM<D_TYPE>& s_result_PE173,
    STREAM<D_TYPE>& s_result_PE174, STREAM<D_TYPE>& s_result_PE175,
    STREAM<D_TYPE>& s_result_PE176, STREAM<D_TYPE>& s_result_PE177,
    STREAM<D_TYPE>& s_result_PE178, STREAM<D_TYPE>& s_result_PE179,
    STREAM<D_TYPE>& s_result_PE180, STREAM<D_TYPE>& s_result_PE181,
    STREAM<D_TYPE>& s_result_PE182, STREAM<D_TYPE>& s_result_PE183,
    STREAM<D_TYPE>& s_result_PE184, STREAM<D_TYPE>& s_result_PE185,
    STREAM<D_TYPE>& s_result_PE186, STREAM<D_TYPE>& s_result_PE187,
    STREAM<D_TYPE>& s_result_PE188, STREAM<D_TYPE>& s_result_PE189,
    STREAM<D_TYPE>& s_result_PE190, STREAM<D_TYPE>& s_result_PE191,
    STREAM<D_TYPE>& s_result_PE192, STREAM<D_TYPE>& s_result_PE193,
    STREAM<D_TYPE>& s_result_PE194, STREAM<D_TYPE>& s_result_PE195,
    STREAM<D_TYPE>& s_result_PE196, STREAM<D_TYPE>& s_result_PE197,
    STREAM<D_TYPE>& s_result_PE198, STREAM<D_TYPE>& s_result_PE199,
    STREAM<D_TYPE>& s_result_PE200, STREAM<D_TYPE>& s_result_PE201, 
    STREAM<D_TYPE>& s_result_PE202, STREAM<D_TYPE>& s_result_PE203, 
    STREAM<D_TYPE>& s_result_PE204, STREAM<D_TYPE>& s_result_PE205, 
    STREAM<D_TYPE>& s_result_PE206, STREAM<D_TYPE>& s_result_PE207, 
    STREAM<D_TYPE>& s_result_PE208, STREAM<D_TYPE>& s_result_PE209, 
    STREAM<D_TYPE>& s_result_PE210, STREAM<D_TYPE>& s_result_PE211, 
    STREAM<D_TYPE>& s_result_PE212, STREAM<D_TYPE>& s_result_PE213, 
    STREAM<D_TYPE>& s_result_PE214, STREAM<D_TYPE>& s_result_PE215, 
    STREAM<ap_uint<512> >& s_result_all);

template<const int ROW_PER_PE>
void gather_results_512PEs_224PE(
    STREAM<D_TYPE>& s_result_PE0, STREAM<D_TYPE>& s_result_PE1, 
    STREAM<D_TYPE>& s_result_PE2, STREAM<D_TYPE>& s_result_PE3, 
    STREAM<D_TYPE>& s_result_PE4, STREAM<D_TYPE>& s_result_PE5, 
    STREAM<D_TYPE>& s_result_PE6, STREAM<D_TYPE>& s_result_PE7, 
    STREAM<D_TYPE>& s_result_PE8, STREAM<D_TYPE>& s_result_PE9, 
    STREAM<D_TYPE>& s_result_PE10, STREAM<D_TYPE>& s_result_PE11, 
    STREAM<D_TYPE>& s_result_PE12, STREAM<D_TYPE>& s_result_PE13, 
    STREAM<D_TYPE>& s_result_PE14, STREAM<D_TYPE>& s_result_PE15, 
    STREAM<D_TYPE>& s_result_PE16, STREAM<D_TYPE>& s_result_PE17, 
    STREAM<D_TYPE>& s_result_PE18, STREAM<D_TYPE>& s_result_PE19, 
    STREAM<D_TYPE>& s_result_PE20, STREAM<D_TYPE>& s_result_PE21, 
    STREAM<D_TYPE>& s_result_PE22, STREAM<D_TYPE>& s_result_PE23, 
    STREAM<D_TYPE>& s_result_PE24, STREAM<D_TYPE>& s_result_PE25, 
    STREAM<D_TYPE>& s_result_PE26, STREAM<D_TYPE>& s_result_PE27, 
    STREAM<D_TYPE>& s_result_PE28, STREAM<D_TYPE>& s_result_PE29, 
    STREAM<D_TYPE>& s_result_PE30, STREAM<D_TYPE>& s_result_PE31, 
    STREAM<D_TYPE>& s_result_PE32, STREAM<D_TYPE>& s_result_PE33, 
    STREAM<D_TYPE>& s_result_PE34, STREAM<D_TYPE>& s_result_PE35, 
    STREAM<D_TYPE>& s_result_PE36, STREAM<D_TYPE>& s_result_PE37, 
    STREAM<D_TYPE>& s_result_PE38, STREAM<D_TYPE>& s_result_PE39, 
    STREAM<D_TYPE>& s_result_PE40, STREAM<D_TYPE>& s_result_PE41, 
    STREAM<D_TYPE>& s_result_PE42, STREAM<D_TYPE>& s_result_PE43, 
    STREAM<D_TYPE>& s_result_PE44, STREAM<D_TYPE>& s_result_PE45, 
    STREAM<D_TYPE>& s_result_PE46, STREAM<D_TYPE>& s_result_PE47, 
    STREAM<D_TYPE>& s_result_PE48, STREAM<D_TYPE>& s_result_PE49, 
    STREAM<D_TYPE>& s_result_PE50, STREAM<D_TYPE>& s_result_PE51, 
    STREAM<D_TYPE>& s_result_PE52, STREAM<D_TYPE>& s_result_PE53, 
    STREAM<D_TYPE>& s_result_PE54, STREAM<D_TYPE>& s_result_PE55, 
    STREAM<D_TYPE>& s_result_PE56, STREAM<D_TYPE>& s_result_PE57, 
    STREAM<D_TYPE>& s_result_PE58, STREAM<D_TYPE>& s_result_PE59, 
    STREAM<D_TYPE>& s_result_PE60, STREAM<D_TYPE>& s_result_PE61, 
    STREAM<D_TYPE>& s_result_PE62, STREAM<D_TYPE>& s_result_PE63, 
    STREAM<D_TYPE>& s_result_PE64, STREAM<D_TYPE>& s_result_PE65, 
    STREAM<D_TYPE>& s_result_PE66, STREAM<D_TYPE>& s_result_PE67, 
    STREAM<D_TYPE>& s_result_PE68, STREAM<D_TYPE>& s_result_PE69, 
    STREAM<D_TYPE>& s_result_PE70, STREAM<D_TYPE>& s_result_PE71, 
    STREAM<D_TYPE>& s_result_PE72, STREAM<D_TYPE>& s_result_PE73, 
    STREAM<D_TYPE>& s_result_PE74, STREAM<D_TYPE>& s_result_PE75, 
    STREAM<D_TYPE>& s_result_PE76, STREAM<D_TYPE>& s_result_PE77, 
    STREAM<D_TYPE>& s_result_PE78, STREAM<D_TYPE>& s_result_PE79, 
    STREAM<D_TYPE>& s_result_PE80, STREAM<D_TYPE>& s_result_PE81, 
    STREAM<D_TYPE>& s_result_PE82, STREAM<D_TYPE>& s_result_PE83, 
    STREAM<D_TYPE>& s_result_PE84, STREAM<D_TYPE>& s_result_PE85, 
    STREAM<D_TYPE>& s_result_PE86, STREAM<D_TYPE>& s_result_PE87, 
    STREAM<D_TYPE>& s_result_PE88, STREAM<D_TYPE>& s_result_PE89, 
    STREAM<D_TYPE>& s_result_PE90, STREAM<D_TYPE>& s_result_PE91, 
    STREAM<D_TYPE>& s_result_PE92, STREAM<D_TYPE>& s_result_PE93, 
    STREAM<D_TYPE>& s_result_PE94, STREAM<D_TYPE>& s_result_PE95, 
    STREAM<D_TYPE>& s_result_PE96, STREAM<D_TYPE>& s_result_PE97, 
    STREAM<D_TYPE>& s_result_PE98, STREAM<D_TYPE>& s_result_PE99, 
    STREAM<D_TYPE>& s_result_PE100, STREAM<D_TYPE>& s_result_PE101, 
    STREAM<D_TYPE>& s_result_PE102, STREAM<D_TYPE>& s_result_PE103, 
    STREAM<D_TYPE>& s_result_PE104, STREAM<D_TYPE>& s_result_PE105, 
    STREAM<D_TYPE>& s_result_PE106, STREAM<D_TYPE>& s_result_PE107, 
    STREAM<D_TYPE>& s_result_PE108, STREAM<D_TYPE>& s_result_PE109, 
    STREAM<D_TYPE>& s_result_PE110, STREAM<D_TYPE>& s_result_PE111, 
    STREAM<D_TYPE>& s_result_PE112, STREAM<D_TYPE>& s_result_PE113, 
    STREAM<D_TYPE>& s_result_PE114, STREAM<D_TYPE>& s_result_PE115, 
    STREAM<D_TYPE>& s_result_PE116, STREAM<D_TYPE>& s_result_PE117, 
    STREAM<D_TYPE>& s_result_PE118, STREAM<D_TYPE>& s_result_PE119, 
    STREAM<D_TYPE>& s_result_PE120, STREAM<D_TYPE>& s_result_PE121, 
    STREAM<D_TYPE>& s_result_PE122, STREAM<D_TYPE>& s_result_PE123, 
    STREAM<D_TYPE>& s_result_PE124, STREAM<D_TYPE>& s_result_PE125, 
    STREAM<D_TYPE>& s_result_PE126, STREAM<D_TYPE>& s_result_PE127, 
    STREAM<D_TYPE>& s_result_PE128, STREAM<D_TYPE>& s_result_PE129,
    STREAM<D_TYPE>& s_result_PE130, STREAM<D_TYPE>& s_result_PE131,
    STREAM<D_TYPE>& s_result_PE132, STREAM<D_TYPE>& s_result_PE133,
    STREAM<D_TYPE>& s_result_PE134, STREAM<D_TYPE>& s_result_PE135,
    STREAM<D_TYPE>& s_result_PE136, STREAM<D_TYPE>& s_result_PE137,
    STREAM<D_TYPE>& s_result_PE138, STREAM<D_TYPE>& s_result_PE139,
    STREAM<D_TYPE>& s_result_PE140, STREAM<D_TYPE>& s_result_PE141,
    STREAM<D_TYPE>& s_result_PE142, STREAM<D_TYPE>& s_result_PE143,
    STREAM<D_TYPE>& s_result_PE144, STREAM<D_TYPE>& s_result_PE145,
    STREAM<D_TYPE>& s_result_PE146, STREAM<D_TYPE>& s_result_PE147,
    STREAM<D_TYPE>& s_result_PE148, STREAM<D_TYPE>& s_result_PE149,
    STREAM<D_TYPE>& s_result_PE150, STREAM<D_TYPE>& s_result_PE151,
    STREAM<D_TYPE>& s_result_PE152, STREAM<D_TYPE>& s_result_PE153,
    STREAM<D_TYPE>& s_result_PE154, STREAM<D_TYPE>& s_result_PE155,
    STREAM<D_TYPE>& s_result_PE156, STREAM<D_TYPE>& s_result_PE157,
    STREAM<D_TYPE>& s_result_PE158, STREAM<D_TYPE>& s_result_PE159,
    STREAM<D_TYPE>& s_result_PE160, STREAM<D_TYPE>& s_result_PE161,
    STREAM<D_TYPE>& s_result_PE162, STREAM<D_TYPE>& s_result_PE163,
    STREAM<D_TYPE>& s_result_PE164, STREAM<D_TYPE>& s_result_PE165,
    STREAM<D_TYPE>& s_result_PE166, STREAM<D_TYPE>& s_result_PE167,
    STREAM<D_TYPE>& s_result_PE168, STREAM<D_TYPE>& s_result_PE169,
    STREAM<D_TYPE>& s_result_PE170, STREAM<D_TYPE>& s_result_PE171,
    STREAM<D_TYPE>& s_result_PE172, STREAM<D_TYPE>& s_result_PE173,
    STREAM<D_TYPE>& s_result_PE174, STREAM<D_TYPE>& s_result_PE175,
    STREAM<D_TYPE>& s_result_PE176, STREAM<D_TYPE>& s_result_PE177,
    STREAM<D_TYPE>& s_result_PE178, STREAM<D_TYPE>& s_result_PE179,
    STREAM<D_TYPE>& s_result_PE180, STREAM<D_TYPE>& s_result_PE181,
    STREAM<D_TYPE>& s_result_PE182, STREAM<D_TYPE>& s_result_PE183,
    STREAM<D_TYPE>& s_result_PE184, STREAM<D_TYPE>& s_result_PE185,
    STREAM<D_TYPE>& s_result_PE186, STREAM<D_TYPE>& s_result_PE187,
    STREAM<D_TYPE>& s_result_PE188, STREAM<D_TYPE>& s_result_PE189,
    STREAM<D_TYPE>& s_result_PE190, STREAM<D_TYPE>& s_result_PE191,
    STREAM<D_TYPE>& s_result_PE192, STREAM<D_TYPE>& s_result_PE193,
    STREAM<D_TYPE>& s_result_PE194, STREAM<D_TYPE>& s_result_PE195,
    STREAM<D_TYPE>& s_result_PE196, STREAM<D_TYPE>& s_result_PE197,
    STREAM<D_TYPE>& s_result_PE198, STREAM<D_TYPE>& s_result_PE199,
    STREAM<D_TYPE>& s_result_PE200, STREAM<D_TYPE>& s_result_PE201, 
    STREAM<D_TYPE>& s_result_PE202, STREAM<D_TYPE>& s_result_PE203, 
    STREAM<D_TYPE>& s_result_PE204, STREAM<D_TYPE>& s_result_PE205, 
    STREAM<D_TYPE>& s_result_PE206, STREAM<D_TYPE>& s_result_PE207, 
    STREAM<D_TYPE>& s_result_PE208, STREAM<D_TYPE>& s_result_PE209, 
    STREAM<D_TYPE>& s_result_PE210, STREAM<D_TYPE>& s_result_PE211, 
    STREAM<D_TYPE>& s_result_PE212, STREAM<D_TYPE>& s_result_PE213, 
    STREAM<D_TYPE>& s_result_PE214, STREAM<D_TYPE>& s_result_PE215,
    STREAM<D_TYPE>& s_result_PE216, STREAM<D_TYPE>& s_result_PE217, 
    STREAM<D_TYPE>& s_result_PE218, STREAM<D_TYPE>& s_result_PE219, 
    STREAM<D_TYPE>& s_result_PE220, STREAM<D_TYPE>& s_result_PE221, 
    STREAM<D_TYPE>& s_result_PE222, STREAM<D_TYPE>& s_result_PE223, 
    STREAM<ap_uint<512> >& s_result_all);

template<const int ROW_PER_PE>
void gather_results_512PEs_256PE(
    STREAM<D_TYPE>& s_result_PE0, STREAM<D_TYPE>& s_result_PE1, 
    STREAM<D_TYPE>& s_result_PE2, STREAM<D_TYPE>& s_result_PE3, 
    STREAM<D_TYPE>& s_result_PE4, STREAM<D_TYPE>& s_result_PE5, 
    STREAM<D_TYPE>& s_result_PE6, STREAM<D_TYPE>& s_result_PE7, 
    STREAM<D_TYPE>& s_result_PE8, STREAM<D_TYPE>& s_result_PE9, 
    STREAM<D_TYPE>& s_result_PE10, STREAM<D_TYPE>& s_result_PE11, 
    STREAM<D_TYPE>& s_result_PE12, STREAM<D_TYPE>& s_result_PE13, 
    STREAM<D_TYPE>& s_result_PE14, STREAM<D_TYPE>& s_result_PE15, 
    STREAM<D_TYPE>& s_result_PE16, STREAM<D_TYPE>& s_result_PE17, 
    STREAM<D_TYPE>& s_result_PE18, STREAM<D_TYPE>& s_result_PE19, 
    STREAM<D_TYPE>& s_result_PE20, STREAM<D_TYPE>& s_result_PE21, 
    STREAM<D_TYPE>& s_result_PE22, STREAM<D_TYPE>& s_result_PE23, 
    STREAM<D_TYPE>& s_result_PE24, STREAM<D_TYPE>& s_result_PE25, 
    STREAM<D_TYPE>& s_result_PE26, STREAM<D_TYPE>& s_result_PE27, 
    STREAM<D_TYPE>& s_result_PE28, STREAM<D_TYPE>& s_result_PE29, 
    STREAM<D_TYPE>& s_result_PE30, STREAM<D_TYPE>& s_result_PE31, 
    STREAM<D_TYPE>& s_result_PE32, STREAM<D_TYPE>& s_result_PE33, 
    STREAM<D_TYPE>& s_result_PE34, STREAM<D_TYPE>& s_result_PE35, 
    STREAM<D_TYPE>& s_result_PE36, STREAM<D_TYPE>& s_result_PE37, 
    STREAM<D_TYPE>& s_result_PE38, STREAM<D_TYPE>& s_result_PE39, 
    STREAM<D_TYPE>& s_result_PE40, STREAM<D_TYPE>& s_result_PE41, 
    STREAM<D_TYPE>& s_result_PE42, STREAM<D_TYPE>& s_result_PE43, 
    STREAM<D_TYPE>& s_result_PE44, STREAM<D_TYPE>& s_result_PE45, 
    STREAM<D_TYPE>& s_result_PE46, STREAM<D_TYPE>& s_result_PE47, 
    STREAM<D_TYPE>& s_result_PE48, STREAM<D_TYPE>& s_result_PE49, 
    STREAM<D_TYPE>& s_result_PE50, STREAM<D_TYPE>& s_result_PE51, 
    STREAM<D_TYPE>& s_result_PE52, STREAM<D_TYPE>& s_result_PE53, 
    STREAM<D_TYPE>& s_result_PE54, STREAM<D_TYPE>& s_result_PE55, 
    STREAM<D_TYPE>& s_result_PE56, STREAM<D_TYPE>& s_result_PE57, 
    STREAM<D_TYPE>& s_result_PE58, STREAM<D_TYPE>& s_result_PE59, 
    STREAM<D_TYPE>& s_result_PE60, STREAM<D_TYPE>& s_result_PE61, 
    STREAM<D_TYPE>& s_result_PE62, STREAM<D_TYPE>& s_result_PE63, 
    STREAM<D_TYPE>& s_result_PE64, STREAM<D_TYPE>& s_result_PE65, 
    STREAM<D_TYPE>& s_result_PE66, STREAM<D_TYPE>& s_result_PE67, 
    STREAM<D_TYPE>& s_result_PE68, STREAM<D_TYPE>& s_result_PE69, 
    STREAM<D_TYPE>& s_result_PE70, STREAM<D_TYPE>& s_result_PE71, 
    STREAM<D_TYPE>& s_result_PE72, STREAM<D_TYPE>& s_result_PE73, 
    STREAM<D_TYPE>& s_result_PE74, STREAM<D_TYPE>& s_result_PE75, 
    STREAM<D_TYPE>& s_result_PE76, STREAM<D_TYPE>& s_result_PE77, 
    STREAM<D_TYPE>& s_result_PE78, STREAM<D_TYPE>& s_result_PE79, 
    STREAM<D_TYPE>& s_result_PE80, STREAM<D_TYPE>& s_result_PE81, 
    STREAM<D_TYPE>& s_result_PE82, STREAM<D_TYPE>& s_result_PE83, 
    STREAM<D_TYPE>& s_result_PE84, STREAM<D_TYPE>& s_result_PE85, 
    STREAM<D_TYPE>& s_result_PE86, STREAM<D_TYPE>& s_result_PE87, 
    STREAM<D_TYPE>& s_result_PE88, STREAM<D_TYPE>& s_result_PE89, 
    STREAM<D_TYPE>& s_result_PE90, STREAM<D_TYPE>& s_result_PE91, 
    STREAM<D_TYPE>& s_result_PE92, STREAM<D_TYPE>& s_result_PE93, 
    STREAM<D_TYPE>& s_result_PE94, STREAM<D_TYPE>& s_result_PE95, 
    STREAM<D_TYPE>& s_result_PE96, STREAM<D_TYPE>& s_result_PE97, 
    STREAM<D_TYPE>& s_result_PE98, STREAM<D_TYPE>& s_result_PE99, 
    STREAM<D_TYPE>& s_result_PE100, STREAM<D_TYPE>& s_result_PE101, 
    STREAM<D_TYPE>& s_result_PE102, STREAM<D_TYPE>& s_result_PE103, 
    STREAM<D_TYPE>& s_result_PE104, STREAM<D_TYPE>& s_result_PE105, 
    STREAM<D_TYPE>& s_result_PE106, STREAM<D_TYPE>& s_result_PE107, 
    STREAM<D_TYPE>& s_result_PE108, STREAM<D_TYPE>& s_result_PE109, 
    STREAM<D_TYPE>& s_result_PE110, STREAM<D_TYPE>& s_result_PE111, 
    STREAM<D_TYPE>& s_result_PE112, STREAM<D_TYPE>& s_result_PE113, 
    STREAM<D_TYPE>& s_result_PE114, STREAM<D_TYPE>& s_result_PE115, 
    STREAM<D_TYPE>& s_result_PE116, STREAM<D_TYPE>& s_result_PE117, 
    STREAM<D_TYPE>& s_result_PE118, STREAM<D_TYPE>& s_result_PE119, 
    STREAM<D_TYPE>& s_result_PE120, STREAM<D_TYPE>& s_result_PE121, 
    STREAM<D_TYPE>& s_result_PE122, STREAM<D_TYPE>& s_result_PE123, 
    STREAM<D_TYPE>& s_result_PE124, STREAM<D_TYPE>& s_result_PE125, 
    STREAM<D_TYPE>& s_result_PE126, STREAM<D_TYPE>& s_result_PE127, 
    STREAM<D_TYPE>& s_result_PE128, STREAM<D_TYPE>& s_result_PE129,
    STREAM<D_TYPE>& s_result_PE130, STREAM<D_TYPE>& s_result_PE131,
    STREAM<D_TYPE>& s_result_PE132, STREAM<D_TYPE>& s_result_PE133,
    STREAM<D_TYPE>& s_result_PE134, STREAM<D_TYPE>& s_result_PE135,
    STREAM<D_TYPE>& s_result_PE136, STREAM<D_TYPE>& s_result_PE137,
    STREAM<D_TYPE>& s_result_PE138, STREAM<D_TYPE>& s_result_PE139,
    STREAM<D_TYPE>& s_result_PE140, STREAM<D_TYPE>& s_result_PE141,
    STREAM<D_TYPE>& s_result_PE142, STREAM<D_TYPE>& s_result_PE143,
    STREAM<D_TYPE>& s_result_PE144, STREAM<D_TYPE>& s_result_PE145,
    STREAM<D_TYPE>& s_result_PE146, STREAM<D_TYPE>& s_result_PE147,
    STREAM<D_TYPE>& s_result_PE148, STREAM<D_TYPE>& s_result_PE149,
    STREAM<D_TYPE>& s_result_PE150, STREAM<D_TYPE>& s_result_PE151,
    STREAM<D_TYPE>& s_result_PE152, STREAM<D_TYPE>& s_result_PE153,
    STREAM<D_TYPE>& s_result_PE154, STREAM<D_TYPE>& s_result_PE155,
    STREAM<D_TYPE>& s_result_PE156, STREAM<D_TYPE>& s_result_PE157,
    STREAM<D_TYPE>& s_result_PE158, STREAM<D_TYPE>& s_result_PE159,
    STREAM<D_TYPE>& s_result_PE160, STREAM<D_TYPE>& s_result_PE161,
    STREAM<D_TYPE>& s_result_PE162, STREAM<D_TYPE>& s_result_PE163,
    STREAM<D_TYPE>& s_result_PE164, STREAM<D_TYPE>& s_result_PE165,
    STREAM<D_TYPE>& s_result_PE166, STREAM<D_TYPE>& s_result_PE167,
    STREAM<D_TYPE>& s_result_PE168, STREAM<D_TYPE>& s_result_PE169,
    STREAM<D_TYPE>& s_result_PE170, STREAM<D_TYPE>& s_result_PE171,
    STREAM<D_TYPE>& s_result_PE172, STREAM<D_TYPE>& s_result_PE173,
    STREAM<D_TYPE>& s_result_PE174, STREAM<D_TYPE>& s_result_PE175,
    STREAM<D_TYPE>& s_result_PE176, STREAM<D_TYPE>& s_result_PE177,
    STREAM<D_TYPE>& s_result_PE178, STREAM<D_TYPE>& s_result_PE179,
    STREAM<D_TYPE>& s_result_PE180, STREAM<D_TYPE>& s_result_PE181,
    STREAM<D_TYPE>& s_result_PE182, STREAM<D_TYPE>& s_result_PE183,
    STREAM<D_TYPE>& s_result_PE184, STREAM<D_TYPE>& s_result_PE185,
    STREAM<D_TYPE>& s_result_PE186, STREAM<D_TYPE>& s_result_PE187,
    STREAM<D_TYPE>& s_result_PE188, STREAM<D_TYPE>& s_result_PE189,
    STREAM<D_TYPE>& s_result_PE190, STREAM<D_TYPE>& s_result_PE191,
    STREAM<D_TYPE>& s_result_PE192, STREAM<D_TYPE>& s_result_PE193,
    STREAM<D_TYPE>& s_result_PE194, STREAM<D_TYPE>& s_result_PE195,
    STREAM<D_TYPE>& s_result_PE196, STREAM<D_TYPE>& s_result_PE197,
    STREAM<D_TYPE>& s_result_PE198, STREAM<D_TYPE>& s_result_PE199,
    STREAM<D_TYPE>& s_result_PE200, STREAM<D_TYPE>& s_result_PE201, 
    STREAM<D_TYPE>& s_result_PE202, STREAM<D_TYPE>& s_result_PE203, 
    STREAM<D_TYPE>& s_result_PE204, STREAM<D_TYPE>& s_result_PE205, 
    STREAM<D_TYPE>& s_result_PE206, STREAM<D_TYPE>& s_result_PE207, 
    STREAM<D_TYPE>& s_result_PE208, STREAM<D_TYPE>& s_result_PE209, 
    STREAM<D_TYPE>& s_result_PE210, STREAM<D_TYPE>& s_result_PE211, 
    STREAM<D_TYPE>& s_result_PE212, STREAM<D_TYPE>& s_result_PE213, 
    STREAM<D_TYPE>& s_result_PE214, STREAM<D_TYPE>& s_result_PE215,
    STREAM<D_TYPE>& s_result_PE216, STREAM<D_TYPE>& s_result_PE217, 
    STREAM<D_TYPE>& s_result_PE218, STREAM<D_TYPE>& s_result_PE219, 
    STREAM<D_TYPE>& s_result_PE220, STREAM<D_TYPE>& s_result_PE221, 
    STREAM<D_TYPE>& s_result_PE222, STREAM<D_TYPE>& s_result_PE223, 
    STREAM<D_TYPE>& s_result_PE224, STREAM<D_TYPE>& s_result_PE225, 
    STREAM<D_TYPE>& s_result_PE226, STREAM<D_TYPE>& s_result_PE227,
    STREAM<D_TYPE>& s_result_PE228, STREAM<D_TYPE>& s_result_PE229,
    STREAM<D_TYPE>& s_result_PE230, STREAM<D_TYPE>& s_result_PE231,
    STREAM<D_TYPE>& s_result_PE232, STREAM<D_TYPE>& s_result_PE233,
    STREAM<D_TYPE>& s_result_PE234, STREAM<D_TYPE>& s_result_PE235,
    STREAM<D_TYPE>& s_result_PE236, STREAM<D_TYPE>& s_result_PE237,
    STREAM<D_TYPE>& s_result_PE238, STREAM<D_TYPE>& s_result_PE239,
    STREAM<D_TYPE>& s_result_PE240, STREAM<D_TYPE>& s_result_PE241,
    STREAM<D_TYPE>& s_result_PE242, STREAM<D_TYPE>& s_result_PE243,
    STREAM<D_TYPE>& s_result_PE244, STREAM<D_TYPE>& s_result_PE245,
    STREAM<D_TYPE>& s_result_PE246, STREAM<D_TYPE>& s_result_PE247,
    STREAM<D_TYPE>& s_result_PE248, STREAM<D_TYPE>& s_result_PE249,
    STREAM<D_TYPE>& s_result_PE250, STREAM<D_TYPE>& s_result_PE251,
    STREAM<D_TYPE>& s_result_PE252, STREAM<D_TYPE>& s_result_PE253,
    STREAM<D_TYPE>& s_result_PE254, STREAM<D_TYPE>& s_result_PE255,
    STREAM<ap_uint<512> >& s_result_all);

template<const int ROW_PER_PE>
void gather_results_48PEs(
    STREAM<D_TYPE>& s_result_PE0, STREAM<D_TYPE>& s_result_PE1, 
    STREAM<D_TYPE>& s_result_PE2, STREAM<D_TYPE>& s_result_PE3, 
    STREAM<D_TYPE>& s_result_PE4, STREAM<D_TYPE>& s_result_PE5, 
    STREAM<D_TYPE>& s_result_PE6, STREAM<D_TYPE>& s_result_PE7, 
    STREAM<D_TYPE>& s_result_PE8, STREAM<D_TYPE>& s_result_PE9, 
    STREAM<D_TYPE>& s_result_PE10, STREAM<D_TYPE>& s_result_PE11, 
    STREAM<D_TYPE>& s_result_PE12, STREAM<D_TYPE>& s_result_PE13, 
    STREAM<D_TYPE>& s_result_PE14, STREAM<D_TYPE>& s_result_PE15, 
    STREAM<D_TYPE>& s_result_PE16, STREAM<D_TYPE>& s_result_PE17, 
    STREAM<D_TYPE>& s_result_PE18, STREAM<D_TYPE>& s_result_PE19, 
    STREAM<D_TYPE>& s_result_PE20, STREAM<D_TYPE>& s_result_PE21, 
    STREAM<D_TYPE>& s_result_PE22, STREAM<D_TYPE>& s_result_PE23, 
    STREAM<D_TYPE>& s_result_PE24, STREAM<D_TYPE>& s_result_PE25, 
    STREAM<D_TYPE>& s_result_PE26, STREAM<D_TYPE>& s_result_PE27, 
    STREAM<D_TYPE>& s_result_PE28, STREAM<D_TYPE>& s_result_PE29, 
    STREAM<D_TYPE>& s_result_PE30, STREAM<D_TYPE>& s_result_PE31, 
    STREAM<D_TYPE>& s_result_PE32, STREAM<D_TYPE>& s_result_PE33, 
    STREAM<D_TYPE>& s_result_PE34, STREAM<D_TYPE>& s_result_PE35, 
    STREAM<D_TYPE>& s_result_PE36, STREAM<D_TYPE>& s_result_PE37, 
    STREAM<D_TYPE>& s_result_PE38, STREAM<D_TYPE>& s_result_PE39, 
    STREAM<D_TYPE>& s_result_PE40, STREAM<D_TYPE>& s_result_PE41, 
    STREAM<D_TYPE>& s_result_PE42, STREAM<D_TYPE>& s_result_PE43, 
    STREAM<D_TYPE>& s_result_PE44, STREAM<D_TYPE>& s_result_PE45, 
    STREAM<D_TYPE>& s_result_PE46, STREAM<D_TYPE>& s_result_PE47, 
    STREAM<ap_uint<512> >& s_result_all);

template<const int ROW_PER_PE>
void gather_results_32PEs(
    STREAM<D_TYPE>& s_result_PE0, STREAM<D_TYPE>& s_result_PE1, 
    STREAM<D_TYPE>& s_result_PE2, STREAM<D_TYPE>& s_result_PE3, 
    STREAM<D_TYPE>& s_result_PE4, STREAM<D_TYPE>& s_result_PE5, 
    STREAM<D_TYPE>& s_result_PE6, STREAM<D_TYPE>& s_result_PE7, 
    STREAM<D_TYPE>& s_result_PE8, STREAM<D_TYPE>& s_result_PE9, 
    STREAM<D_TYPE>& s_result_PE10, STREAM<D_TYPE>& s_result_PE11, 
    STREAM<D_TYPE>& s_result_PE12, STREAM<D_TYPE>& s_result_PE13, 
    STREAM<D_TYPE>& s_result_PE14, STREAM<D_TYPE>& s_result_PE15, 
    STREAM<D_TYPE>& s_result_PE16, STREAM<D_TYPE>& s_result_PE17, 
    STREAM<D_TYPE>& s_result_PE18, STREAM<D_TYPE>& s_result_PE19, 
    STREAM<D_TYPE>& s_result_PE20, STREAM<D_TYPE>& s_result_PE21, 
    STREAM<D_TYPE>& s_result_PE22, STREAM<D_TYPE>& s_result_PE23, 
    STREAM<D_TYPE>& s_result_PE24, STREAM<D_TYPE>& s_result_PE25, 
    STREAM<D_TYPE>& s_result_PE26, STREAM<D_TYPE>& s_result_PE27, 
    STREAM<D_TYPE>& s_result_PE28, STREAM<D_TYPE>& s_result_PE29, 
    STREAM<D_TYPE>& s_result_PE30, STREAM<D_TYPE>& s_result_PE31, 
    STREAM<ap_uint<512> >& s_result_all);

template<const int ROW_PER_PE>
void gather_results_208PEs(
    STREAM<D_TYPE>& s_result_PE0, STREAM<D_TYPE>& s_result_PE1, 
    STREAM<D_TYPE>& s_result_PE2, STREAM<D_TYPE>& s_result_PE3, 
    STREAM<D_TYPE>& s_result_PE4, STREAM<D_TYPE>& s_result_PE5, 
    STREAM<D_TYPE>& s_result_PE6, STREAM<D_TYPE>& s_result_PE7, 
    STREAM<D_TYPE>& s_result_PE8, STREAM<D_TYPE>& s_result_PE9, 
    STREAM<D_TYPE>& s_result_PE10, STREAM<D_TYPE>& s_result_PE11, 
    STREAM<D_TYPE>& s_result_PE12, STREAM<D_TYPE>& s_result_PE13, 
    STREAM<D_TYPE>& s_result_PE14, STREAM<D_TYPE>& s_result_PE15, 
    STREAM<D_TYPE>& s_result_PE16, STREAM<D_TYPE>& s_result_PE17, 
    STREAM<D_TYPE>& s_result_PE18, STREAM<D_TYPE>& s_result_PE19, 
    STREAM<D_TYPE>& s_result_PE20, STREAM<D_TYPE>& s_result_PE21, 
    STREAM<D_TYPE>& s_result_PE22, STREAM<D_TYPE>& s_result_PE23, 
    STREAM<D_TYPE>& s_result_PE24, STREAM<D_TYPE>& s_result_PE25, 
    STREAM<D_TYPE>& s_result_PE26, STREAM<D_TYPE>& s_result_PE27, 
    STREAM<D_TYPE>& s_result_PE28, STREAM<D_TYPE>& s_result_PE29, 
    STREAM<D_TYPE>& s_result_PE30, STREAM<D_TYPE>& s_result_PE31, 
    STREAM<D_TYPE>& s_result_PE32, STREAM<D_TYPE>& s_result_PE33, 
    STREAM<D_TYPE>& s_result_PE34, STREAM<D_TYPE>& s_result_PE35, 
    STREAM<D_TYPE>& s_result_PE36, STREAM<D_TYPE>& s_result_PE37, 
    STREAM<D_TYPE>& s_result_PE38, STREAM<D_TYPE>& s_result_PE39, 
    STREAM<D_TYPE>& s_result_PE40, STREAM<D_TYPE>& s_result_PE41, 
    STREAM<D_TYPE>& s_result_PE42, STREAM<D_TYPE>& s_result_PE43, 
    STREAM<D_TYPE>& s_result_PE44, STREAM<D_TYPE>& s_result_PE45, 
    STREAM<D_TYPE>& s_result_PE46, STREAM<D_TYPE>& s_result_PE47, 
    STREAM<D_TYPE>& s_result_PE48, STREAM<D_TYPE>& s_result_PE49, 
    STREAM<D_TYPE>& s_result_PE50, STREAM<D_TYPE>& s_result_PE51, 
    STREAM<D_TYPE>& s_result_PE52, STREAM<D_TYPE>& s_result_PE53, 
    STREAM<D_TYPE>& s_result_PE54, STREAM<D_TYPE>& s_result_PE55, 
    STREAM<D_TYPE>& s_result_PE56, STREAM<D_TYPE>& s_result_PE57, 
    STREAM<D_TYPE>& s_result_PE58, STREAM<D_TYPE>& s_result_PE59, 
    STREAM<D_TYPE>& s_result_PE60, STREAM<D_TYPE>& s_result_PE61, 
    STREAM<D_TYPE>& s_result_PE62, STREAM<D_TYPE>& s_result_PE63, 
    STREAM<D_TYPE>& s_result_PE64, STREAM<D_TYPE>& s_result_PE65, 
    STREAM<D_TYPE>& s_result_PE66, STREAM<D_TYPE>& s_result_PE67, 
    STREAM<D_TYPE>& s_result_PE68, STREAM<D_TYPE>& s_result_PE69, 
    STREAM<D_TYPE>& s_result_PE70, STREAM<D_TYPE>& s_result_PE71, 
    STREAM<D_TYPE>& s_result_PE72, STREAM<D_TYPE>& s_result_PE73, 
    STREAM<D_TYPE>& s_result_PE74, STREAM<D_TYPE>& s_result_PE75, 
    STREAM<D_TYPE>& s_result_PE76, STREAM<D_TYPE>& s_result_PE77, 
    STREAM<D_TYPE>& s_result_PE78, STREAM<D_TYPE>& s_result_PE79, 
    STREAM<D_TYPE>& s_result_PE80, STREAM<D_TYPE>& s_result_PE81, 
    STREAM<D_TYPE>& s_result_PE82, STREAM<D_TYPE>& s_result_PE83, 
    STREAM<D_TYPE>& s_result_PE84, STREAM<D_TYPE>& s_result_PE85, 
    STREAM<D_TYPE>& s_result_PE86, STREAM<D_TYPE>& s_result_PE87, 
    STREAM<D_TYPE>& s_result_PE88, STREAM<D_TYPE>& s_result_PE89, 
    STREAM<D_TYPE>& s_result_PE90, STREAM<D_TYPE>& s_result_PE91, 
    STREAM<D_TYPE>& s_result_PE92, STREAM<D_TYPE>& s_result_PE93, 
    STREAM<D_TYPE>& s_result_PE94, STREAM<D_TYPE>& s_result_PE95, 
    STREAM<D_TYPE>& s_result_PE96, STREAM<D_TYPE>& s_result_PE97, 
    STREAM<D_TYPE>& s_result_PE98, STREAM<D_TYPE>& s_result_PE99, 
    STREAM<D_TYPE>& s_result_PE100, STREAM<D_TYPE>& s_result_PE101, 
    STREAM<D_TYPE>& s_result_PE102, STREAM<D_TYPE>& s_result_PE103, 
    STREAM<D_TYPE>& s_result_PE104, STREAM<D_TYPE>& s_result_PE105, 
    STREAM<D_TYPE>& s_result_PE106, STREAM<D_TYPE>& s_result_PE107, 
    STREAM<D_TYPE>& s_result_PE108, STREAM<D_TYPE>& s_result_PE109, 
    STREAM<D_TYPE>& s_result_PE110, STREAM<D_TYPE>& s_result_PE111, 
    STREAM<D_TYPE>& s_result_PE112, STREAM<D_TYPE>& s_result_PE113, 
    STREAM<D_TYPE>& s_result_PE114, STREAM<D_TYPE>& s_result_PE115, 
    STREAM<D_TYPE>& s_result_PE116, STREAM<D_TYPE>& s_result_PE117, 
    STREAM<D_TYPE>& s_result_PE118, STREAM<D_TYPE>& s_result_PE119, 
    STREAM<D_TYPE>& s_result_PE120, STREAM<D_TYPE>& s_result_PE121, 
    STREAM<D_TYPE>& s_result_PE122, STREAM<D_TYPE>& s_result_PE123, 
    STREAM<D_TYPE>& s_result_PE124, STREAM<D_TYPE>& s_result_PE125, 
    STREAM<D_TYPE>& s_result_PE126, STREAM<D_TYPE>& s_result_PE127, 
    STREAM<D_TYPE>& s_result_PE128, STREAM<D_TYPE>& s_result_PE129,
    STREAM<D_TYPE>& s_result_PE130, STREAM<D_TYPE>& s_result_PE131,
    STREAM<D_TYPE>& s_result_PE132, STREAM<D_TYPE>& s_result_PE133,
    STREAM<D_TYPE>& s_result_PE134, STREAM<D_TYPE>& s_result_PE135,
    STREAM<D_TYPE>& s_result_PE136, STREAM<D_TYPE>& s_result_PE137,
    STREAM<D_TYPE>& s_result_PE138, STREAM<D_TYPE>& s_result_PE139,
    STREAM<D_TYPE>& s_result_PE140, STREAM<D_TYPE>& s_result_PE141,
    STREAM<D_TYPE>& s_result_PE142, STREAM<D_TYPE>& s_result_PE143,
    STREAM<D_TYPE>& s_result_PE144, STREAM<D_TYPE>& s_result_PE145,
    STREAM<D_TYPE>& s_result_PE146, STREAM<D_TYPE>& s_result_PE147,
    STREAM<D_TYPE>& s_result_PE148, STREAM<D_TYPE>& s_result_PE149,
    STREAM<D_TYPE>& s_result_PE150, STREAM<D_TYPE>& s_result_PE151,
    STREAM<D_TYPE>& s_result_PE152, STREAM<D_TYPE>& s_result_PE153,
    STREAM<D_TYPE>& s_result_PE154, STREAM<D_TYPE>& s_result_PE155,
    STREAM<D_TYPE>& s_result_PE156, STREAM<D_TYPE>& s_result_PE157,
    STREAM<D_TYPE>& s_result_PE158, STREAM<D_TYPE>& s_result_PE159,
    STREAM<D_TYPE>& s_result_PE160, STREAM<D_TYPE>& s_result_PE161,
    STREAM<D_TYPE>& s_result_PE162, STREAM<D_TYPE>& s_result_PE163,
    STREAM<D_TYPE>& s_result_PE164, STREAM<D_TYPE>& s_result_PE165,
    STREAM<D_TYPE>& s_result_PE166, STREAM<D_TYPE>& s_result_PE167,
    STREAM<D_TYPE>& s_result_PE168, STREAM<D_TYPE>& s_result_PE169,
    STREAM<D_TYPE>& s_result_PE170, STREAM<D_TYPE>& s_result_PE171,
    STREAM<D_TYPE>& s_result_PE172, STREAM<D_TYPE>& s_result_PE173,
    STREAM<D_TYPE>& s_result_PE174, STREAM<D_TYPE>& s_result_PE175,
    STREAM<D_TYPE>& s_result_PE176, STREAM<D_TYPE>& s_result_PE177,
    STREAM<D_TYPE>& s_result_PE178, STREAM<D_TYPE>& s_result_PE179,
    STREAM<D_TYPE>& s_result_PE180, STREAM<D_TYPE>& s_result_PE181,
    STREAM<D_TYPE>& s_result_PE182, STREAM<D_TYPE>& s_result_PE183,
    STREAM<D_TYPE>& s_result_PE184, STREAM<D_TYPE>& s_result_PE185,
    STREAM<D_TYPE>& s_result_PE186, STREAM<D_TYPE>& s_result_PE187,
    STREAM<D_TYPE>& s_result_PE188, STREAM<D_TYPE>& s_result_PE189,
    STREAM<D_TYPE>& s_result_PE190, STREAM<D_TYPE>& s_result_PE191,
    STREAM<D_TYPE>& s_result_PE192, STREAM<D_TYPE>& s_result_PE193,
    STREAM<D_TYPE>& s_result_PE194, STREAM<D_TYPE>& s_result_PE195,
    STREAM<D_TYPE>& s_result_PE196, STREAM<D_TYPE>& s_result_PE197,
    STREAM<D_TYPE>& s_result_PE198, STREAM<D_TYPE>& s_result_PE199,
    STREAM<D_TYPE>& s_result_PE200, STREAM<D_TYPE>& s_result_PE201, 
    STREAM<D_TYPE>& s_result_PE202, STREAM<D_TYPE>& s_result_PE203, 
    STREAM<D_TYPE>& s_result_PE204, STREAM<D_TYPE>& s_result_PE205, 
    STREAM<D_TYPE>& s_result_PE206, STREAM<D_TYPE>& s_result_PE207, 
    STREAM<ap_uint<512> >& s_result_all);

template<const int ROW_PER_PE>
void gather_results_416PEs(
    STREAM<D_TYPE>& s_result_PE0, STREAM<D_TYPE>& s_result_PE1, 
    STREAM<D_TYPE>& s_result_PE2, STREAM<D_TYPE>& s_result_PE3, 
    STREAM<D_TYPE>& s_result_PE4, STREAM<D_TYPE>& s_result_PE5, 
    STREAM<D_TYPE>& s_result_PE6, STREAM<D_TYPE>& s_result_PE7, 
    STREAM<D_TYPE>& s_result_PE8, STREAM<D_TYPE>& s_result_PE9, 
    STREAM<D_TYPE>& s_result_PE10, STREAM<D_TYPE>& s_result_PE11, 
    STREAM<D_TYPE>& s_result_PE12, STREAM<D_TYPE>& s_result_PE13, 
    STREAM<D_TYPE>& s_result_PE14, STREAM<D_TYPE>& s_result_PE15, 
    STREAM<D_TYPE>& s_result_PE16, STREAM<D_TYPE>& s_result_PE17, 
    STREAM<D_TYPE>& s_result_PE18, STREAM<D_TYPE>& s_result_PE19, 
    STREAM<D_TYPE>& s_result_PE20, STREAM<D_TYPE>& s_result_PE21, 
    STREAM<D_TYPE>& s_result_PE22, STREAM<D_TYPE>& s_result_PE23, 
    STREAM<D_TYPE>& s_result_PE24, STREAM<D_TYPE>& s_result_PE25, 
    STREAM<D_TYPE>& s_result_PE26, STREAM<D_TYPE>& s_result_PE27, 
    STREAM<D_TYPE>& s_result_PE28, STREAM<D_TYPE>& s_result_PE29, 
    STREAM<D_TYPE>& s_result_PE30, STREAM<D_TYPE>& s_result_PE31, 
    STREAM<D_TYPE>& s_result_PE32, STREAM<D_TYPE>& s_result_PE33, 
    STREAM<D_TYPE>& s_result_PE34, STREAM<D_TYPE>& s_result_PE35, 
    STREAM<D_TYPE>& s_result_PE36, STREAM<D_TYPE>& s_result_PE37, 
    STREAM<D_TYPE>& s_result_PE38, STREAM<D_TYPE>& s_result_PE39, 
    STREAM<D_TYPE>& s_result_PE40, STREAM<D_TYPE>& s_result_PE41, 
    STREAM<D_TYPE>& s_result_PE42, STREAM<D_TYPE>& s_result_PE43, 
    STREAM<D_TYPE>& s_result_PE44, STREAM<D_TYPE>& s_result_PE45, 
    STREAM<D_TYPE>& s_result_PE46, STREAM<D_TYPE>& s_result_PE47, 
    STREAM<D_TYPE>& s_result_PE48, STREAM<D_TYPE>& s_result_PE49, 
    STREAM<D_TYPE>& s_result_PE50, STREAM<D_TYPE>& s_result_PE51, 
    STREAM<D_TYPE>& s_result_PE52, STREAM<D_TYPE>& s_result_PE53, 
    STREAM<D_TYPE>& s_result_PE54, STREAM<D_TYPE>& s_result_PE55, 
    STREAM<D_TYPE>& s_result_PE56, STREAM<D_TYPE>& s_result_PE57, 
    STREAM<D_TYPE>& s_result_PE58, STREAM<D_TYPE>& s_result_PE59, 
    STREAM<D_TYPE>& s_result_PE60, STREAM<D_TYPE>& s_result_PE61, 
    STREAM<D_TYPE>& s_result_PE62, STREAM<D_TYPE>& s_result_PE63, 
    STREAM<D_TYPE>& s_result_PE64, STREAM<D_TYPE>& s_result_PE65, 
    STREAM<D_TYPE>& s_result_PE66, STREAM<D_TYPE>& s_result_PE67, 
    STREAM<D_TYPE>& s_result_PE68, STREAM<D_TYPE>& s_result_PE69, 
    STREAM<D_TYPE>& s_result_PE70, STREAM<D_TYPE>& s_result_PE71, 
    STREAM<D_TYPE>& s_result_PE72, STREAM<D_TYPE>& s_result_PE73, 
    STREAM<D_TYPE>& s_result_PE74, STREAM<D_TYPE>& s_result_PE75, 
    STREAM<D_TYPE>& s_result_PE76, STREAM<D_TYPE>& s_result_PE77, 
    STREAM<D_TYPE>& s_result_PE78, STREAM<D_TYPE>& s_result_PE79, 
    STREAM<D_TYPE>& s_result_PE80, STREAM<D_TYPE>& s_result_PE81, 
    STREAM<D_TYPE>& s_result_PE82, STREAM<D_TYPE>& s_result_PE83, 
    STREAM<D_TYPE>& s_result_PE84, STREAM<D_TYPE>& s_result_PE85, 
    STREAM<D_TYPE>& s_result_PE86, STREAM<D_TYPE>& s_result_PE87, 
    STREAM<D_TYPE>& s_result_PE88, STREAM<D_TYPE>& s_result_PE89, 
    STREAM<D_TYPE>& s_result_PE90, STREAM<D_TYPE>& s_result_PE91, 
    STREAM<D_TYPE>& s_result_PE92, STREAM<D_TYPE>& s_result_PE93, 
    STREAM<D_TYPE>& s_result_PE94, STREAM<D_TYPE>& s_result_PE95, 
    STREAM<D_TYPE>& s_result_PE96, STREAM<D_TYPE>& s_result_PE97, 
    STREAM<D_TYPE>& s_result_PE98, STREAM<D_TYPE>& s_result_PE99, 
    STREAM<D_TYPE>& s_result_PE100, STREAM<D_TYPE>& s_result_PE101, 
    STREAM<D_TYPE>& s_result_PE102, STREAM<D_TYPE>& s_result_PE103, 
    STREAM<D_TYPE>& s_result_PE104, STREAM<D_TYPE>& s_result_PE105, 
    STREAM<D_TYPE>& s_result_PE106, STREAM<D_TYPE>& s_result_PE107, 
    STREAM<D_TYPE>& s_result_PE108, STREAM<D_TYPE>& s_result_PE109, 
    STREAM<D_TYPE>& s_result_PE110, STREAM<D_TYPE>& s_result_PE111, 
    STREAM<D_TYPE>& s_result_PE112, STREAM<D_TYPE>& s_result_PE113, 
    STREAM<D_TYPE>& s_result_PE114, STREAM<D_TYPE>& s_result_PE115, 
    STREAM<D_TYPE>& s_result_PE116, STREAM<D_TYPE>& s_result_PE117, 
    STREAM<D_TYPE>& s_result_PE118, STREAM<D_TYPE>& s_result_PE119, 
    STREAM<D_TYPE>& s_result_PE120, STREAM<D_TYPE>& s_result_PE121, 
    STREAM<D_TYPE>& s_result_PE122, STREAM<D_TYPE>& s_result_PE123, 
    STREAM<D_TYPE>& s_result_PE124, STREAM<D_TYPE>& s_result_PE125, 
    STREAM<D_TYPE>& s_result_PE126, STREAM<D_TYPE>& s_result_PE127, 
    STREAM<D_TYPE>& s_result_PE128, STREAM<D_TYPE>& s_result_PE129,
    STREAM<D_TYPE>& s_result_PE130, STREAM<D_TYPE>& s_result_PE131,
    STREAM<D_TYPE>& s_result_PE132, STREAM<D_TYPE>& s_result_PE133,
    STREAM<D_TYPE>& s_result_PE134, STREAM<D_TYPE>& s_result_PE135,
    STREAM<D_TYPE>& s_result_PE136, STREAM<D_TYPE>& s_result_PE137,
    STREAM<D_TYPE>& s_result_PE138, STREAM<D_TYPE>& s_result_PE139,
    STREAM<D_TYPE>& s_result_PE140, STREAM<D_TYPE>& s_result_PE141,
    STREAM<D_TYPE>& s_result_PE142, STREAM<D_TYPE>& s_result_PE143,
    STREAM<D_TYPE>& s_result_PE144, STREAM<D_TYPE>& s_result_PE145,
    STREAM<D_TYPE>& s_result_PE146, STREAM<D_TYPE>& s_result_PE147,
    STREAM<D_TYPE>& s_result_PE148, STREAM<D_TYPE>& s_result_PE149,
    STREAM<D_TYPE>& s_result_PE150, STREAM<D_TYPE>& s_result_PE151,
    STREAM<D_TYPE>& s_result_PE152, STREAM<D_TYPE>& s_result_PE153,
    STREAM<D_TYPE>& s_result_PE154, STREAM<D_TYPE>& s_result_PE155,
    STREAM<D_TYPE>& s_result_PE156, STREAM<D_TYPE>& s_result_PE157,
    STREAM<D_TYPE>& s_result_PE158, STREAM<D_TYPE>& s_result_PE159,
    STREAM<D_TYPE>& s_result_PE160, STREAM<D_TYPE>& s_result_PE161,
    STREAM<D_TYPE>& s_result_PE162, STREAM<D_TYPE>& s_result_PE163,
    STREAM<D_TYPE>& s_result_PE164, STREAM<D_TYPE>& s_result_PE165,
    STREAM<D_TYPE>& s_result_PE166, STREAM<D_TYPE>& s_result_PE167,
    STREAM<D_TYPE>& s_result_PE168, STREAM<D_TYPE>& s_result_PE169,
    STREAM<D_TYPE>& s_result_PE170, STREAM<D_TYPE>& s_result_PE171,
    STREAM<D_TYPE>& s_result_PE172, STREAM<D_TYPE>& s_result_PE173,
    STREAM<D_TYPE>& s_result_PE174, STREAM<D_TYPE>& s_result_PE175,
    STREAM<D_TYPE>& s_result_PE176, STREAM<D_TYPE>& s_result_PE177,
    STREAM<D_TYPE>& s_result_PE178, STREAM<D_TYPE>& s_result_PE179,
    STREAM<D_TYPE>& s_result_PE180, STREAM<D_TYPE>& s_result_PE181,
    STREAM<D_TYPE>& s_result_PE182, STREAM<D_TYPE>& s_result_PE183,
    STREAM<D_TYPE>& s_result_PE184, STREAM<D_TYPE>& s_result_PE185,
    STREAM<D_TYPE>& s_result_PE186, STREAM<D_TYPE>& s_result_PE187,
    STREAM<D_TYPE>& s_result_PE188, STREAM<D_TYPE>& s_result_PE189,
    STREAM<D_TYPE>& s_result_PE190, STREAM<D_TYPE>& s_result_PE191,
    STREAM<D_TYPE>& s_result_PE192, STREAM<D_TYPE>& s_result_PE193,
    STREAM<D_TYPE>& s_result_PE194, STREAM<D_TYPE>& s_result_PE195,
    STREAM<D_TYPE>& s_result_PE196, STREAM<D_TYPE>& s_result_PE197,
    STREAM<D_TYPE>& s_result_PE198, STREAM<D_TYPE>& s_result_PE199,
    STREAM<D_TYPE>& s_result_PE200, STREAM<D_TYPE>& s_result_PE201, 
    STREAM<D_TYPE>& s_result_PE202, STREAM<D_TYPE>& s_result_PE203, 
    STREAM<D_TYPE>& s_result_PE204, STREAM<D_TYPE>& s_result_PE205, 
    STREAM<D_TYPE>& s_result_PE206, STREAM<D_TYPE>& s_result_PE207, 
    STREAM<D_TYPE>& s_result_PE208, STREAM<D_TYPE>& s_result_PE209, 
    STREAM<D_TYPE>& s_result_PE210, STREAM<D_TYPE>& s_result_PE211, 
    STREAM<D_TYPE>& s_result_PE212, STREAM<D_TYPE>& s_result_PE213, 
    STREAM<D_TYPE>& s_result_PE214, STREAM<D_TYPE>& s_result_PE215,
    STREAM<D_TYPE>& s_result_PE216, STREAM<D_TYPE>& s_result_PE217, 
    STREAM<D_TYPE>& s_result_PE218, STREAM<D_TYPE>& s_result_PE219, 
    STREAM<D_TYPE>& s_result_PE220, STREAM<D_TYPE>& s_result_PE221, 
    STREAM<D_TYPE>& s_result_PE222, STREAM<D_TYPE>& s_result_PE223, 
    STREAM<D_TYPE>& s_result_PE224, STREAM<D_TYPE>& s_result_PE225, 
    STREAM<D_TYPE>& s_result_PE226, STREAM<D_TYPE>& s_result_PE227,
    STREAM<D_TYPE>& s_result_PE228, STREAM<D_TYPE>& s_result_PE229,
    STREAM<D_TYPE>& s_result_PE230, STREAM<D_TYPE>& s_result_PE231,
    STREAM<D_TYPE>& s_result_PE232, STREAM<D_TYPE>& s_result_PE233,
    STREAM<D_TYPE>& s_result_PE234, STREAM<D_TYPE>& s_result_PE235,
    STREAM<D_TYPE>& s_result_PE236, STREAM<D_TYPE>& s_result_PE237,
    STREAM<D_TYPE>& s_result_PE238, STREAM<D_TYPE>& s_result_PE239,
    STREAM<D_TYPE>& s_result_PE240, STREAM<D_TYPE>& s_result_PE241,
    STREAM<D_TYPE>& s_result_PE242, STREAM<D_TYPE>& s_result_PE243,
    STREAM<D_TYPE>& s_result_PE244, STREAM<D_TYPE>& s_result_PE245,
    STREAM<D_TYPE>& s_result_PE246, STREAM<D_TYPE>& s_result_PE247,
    STREAM<D_TYPE>& s_result_PE248, STREAM<D_TYPE>& s_result_PE249,
    STREAM<D_TYPE>& s_result_PE250, STREAM<D_TYPE>& s_result_PE251,
    STREAM<D_TYPE>& s_result_PE252, STREAM<D_TYPE>& s_result_PE253,
    STREAM<D_TYPE>& s_result_PE254, STREAM<D_TYPE>& s_result_PE255,
    STREAM<D_TYPE>& s_result_PE256, STREAM<D_TYPE>& s_result_PE257,
    STREAM<D_TYPE>& s_result_PE258, STREAM<D_TYPE>& s_result_PE259,
    STREAM<D_TYPE>& s_result_PE260, STREAM<D_TYPE>& s_result_PE261,
    STREAM<D_TYPE>& s_result_PE262, STREAM<D_TYPE>& s_result_PE263,
    STREAM<D_TYPE>& s_result_PE264, STREAM<D_TYPE>& s_result_PE265,
    STREAM<D_TYPE>& s_result_PE266, STREAM<D_TYPE>& s_result_PE267,
    STREAM<D_TYPE>& s_result_PE268, STREAM<D_TYPE>& s_result_PE269,
    STREAM<D_TYPE>& s_result_PE270, STREAM<D_TYPE>& s_result_PE271,
    STREAM<D_TYPE>& s_result_PE272, STREAM<D_TYPE>& s_result_PE273,
    STREAM<D_TYPE>& s_result_PE274, STREAM<D_TYPE>& s_result_PE275,
    STREAM<D_TYPE>& s_result_PE276, STREAM<D_TYPE>& s_result_PE277,
    STREAM<D_TYPE>& s_result_PE278, STREAM<D_TYPE>& s_result_PE279,
    STREAM<D_TYPE>& s_result_PE280, STREAM<D_TYPE>& s_result_PE281,
    STREAM<D_TYPE>& s_result_PE282, STREAM<D_TYPE>& s_result_PE283,
    STREAM<D_TYPE>& s_result_PE284, STREAM<D_TYPE>& s_result_PE285,
    STREAM<D_TYPE>& s_result_PE286, STREAM<D_TYPE>& s_result_PE287,
    STREAM<D_TYPE>& s_result_PE288, STREAM<D_TYPE>& s_result_PE289,
    STREAM<D_TYPE>& s_result_PE290, STREAM<D_TYPE>& s_result_PE291,
    STREAM<D_TYPE>& s_result_PE292, STREAM<D_TYPE>& s_result_PE293,
    STREAM<D_TYPE>& s_result_PE294, STREAM<D_TYPE>& s_result_PE295,
    STREAM<D_TYPE>& s_result_PE296, STREAM<D_TYPE>& s_result_PE297,
    STREAM<D_TYPE>& s_result_PE298, STREAM<D_TYPE>& s_result_PE299,
    STREAM<D_TYPE>& s_result_PE300, STREAM<D_TYPE>& s_result_PE301,
    STREAM<D_TYPE>& s_result_PE302, STREAM<D_TYPE>& s_result_PE303,
    STREAM<D_TYPE>& s_result_PE304, STREAM<D_TYPE>& s_result_PE305,
    STREAM<D_TYPE>& s_result_PE306, STREAM<D_TYPE>& s_result_PE307,
    STREAM<D_TYPE>& s_result_PE308, STREAM<D_TYPE>& s_result_PE309,
    STREAM<D_TYPE>& s_result_PE310, STREAM<D_TYPE>& s_result_PE311,
    STREAM<D_TYPE>& s_result_PE312, STREAM<D_TYPE>& s_result_PE313,
    STREAM<D_TYPE>& s_result_PE314, STREAM<D_TYPE>& s_result_PE315,
    STREAM<D_TYPE>& s_result_PE316, STREAM<D_TYPE>& s_result_PE317,
    STREAM<D_TYPE>& s_result_PE318, STREAM<D_TYPE>& s_result_PE319,
    STREAM<D_TYPE>& s_result_PE320, STREAM<D_TYPE>& s_result_PE321,
    STREAM<D_TYPE>& s_result_PE322, STREAM<D_TYPE>& s_result_PE323,
    STREAM<D_TYPE>& s_result_PE324, STREAM<D_TYPE>& s_result_PE325,
    STREAM<D_TYPE>& s_result_PE326, STREAM<D_TYPE>& s_result_PE327,
    STREAM<D_TYPE>& s_result_PE328, STREAM<D_TYPE>& s_result_PE329,
    STREAM<D_TYPE>& s_result_PE330, STREAM<D_TYPE>& s_result_PE331,
    STREAM<D_TYPE>& s_result_PE332, STREAM<D_TYPE>& s_result_PE333,
    STREAM<D_TYPE>& s_result_PE334, STREAM<D_TYPE>& s_result_PE335,
    STREAM<D_TYPE>& s_result_PE336, STREAM<D_TYPE>& s_result_PE337,
    STREAM<D_TYPE>& s_result_PE338, STREAM<D_TYPE>& s_result_PE339,
    STREAM<D_TYPE>& s_result_PE340, STREAM<D_TYPE>& s_result_PE341,
    STREAM<D_TYPE>& s_result_PE342, STREAM<D_TYPE>& s_result_PE343,
    STREAM<D_TYPE>& s_result_PE344, STREAM<D_TYPE>& s_result_PE345,
    STREAM<D_TYPE>& s_result_PE346, STREAM<D_TYPE>& s_result_PE347,
    STREAM<D_TYPE>& s_result_PE348, STREAM<D_TYPE>& s_result_PE349,
    STREAM<D_TYPE>& s_result_PE350, STREAM<D_TYPE>& s_result_PE351,
    STREAM<D_TYPE>& s_result_PE352, STREAM<D_TYPE>& s_result_PE353,
    STREAM<D_TYPE>& s_result_PE354, STREAM<D_TYPE>& s_result_PE355,
    STREAM<D_TYPE>& s_result_PE356, STREAM<D_TYPE>& s_result_PE357,
    STREAM<D_TYPE>& s_result_PE358, STREAM<D_TYPE>& s_result_PE359,
    STREAM<D_TYPE>& s_result_PE360, STREAM<D_TYPE>& s_result_PE361,
    STREAM<D_TYPE>& s_result_PE362, STREAM<D_TYPE>& s_result_PE363,
    STREAM<D_TYPE>& s_result_PE364, STREAM<D_TYPE>& s_result_PE365,
    STREAM<D_TYPE>& s_result_PE366, STREAM<D_TYPE>& s_result_PE367,
    STREAM<D_TYPE>& s_result_PE368, STREAM<D_TYPE>& s_result_PE369,
    STREAM<D_TYPE>& s_result_PE370, STREAM<D_TYPE>& s_result_PE371,
    STREAM<D_TYPE>& s_result_PE372, STREAM<D_TYPE>& s_result_PE373,
    STREAM<D_TYPE>& s_result_PE374, STREAM<D_TYPE>& s_result_PE375,
    STREAM<D_TYPE>& s_result_PE376, STREAM<D_TYPE>& s_result_PE377,
    STREAM<D_TYPE>& s_result_PE378, STREAM<D_TYPE>& s_result_PE379,
    STREAM<D_TYPE>& s_result_PE380, STREAM<D_TYPE>& s_result_PE381,
    STREAM<D_TYPE>& s_result_PE382, STREAM<D_TYPE>& s_result_PE383,
    STREAM<D_TYPE>& s_result_PE384, STREAM<D_TYPE>& s_result_PE385,
    STREAM<D_TYPE>& s_result_PE386, STREAM<D_TYPE>& s_result_PE387,
    STREAM<D_TYPE>& s_result_PE388, STREAM<D_TYPE>& s_result_PE389,
    STREAM<D_TYPE>& s_result_PE390, STREAM<D_TYPE>& s_result_PE391,
    STREAM<D_TYPE>& s_result_PE392, STREAM<D_TYPE>& s_result_PE393,
    STREAM<D_TYPE>& s_result_PE394, STREAM<D_TYPE>& s_result_PE395,
    STREAM<D_TYPE>& s_result_PE396, STREAM<D_TYPE>& s_result_PE397,
    STREAM<D_TYPE>& s_result_PE398, STREAM<D_TYPE>& s_result_PE399,
    STREAM<D_TYPE>& s_result_PE400, STREAM<D_TYPE>& s_result_PE401,
    STREAM<D_TYPE>& s_result_PE402, STREAM<D_TYPE>& s_result_PE403,
    STREAM<D_TYPE>& s_result_PE404, STREAM<D_TYPE>& s_result_PE405,
    STREAM<D_TYPE>& s_result_PE406, STREAM<D_TYPE>& s_result_PE407,
    STREAM<D_TYPE>& s_result_PE408, STREAM<D_TYPE>& s_result_PE409,
    STREAM<D_TYPE>& s_result_PE410, STREAM<D_TYPE>& s_result_PE411,
    STREAM<D_TYPE>& s_result_PE412, STREAM<D_TYPE>& s_result_PE413,
    STREAM<D_TYPE>& s_result_PE414, STREAM<D_TYPE>& s_result_PE415,
    STREAM<ap_uint<512> >& s_result_all);

template<const int ROW_PER_PE>
void gather_results_node1(
    STREAM<ap_uint<512> > & s_result1_partial_0, STREAM<ap_uint<512> > & s_result1_partial_1, 
    STREAM<ap_uint<512> > & s_result1_partial_2, STREAM<ap_uint<512> > & s_result1_partial_3, 
    STREAM<ap_uint<512> > & s_result1_partial_4, STREAM<ap_uint<512> > & s_result1_partial_5, 
    STREAM<ap_uint<512> > & s_result1_partial_6, STREAM<ap_uint<512> > & s_result1_partial_7, 
    // STREAM<ap_uint<512> > & s_result1_partial_8, STREAM<ap_uint<512> > & s_result1_partial_9, 
    // STREAM<ap_uint<512> > & s_result1_partial_10, STREAM<ap_uint<512> > & s_result1_partial_11, 
    // STREAM<ap_uint<512> > & s_result1_partial_12, STREAM<ap_uint<512> > & s_result1_partial_13, 
    // STREAM<ap_uint<512> > & s_result1_partial_14, STREAM<ap_uint<512> > & s_result1_partial_15, 
    STREAM<ap_uint<512> > & s_result_node);


void dataTransform(STREAM<ap_uint<512> > & s_result_node, STREAM<ap_uint<512> > & s_feature_send_out, STREAM<ap_uint<512> > & s_padded_zero, STREAM<ap_uint<512> > & s_data_out);

void dataTransform(STREAM<ap_uint<512> > & s_feature_in, STREAM<ap_uint<512> > & s_data_out);

void stream_data_out(STREAM<ap_uint<512> >& s_data_out_buffer, STREAM<ap_uint<512> >& s_data_out);

void pad_zero(STREAM<ap_uint<512> >& s_padded_zero);

void consumeData_zero(STREAM<ap_uint<512> >& s_data_in_zero);



const int trip_count_item_num = BATCH_NUM * BATCH_SIZE;

const int fifo_batch_size = FIFO_BATCH_SIZE;

const int depth_s_embedding_buffer_HBM0 = VECTOR_SIZE_HBM_BANK_0 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM1 = VECTOR_SIZE_HBM_BANK_1 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM2 = VECTOR_SIZE_HBM_BANK_2 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM3 = VECTOR_SIZE_HBM_BANK_3 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM4 = VECTOR_SIZE_HBM_BANK_4 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM5 = VECTOR_SIZE_HBM_BANK_5 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM6 = VECTOR_SIZE_HBM_BANK_6 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM7 = VECTOR_SIZE_HBM_BANK_7 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM8 = VECTOR_SIZE_HBM_BANK_8 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM9 = VECTOR_SIZE_HBM_BANK_9 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM10 = VECTOR_SIZE_HBM_BANK_10 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM11 = VECTOR_SIZE_HBM_BANK_11 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM12 = VECTOR_SIZE_HBM_BANK_12 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM13 = VECTOR_SIZE_HBM_BANK_13 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM14 = VECTOR_SIZE_HBM_BANK_14 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM15 = VECTOR_SIZE_HBM_BANK_15 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM16 = VECTOR_SIZE_HBM_BANK_16 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM17 = VECTOR_SIZE_HBM_BANK_17 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM18 = VECTOR_SIZE_HBM_BANK_18 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM19 = VECTOR_SIZE_HBM_BANK_19 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM20 = VECTOR_SIZE_HBM_BANK_20 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM21 = VECTOR_SIZE_HBM_BANK_21 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM22 = VECTOR_SIZE_HBM_BANK_22 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM23 = VECTOR_SIZE_HBM_BANK_23 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM24 = VECTOR_SIZE_HBM_BANK_24 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM25 = VECTOR_SIZE_HBM_BANK_25 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM26 = VECTOR_SIZE_HBM_BANK_26 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM27 = VECTOR_SIZE_HBM_BANK_27 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM28 = VECTOR_SIZE_HBM_BANK_28 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM29 = VECTOR_SIZE_HBM_BANK_29 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM30 = VECTOR_SIZE_HBM_BANK_30 * FIFO_BATCH_SIZE;

const int depth_s_embedding_buffer_wide_HBM0 = VECTOR_SIZE_HBM_BANK_0 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM1 = VECTOR_SIZE_HBM_BANK_1 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM2 = VECTOR_SIZE_HBM_BANK_2 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM3 = VECTOR_SIZE_HBM_BANK_3 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM4 = VECTOR_SIZE_HBM_BANK_4 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM5 = VECTOR_SIZE_HBM_BANK_5 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM6 = VECTOR_SIZE_HBM_BANK_6 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM7 = VECTOR_SIZE_HBM_BANK_7 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM8 = VECTOR_SIZE_HBM_BANK_8 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM9 = VECTOR_SIZE_HBM_BANK_9 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM10 = VECTOR_SIZE_HBM_BANK_10 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM11 = VECTOR_SIZE_HBM_BANK_11 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM12 = VECTOR_SIZE_HBM_BANK_12 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM13 = VECTOR_SIZE_HBM_BANK_13 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM14 = VECTOR_SIZE_HBM_BANK_14 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM15 = VECTOR_SIZE_HBM_BANK_15 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM16 = VECTOR_SIZE_HBM_BANK_16 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM17 = VECTOR_SIZE_HBM_BANK_17 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM18 = VECTOR_SIZE_HBM_BANK_18 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM19 = VECTOR_SIZE_HBM_BANK_19 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM20 = VECTOR_SIZE_HBM_BANK_20 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM21 = VECTOR_SIZE_HBM_BANK_21 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM22 = VECTOR_SIZE_HBM_BANK_22 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM23 = VECTOR_SIZE_HBM_BANK_23 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM24 = VECTOR_SIZE_HBM_BANK_24 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM25 = VECTOR_SIZE_HBM_BANK_25 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM26 = VECTOR_SIZE_HBM_BANK_26 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM27 = VECTOR_SIZE_HBM_BANK_27 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM28 = VECTOR_SIZE_HBM_BANK_28 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM29 = VECTOR_SIZE_HBM_BANK_29 * FIFO_BATCH_SIZE / 4;
const int depth_s_embedding_buffer_wide_HBM30 = VECTOR_SIZE_HBM_BANK_30 * FIFO_BATCH_SIZE / 4;

void recvDataTransform(STREAM<ap_uint<512> > & s_data_in, STREAM<ap_uint<512> > & s_feature_in, STREAM<ap_uint<512> > & s_feature_send_out, STREAM<ap_uint<512> > & s_data_in_zero){

    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {

        for (int i = 0; i < 128; i++){
            #pragma HLS pipeline II=1
            ap_uint<512> data_word = s_data_in.read();
            s_feature_in.write(data_word);
            s_feature_send_out.write(data_word);
        }

        for (int i = 0; i < 64; i++) {
            #pragma HLS pipeline II=1
            s_data_in_zero.write(s_data_in.read()); // padded packet
        }

        #ifndef ACCL_SYNTHESIS
            std::cout <<"reduce root recvDataTransform item:"<<item<<std::endl;
        #endif
    }
}

void load_access_idx(
    STREAM<int>& start_flag,
    STREAM<int>& s_idx_buffer_HBM0, STREAM<int>& s_idx_buffer_HBM1, 
    STREAM<int>& s_idx_buffer_HBM2, STREAM<int>& s_idx_buffer_HBM3, 
    STREAM<int>& s_idx_buffer_HBM4, STREAM<int>& s_idx_buffer_HBM5, 
    STREAM<int>& s_idx_buffer_HBM6, STREAM<int>& s_idx_buffer_HBM7, 
    STREAM<int>& s_idx_buffer_HBM8, STREAM<int>& s_idx_buffer_HBM9, 
    STREAM<int>& s_idx_buffer_HBM10, STREAM<int>& s_idx_buffer_HBM11, 
    STREAM<int>& s_idx_buffer_HBM12, STREAM<int>& s_idx_buffer_HBM13, 
    STREAM<int>& s_idx_buffer_HBM14, STREAM<int>& s_idx_buffer_HBM15, 
    STREAM<int>& s_idx_buffer_HBM16, STREAM<int>& s_idx_buffer_HBM17, 
    STREAM<int>& s_idx_buffer_HBM18, STREAM<int>& s_idx_buffer_HBM19, 
    STREAM<int>& s_idx_buffer_HBM20, STREAM<int>& s_idx_buffer_HBM21, 
    STREAM<int>& s_idx_buffer_HBM22, STREAM<int>& s_idx_buffer_HBM23, 
    STREAM<int>& s_idx_buffer_HBM24, STREAM<int>& s_idx_buffer_HBM25, 
    STREAM<int>& s_idx_buffer_HBM26, STREAM<int>& s_idx_buffer_HBM27,
    STREAM<int>& s_idx_buffer_HBM28, STREAM<int>& s_idx_buffer_HBM29) { 

    int idx_HBM0, idx_HBM1, idx_HBM2, idx_HBM3, 
        idx_HBM4, idx_HBM5, idx_HBM6, idx_HBM7, 
        idx_HBM8, idx_HBM9, idx_HBM10, idx_HBM11, 
        idx_HBM12, idx_HBM13, idx_HBM14, idx_HBM15, 
        idx_HBM16, idx_HBM17, idx_HBM18, idx_HBM19, 
        idx_HBM20, idx_HBM21, idx_HBM22, idx_HBM23, 
        idx_HBM24, idx_HBM25, idx_HBM26, idx_HBM27,
        idx_HBM28, idx_HBM29, idx_HBM30;

    // batch = 32
    int idx_random[] = {3, 99, 38, 72, 29, 57, 1, 72, 36, 76, 35, 50, 37, 57, 
        13, 66, 26, 70, 41, 93, 48, 82, 44, 78, 25, 52, 3, 92, 36, 56, 46, 88};

    // Synchronization:
    // for (int i = 0; i < 64; i++) {
    //     #pragma HLS pipeline II=1
    //     start_flag.write(0); // for synchronization
    // }

    writeIndex:
    for (int i = 0; i < BATCH_NUM; i++) {
        
        for (int j = 0; j < BATCH_SIZE; j++) {
            #pragma HLS pipeline II=1

            int idx = idx_random[j];

            // start_flag.write(idx);

            s_idx_buffer_HBM0.write(idx);
            s_idx_buffer_HBM1.write(idx);
            s_idx_buffer_HBM2.write(idx);
            s_idx_buffer_HBM3.write(idx);
            s_idx_buffer_HBM4.write(idx);
            s_idx_buffer_HBM5.write(idx);
            s_idx_buffer_HBM6.write(idx);
            s_idx_buffer_HBM7.write(idx);
            s_idx_buffer_HBM8.write(idx);
            s_idx_buffer_HBM9.write(idx);
            s_idx_buffer_HBM10.write(idx);
            s_idx_buffer_HBM11.write(idx);
            s_idx_buffer_HBM12.write(idx);
            s_idx_buffer_HBM13.write(idx);
            s_idx_buffer_HBM14.write(idx);
            s_idx_buffer_HBM15.write(idx);
            s_idx_buffer_HBM16.write(idx);
            s_idx_buffer_HBM17.write(idx);
            s_idx_buffer_HBM18.write(idx);
            s_idx_buffer_HBM19.write(idx);
            s_idx_buffer_HBM20.write(idx);
            s_idx_buffer_HBM21.write(idx);
            s_idx_buffer_HBM22.write(idx);
            s_idx_buffer_HBM23.write(idx);
            s_idx_buffer_HBM24.write(idx);
            s_idx_buffer_HBM25.write(idx);
            s_idx_buffer_HBM26.write(idx);
            s_idx_buffer_HBM27.write(idx);
            s_idx_buffer_HBM28.write(idx);
            s_idx_buffer_HBM29.write(idx);
        }
    }
}

template<
    const int START_ADDR_0, const int AXI_PADDED_SIZE_0, 
    const int START_ADDR_1, const int AXI_PADDED_SIZE_1,
    const int ROW_PER_PE>
void load_single_embedding_2_tables(
    STREAM<int>& s_idx_buffer, const t_axi* table_RAM, 
    STREAM<t_axi>& s_embedding_buffer) {
#pragma HLS INLINE off

    // 8 < data size <= 16, load 2 times
    for (int i = 0; i < BATCH_NUM * BATCH_SIZE; i++) {
        #pragma HLS LOOP_TRIPCOUNT min=trip_count_item_num max=trip_count_item_num

        int idx =  s_idx_buffer.read();

        int base_addr_0 = START_ADDR_0 + idx * AXI_PADDED_SIZE_0;
        int base_addr_1 = START_ADDR_1 + idx * AXI_PADDED_SIZE_1;
        int base_addr = 0;

        read_table:
        for (int j = 0; j < (AXI_PADDED_SIZE_0 + AXI_PADDED_SIZE_1); j++) {
            #pragma HLS pipeline II=1
            base_addr = j < AXI_PADDED_SIZE_0 ? (base_addr_0 + j) : (base_addr_1 + j - AXI_PADDED_SIZE_0);
            s_embedding_buffer.write(table_RAM[base_addr]);
        }

        // int base_addr_0 = START_ADDR_0 + idx * AXI_PADDED_SIZE_0;
        // for (int j = 0; j < AXI_PADDED_SIZE_0; j++) {
        //     #pragma HLS pipeline II=1
        //     s_embedding_buffer.write(table_RAM[base_addr_0 + j]);
        // }
        // int base_addr_1 = START_ADDR_1 + idx * AXI_PADDED_SIZE_1;
        // for (int j = 0; j < AXI_PADDED_SIZE_1; j++) {
        //     #pragma HLS pipeline II=1
        //     s_embedding_buffer.write(table_RAM[base_addr_1 + j]);
        // }
    }
}


template<typename T, const int VECTOR_LENGTH, const int ROW_PER_PE>
void int_to_wide(
    STREAM<T>& s_embedding_buffer, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_1) {
#pragma HLS inline off

    for (int i = 0; i < BATCH_NUM * BATCH_SIZE; i++) {
        #pragma HLS LOOP_TRIPCOUNT min=trip_count_item_num max=trip_count_item_num

        for (int j = 0; j < VECTOR_LENGTH / INTS_PER_W; j++) {
            #pragma HLS pipeline II=4
            W_TYPE reg0;
            reg0.range(31, 0) = s_embedding_buffer.read();
            reg0.range(63, 32) = s_embedding_buffer.read();
            reg0.range(95, 64) = s_embedding_buffer.read();
            reg0.range(127, 96) = s_embedding_buffer.read();

            s_embedding_buffer_wide_1.write(reg0);
        }
    }
}

template<const int VECTOR_LENGTH_0, const int VECTOR_LENGTH_1, const int VECTOR_LENGTH_2, const int VECTOR_LENGTH_3, const int VECTOR_LENGTH_4, const int VECTOR_LENGTH_5, const int VECTOR_LENGTH_6, const int VECTOR_LENGTH_7, const int ROW_PER_PE>
void gather_embeddings_8(
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM0_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM1_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM2_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM3_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM4_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM5_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM6_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM7_1, 
    STREAM<ap_uint<512> >& s_feature_in
) {
#pragma HLS inline off

    std::cout << "gather_embeddings_8: " << std::endl;
    int count = 0;

    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        
        for (int i = 0; i < VECTOR_LENGTH_0 / INTS_PER_W / 4; i++) {
            #pragma HLS pipeline II=4
            count++;
            // vector_size of HBM0 is 16, others are 32
            ap_uint<512> reg0;
            reg0.range(127, 0) = s_embedding_buffer_wide_HBM0_1.read();
            reg0.range(255, 128) = s_embedding_buffer_wide_HBM0_1.read();
            reg0.range(383, 256) = s_embedding_buffer_wide_HBM0_1.read();
            reg0.range(511, 384) = s_embedding_buffer_wide_HBM0_1.read();
            s_feature_in.write(reg0);
        }
        for (int i = 0; i < VECTOR_LENGTH_1 / INTS_PER_W / 4; i++) {
            #pragma HLS pipeline II=4
            count++;
            ap_uint<512> reg0;
            reg0.range(127, 0) = s_embedding_buffer_wide_HBM1_1.read();
            reg0.range(255, 128) = s_embedding_buffer_wide_HBM1_1.read();
            reg0.range(383, 256) = s_embedding_buffer_wide_HBM1_1.read();
            reg0.range(511, 384) = s_embedding_buffer_wide_HBM1_1.read();
            s_feature_in.write(reg0);
        }
        for (int i = 0; i < VECTOR_LENGTH_2 / INTS_PER_W / 4; i++) {
            #pragma HLS pipeline II=4
            count++;
            ap_uint<512> reg0;
            reg0.range(127, 0) = s_embedding_buffer_wide_HBM2_1.read();
            reg0.range(255, 128) = s_embedding_buffer_wide_HBM2_1.read();
            reg0.range(383, 256) = s_embedding_buffer_wide_HBM2_1.read();
            reg0.range(511, 384) = s_embedding_buffer_wide_HBM2_1.read();
            s_feature_in.write(reg0);
        }
        for (int i = 0; i < VECTOR_LENGTH_3 / INTS_PER_W / 4; i++) {
            #pragma HLS pipeline II=4
            count++;
            ap_uint<512> reg0;
            reg0.range(127, 0) = s_embedding_buffer_wide_HBM3_1.read();
            reg0.range(255, 128) = s_embedding_buffer_wide_HBM3_1.read();
            reg0.range(383, 256) = s_embedding_buffer_wide_HBM3_1.read();
            reg0.range(511, 384) = s_embedding_buffer_wide_HBM3_1.read();
            s_feature_in.write(reg0);
        }
        for (int i = 0; i < VECTOR_LENGTH_4 / INTS_PER_W / 4; i++) {
            #pragma HLS pipeline II=4
            count++;
            ap_uint<512> reg0;
            reg0.range(127, 0) = s_embedding_buffer_wide_HBM4_1.read();
            reg0.range(255, 128) = s_embedding_buffer_wide_HBM4_1.read();
            reg0.range(383, 256) = s_embedding_buffer_wide_HBM4_1.read();
            reg0.range(511, 384) = s_embedding_buffer_wide_HBM4_1.read();
            s_feature_in.write(reg0);
        }
        for (int i = 0; i < VECTOR_LENGTH_5 / INTS_PER_W / 4; i++) {
            #pragma HLS pipeline II=4
            count++;
            ap_uint<512> reg0;
            reg0.range(127, 0) = s_embedding_buffer_wide_HBM5_1.read();
            reg0.range(255, 128) = s_embedding_buffer_wide_HBM5_1.read();
            reg0.range(383, 256) = s_embedding_buffer_wide_HBM5_1.read();
            reg0.range(511, 384) = s_embedding_buffer_wide_HBM5_1.read();
            s_feature_in.write(reg0);
        }
        for (int i = 0; i < VECTOR_LENGTH_6 / INTS_PER_W / 4; i++) {
            #pragma HLS pipeline II=4
            count++;
            ap_uint<512> reg0;
            reg0.range(127, 0) = s_embedding_buffer_wide_HBM6_1.read();
            reg0.range(255, 128) = s_embedding_buffer_wide_HBM6_1.read();
            reg0.range(383, 256) = s_embedding_buffer_wide_HBM6_1.read();
            reg0.range(511, 384) = s_embedding_buffer_wide_HBM6_1.read();
            s_feature_in.write(reg0);
        }
        for (int i = 0; i < VECTOR_LENGTH_7 / INTS_PER_W / 4; i++) {
            #pragma HLS pipeline II=4
            count++;
            ap_uint<512> reg0;
            reg0.range(127, 0) = s_embedding_buffer_wide_HBM7_1.read();
            reg0.range(255, 128) = s_embedding_buffer_wide_HBM7_1.read();
            reg0.range(383, 256) = s_embedding_buffer_wide_HBM7_1.read();
            reg0.range(511, 384) = s_embedding_buffer_wide_HBM7_1.read();
            s_feature_in.write(reg0);
        }
        std::cout << "      count: " << count << std::endl;
    }
    
}

template<const int VECTOR_LENGTH_0, const int VECTOR_LENGTH_1, const int VECTOR_LENGTH_2, const int VECTOR_LENGTH_3, const int VECTOR_LENGTH_4, const int VECTOR_LENGTH_5, const int VECTOR_LENGTH_6, const int ROW_PER_PE>
void gather_embeddings_7(
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM0_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM1_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM2_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM3_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM4_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM5_1, 
    STREAM<W_TYPE>& s_embedding_buffer_wide_HBM6_1, 
    STREAM<ap_uint<512> >& s_feature_in
) {
#pragma HLS inline off

    std::cout << "gather_embeddings_8: " << std::endl;
    int count = 0;

    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        
        for (int i = 0; i < VECTOR_LENGTH_0 / INTS_PER_W / 4; i++) {
            #pragma HLS pipeline II=4
            count++;
            ap_uint<512> reg0;
            reg0.range(127, 0) = s_embedding_buffer_wide_HBM0_1.read();
            reg0.range(255, 128) = s_embedding_buffer_wide_HBM0_1.read();
            reg0.range(383, 256) = s_embedding_buffer_wide_HBM0_1.read();
            reg0.range(511, 384) = s_embedding_buffer_wide_HBM0_1.read();
            s_feature_in.write(reg0);
        }
        for (int i = 0; i < VECTOR_LENGTH_1 / INTS_PER_W / 4; i++) {
            #pragma HLS pipeline II=4
            count++;
            ap_uint<512> reg0;
            reg0.range(127, 0) = s_embedding_buffer_wide_HBM1_1.read();
            reg0.range(255, 128) = s_embedding_buffer_wide_HBM1_1.read();
            reg0.range(383, 256) = s_embedding_buffer_wide_HBM1_1.read();
            reg0.range(511, 384) = s_embedding_buffer_wide_HBM1_1.read();
            s_feature_in.write(reg0);
        }
        for (int i = 0; i < VECTOR_LENGTH_2 / INTS_PER_W / 4; i++) {
            #pragma HLS pipeline II=4
            count++;
            ap_uint<512> reg0;
            reg0.range(127, 0) = s_embedding_buffer_wide_HBM2_1.read();
            reg0.range(255, 128) = s_embedding_buffer_wide_HBM2_1.read();
            reg0.range(383, 256) = s_embedding_buffer_wide_HBM2_1.read();
            reg0.range(511, 384) = s_embedding_buffer_wide_HBM2_1.read();
            s_feature_in.write(reg0);
        }
        for (int i = 0; i < VECTOR_LENGTH_3 / INTS_PER_W / 4; i++) {
            #pragma HLS pipeline II=4
            count++;
            ap_uint<512> reg0;
            reg0.range(127, 0) = s_embedding_buffer_wide_HBM3_1.read();
            reg0.range(255, 128) = s_embedding_buffer_wide_HBM3_1.read();
            reg0.range(383, 256) = s_embedding_buffer_wide_HBM3_1.read();
            reg0.range(511, 384) = s_embedding_buffer_wide_HBM3_1.read();
            s_feature_in.write(reg0);
        }
        for (int i = 0; i < VECTOR_LENGTH_4 / INTS_PER_W / 4; i++) {
            #pragma HLS pipeline II=4
            count++;
            ap_uint<512> reg0;
            reg0.range(127, 0) = s_embedding_buffer_wide_HBM4_1.read();
            reg0.range(255, 128) = s_embedding_buffer_wide_HBM4_1.read();
            reg0.range(383, 256) = s_embedding_buffer_wide_HBM4_1.read();
            reg0.range(511, 384) = s_embedding_buffer_wide_HBM4_1.read();
            s_feature_in.write(reg0);
        }
        for (int i = 0; i < VECTOR_LENGTH_5 / INTS_PER_W / 4; i++) {
            #pragma HLS pipeline II=4
            count++;
            ap_uint<512> reg0;
            reg0.range(127, 0) = s_embedding_buffer_wide_HBM5_1.read();
            reg0.range(255, 128) = s_embedding_buffer_wide_HBM5_1.read();
            reg0.range(383, 256) = s_embedding_buffer_wide_HBM5_1.read();
            reg0.range(511, 384) = s_embedding_buffer_wide_HBM5_1.read();
            s_feature_in.write(reg0);
        }
        for (int i = 0; i < VECTOR_LENGTH_6 / INTS_PER_W / 4; i++) {
            #pragma HLS pipeline II=4
            count++;
            ap_uint<512> reg0;
            reg0.range(127, 0) = s_embedding_buffer_wide_HBM6_1.read();
            reg0.range(255, 128) = s_embedding_buffer_wide_HBM6_1.read();
            reg0.range(383, 256) = s_embedding_buffer_wide_HBM6_1.read();
            reg0.range(511, 384) = s_embedding_buffer_wide_HBM6_1.read();
            s_feature_in.write(reg0);
        }
        std::cout << "      count: " << count << std::endl;
    }
    
}

template<const int ROW_PER_PE>
void gather_embeddings(
    STREAM<ap_uint<512> >& s_embedding_0,
    STREAM<ap_uint<512> >& s_embedding_1,
    STREAM<ap_uint<512> >& s_embedding_2,
    STREAM<ap_uint<512> >& s_embedding_3,
    STREAM<ap_uint<512> >& s_feature_in
){
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < 16; i++){
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_0.read());
        }
        for (int i = 0; i < 16; i++){
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_1.read());
        }
        for (int i = 0; i < 14; i++){
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_2.read());
        }
        for (int i = 0; i < 14; i++){
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_3.read());
        }
    }
}

template<const int FEATURE_SIZE, const int ROW_PER_PE>
void store_features(
    STREAM<ap_uint<512> >& s_feature_in,
    STREAM<ap_uint<512> >& s_feature_out)
{

    ap_uint<512> features_local[FEATURE_SIZE / INTS_PER_W / 4];
#pragma HLS resource variable=features_local core=RAM_1P_URAM

    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        store_features:
        for (int i = 0; i < FEATURE_SIZE / INTS_PER_W / 4; i++){
            #pragma HLS pipeline II=1
            ap_uint<512> tmp_data = s_feature_in.read();
            features_local[i] = tmp_data;
            // s_embedding_table.write(tmp_data);
        }
        features_out:
        for (int i = 0; i < ROW_PER_PE; i++) {
            for (int j = 0; j < FEATURE_SIZE / INTS_PER_W / 4; j++) {
                #pragma HLS pipeline II=1
                s_feature_out.write(features_local[i]);
            }
        }

    }
}

void replicate_feature_in(STREAM<ap_uint<512> > & s_feature_in, STREAM<ap_uint<512> > & s_feature_in_0, STREAM<ap_uint<512> > & s_feature_in_1, STREAM<ap_uint<512> > & s_embedding_table){
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < ROOT_HIDDEN_SIZE1 / INTS_PER_W / 4; i++){
            #pragma HLS pipeline II=1
            ap_uint<512> s_data = s_feature_in.read();
            s_feature_in_0.write(s_data);
            s_feature_in_1.write(s_data);
            s_embedding_table.write(s_data);
        }

    }
}

void replicate_feature_in_4(
    STREAM<ap_uint<512> > & s_feature_in, 
    STREAM<ap_uint<512> > & s_feature_in_0, STREAM<ap_uint<512> > & s_feature_in_1, 
    STREAM<ap_uint<512> > & s_feature_in_2, STREAM<ap_uint<512> > & s_feature_in_3, 
    STREAM<ap_uint<512> > & s_embedding_table)
{
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < ROOT_HIDDEN_SIZE1 / INTS_PER_W / 4; i++){
            #pragma HLS pipeline II=1
            ap_uint<512> s_data = s_feature_in.read();
            s_feature_in_0.write(s_data);
            s_feature_in_1.write(s_data);
            s_feature_in_2.write(s_data);
            s_feature_in_3.write(s_data);
            s_embedding_table.write(s_data);
        }

    }
}

void replicate_feature_in_6(
    STREAM<ap_uint<512> > & s_feature_in, 
    STREAM<ap_uint<512> > & s_feature_in_0, STREAM<ap_uint<512> > & s_feature_in_1, 
    STREAM<ap_uint<512> > & s_feature_in_2, STREAM<ap_uint<512> > & s_feature_in_3, 
    STREAM<ap_uint<512> > & s_feature_in_4, STREAM<ap_uint<512> > & s_feature_in_5, 
    STREAM<ap_uint<512> > & s_embedding_table)
{
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < ROOT_HIDDEN_SIZE1 / INTS_PER_W / 4; i++){
            #pragma HLS pipeline II=1
            ap_uint<512> s_data = s_feature_in.read();
            s_feature_in_0.write(s_data);
            s_feature_in_1.write(s_data);
            s_feature_in_2.write(s_data);
            s_feature_in_3.write(s_data);
            s_feature_in_4.write(s_data);
            s_feature_in_5.write(s_data);
            s_embedding_table.write(s_data);
        }

    }
}

void replicate_feature_in_7(
    STREAM<ap_uint<512> > & s_feature_in, 
    STREAM<ap_uint<512> > & s_feature_in_0, STREAM<ap_uint<512> > & s_feature_in_1, 
    STREAM<ap_uint<512> > & s_feature_in_2, STREAM<ap_uint<512> > & s_feature_in_3, 
    STREAM<ap_uint<512> > & s_feature_in_4, STREAM<ap_uint<512> > & s_feature_in_5, 
    STREAM<ap_uint<512> > & s_feature_in_6, 
    STREAM<ap_uint<512> > & s_embedding_table)
{
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < ROOT_HIDDEN_SIZE1 / INTS_PER_W / 4; i++){
            #pragma HLS pipeline II=1
            ap_uint<512> s_data = s_feature_in.read();
            s_feature_in_0.write(s_data);
            s_feature_in_1.write(s_data);
            s_feature_in_2.write(s_data);
            s_feature_in_3.write(s_data);
            s_feature_in_4.write(s_data);
            s_feature_in_5.write(s_data);
            s_feature_in_6.write(s_data);
            s_embedding_table.write(s_data);
        }
    }

    
}

void replicate_feature_in_8(
    STREAM<ap_uint<512> > & s_feature_in, 
    STREAM<ap_uint<512> > & s_feature_in_0, STREAM<ap_uint<512> > & s_feature_in_1, 
    STREAM<ap_uint<512> > & s_feature_in_2, STREAM<ap_uint<512> > & s_feature_in_3, 
    STREAM<ap_uint<512> > & s_feature_in_4, STREAM<ap_uint<512> > & s_feature_in_5, 
    STREAM<ap_uint<512> > & s_feature_in_6, STREAM<ap_uint<512> > & s_feature_in_7, 
    STREAM<ap_uint<512> > & s_embedding_table)
{
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < ROOT_HIDDEN_SIZE1 / INTS_PER_W / 4; i++){
            #pragma HLS pipeline II=1
            ap_uint<512> s_data = s_feature_in.read();
            s_feature_in_0.write(s_data);
            s_feature_in_1.write(s_data);
            s_feature_in_2.write(s_data);
            s_feature_in_3.write(s_data);
            s_feature_in_4.write(s_data);
            s_feature_in_5.write(s_data);
            s_feature_in_6.write(s_data);
            s_feature_in_7.write(s_data);
            s_embedding_table.write(s_data);
        }

    }
}

void replicate_feature_in_13(
    STREAM<ap_uint<512> > & s_feature_in, 
    STREAM<ap_uint<512> > & s_feature_in_0, STREAM<ap_uint<512> > & s_feature_in_1, 
    STREAM<ap_uint<512> > & s_feature_in_2, STREAM<ap_uint<512> > & s_feature_in_3, 
    STREAM<ap_uint<512> > & s_feature_in_4, STREAM<ap_uint<512> > & s_feature_in_5, 
    STREAM<ap_uint<512> > & s_feature_in_6, STREAM<ap_uint<512> > & s_feature_in_7, 
    STREAM<ap_uint<512> > & s_feature_in_8, STREAM<ap_uint<512> > & s_feature_in_9, 
    STREAM<ap_uint<512> > & s_feature_in_10, STREAM<ap_uint<512> > & s_feature_in_11, 
    STREAM<ap_uint<512> > & s_feature_in_12, 
    STREAM<ap_uint<512> > & s_embedding_table)
{
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < ROOT_HIDDEN_SIZE1 / INTS_PER_W / 4; i++){
            #pragma HLS pipeline II=1
            ap_uint<512> s_data = s_feature_in.read();
            s_feature_in_0.write(s_data);
            s_feature_in_1.write(s_data);
            s_feature_in_2.write(s_data);
            s_feature_in_3.write(s_data);
            s_feature_in_4.write(s_data);
            s_feature_in_5.write(s_data);
            s_feature_in_6.write(s_data);
            s_feature_in_7.write(s_data);
            s_feature_in_8.write(s_data);
            s_feature_in_9.write(s_data);
            s_feature_in_10.write(s_data);
            s_feature_in_11.write(s_data);
            s_feature_in_12.write(s_data);
            s_embedding_table.write(s_data);
        }

    }
}

void replicate_feature_in_26(
    STREAM<ap_uint<512> > & s_feature_in, 
    STREAM<ap_uint<512> > & s_feature_in_0, STREAM<ap_uint<512> > & s_feature_in_1, 
    STREAM<ap_uint<512> > & s_feature_in_2, STREAM<ap_uint<512> > & s_feature_in_3, 
    STREAM<ap_uint<512> > & s_feature_in_4, STREAM<ap_uint<512> > & s_feature_in_5, 
    STREAM<ap_uint<512> > & s_feature_in_6, STREAM<ap_uint<512> > & s_feature_in_7, 
    STREAM<ap_uint<512> > & s_feature_in_8, STREAM<ap_uint<512> > & s_feature_in_9, 
    STREAM<ap_uint<512> > & s_feature_in_10, STREAM<ap_uint<512> > & s_feature_in_11, 
    STREAM<ap_uint<512> > & s_feature_in_12, STREAM<ap_uint<512> > & s_feature_in_13, 
    STREAM<ap_uint<512> > & s_feature_in_14, STREAM<ap_uint<512> > & s_feature_in_15,
    STREAM<ap_uint<512> > & s_feature_in_16, STREAM<ap_uint<512> > & s_feature_in_17,
    STREAM<ap_uint<512> > & s_feature_in_18, STREAM<ap_uint<512> > & s_feature_in_19,
    STREAM<ap_uint<512> > & s_feature_in_20, STREAM<ap_uint<512> > & s_feature_in_21,
    STREAM<ap_uint<512> > & s_feature_in_22, STREAM<ap_uint<512> > & s_feature_in_23,
    STREAM<ap_uint<512> > & s_feature_in_24, STREAM<ap_uint<512> > & s_feature_in_25,
    STREAM<ap_uint<512> > & s_embedding_table)
{
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < ROOT_HIDDEN_SIZE1 / INTS_PER_W / 4; i++){
            #pragma HLS pipeline II=1
            ap_uint<512> s_data = s_feature_in.read();
            s_feature_in_0.write(s_data);
            s_feature_in_1.write(s_data);
            s_feature_in_2.write(s_data);
            s_feature_in_3.write(s_data);
            s_feature_in_4.write(s_data);
            s_feature_in_5.write(s_data);
            s_feature_in_6.write(s_data);
            s_feature_in_7.write(s_data);
            s_feature_in_8.write(s_data);
            s_feature_in_9.write(s_data);
            s_feature_in_10.write(s_data);
            s_feature_in_11.write(s_data);
            s_feature_in_12.write(s_data);

            s_feature_in_13.write(s_data);
            s_feature_in_14.write(s_data);
            s_feature_in_15.write(s_data);
            s_feature_in_16.write(s_data);
            s_feature_in_17.write(s_data);
            s_feature_in_18.write(s_data);
            s_feature_in_19.write(s_data);
            s_feature_in_20.write(s_data);
            s_feature_in_21.write(s_data);
            s_feature_in_22.write(s_data);
            s_feature_in_23.write(s_data);
            s_feature_in_24.write(s_data);
            s_feature_in_25.write(s_data);

            s_embedding_table.write(s_data);
        }

    }
}

template<const int FEATURE_SIZE, const int ROW_PER_PE>
void replicate_feature_in_16(
    STREAM<ap_uint<512> > & s_feature_in, 
    STREAM<ap_uint<512> > & s_feature_in_0, STREAM<ap_uint<512> > & s_feature_in_1, 
    STREAM<ap_uint<512> > & s_feature_in_2, STREAM<ap_uint<512> > & s_feature_in_3, 
    STREAM<ap_uint<512> > & s_feature_in_4, STREAM<ap_uint<512> > & s_feature_in_5, 
    STREAM<ap_uint<512> > & s_feature_in_6, STREAM<ap_uint<512> > & s_feature_in_7 
    // STREAM<ap_uint<512> > & s_feature_in_8, STREAM<ap_uint<512> > & s_feature_in_9, 
    // STREAM<ap_uint<512> > & s_feature_in_10, STREAM<ap_uint<512> > & s_feature_in_11, 
    // STREAM<ap_uint<512> > & s_feature_in_12, STREAM<ap_uint<512> > & s_feature_in_13, 
    // STREAM<ap_uint<512> > & s_feature_in_14, STREAM<ap_uint<512> > & s_feature_in_15
    )
{
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < ROW_PER_PE * FEATURE_SIZE / INTS_PER_W / 4; i++){
            #pragma HLS pipeline II=1
            ap_uint<512> s_data = s_feature_in.read();
            s_feature_in_0.write(s_data);
            s_feature_in_1.write(s_data);
            s_feature_in_2.write(s_data);
            s_feature_in_3.write(s_data);
            s_feature_in_4.write(s_data);
            s_feature_in_5.write(s_data);
            s_feature_in_6.write(s_data);
            s_feature_in_7.write(s_data);
            // s_feature_in_8.write(s_data);
            // s_feature_in_9.write(s_data);
            // s_feature_in_10.write(s_data);
            // s_feature_in_11.write(s_data);
            // s_feature_in_12.write(s_data);
            // s_feature_in_13.write(s_data);
            // s_feature_in_14.write(s_data);
            // s_feature_in_15.write(s_data);
        }

    }
}

template<const int FEATURE_SIZE>
void replicate_feature_512PEs_216PE(
    STREAM<ap_uint<512> >& s_feature_in, 
    STREAM<ap_uint<512> >& s_embedding_table,
    STREAM<W_TYPE>& s_feature_PE0_0, STREAM<W_TYPE>& s_feature_PE0_1,
    STREAM<W_TYPE>& s_feature_PE0_2, STREAM<W_TYPE>& s_feature_PE0_3,
    STREAM<W_TYPE>& s_feature_PE1_0, STREAM<W_TYPE>& s_feature_PE1_1,
    STREAM<W_TYPE>& s_feature_PE1_2, STREAM<W_TYPE>& s_feature_PE1_3,
    STREAM<W_TYPE>& s_feature_PE2_0, STREAM<W_TYPE>& s_feature_PE2_1,
    STREAM<W_TYPE>& s_feature_PE2_2, STREAM<W_TYPE>& s_feature_PE2_3,
    STREAM<W_TYPE>& s_feature_PE3_0, STREAM<W_TYPE>& s_feature_PE3_1,
    STREAM<W_TYPE>& s_feature_PE3_2, STREAM<W_TYPE>& s_feature_PE3_3,
    STREAM<W_TYPE>& s_feature_PE4_0, STREAM<W_TYPE>& s_feature_PE4_1,
    STREAM<W_TYPE>& s_feature_PE4_2, STREAM<W_TYPE>& s_feature_PE4_3,
    STREAM<W_TYPE>& s_feature_PE5_0, STREAM<W_TYPE>& s_feature_PE5_1,
    STREAM<W_TYPE>& s_feature_PE5_2, STREAM<W_TYPE>& s_feature_PE5_3,
    STREAM<W_TYPE>& s_feature_PE6_0, STREAM<W_TYPE>& s_feature_PE6_1,
    STREAM<W_TYPE>& s_feature_PE6_2, STREAM<W_TYPE>& s_feature_PE6_3,
    STREAM<W_TYPE>& s_feature_PE7_0, STREAM<W_TYPE>& s_feature_PE7_1,
    STREAM<W_TYPE>& s_feature_PE7_2, STREAM<W_TYPE>& s_feature_PE7_3,
    STREAM<W_TYPE>& s_feature_PE8_0, STREAM<W_TYPE>& s_feature_PE8_1,
    STREAM<W_TYPE>& s_feature_PE8_2, STREAM<W_TYPE>& s_feature_PE8_3,
    STREAM<W_TYPE>& s_feature_PE9_0, STREAM<W_TYPE>& s_feature_PE9_1,
    STREAM<W_TYPE>& s_feature_PE9_2, STREAM<W_TYPE>& s_feature_PE9_3,
    STREAM<W_TYPE>& s_feature_PE10_0, STREAM<W_TYPE>& s_feature_PE10_1,
    STREAM<W_TYPE>& s_feature_PE10_2, STREAM<W_TYPE>& s_feature_PE10_3,
    STREAM<W_TYPE>& s_feature_PE11_0, STREAM<W_TYPE>& s_feature_PE11_1,
    STREAM<W_TYPE>& s_feature_PE11_2, STREAM<W_TYPE>& s_feature_PE11_3,
    STREAM<W_TYPE>& s_feature_PE12_0, STREAM<W_TYPE>& s_feature_PE12_1,
    STREAM<W_TYPE>& s_feature_PE12_2, STREAM<W_TYPE>& s_feature_PE12_3,
    STREAM<W_TYPE>& s_feature_PE13_0, STREAM<W_TYPE>& s_feature_PE13_1,
    STREAM<W_TYPE>& s_feature_PE13_2, STREAM<W_TYPE>& s_feature_PE13_3,
    STREAM<W_TYPE>& s_feature_PE14_0, STREAM<W_TYPE>& s_feature_PE14_1,
    STREAM<W_TYPE>& s_feature_PE14_2, STREAM<W_TYPE>& s_feature_PE14_3,
    STREAM<W_TYPE>& s_feature_PE15_0, STREAM<W_TYPE>& s_feature_PE15_1,
    STREAM<W_TYPE>& s_feature_PE15_2, STREAM<W_TYPE>& s_feature_PE15_3,
    STREAM<W_TYPE>& s_feature_PE16_0, STREAM<W_TYPE>& s_feature_PE16_1,
    STREAM<W_TYPE>& s_feature_PE16_2, STREAM<W_TYPE>& s_feature_PE16_3,
    STREAM<W_TYPE>& s_feature_PE17_0, STREAM<W_TYPE>& s_feature_PE17_1,
    STREAM<W_TYPE>& s_feature_PE17_2, STREAM<W_TYPE>& s_feature_PE17_3,
    STREAM<W_TYPE>& s_feature_PE18_0, STREAM<W_TYPE>& s_feature_PE18_1,
    STREAM<W_TYPE>& s_feature_PE18_2, STREAM<W_TYPE>& s_feature_PE18_3,
    STREAM<W_TYPE>& s_feature_PE19_0, STREAM<W_TYPE>& s_feature_PE19_1,
    STREAM<W_TYPE>& s_feature_PE19_2, STREAM<W_TYPE>& s_feature_PE19_3,
    STREAM<W_TYPE>& s_feature_PE20_0, STREAM<W_TYPE>& s_feature_PE20_1,
    STREAM<W_TYPE>& s_feature_PE20_2, STREAM<W_TYPE>& s_feature_PE20_3,
    STREAM<W_TYPE>& s_feature_PE21_0, STREAM<W_TYPE>& s_feature_PE21_1,
    STREAM<W_TYPE>& s_feature_PE21_2, STREAM<W_TYPE>& s_feature_PE21_3,
    STREAM<W_TYPE>& s_feature_PE22_0, STREAM<W_TYPE>& s_feature_PE22_1,
    STREAM<W_TYPE>& s_feature_PE22_2, STREAM<W_TYPE>& s_feature_PE22_3,
    STREAM<W_TYPE>& s_feature_PE23_0, STREAM<W_TYPE>& s_feature_PE23_1,
    STREAM<W_TYPE>& s_feature_PE23_2, STREAM<W_TYPE>& s_feature_PE23_3,
    STREAM<W_TYPE>& s_feature_PE24_0, STREAM<W_TYPE>& s_feature_PE24_1,
    STREAM<W_TYPE>& s_feature_PE24_2, STREAM<W_TYPE>& s_feature_PE24_3,
    STREAM<W_TYPE>& s_feature_PE25_0, STREAM<W_TYPE>& s_feature_PE25_1,
    STREAM<W_TYPE>& s_feature_PE25_2, STREAM<W_TYPE>& s_feature_PE25_3,
    STREAM<W_TYPE>& s_feature_PE26_0, STREAM<W_TYPE>& s_feature_PE26_1,
    STREAM<W_TYPE>& s_feature_PE26_2, STREAM<W_TYPE>& s_feature_PE26_3,
    STREAM<W_TYPE>& s_feature_PE27_0, STREAM<W_TYPE>& s_feature_PE27_1,
    STREAM<W_TYPE>& s_feature_PE27_2, STREAM<W_TYPE>& s_feature_PE27_3,
    STREAM<W_TYPE>& s_feature_PE28_0, STREAM<W_TYPE>& s_feature_PE28_1,
    STREAM<W_TYPE>& s_feature_PE28_2, STREAM<W_TYPE>& s_feature_PE28_3,
    STREAM<W_TYPE>& s_feature_PE29_0, STREAM<W_TYPE>& s_feature_PE29_1,
    STREAM<W_TYPE>& s_feature_PE29_2, STREAM<W_TYPE>& s_feature_PE29_3,
    STREAM<W_TYPE>& s_feature_PE30_0, STREAM<W_TYPE>& s_feature_PE30_1,
    STREAM<W_TYPE>& s_feature_PE30_2, STREAM<W_TYPE>& s_feature_PE30_3,
    STREAM<W_TYPE>& s_feature_PE31_0, STREAM<W_TYPE>& s_feature_PE31_1,
    STREAM<W_TYPE>& s_feature_PE31_2, STREAM<W_TYPE>& s_feature_PE31_3,
    STREAM<W_TYPE>& s_feature_PE32_0, STREAM<W_TYPE>& s_feature_PE32_1,
    STREAM<W_TYPE>& s_feature_PE32_2, STREAM<W_TYPE>& s_feature_PE32_3,
    STREAM<W_TYPE>& s_feature_PE33_0, STREAM<W_TYPE>& s_feature_PE33_1,
    STREAM<W_TYPE>& s_feature_PE33_2, STREAM<W_TYPE>& s_feature_PE33_3,
    STREAM<W_TYPE>& s_feature_PE34_0, STREAM<W_TYPE>& s_feature_PE34_1,
    STREAM<W_TYPE>& s_feature_PE34_2, STREAM<W_TYPE>& s_feature_PE34_3,
    STREAM<W_TYPE>& s_feature_PE35_0, STREAM<W_TYPE>& s_feature_PE35_1,
    STREAM<W_TYPE>& s_feature_PE35_2, STREAM<W_TYPE>& s_feature_PE35_3,
    STREAM<W_TYPE>& s_feature_PE36_0, STREAM<W_TYPE>& s_feature_PE36_1,
    STREAM<W_TYPE>& s_feature_PE36_2, STREAM<W_TYPE>& s_feature_PE36_3,
    STREAM<W_TYPE>& s_feature_PE37_0, STREAM<W_TYPE>& s_feature_PE37_1,
    STREAM<W_TYPE>& s_feature_PE37_2, STREAM<W_TYPE>& s_feature_PE37_3,
    STREAM<W_TYPE>& s_feature_PE38_0, STREAM<W_TYPE>& s_feature_PE38_1,
    STREAM<W_TYPE>& s_feature_PE38_2, STREAM<W_TYPE>& s_feature_PE38_3,
    STREAM<W_TYPE>& s_feature_PE39_0, STREAM<W_TYPE>& s_feature_PE39_1,
    STREAM<W_TYPE>& s_feature_PE39_2, STREAM<W_TYPE>& s_feature_PE39_3,
    STREAM<W_TYPE>& s_feature_PE40_0, STREAM<W_TYPE>& s_feature_PE40_1,
    STREAM<W_TYPE>& s_feature_PE40_2, STREAM<W_TYPE>& s_feature_PE40_3,
    STREAM<W_TYPE>& s_feature_PE41_0, STREAM<W_TYPE>& s_feature_PE41_1,
    STREAM<W_TYPE>& s_feature_PE41_2, STREAM<W_TYPE>& s_feature_PE41_3,
    STREAM<W_TYPE>& s_feature_PE42_0, STREAM<W_TYPE>& s_feature_PE42_1,
    STREAM<W_TYPE>& s_feature_PE42_2, STREAM<W_TYPE>& s_feature_PE42_3,
    STREAM<W_TYPE>& s_feature_PE43_0, STREAM<W_TYPE>& s_feature_PE43_1,
    STREAM<W_TYPE>& s_feature_PE43_2, STREAM<W_TYPE>& s_feature_PE43_3,
    STREAM<W_TYPE>& s_feature_PE44_0, STREAM<W_TYPE>& s_feature_PE44_1,
    STREAM<W_TYPE>& s_feature_PE44_2, STREAM<W_TYPE>& s_feature_PE44_3,
    STREAM<W_TYPE>& s_feature_PE45_0, STREAM<W_TYPE>& s_feature_PE45_1,
    STREAM<W_TYPE>& s_feature_PE45_2, STREAM<W_TYPE>& s_feature_PE45_3,
    STREAM<W_TYPE>& s_feature_PE46_0, STREAM<W_TYPE>& s_feature_PE46_1,
    STREAM<W_TYPE>& s_feature_PE46_2, STREAM<W_TYPE>& s_feature_PE46_3,
    STREAM<W_TYPE>& s_feature_PE47_0, STREAM<W_TYPE>& s_feature_PE47_1,
    STREAM<W_TYPE>& s_feature_PE47_2, STREAM<W_TYPE>& s_feature_PE47_3,
    STREAM<W_TYPE>& s_feature_PE48_0, STREAM<W_TYPE>& s_feature_PE48_1,
    STREAM<W_TYPE>& s_feature_PE48_2, STREAM<W_TYPE>& s_feature_PE48_3,
    STREAM<W_TYPE>& s_feature_PE49_0, STREAM<W_TYPE>& s_feature_PE49_1,
    STREAM<W_TYPE>& s_feature_PE49_2, STREAM<W_TYPE>& s_feature_PE49_3,
    STREAM<W_TYPE>& s_feature_PE50_0, STREAM<W_TYPE>& s_feature_PE50_1,
    STREAM<W_TYPE>& s_feature_PE50_2, STREAM<W_TYPE>& s_feature_PE50_3,
    STREAM<W_TYPE>& s_feature_PE51_0, STREAM<W_TYPE>& s_feature_PE51_1,
    STREAM<W_TYPE>& s_feature_PE51_2, STREAM<W_TYPE>& s_feature_PE51_3,
    STREAM<W_TYPE>& s_feature_PE52_0, STREAM<W_TYPE>& s_feature_PE52_1,
    STREAM<W_TYPE>& s_feature_PE52_2, STREAM<W_TYPE>& s_feature_PE52_3,
    STREAM<W_TYPE>& s_feature_PE53_0, STREAM<W_TYPE>& s_feature_PE53_1,
    STREAM<W_TYPE>& s_feature_PE53_2, STREAM<W_TYPE>& s_feature_PE53_3,
    STREAM<W_TYPE>& s_feature_PE54_0, STREAM<W_TYPE>& s_feature_PE54_1,
    STREAM<W_TYPE>& s_feature_PE54_2, STREAM<W_TYPE>& s_feature_PE54_3,
    STREAM<W_TYPE>& s_feature_PE55_0, STREAM<W_TYPE>& s_feature_PE55_1,
    STREAM<W_TYPE>& s_feature_PE55_2, STREAM<W_TYPE>& s_feature_PE55_3,
    STREAM<W_TYPE>& s_feature_PE56_0, STREAM<W_TYPE>& s_feature_PE56_1,
    STREAM<W_TYPE>& s_feature_PE56_2, STREAM<W_TYPE>& s_feature_PE56_3,
    STREAM<W_TYPE>& s_feature_PE57_0, STREAM<W_TYPE>& s_feature_PE57_1,
    STREAM<W_TYPE>& s_feature_PE57_2, STREAM<W_TYPE>& s_feature_PE57_3,
    STREAM<W_TYPE>& s_feature_PE58_0, STREAM<W_TYPE>& s_feature_PE58_1,
    STREAM<W_TYPE>& s_feature_PE58_2, STREAM<W_TYPE>& s_feature_PE58_3,
    STREAM<W_TYPE>& s_feature_PE59_0, STREAM<W_TYPE>& s_feature_PE59_1,
    STREAM<W_TYPE>& s_feature_PE59_2, STREAM<W_TYPE>& s_feature_PE59_3,
    STREAM<W_TYPE>& s_feature_PE60_0, STREAM<W_TYPE>& s_feature_PE60_1,
    STREAM<W_TYPE>& s_feature_PE60_2, STREAM<W_TYPE>& s_feature_PE60_3,
    STREAM<W_TYPE>& s_feature_PE61_0, STREAM<W_TYPE>& s_feature_PE61_1,
    STREAM<W_TYPE>& s_feature_PE61_2, STREAM<W_TYPE>& s_feature_PE61_3,
    STREAM<W_TYPE>& s_feature_PE62_0, STREAM<W_TYPE>& s_feature_PE62_1,
    STREAM<W_TYPE>& s_feature_PE62_2, STREAM<W_TYPE>& s_feature_PE62_3,
    STREAM<W_TYPE>& s_feature_PE63_0, STREAM<W_TYPE>& s_feature_PE63_1,
    STREAM<W_TYPE>& s_feature_PE63_2, STREAM<W_TYPE>& s_feature_PE63_3,
    STREAM<W_TYPE>& s_feature_PE64_0, STREAM<W_TYPE>& s_feature_PE64_1,
    STREAM<W_TYPE>& s_feature_PE64_2, STREAM<W_TYPE>& s_feature_PE64_3,
    STREAM<W_TYPE>& s_feature_PE65_0, STREAM<W_TYPE>& s_feature_PE65_1,
    STREAM<W_TYPE>& s_feature_PE65_2, STREAM<W_TYPE>& s_feature_PE65_3,
    STREAM<W_TYPE>& s_feature_PE66_0, STREAM<W_TYPE>& s_feature_PE66_1,
    STREAM<W_TYPE>& s_feature_PE66_2, STREAM<W_TYPE>& s_feature_PE66_3,
    STREAM<W_TYPE>& s_feature_PE67_0, STREAM<W_TYPE>& s_feature_PE67_1,
    STREAM<W_TYPE>& s_feature_PE67_2, STREAM<W_TYPE>& s_feature_PE67_3,
    STREAM<W_TYPE>& s_feature_PE68_0, STREAM<W_TYPE>& s_feature_PE68_1,
    STREAM<W_TYPE>& s_feature_PE68_2, STREAM<W_TYPE>& s_feature_PE68_3,
    STREAM<W_TYPE>& s_feature_PE69_0, STREAM<W_TYPE>& s_feature_PE69_1,
    STREAM<W_TYPE>& s_feature_PE69_2, STREAM<W_TYPE>& s_feature_PE69_3,
    STREAM<W_TYPE>& s_feature_PE70_0, STREAM<W_TYPE>& s_feature_PE70_1,
    STREAM<W_TYPE>& s_feature_PE70_2, STREAM<W_TYPE>& s_feature_PE70_3,
    STREAM<W_TYPE>& s_feature_PE71_0, STREAM<W_TYPE>& s_feature_PE71_1,
    STREAM<W_TYPE>& s_feature_PE71_2, STREAM<W_TYPE>& s_feature_PE71_3,
    STREAM<W_TYPE>& s_feature_PE72_0, STREAM<W_TYPE>& s_feature_PE72_1,
    STREAM<W_TYPE>& s_feature_PE72_2, STREAM<W_TYPE>& s_feature_PE72_3,
    STREAM<W_TYPE>& s_feature_PE73_0, STREAM<W_TYPE>& s_feature_PE73_1,
    STREAM<W_TYPE>& s_feature_PE73_2, STREAM<W_TYPE>& s_feature_PE73_3,
    STREAM<W_TYPE>& s_feature_PE74_0, STREAM<W_TYPE>& s_feature_PE74_1,
    STREAM<W_TYPE>& s_feature_PE74_2, STREAM<W_TYPE>& s_feature_PE74_3,
    STREAM<W_TYPE>& s_feature_PE75_0, STREAM<W_TYPE>& s_feature_PE75_1,
    STREAM<W_TYPE>& s_feature_PE75_2, STREAM<W_TYPE>& s_feature_PE75_3,
    STREAM<W_TYPE>& s_feature_PE76_0, STREAM<W_TYPE>& s_feature_PE76_1,
    STREAM<W_TYPE>& s_feature_PE76_2, STREAM<W_TYPE>& s_feature_PE76_3,
    STREAM<W_TYPE>& s_feature_PE77_0, STREAM<W_TYPE>& s_feature_PE77_1,
    STREAM<W_TYPE>& s_feature_PE77_2, STREAM<W_TYPE>& s_feature_PE77_3,
    STREAM<W_TYPE>& s_feature_PE78_0, STREAM<W_TYPE>& s_feature_PE78_1,
    STREAM<W_TYPE>& s_feature_PE78_2, STREAM<W_TYPE>& s_feature_PE78_3,
    STREAM<W_TYPE>& s_feature_PE79_0, STREAM<W_TYPE>& s_feature_PE79_1,
    STREAM<W_TYPE>& s_feature_PE79_2, STREAM<W_TYPE>& s_feature_PE79_3,
    STREAM<W_TYPE>& s_feature_PE80_0, STREAM<W_TYPE>& s_feature_PE80_1,
    STREAM<W_TYPE>& s_feature_PE80_2, STREAM<W_TYPE>& s_feature_PE80_3,
    STREAM<W_TYPE>& s_feature_PE81_0, STREAM<W_TYPE>& s_feature_PE81_1,
    STREAM<W_TYPE>& s_feature_PE81_2, STREAM<W_TYPE>& s_feature_PE81_3,
    STREAM<W_TYPE>& s_feature_PE82_0, STREAM<W_TYPE>& s_feature_PE82_1,
    STREAM<W_TYPE>& s_feature_PE82_2, STREAM<W_TYPE>& s_feature_PE82_3,
    STREAM<W_TYPE>& s_feature_PE83_0, STREAM<W_TYPE>& s_feature_PE83_1,
    STREAM<W_TYPE>& s_feature_PE83_2, STREAM<W_TYPE>& s_feature_PE83_3,
    STREAM<W_TYPE>& s_feature_PE84_0, STREAM<W_TYPE>& s_feature_PE84_1,
    STREAM<W_TYPE>& s_feature_PE84_2, STREAM<W_TYPE>& s_feature_PE84_3,
    STREAM<W_TYPE>& s_feature_PE85_0, STREAM<W_TYPE>& s_feature_PE85_1,
    STREAM<W_TYPE>& s_feature_PE85_2, STREAM<W_TYPE>& s_feature_PE85_3,
    STREAM<W_TYPE>& s_feature_PE86_0, STREAM<W_TYPE>& s_feature_PE86_1,
    STREAM<W_TYPE>& s_feature_PE86_2, STREAM<W_TYPE>& s_feature_PE86_3,
    STREAM<W_TYPE>& s_feature_PE87_0, STREAM<W_TYPE>& s_feature_PE87_1,
    STREAM<W_TYPE>& s_feature_PE87_2, STREAM<W_TYPE>& s_feature_PE87_3,
    STREAM<W_TYPE>& s_feature_PE88_0, STREAM<W_TYPE>& s_feature_PE88_1,
    STREAM<W_TYPE>& s_feature_PE88_2, STREAM<W_TYPE>& s_feature_PE88_3,
    STREAM<W_TYPE>& s_feature_PE89_0, STREAM<W_TYPE>& s_feature_PE89_1,
    STREAM<W_TYPE>& s_feature_PE89_2, STREAM<W_TYPE>& s_feature_PE89_3,
    STREAM<W_TYPE>& s_feature_PE90_0, STREAM<W_TYPE>& s_feature_PE90_1,
    STREAM<W_TYPE>& s_feature_PE90_2, STREAM<W_TYPE>& s_feature_PE90_3,
    STREAM<W_TYPE>& s_feature_PE91_0, STREAM<W_TYPE>& s_feature_PE91_1,
    STREAM<W_TYPE>& s_feature_PE91_2, STREAM<W_TYPE>& s_feature_PE91_3,
    STREAM<W_TYPE>& s_feature_PE92_0, STREAM<W_TYPE>& s_feature_PE92_1,
    STREAM<W_TYPE>& s_feature_PE92_2, STREAM<W_TYPE>& s_feature_PE92_3,
    STREAM<W_TYPE>& s_feature_PE93_0, STREAM<W_TYPE>& s_feature_PE93_1,
    STREAM<W_TYPE>& s_feature_PE93_2, STREAM<W_TYPE>& s_feature_PE93_3,
    STREAM<W_TYPE>& s_feature_PE94_0, STREAM<W_TYPE>& s_feature_PE94_1,
    STREAM<W_TYPE>& s_feature_PE94_2, STREAM<W_TYPE>& s_feature_PE94_3,
    STREAM<W_TYPE>& s_feature_PE95_0, STREAM<W_TYPE>& s_feature_PE95_1,
    STREAM<W_TYPE>& s_feature_PE95_2, STREAM<W_TYPE>& s_feature_PE95_3,
    STREAM<W_TYPE>& s_feature_PE96_0, STREAM<W_TYPE>& s_feature_PE96_1,
    STREAM<W_TYPE>& s_feature_PE96_2, STREAM<W_TYPE>& s_feature_PE96_3,
    STREAM<W_TYPE>& s_feature_PE97_0, STREAM<W_TYPE>& s_feature_PE97_1,
    STREAM<W_TYPE>& s_feature_PE97_2, STREAM<W_TYPE>& s_feature_PE97_3,
    STREAM<W_TYPE>& s_feature_PE98_0, STREAM<W_TYPE>& s_feature_PE98_1,
    STREAM<W_TYPE>& s_feature_PE98_2, STREAM<W_TYPE>& s_feature_PE98_3,
    STREAM<W_TYPE>& s_feature_PE99_0, STREAM<W_TYPE>& s_feature_PE99_1,
    STREAM<W_TYPE>& s_feature_PE99_2, STREAM<W_TYPE>& s_feature_PE99_3,
    STREAM<W_TYPE>& s_feature_PE100_0, STREAM<W_TYPE>& s_feature_PE100_1,
    STREAM<W_TYPE>& s_feature_PE100_2, STREAM<W_TYPE>& s_feature_PE100_3,
    STREAM<W_TYPE>& s_feature_PE101_0, STREAM<W_TYPE>& s_feature_PE101_1,
    STREAM<W_TYPE>& s_feature_PE101_2, STREAM<W_TYPE>& s_feature_PE101_3,
    STREAM<W_TYPE>& s_feature_PE102_0, STREAM<W_TYPE>& s_feature_PE102_1,
    STREAM<W_TYPE>& s_feature_PE102_2, STREAM<W_TYPE>& s_feature_PE102_3,
    STREAM<W_TYPE>& s_feature_PE103_0, STREAM<W_TYPE>& s_feature_PE103_1,
    STREAM<W_TYPE>& s_feature_PE103_2, STREAM<W_TYPE>& s_feature_PE103_3,
    STREAM<W_TYPE>& s_feature_PE104_0, STREAM<W_TYPE>& s_feature_PE104_1,
    STREAM<W_TYPE>& s_feature_PE104_2, STREAM<W_TYPE>& s_feature_PE104_3,
    STREAM<W_TYPE>& s_feature_PE105_0, STREAM<W_TYPE>& s_feature_PE105_1,
    STREAM<W_TYPE>& s_feature_PE105_2, STREAM<W_TYPE>& s_feature_PE105_3,
    STREAM<W_TYPE>& s_feature_PE106_0, STREAM<W_TYPE>& s_feature_PE106_1,
    STREAM<W_TYPE>& s_feature_PE106_2, STREAM<W_TYPE>& s_feature_PE106_3,
    STREAM<W_TYPE>& s_feature_PE107_0, STREAM<W_TYPE>& s_feature_PE107_1,
    STREAM<W_TYPE>& s_feature_PE107_2, STREAM<W_TYPE>& s_feature_PE107_3,
    STREAM<W_TYPE>& s_feature_PE108_0, STREAM<W_TYPE>& s_feature_PE108_1,
    STREAM<W_TYPE>& s_feature_PE108_2, STREAM<W_TYPE>& s_feature_PE108_3,
    STREAM<W_TYPE>& s_feature_PE109_0, STREAM<W_TYPE>& s_feature_PE109_1,
    STREAM<W_TYPE>& s_feature_PE109_2, STREAM<W_TYPE>& s_feature_PE109_3,
    STREAM<W_TYPE>& s_feature_PE110_0, STREAM<W_TYPE>& s_feature_PE110_1,
    STREAM<W_TYPE>& s_feature_PE110_2, STREAM<W_TYPE>& s_feature_PE110_3,
    STREAM<W_TYPE>& s_feature_PE111_0, STREAM<W_TYPE>& s_feature_PE111_1,
    STREAM<W_TYPE>& s_feature_PE111_2, STREAM<W_TYPE>& s_feature_PE111_3,
    STREAM<W_TYPE>& s_feature_PE112_0, STREAM<W_TYPE>& s_feature_PE112_1,
    STREAM<W_TYPE>& s_feature_PE112_2, STREAM<W_TYPE>& s_feature_PE112_3,
    STREAM<W_TYPE>& s_feature_PE113_0, STREAM<W_TYPE>& s_feature_PE113_1,
    STREAM<W_TYPE>& s_feature_PE113_2, STREAM<W_TYPE>& s_feature_PE113_3,
    STREAM<W_TYPE>& s_feature_PE114_0, STREAM<W_TYPE>& s_feature_PE114_1,
    STREAM<W_TYPE>& s_feature_PE114_2, STREAM<W_TYPE>& s_feature_PE114_3,
    STREAM<W_TYPE>& s_feature_PE115_0, STREAM<W_TYPE>& s_feature_PE115_1,
    STREAM<W_TYPE>& s_feature_PE115_2, STREAM<W_TYPE>& s_feature_PE115_3,
    STREAM<W_TYPE>& s_feature_PE116_0, STREAM<W_TYPE>& s_feature_PE116_1,
    STREAM<W_TYPE>& s_feature_PE116_2, STREAM<W_TYPE>& s_feature_PE116_3,
    STREAM<W_TYPE>& s_feature_PE117_0, STREAM<W_TYPE>& s_feature_PE117_1,
    STREAM<W_TYPE>& s_feature_PE117_2, STREAM<W_TYPE>& s_feature_PE117_3,
    STREAM<W_TYPE>& s_feature_PE118_0, STREAM<W_TYPE>& s_feature_PE118_1,
    STREAM<W_TYPE>& s_feature_PE118_2, STREAM<W_TYPE>& s_feature_PE118_3,
    STREAM<W_TYPE>& s_feature_PE119_0, STREAM<W_TYPE>& s_feature_PE119_1,
    STREAM<W_TYPE>& s_feature_PE119_2, STREAM<W_TYPE>& s_feature_PE119_3,
    STREAM<W_TYPE>& s_feature_PE120_0, STREAM<W_TYPE>& s_feature_PE120_1,
    STREAM<W_TYPE>& s_feature_PE120_2, STREAM<W_TYPE>& s_feature_PE120_3,
    STREAM<W_TYPE>& s_feature_PE121_0, STREAM<W_TYPE>& s_feature_PE121_1,
    STREAM<W_TYPE>& s_feature_PE121_2, STREAM<W_TYPE>& s_feature_PE121_3,
    STREAM<W_TYPE>& s_feature_PE122_0, STREAM<W_TYPE>& s_feature_PE122_1,
    STREAM<W_TYPE>& s_feature_PE122_2, STREAM<W_TYPE>& s_feature_PE122_3,
    STREAM<W_TYPE>& s_feature_PE123_0, STREAM<W_TYPE>& s_feature_PE123_1,
    STREAM<W_TYPE>& s_feature_PE123_2, STREAM<W_TYPE>& s_feature_PE123_3,
    STREAM<W_TYPE>& s_feature_PE124_0, STREAM<W_TYPE>& s_feature_PE124_1,
    STREAM<W_TYPE>& s_feature_PE124_2, STREAM<W_TYPE>& s_feature_PE124_3,
    STREAM<W_TYPE>& s_feature_PE125_0, STREAM<W_TYPE>& s_feature_PE125_1,
    STREAM<W_TYPE>& s_feature_PE125_2, STREAM<W_TYPE>& s_feature_PE125_3,
    STREAM<W_TYPE>& s_feature_PE126_0, STREAM<W_TYPE>& s_feature_PE126_1,
    STREAM<W_TYPE>& s_feature_PE126_2, STREAM<W_TYPE>& s_feature_PE126_3,
    STREAM<W_TYPE>& s_feature_PE127_0, STREAM<W_TYPE>& s_feature_PE127_1,
    STREAM<W_TYPE>& s_feature_PE127_2, STREAM<W_TYPE>& s_feature_PE127_3,
    STREAM<W_TYPE>& s_feature_PE128_0, STREAM<W_TYPE>& s_feature_PE128_1,
    STREAM<W_TYPE>& s_feature_PE128_2, STREAM<W_TYPE>& s_feature_PE128_3,
    STREAM<W_TYPE>& s_feature_PE129_0, STREAM<W_TYPE>& s_feature_PE129_1,
    STREAM<W_TYPE>& s_feature_PE129_2, STREAM<W_TYPE>& s_feature_PE129_3,
    STREAM<W_TYPE>& s_feature_PE130_0, STREAM<W_TYPE>& s_feature_PE130_1,
    STREAM<W_TYPE>& s_feature_PE130_2, STREAM<W_TYPE>& s_feature_PE130_3,
    STREAM<W_TYPE>& s_feature_PE131_0, STREAM<W_TYPE>& s_feature_PE131_1,
    STREAM<W_TYPE>& s_feature_PE131_2, STREAM<W_TYPE>& s_feature_PE131_3,
    STREAM<W_TYPE>& s_feature_PE132_0, STREAM<W_TYPE>& s_feature_PE132_1,
    STREAM<W_TYPE>& s_feature_PE132_2, STREAM<W_TYPE>& s_feature_PE132_3,
    STREAM<W_TYPE>& s_feature_PE133_0, STREAM<W_TYPE>& s_feature_PE133_1,
    STREAM<W_TYPE>& s_feature_PE133_2, STREAM<W_TYPE>& s_feature_PE133_3,
    STREAM<W_TYPE>& s_feature_PE134_0, STREAM<W_TYPE>& s_feature_PE134_1,
    STREAM<W_TYPE>& s_feature_PE134_2, STREAM<W_TYPE>& s_feature_PE134_3,
    STREAM<W_TYPE>& s_feature_PE135_0, STREAM<W_TYPE>& s_feature_PE135_1,
    STREAM<W_TYPE>& s_feature_PE135_2, STREAM<W_TYPE>& s_feature_PE135_3,
    STREAM<W_TYPE>& s_feature_PE136_0, STREAM<W_TYPE>& s_feature_PE136_1,
    STREAM<W_TYPE>& s_feature_PE136_2, STREAM<W_TYPE>& s_feature_PE136_3,
    STREAM<W_TYPE>& s_feature_PE137_0, STREAM<W_TYPE>& s_feature_PE137_1,
    STREAM<W_TYPE>& s_feature_PE137_2, STREAM<W_TYPE>& s_feature_PE137_3,
    STREAM<W_TYPE>& s_feature_PE138_0, STREAM<W_TYPE>& s_feature_PE138_1,
    STREAM<W_TYPE>& s_feature_PE138_2, STREAM<W_TYPE>& s_feature_PE138_3,
    STREAM<W_TYPE>& s_feature_PE139_0, STREAM<W_TYPE>& s_feature_PE139_1,
    STREAM<W_TYPE>& s_feature_PE139_2, STREAM<W_TYPE>& s_feature_PE139_3,
    STREAM<W_TYPE>& s_feature_PE140_0, STREAM<W_TYPE>& s_feature_PE140_1,
    STREAM<W_TYPE>& s_feature_PE140_2, STREAM<W_TYPE>& s_feature_PE140_3,
    STREAM<W_TYPE>& s_feature_PE141_0, STREAM<W_TYPE>& s_feature_PE141_1,
    STREAM<W_TYPE>& s_feature_PE141_2, STREAM<W_TYPE>& s_feature_PE141_3,
    STREAM<W_TYPE>& s_feature_PE142_0, STREAM<W_TYPE>& s_feature_PE142_1,
    STREAM<W_TYPE>& s_feature_PE142_2, STREAM<W_TYPE>& s_feature_PE142_3,
    STREAM<W_TYPE>& s_feature_PE143_0, STREAM<W_TYPE>& s_feature_PE143_1,
    STREAM<W_TYPE>& s_feature_PE143_2, STREAM<W_TYPE>& s_feature_PE143_3,
    STREAM<W_TYPE>& s_feature_PE144_0, STREAM<W_TYPE>& s_feature_PE144_1,
    STREAM<W_TYPE>& s_feature_PE144_2, STREAM<W_TYPE>& s_feature_PE144_3,
    STREAM<W_TYPE>& s_feature_PE145_0, STREAM<W_TYPE>& s_feature_PE145_1,
    STREAM<W_TYPE>& s_feature_PE145_2, STREAM<W_TYPE>& s_feature_PE145_3,
    STREAM<W_TYPE>& s_feature_PE146_0, STREAM<W_TYPE>& s_feature_PE146_1,
    STREAM<W_TYPE>& s_feature_PE146_2, STREAM<W_TYPE>& s_feature_PE146_3,
    STREAM<W_TYPE>& s_feature_PE147_0, STREAM<W_TYPE>& s_feature_PE147_1,
    STREAM<W_TYPE>& s_feature_PE147_2, STREAM<W_TYPE>& s_feature_PE147_3,
    STREAM<W_TYPE>& s_feature_PE148_0, STREAM<W_TYPE>& s_feature_PE148_1,
    STREAM<W_TYPE>& s_feature_PE148_2, STREAM<W_TYPE>& s_feature_PE148_3,
    STREAM<W_TYPE>& s_feature_PE149_0, STREAM<W_TYPE>& s_feature_PE149_1,
    STREAM<W_TYPE>& s_feature_PE149_2, STREAM<W_TYPE>& s_feature_PE149_3,
    STREAM<W_TYPE>& s_feature_PE150_0, STREAM<W_TYPE>& s_feature_PE150_1,
    STREAM<W_TYPE>& s_feature_PE150_2, STREAM<W_TYPE>& s_feature_PE150_3,
    STREAM<W_TYPE>& s_feature_PE151_0, STREAM<W_TYPE>& s_feature_PE151_1,
    STREAM<W_TYPE>& s_feature_PE151_2, STREAM<W_TYPE>& s_feature_PE151_3,
    STREAM<W_TYPE>& s_feature_PE152_0, STREAM<W_TYPE>& s_feature_PE152_1,
    STREAM<W_TYPE>& s_feature_PE152_2, STREAM<W_TYPE>& s_feature_PE152_3,
    STREAM<W_TYPE>& s_feature_PE153_0, STREAM<W_TYPE>& s_feature_PE153_1,
    STREAM<W_TYPE>& s_feature_PE153_2, STREAM<W_TYPE>& s_feature_PE153_3,
    STREAM<W_TYPE>& s_feature_PE154_0, STREAM<W_TYPE>& s_feature_PE154_1,
    STREAM<W_TYPE>& s_feature_PE154_2, STREAM<W_TYPE>& s_feature_PE154_3,
    STREAM<W_TYPE>& s_feature_PE155_0, STREAM<W_TYPE>& s_feature_PE155_1,
    STREAM<W_TYPE>& s_feature_PE155_2, STREAM<W_TYPE>& s_feature_PE155_3,
    STREAM<W_TYPE>& s_feature_PE156_0, STREAM<W_TYPE>& s_feature_PE156_1,
    STREAM<W_TYPE>& s_feature_PE156_2, STREAM<W_TYPE>& s_feature_PE156_3,
    STREAM<W_TYPE>& s_feature_PE157_0, STREAM<W_TYPE>& s_feature_PE157_1,
    STREAM<W_TYPE>& s_feature_PE157_2, STREAM<W_TYPE>& s_feature_PE157_3,
    STREAM<W_TYPE>& s_feature_PE158_0, STREAM<W_TYPE>& s_feature_PE158_1,
    STREAM<W_TYPE>& s_feature_PE158_2, STREAM<W_TYPE>& s_feature_PE158_3,
    STREAM<W_TYPE>& s_feature_PE159_0, STREAM<W_TYPE>& s_feature_PE159_1,
    STREAM<W_TYPE>& s_feature_PE159_2, STREAM<W_TYPE>& s_feature_PE159_3,
    STREAM<W_TYPE>& s_feature_PE160_0, STREAM<W_TYPE>& s_feature_PE160_1,
    STREAM<W_TYPE>& s_feature_PE160_2, STREAM<W_TYPE>& s_feature_PE160_3,
    STREAM<W_TYPE>& s_feature_PE161_0, STREAM<W_TYPE>& s_feature_PE161_1,
    STREAM<W_TYPE>& s_feature_PE161_2, STREAM<W_TYPE>& s_feature_PE161_3,
    STREAM<W_TYPE>& s_feature_PE162_0, STREAM<W_TYPE>& s_feature_PE162_1,
    STREAM<W_TYPE>& s_feature_PE162_2, STREAM<W_TYPE>& s_feature_PE162_3,
    STREAM<W_TYPE>& s_feature_PE163_0, STREAM<W_TYPE>& s_feature_PE163_1,
    STREAM<W_TYPE>& s_feature_PE163_2, STREAM<W_TYPE>& s_feature_PE163_3,
    STREAM<W_TYPE>& s_feature_PE164_0, STREAM<W_TYPE>& s_feature_PE164_1,
    STREAM<W_TYPE>& s_feature_PE164_2, STREAM<W_TYPE>& s_feature_PE164_3,
    STREAM<W_TYPE>& s_feature_PE165_0, STREAM<W_TYPE>& s_feature_PE165_1,
    STREAM<W_TYPE>& s_feature_PE165_2, STREAM<W_TYPE>& s_feature_PE165_3,
    STREAM<W_TYPE>& s_feature_PE166_0, STREAM<W_TYPE>& s_feature_PE166_1,
    STREAM<W_TYPE>& s_feature_PE166_2, STREAM<W_TYPE>& s_feature_PE166_3,
    STREAM<W_TYPE>& s_feature_PE167_0, STREAM<W_TYPE>& s_feature_PE167_1,
    STREAM<W_TYPE>& s_feature_PE167_2, STREAM<W_TYPE>& s_feature_PE167_3,
    STREAM<W_TYPE>& s_feature_PE168_0, STREAM<W_TYPE>& s_feature_PE168_1,
    STREAM<W_TYPE>& s_feature_PE168_2, STREAM<W_TYPE>& s_feature_PE168_3,
    STREAM<W_TYPE>& s_feature_PE169_0, STREAM<W_TYPE>& s_feature_PE169_1,
    STREAM<W_TYPE>& s_feature_PE169_2, STREAM<W_TYPE>& s_feature_PE169_3,
    STREAM<W_TYPE>& s_feature_PE170_0, STREAM<W_TYPE>& s_feature_PE170_1,
    STREAM<W_TYPE>& s_feature_PE170_2, STREAM<W_TYPE>& s_feature_PE170_3,
    STREAM<W_TYPE>& s_feature_PE171_0, STREAM<W_TYPE>& s_feature_PE171_1,
    STREAM<W_TYPE>& s_feature_PE171_2, STREAM<W_TYPE>& s_feature_PE171_3,
    STREAM<W_TYPE>& s_feature_PE172_0, STREAM<W_TYPE>& s_feature_PE172_1,
    STREAM<W_TYPE>& s_feature_PE172_2, STREAM<W_TYPE>& s_feature_PE172_3,
    STREAM<W_TYPE>& s_feature_PE173_0, STREAM<W_TYPE>& s_feature_PE173_1,
    STREAM<W_TYPE>& s_feature_PE173_2, STREAM<W_TYPE>& s_feature_PE173_3,
    STREAM<W_TYPE>& s_feature_PE174_0, STREAM<W_TYPE>& s_feature_PE174_1,
    STREAM<W_TYPE>& s_feature_PE174_2, STREAM<W_TYPE>& s_feature_PE174_3,
    STREAM<W_TYPE>& s_feature_PE175_0, STREAM<W_TYPE>& s_feature_PE175_1,
    STREAM<W_TYPE>& s_feature_PE175_2, STREAM<W_TYPE>& s_feature_PE175_3,
    STREAM<W_TYPE>& s_feature_PE176_0, STREAM<W_TYPE>& s_feature_PE176_1,
    STREAM<W_TYPE>& s_feature_PE176_2, STREAM<W_TYPE>& s_feature_PE176_3,
    STREAM<W_TYPE>& s_feature_PE177_0, STREAM<W_TYPE>& s_feature_PE177_1,
    STREAM<W_TYPE>& s_feature_PE177_2, STREAM<W_TYPE>& s_feature_PE177_3,
    STREAM<W_TYPE>& s_feature_PE178_0, STREAM<W_TYPE>& s_feature_PE178_1,
    STREAM<W_TYPE>& s_feature_PE178_2, STREAM<W_TYPE>& s_feature_PE178_3,
    STREAM<W_TYPE>& s_feature_PE179_0, STREAM<W_TYPE>& s_feature_PE179_1,
    STREAM<W_TYPE>& s_feature_PE179_2, STREAM<W_TYPE>& s_feature_PE179_3,
    STREAM<W_TYPE>& s_feature_PE180_0, STREAM<W_TYPE>& s_feature_PE180_1,
    STREAM<W_TYPE>& s_feature_PE180_2, STREAM<W_TYPE>& s_feature_PE180_3,
    STREAM<W_TYPE>& s_feature_PE181_0, STREAM<W_TYPE>& s_feature_PE181_1,
    STREAM<W_TYPE>& s_feature_PE181_2, STREAM<W_TYPE>& s_feature_PE181_3,
    STREAM<W_TYPE>& s_feature_PE182_0, STREAM<W_TYPE>& s_feature_PE182_1,
    STREAM<W_TYPE>& s_feature_PE182_2, STREAM<W_TYPE>& s_feature_PE182_3,
    STREAM<W_TYPE>& s_feature_PE183_0, STREAM<W_TYPE>& s_feature_PE183_1,
    STREAM<W_TYPE>& s_feature_PE183_2, STREAM<W_TYPE>& s_feature_PE183_3,
    STREAM<W_TYPE>& s_feature_PE184_0, STREAM<W_TYPE>& s_feature_PE184_1,
    STREAM<W_TYPE>& s_feature_PE184_2, STREAM<W_TYPE>& s_feature_PE184_3,
    STREAM<W_TYPE>& s_feature_PE185_0, STREAM<W_TYPE>& s_feature_PE185_1,
    STREAM<W_TYPE>& s_feature_PE185_2, STREAM<W_TYPE>& s_feature_PE185_3,
    STREAM<W_TYPE>& s_feature_PE186_0, STREAM<W_TYPE>& s_feature_PE186_1,
    STREAM<W_TYPE>& s_feature_PE186_2, STREAM<W_TYPE>& s_feature_PE186_3,
    STREAM<W_TYPE>& s_feature_PE187_0, STREAM<W_TYPE>& s_feature_PE187_1,
    STREAM<W_TYPE>& s_feature_PE187_2, STREAM<W_TYPE>& s_feature_PE187_3,
    STREAM<W_TYPE>& s_feature_PE188_0, STREAM<W_TYPE>& s_feature_PE188_1,
    STREAM<W_TYPE>& s_feature_PE188_2, STREAM<W_TYPE>& s_feature_PE188_3,
    STREAM<W_TYPE>& s_feature_PE189_0, STREAM<W_TYPE>& s_feature_PE189_1,
    STREAM<W_TYPE>& s_feature_PE189_2, STREAM<W_TYPE>& s_feature_PE189_3,
    STREAM<W_TYPE>& s_feature_PE190_0, STREAM<W_TYPE>& s_feature_PE190_1,
    STREAM<W_TYPE>& s_feature_PE190_2, STREAM<W_TYPE>& s_feature_PE190_3,
    STREAM<W_TYPE>& s_feature_PE191_0, STREAM<W_TYPE>& s_feature_PE191_1,
    STREAM<W_TYPE>& s_feature_PE191_2, STREAM<W_TYPE>& s_feature_PE191_3,
    STREAM<W_TYPE>& s_feature_PE192_0, STREAM<W_TYPE>& s_feature_PE192_1,
    STREAM<W_TYPE>& s_feature_PE192_2, STREAM<W_TYPE>& s_feature_PE192_3,
    STREAM<W_TYPE>& s_feature_PE193_0, STREAM<W_TYPE>& s_feature_PE193_1,
    STREAM<W_TYPE>& s_feature_PE193_2, STREAM<W_TYPE>& s_feature_PE193_3,
    STREAM<W_TYPE>& s_feature_PE194_0, STREAM<W_TYPE>& s_feature_PE194_1,
    STREAM<W_TYPE>& s_feature_PE194_2, STREAM<W_TYPE>& s_feature_PE194_3,
    STREAM<W_TYPE>& s_feature_PE195_0, STREAM<W_TYPE>& s_feature_PE195_1,
    STREAM<W_TYPE>& s_feature_PE195_2, STREAM<W_TYPE>& s_feature_PE195_3,
    STREAM<W_TYPE>& s_feature_PE196_0, STREAM<W_TYPE>& s_feature_PE196_1,
    STREAM<W_TYPE>& s_feature_PE196_2, STREAM<W_TYPE>& s_feature_PE196_3,
    STREAM<W_TYPE>& s_feature_PE197_0, STREAM<W_TYPE>& s_feature_PE197_1,
    STREAM<W_TYPE>& s_feature_PE197_2, STREAM<W_TYPE>& s_feature_PE197_3,
    STREAM<W_TYPE>& s_feature_PE198_0, STREAM<W_TYPE>& s_feature_PE198_1,
    STREAM<W_TYPE>& s_feature_PE198_2, STREAM<W_TYPE>& s_feature_PE198_3,
    STREAM<W_TYPE>& s_feature_PE199_0, STREAM<W_TYPE>& s_feature_PE199_1,
    STREAM<W_TYPE>& s_feature_PE199_2, STREAM<W_TYPE>& s_feature_PE199_3,
    STREAM<W_TYPE>& s_feature_PE200_0, STREAM<W_TYPE>& s_feature_PE200_1,
    STREAM<W_TYPE>& s_feature_PE200_2, STREAM<W_TYPE>& s_feature_PE200_3,
    STREAM<W_TYPE>& s_feature_PE201_0, STREAM<W_TYPE>& s_feature_PE201_1,
    STREAM<W_TYPE>& s_feature_PE201_2, STREAM<W_TYPE>& s_feature_PE201_3,
    STREAM<W_TYPE>& s_feature_PE202_0, STREAM<W_TYPE>& s_feature_PE202_1,
    STREAM<W_TYPE>& s_feature_PE202_2, STREAM<W_TYPE>& s_feature_PE202_3,
    STREAM<W_TYPE>& s_feature_PE203_0, STREAM<W_TYPE>& s_feature_PE203_1,
    STREAM<W_TYPE>& s_feature_PE203_2, STREAM<W_TYPE>& s_feature_PE203_3,
    STREAM<W_TYPE>& s_feature_PE204_0, STREAM<W_TYPE>& s_feature_PE204_1,
    STREAM<W_TYPE>& s_feature_PE204_2, STREAM<W_TYPE>& s_feature_PE204_3,
    STREAM<W_TYPE>& s_feature_PE205_0, STREAM<W_TYPE>& s_feature_PE205_1,
    STREAM<W_TYPE>& s_feature_PE205_2, STREAM<W_TYPE>& s_feature_PE205_3,
    STREAM<W_TYPE>& s_feature_PE206_0, STREAM<W_TYPE>& s_feature_PE206_1,
    STREAM<W_TYPE>& s_feature_PE206_2, STREAM<W_TYPE>& s_feature_PE206_3,
    STREAM<W_TYPE>& s_feature_PE207_0, STREAM<W_TYPE>& s_feature_PE207_1,
    STREAM<W_TYPE>& s_feature_PE207_2, STREAM<W_TYPE>& s_feature_PE207_3,
    STREAM<W_TYPE>& s_feature_PE208_0, STREAM<W_TYPE>& s_feature_PE208_1,
    STREAM<W_TYPE>& s_feature_PE208_2, STREAM<W_TYPE>& s_feature_PE208_3,
    STREAM<W_TYPE>& s_feature_PE209_0, STREAM<W_TYPE>& s_feature_PE209_1,
    STREAM<W_TYPE>& s_feature_PE209_2, STREAM<W_TYPE>& s_feature_PE209_3,
    STREAM<W_TYPE>& s_feature_PE210_0, STREAM<W_TYPE>& s_feature_PE210_1,
    STREAM<W_TYPE>& s_feature_PE210_2, STREAM<W_TYPE>& s_feature_PE210_3,
    STREAM<W_TYPE>& s_feature_PE211_0, STREAM<W_TYPE>& s_feature_PE211_1,
    STREAM<W_TYPE>& s_feature_PE211_2, STREAM<W_TYPE>& s_feature_PE211_3,
    STREAM<W_TYPE>& s_feature_PE212_0, STREAM<W_TYPE>& s_feature_PE212_1,
    STREAM<W_TYPE>& s_feature_PE212_2, STREAM<W_TYPE>& s_feature_PE212_3,
    STREAM<W_TYPE>& s_feature_PE213_0, STREAM<W_TYPE>& s_feature_PE213_1,
    STREAM<W_TYPE>& s_feature_PE213_2, STREAM<W_TYPE>& s_feature_PE213_3,
    STREAM<W_TYPE>& s_feature_PE214_0, STREAM<W_TYPE>& s_feature_PE214_1,
    STREAM<W_TYPE>& s_feature_PE214_2, STREAM<W_TYPE>& s_feature_PE214_3,
    STREAM<W_TYPE>& s_feature_PE215_0, STREAM<W_TYPE>& s_feature_PE215_1,
    STREAM<W_TYPE>& s_feature_PE215_2, STREAM<W_TYPE>& s_feature_PE215_3
) {

    for (int i = 0; i < BATCH_NUM * BATCH_SIZE * FEATURE_SIZE / INTS_PER_W / 4; i++) {
        #pragma HLS pipeline II=1

        ap_uint<512>  reg = s_feature_in.read();

        W_TYPE reg0 = reg.range(127, 0);
        W_TYPE reg1 = reg.range(255, 128);
        W_TYPE reg2 = reg.range(383, 256);
        W_TYPE reg3 = reg.range(511, 255);

        s_embedding_table.write(reg);

        s_feature_PE0_0.write(reg0);
        s_feature_PE0_1.write(reg1);
        s_feature_PE0_2.write(reg2);
        s_feature_PE0_3.write(reg3);
        s_feature_PE1_0.write(reg0);
        s_feature_PE1_1.write(reg1);
        s_feature_PE1_2.write(reg2);
        s_feature_PE1_3.write(reg3);
        s_feature_PE2_0.write(reg0);
        s_feature_PE2_1.write(reg1);
        s_feature_PE2_2.write(reg2);
        s_feature_PE2_3.write(reg3);
        s_feature_PE3_0.write(reg0);
        s_feature_PE3_1.write(reg1);
        s_feature_PE3_2.write(reg2);
        s_feature_PE3_3.write(reg3);
        s_feature_PE4_0.write(reg0);
        s_feature_PE4_1.write(reg1);
        s_feature_PE4_2.write(reg2);
        s_feature_PE4_3.write(reg3);
        s_feature_PE5_0.write(reg0);
        s_feature_PE5_1.write(reg1);
        s_feature_PE5_2.write(reg2);
        s_feature_PE5_3.write(reg3);
        s_feature_PE6_0.write(reg0);
        s_feature_PE6_1.write(reg1);
        s_feature_PE6_2.write(reg2);
        s_feature_PE6_3.write(reg3);
        s_feature_PE7_0.write(reg0);
        s_feature_PE7_1.write(reg1);
        s_feature_PE7_2.write(reg2);
        s_feature_PE7_3.write(reg3);
        s_feature_PE8_0.write(reg0);
        s_feature_PE8_1.write(reg1);
        s_feature_PE8_2.write(reg2);
        s_feature_PE8_3.write(reg3);
        s_feature_PE9_0.write(reg0);
        s_feature_PE9_1.write(reg1);
        s_feature_PE9_2.write(reg2);
        s_feature_PE9_3.write(reg3);
        s_feature_PE10_0.write(reg0);
        s_feature_PE10_1.write(reg1);
        s_feature_PE10_2.write(reg2);
        s_feature_PE10_3.write(reg3);
        s_feature_PE11_0.write(reg0);
        s_feature_PE11_1.write(reg1);
        s_feature_PE11_2.write(reg2);
        s_feature_PE11_3.write(reg3);
        s_feature_PE12_0.write(reg0);
        s_feature_PE12_1.write(reg1);
        s_feature_PE12_2.write(reg2);
        s_feature_PE12_3.write(reg3);
        s_feature_PE13_0.write(reg0);
        s_feature_PE13_1.write(reg1);
        s_feature_PE13_2.write(reg2);
        s_feature_PE13_3.write(reg3);
        s_feature_PE14_0.write(reg0);
        s_feature_PE14_1.write(reg1);
        s_feature_PE14_2.write(reg2);
        s_feature_PE14_3.write(reg3);
        s_feature_PE15_0.write(reg0);
        s_feature_PE15_1.write(reg1);
        s_feature_PE15_2.write(reg2);
        s_feature_PE15_3.write(reg3);
        s_feature_PE16_0.write(reg0);
        s_feature_PE16_1.write(reg1);
        s_feature_PE16_2.write(reg2);
        s_feature_PE16_3.write(reg3);
        s_feature_PE17_0.write(reg0);
        s_feature_PE17_1.write(reg1);
        s_feature_PE17_2.write(reg2);
        s_feature_PE17_3.write(reg3);
        s_feature_PE18_0.write(reg0);
        s_feature_PE18_1.write(reg1);
        s_feature_PE18_2.write(reg2);
        s_feature_PE18_3.write(reg3);
        s_feature_PE19_0.write(reg0);
        s_feature_PE19_1.write(reg1);
        s_feature_PE19_2.write(reg2);
        s_feature_PE19_3.write(reg3);
        s_feature_PE20_0.write(reg0);
        s_feature_PE20_1.write(reg1);
        s_feature_PE20_2.write(reg2);
        s_feature_PE20_3.write(reg3);
        s_feature_PE21_0.write(reg0);
        s_feature_PE21_1.write(reg1);
        s_feature_PE21_2.write(reg2);
        s_feature_PE21_3.write(reg3);
        s_feature_PE22_0.write(reg0);
        s_feature_PE22_1.write(reg1);
        s_feature_PE22_2.write(reg2);
        s_feature_PE22_3.write(reg3);
        s_feature_PE23_0.write(reg0);
        s_feature_PE23_1.write(reg1);
        s_feature_PE23_2.write(reg2);
        s_feature_PE23_3.write(reg3);
        s_feature_PE24_0.write(reg0);
        s_feature_PE24_1.write(reg1);
        s_feature_PE24_2.write(reg2);
        s_feature_PE24_3.write(reg3);
        s_feature_PE25_0.write(reg0);
        s_feature_PE25_1.write(reg1);
        s_feature_PE25_2.write(reg2);
        s_feature_PE25_3.write(reg3);
        s_feature_PE26_0.write(reg0);
        s_feature_PE26_1.write(reg1);
        s_feature_PE26_2.write(reg2);
        s_feature_PE26_3.write(reg3);
        s_feature_PE27_0.write(reg0);
        s_feature_PE27_1.write(reg1);
        s_feature_PE27_2.write(reg2);
        s_feature_PE27_3.write(reg3);
        s_feature_PE28_0.write(reg0);
        s_feature_PE28_1.write(reg1);
        s_feature_PE28_2.write(reg2);
        s_feature_PE28_3.write(reg3);
        s_feature_PE29_0.write(reg0);
        s_feature_PE29_1.write(reg1);
        s_feature_PE29_2.write(reg2);
        s_feature_PE29_3.write(reg3);
        s_feature_PE30_0.write(reg0);
        s_feature_PE30_1.write(reg1);
        s_feature_PE30_2.write(reg2);
        s_feature_PE30_3.write(reg3);
        s_feature_PE31_0.write(reg0);
        s_feature_PE31_1.write(reg1);
        s_feature_PE31_2.write(reg2);
        s_feature_PE31_3.write(reg3);
        s_feature_PE32_0.write(reg0);
        s_feature_PE32_1.write(reg1);
        s_feature_PE32_2.write(reg2);
        s_feature_PE32_3.write(reg3);
        s_feature_PE33_0.write(reg0);
        s_feature_PE33_1.write(reg1);
        s_feature_PE33_2.write(reg2);
        s_feature_PE33_3.write(reg3);
        s_feature_PE34_0.write(reg0);
        s_feature_PE34_1.write(reg1);
        s_feature_PE34_2.write(reg2);
        s_feature_PE34_3.write(reg3);
        s_feature_PE35_0.write(reg0);
        s_feature_PE35_1.write(reg1);
        s_feature_PE35_2.write(reg2);
        s_feature_PE35_3.write(reg3);
        s_feature_PE36_0.write(reg0);
        s_feature_PE36_1.write(reg1);
        s_feature_PE36_2.write(reg2);
        s_feature_PE36_3.write(reg3);
        s_feature_PE37_0.write(reg0);
        s_feature_PE37_1.write(reg1);
        s_feature_PE37_2.write(reg2);
        s_feature_PE37_3.write(reg3);
        s_feature_PE38_0.write(reg0);
        s_feature_PE38_1.write(reg1);
        s_feature_PE38_2.write(reg2);
        s_feature_PE38_3.write(reg3);
        s_feature_PE39_0.write(reg0);
        s_feature_PE39_1.write(reg1);
        s_feature_PE39_2.write(reg2);
        s_feature_PE39_3.write(reg3);
        s_feature_PE40_0.write(reg0);
        s_feature_PE40_1.write(reg1);
        s_feature_PE40_2.write(reg2);
        s_feature_PE40_3.write(reg3);
        s_feature_PE41_0.write(reg0);
        s_feature_PE41_1.write(reg1);
        s_feature_PE41_2.write(reg2);
        s_feature_PE41_3.write(reg3);
        s_feature_PE42_0.write(reg0);
        s_feature_PE42_1.write(reg1);
        s_feature_PE42_2.write(reg2);
        s_feature_PE42_3.write(reg3);
        s_feature_PE43_0.write(reg0);
        s_feature_PE43_1.write(reg1);
        s_feature_PE43_2.write(reg2);
        s_feature_PE43_3.write(reg3);
        s_feature_PE44_0.write(reg0);
        s_feature_PE44_1.write(reg1);
        s_feature_PE44_2.write(reg2);
        s_feature_PE44_3.write(reg3);
        s_feature_PE45_0.write(reg0);
        s_feature_PE45_1.write(reg1);
        s_feature_PE45_2.write(reg2);
        s_feature_PE45_3.write(reg3);
        s_feature_PE46_0.write(reg0);
        s_feature_PE46_1.write(reg1);
        s_feature_PE46_2.write(reg2);
        s_feature_PE46_3.write(reg3);
        s_feature_PE47_0.write(reg0);
        s_feature_PE47_1.write(reg1);
        s_feature_PE47_2.write(reg2);
        s_feature_PE47_3.write(reg3);
        s_feature_PE48_0.write(reg0);
        s_feature_PE48_1.write(reg1);
        s_feature_PE48_2.write(reg2);
        s_feature_PE48_3.write(reg3);
        s_feature_PE49_0.write(reg0);
        s_feature_PE49_1.write(reg1);
        s_feature_PE49_2.write(reg2);
        s_feature_PE49_3.write(reg3);
        s_feature_PE50_0.write(reg0);
        s_feature_PE50_1.write(reg1);
        s_feature_PE50_2.write(reg2);
        s_feature_PE50_3.write(reg3);
        s_feature_PE51_0.write(reg0);
        s_feature_PE51_1.write(reg1);
        s_feature_PE51_2.write(reg2);
        s_feature_PE51_3.write(reg3);
        s_feature_PE52_0.write(reg0);
        s_feature_PE52_1.write(reg1);
        s_feature_PE52_2.write(reg2);
        s_feature_PE52_3.write(reg3);
        s_feature_PE53_0.write(reg0);
        s_feature_PE53_1.write(reg1);
        s_feature_PE53_2.write(reg2);
        s_feature_PE53_3.write(reg3);
        s_feature_PE54_0.write(reg0);
        s_feature_PE54_1.write(reg1);
        s_feature_PE54_2.write(reg2);
        s_feature_PE54_3.write(reg3);
        s_feature_PE55_0.write(reg0);
        s_feature_PE55_1.write(reg1);
        s_feature_PE55_2.write(reg2);
        s_feature_PE55_3.write(reg3);
        s_feature_PE56_0.write(reg0);
        s_feature_PE56_1.write(reg1);
        s_feature_PE56_2.write(reg2);
        s_feature_PE56_3.write(reg3);
        s_feature_PE57_0.write(reg0);
        s_feature_PE57_1.write(reg1);
        s_feature_PE57_2.write(reg2);
        s_feature_PE57_3.write(reg3);
        s_feature_PE58_0.write(reg0);
        s_feature_PE58_1.write(reg1);
        s_feature_PE58_2.write(reg2);
        s_feature_PE58_3.write(reg3);
        s_feature_PE59_0.write(reg0);
        s_feature_PE59_1.write(reg1);
        s_feature_PE59_2.write(reg2);
        s_feature_PE59_3.write(reg3);
        s_feature_PE60_0.write(reg0);
        s_feature_PE60_1.write(reg1);
        s_feature_PE60_2.write(reg2);
        s_feature_PE60_3.write(reg3);
        s_feature_PE61_0.write(reg0);
        s_feature_PE61_1.write(reg1);
        s_feature_PE61_2.write(reg2);
        s_feature_PE61_3.write(reg3);
        s_feature_PE62_0.write(reg0);
        s_feature_PE62_1.write(reg1);
        s_feature_PE62_2.write(reg2);
        s_feature_PE62_3.write(reg3);
        s_feature_PE63_0.write(reg0);
        s_feature_PE63_1.write(reg1);
        s_feature_PE63_2.write(reg2);
        s_feature_PE63_3.write(reg3);
        s_feature_PE64_0.write(reg0);
        s_feature_PE64_1.write(reg1);
        s_feature_PE64_2.write(reg2);
        s_feature_PE64_3.write(reg3);
        s_feature_PE65_0.write(reg0);
        s_feature_PE65_1.write(reg1);
        s_feature_PE65_2.write(reg2);
        s_feature_PE65_3.write(reg3);
        s_feature_PE66_0.write(reg0);
        s_feature_PE66_1.write(reg1);
        s_feature_PE66_2.write(reg2);
        s_feature_PE66_3.write(reg3);
        s_feature_PE67_0.write(reg0);
        s_feature_PE67_1.write(reg1);
        s_feature_PE67_2.write(reg2);
        s_feature_PE67_3.write(reg3);
        s_feature_PE68_0.write(reg0);
        s_feature_PE68_1.write(reg1);
        s_feature_PE68_2.write(reg2);
        s_feature_PE68_3.write(reg3);
        s_feature_PE69_0.write(reg0);
        s_feature_PE69_1.write(reg1);
        s_feature_PE69_2.write(reg2);
        s_feature_PE69_3.write(reg3);
        s_feature_PE70_0.write(reg0);
        s_feature_PE70_1.write(reg1);
        s_feature_PE70_2.write(reg2);
        s_feature_PE70_3.write(reg3);
        s_feature_PE71_0.write(reg0);
        s_feature_PE71_1.write(reg1);
        s_feature_PE71_2.write(reg2);
        s_feature_PE71_3.write(reg3);
        s_feature_PE72_0.write(reg0);
        s_feature_PE72_1.write(reg1);
        s_feature_PE72_2.write(reg2);
        s_feature_PE72_3.write(reg3);
        s_feature_PE73_0.write(reg0);
        s_feature_PE73_1.write(reg1);
        s_feature_PE73_2.write(reg2);
        s_feature_PE73_3.write(reg3);
        s_feature_PE74_0.write(reg0);
        s_feature_PE74_1.write(reg1);
        s_feature_PE74_2.write(reg2);
        s_feature_PE74_3.write(reg3);
        s_feature_PE75_0.write(reg0);
        s_feature_PE75_1.write(reg1);
        s_feature_PE75_2.write(reg2);
        s_feature_PE75_3.write(reg3);
        s_feature_PE76_0.write(reg0);
        s_feature_PE76_1.write(reg1);
        s_feature_PE76_2.write(reg2);
        s_feature_PE76_3.write(reg3);
        s_feature_PE77_0.write(reg0);
        s_feature_PE77_1.write(reg1);
        s_feature_PE77_2.write(reg2);
        s_feature_PE77_3.write(reg3);
        s_feature_PE78_0.write(reg0);
        s_feature_PE78_1.write(reg1);
        s_feature_PE78_2.write(reg2);
        s_feature_PE78_3.write(reg3);
        s_feature_PE79_0.write(reg0);
        s_feature_PE79_1.write(reg1);
        s_feature_PE79_2.write(reg2);
        s_feature_PE79_3.write(reg3);
        s_feature_PE80_0.write(reg0);
        s_feature_PE80_1.write(reg1);
        s_feature_PE80_2.write(reg2);
        s_feature_PE80_3.write(reg3);
        s_feature_PE81_0.write(reg0);
        s_feature_PE81_1.write(reg1);
        s_feature_PE81_2.write(reg2);
        s_feature_PE81_3.write(reg3);
        s_feature_PE82_0.write(reg0);
        s_feature_PE82_1.write(reg1);
        s_feature_PE82_2.write(reg2);
        s_feature_PE82_3.write(reg3);
        s_feature_PE83_0.write(reg0);
        s_feature_PE83_1.write(reg1);
        s_feature_PE83_2.write(reg2);
        s_feature_PE83_3.write(reg3);
        s_feature_PE84_0.write(reg0);
        s_feature_PE84_1.write(reg1);
        s_feature_PE84_2.write(reg2);
        s_feature_PE84_3.write(reg3);
        s_feature_PE85_0.write(reg0);
        s_feature_PE85_1.write(reg1);
        s_feature_PE85_2.write(reg2);
        s_feature_PE85_3.write(reg3);
        s_feature_PE86_0.write(reg0);
        s_feature_PE86_1.write(reg1);
        s_feature_PE86_2.write(reg2);
        s_feature_PE86_3.write(reg3);
        s_feature_PE87_0.write(reg0);
        s_feature_PE87_1.write(reg1);
        s_feature_PE87_2.write(reg2);
        s_feature_PE87_3.write(reg3);
        s_feature_PE88_0.write(reg0);
        s_feature_PE88_1.write(reg1);
        s_feature_PE88_2.write(reg2);
        s_feature_PE88_3.write(reg3);
        s_feature_PE89_0.write(reg0);
        s_feature_PE89_1.write(reg1);
        s_feature_PE89_2.write(reg2);
        s_feature_PE89_3.write(reg3);
        s_feature_PE90_0.write(reg0);
        s_feature_PE90_1.write(reg1);
        s_feature_PE90_2.write(reg2);
        s_feature_PE90_3.write(reg3);
        s_feature_PE91_0.write(reg0);
        s_feature_PE91_1.write(reg1);
        s_feature_PE91_2.write(reg2);
        s_feature_PE91_3.write(reg3);
        s_feature_PE92_0.write(reg0);
        s_feature_PE92_1.write(reg1);
        s_feature_PE92_2.write(reg2);
        s_feature_PE92_3.write(reg3);
        s_feature_PE93_0.write(reg0);
        s_feature_PE93_1.write(reg1);
        s_feature_PE93_2.write(reg2);
        s_feature_PE93_3.write(reg3);
        s_feature_PE94_0.write(reg0);
        s_feature_PE94_1.write(reg1);
        s_feature_PE94_2.write(reg2);
        s_feature_PE94_3.write(reg3);
        s_feature_PE95_0.write(reg0);
        s_feature_PE95_1.write(reg1);
        s_feature_PE95_2.write(reg2);
        s_feature_PE95_3.write(reg3);
        s_feature_PE96_0.write(reg0);
        s_feature_PE96_1.write(reg1);
        s_feature_PE96_2.write(reg2);
        s_feature_PE96_3.write(reg3);
        s_feature_PE97_0.write(reg0);
        s_feature_PE97_1.write(reg1);
        s_feature_PE97_2.write(reg2);
        s_feature_PE97_3.write(reg3);
        s_feature_PE98_0.write(reg0);
        s_feature_PE98_1.write(reg1);
        s_feature_PE98_2.write(reg2);
        s_feature_PE98_3.write(reg3);
        s_feature_PE99_0.write(reg0);
        s_feature_PE99_1.write(reg1);
        s_feature_PE99_2.write(reg2);
        s_feature_PE99_3.write(reg3);
        s_feature_PE100_0.write(reg0);
        s_feature_PE100_1.write(reg1);
        s_feature_PE100_2.write(reg2);
        s_feature_PE100_3.write(reg3);
        s_feature_PE101_0.write(reg0);
        s_feature_PE101_1.write(reg1);
        s_feature_PE101_2.write(reg2);
        s_feature_PE101_3.write(reg3);
        s_feature_PE102_0.write(reg0);
        s_feature_PE102_1.write(reg1);
        s_feature_PE102_2.write(reg2);
        s_feature_PE102_3.write(reg3);
        s_feature_PE103_0.write(reg0);
        s_feature_PE103_1.write(reg1);
        s_feature_PE103_2.write(reg2);
        s_feature_PE103_3.write(reg3);
        s_feature_PE104_0.write(reg0);
        s_feature_PE104_1.write(reg1);
        s_feature_PE104_2.write(reg2);
        s_feature_PE104_3.write(reg3);
        s_feature_PE105_0.write(reg0);
        s_feature_PE105_1.write(reg1);
        s_feature_PE105_2.write(reg2);
        s_feature_PE105_3.write(reg3);
        s_feature_PE106_0.write(reg0);
        s_feature_PE106_1.write(reg1);
        s_feature_PE106_2.write(reg2);
        s_feature_PE106_3.write(reg3);
        s_feature_PE107_0.write(reg0);
        s_feature_PE107_1.write(reg1);
        s_feature_PE107_2.write(reg2);
        s_feature_PE107_3.write(reg3);
        s_feature_PE108_0.write(reg0);
        s_feature_PE108_1.write(reg1);
        s_feature_PE108_2.write(reg2);
        s_feature_PE108_3.write(reg3);
        s_feature_PE109_0.write(reg0);
        s_feature_PE109_1.write(reg1);
        s_feature_PE109_2.write(reg2);
        s_feature_PE109_3.write(reg3);
        s_feature_PE110_0.write(reg0);
        s_feature_PE110_1.write(reg1);
        s_feature_PE110_2.write(reg2);
        s_feature_PE110_3.write(reg3);
        s_feature_PE111_0.write(reg0);
        s_feature_PE111_1.write(reg1);
        s_feature_PE111_2.write(reg2);
        s_feature_PE111_3.write(reg3);
        s_feature_PE112_0.write(reg0);
        s_feature_PE112_1.write(reg1);
        s_feature_PE112_2.write(reg2);
        s_feature_PE112_3.write(reg3);
        s_feature_PE113_0.write(reg0);
        s_feature_PE113_1.write(reg1);
        s_feature_PE113_2.write(reg2);
        s_feature_PE113_3.write(reg3);
        s_feature_PE114_0.write(reg0);
        s_feature_PE114_1.write(reg1);
        s_feature_PE114_2.write(reg2);
        s_feature_PE114_3.write(reg3);
        s_feature_PE115_0.write(reg0);
        s_feature_PE115_1.write(reg1);
        s_feature_PE115_2.write(reg2);
        s_feature_PE115_3.write(reg3);
        s_feature_PE116_0.write(reg0);
        s_feature_PE116_1.write(reg1);
        s_feature_PE116_2.write(reg2);
        s_feature_PE116_3.write(reg3);
        s_feature_PE117_0.write(reg0);
        s_feature_PE117_1.write(reg1);
        s_feature_PE117_2.write(reg2);
        s_feature_PE117_3.write(reg3);
        s_feature_PE118_0.write(reg0);
        s_feature_PE118_1.write(reg1);
        s_feature_PE118_2.write(reg2);
        s_feature_PE118_3.write(reg3);
        s_feature_PE119_0.write(reg0);
        s_feature_PE119_1.write(reg1);
        s_feature_PE119_2.write(reg2);
        s_feature_PE119_3.write(reg3);
        s_feature_PE120_0.write(reg0);
        s_feature_PE120_1.write(reg1);
        s_feature_PE120_2.write(reg2);
        s_feature_PE120_3.write(reg3);
        s_feature_PE121_0.write(reg0);
        s_feature_PE121_1.write(reg1);
        s_feature_PE121_2.write(reg2);
        s_feature_PE121_3.write(reg3);
        s_feature_PE122_0.write(reg0);
        s_feature_PE122_1.write(reg1);
        s_feature_PE122_2.write(reg2);
        s_feature_PE122_3.write(reg3);
        s_feature_PE123_0.write(reg0);
        s_feature_PE123_1.write(reg1);
        s_feature_PE123_2.write(reg2);
        s_feature_PE123_3.write(reg3);
        s_feature_PE124_0.write(reg0);
        s_feature_PE124_1.write(reg1);
        s_feature_PE124_2.write(reg2);
        s_feature_PE124_3.write(reg3);
        s_feature_PE125_0.write(reg0);
        s_feature_PE125_1.write(reg1);
        s_feature_PE125_2.write(reg2);
        s_feature_PE125_3.write(reg3);
        s_feature_PE126_0.write(reg0);
        s_feature_PE126_1.write(reg1);
        s_feature_PE126_2.write(reg2);
        s_feature_PE126_3.write(reg3);
        s_feature_PE127_0.write(reg0);
        s_feature_PE127_1.write(reg1);
        s_feature_PE127_2.write(reg2);
        s_feature_PE127_3.write(reg3);
        s_feature_PE128_0.write(reg0);
        s_feature_PE128_1.write(reg1);
        s_feature_PE128_2.write(reg2);
        s_feature_PE128_3.write(reg3);
        s_feature_PE129_0.write(reg0);
        s_feature_PE129_1.write(reg1);
        s_feature_PE129_2.write(reg2);
        s_feature_PE129_3.write(reg3);
        s_feature_PE130_0.write(reg0);
        s_feature_PE130_1.write(reg1);
        s_feature_PE130_2.write(reg2);
        s_feature_PE130_3.write(reg3);
        s_feature_PE131_0.write(reg0);
        s_feature_PE131_1.write(reg1);
        s_feature_PE131_2.write(reg2);
        s_feature_PE131_3.write(reg3);
        s_feature_PE132_0.write(reg0);
        s_feature_PE132_1.write(reg1);
        s_feature_PE132_2.write(reg2);
        s_feature_PE132_3.write(reg3);
        s_feature_PE133_0.write(reg0);
        s_feature_PE133_1.write(reg1);
        s_feature_PE133_2.write(reg2);
        s_feature_PE133_3.write(reg3);
        s_feature_PE134_0.write(reg0);
        s_feature_PE134_1.write(reg1);
        s_feature_PE134_2.write(reg2);
        s_feature_PE134_3.write(reg3);
        s_feature_PE135_0.write(reg0);
        s_feature_PE135_1.write(reg1);
        s_feature_PE135_2.write(reg2);
        s_feature_PE135_3.write(reg3);
        s_feature_PE136_0.write(reg0);
        s_feature_PE136_1.write(reg1);
        s_feature_PE136_2.write(reg2);
        s_feature_PE136_3.write(reg3);
        s_feature_PE137_0.write(reg0);
        s_feature_PE137_1.write(reg1);
        s_feature_PE137_2.write(reg2);
        s_feature_PE137_3.write(reg3);
        s_feature_PE138_0.write(reg0);
        s_feature_PE138_1.write(reg1);
        s_feature_PE138_2.write(reg2);
        s_feature_PE138_3.write(reg3);
        s_feature_PE139_0.write(reg0);
        s_feature_PE139_1.write(reg1);
        s_feature_PE139_2.write(reg2);
        s_feature_PE139_3.write(reg3);
        s_feature_PE140_0.write(reg0);
        s_feature_PE140_1.write(reg1);
        s_feature_PE140_2.write(reg2);
        s_feature_PE140_3.write(reg3);
        s_feature_PE141_0.write(reg0);
        s_feature_PE141_1.write(reg1);
        s_feature_PE141_2.write(reg2);
        s_feature_PE141_3.write(reg3);
        s_feature_PE142_0.write(reg0);
        s_feature_PE142_1.write(reg1);
        s_feature_PE142_2.write(reg2);
        s_feature_PE142_3.write(reg3);
        s_feature_PE143_0.write(reg0);
        s_feature_PE143_1.write(reg1);
        s_feature_PE143_2.write(reg2);
        s_feature_PE143_3.write(reg3);
        s_feature_PE144_0.write(reg0);
        s_feature_PE144_1.write(reg1);
        s_feature_PE144_2.write(reg2);
        s_feature_PE144_3.write(reg3);
        s_feature_PE145_0.write(reg0);
        s_feature_PE145_1.write(reg1);
        s_feature_PE145_2.write(reg2);
        s_feature_PE145_3.write(reg3);
        s_feature_PE146_0.write(reg0);
        s_feature_PE146_1.write(reg1);
        s_feature_PE146_2.write(reg2);
        s_feature_PE146_3.write(reg3);
        s_feature_PE147_0.write(reg0);
        s_feature_PE147_1.write(reg1);
        s_feature_PE147_2.write(reg2);
        s_feature_PE147_3.write(reg3);
        s_feature_PE148_0.write(reg0);
        s_feature_PE148_1.write(reg1);
        s_feature_PE148_2.write(reg2);
        s_feature_PE148_3.write(reg3);
        s_feature_PE149_0.write(reg0);
        s_feature_PE149_1.write(reg1);
        s_feature_PE149_2.write(reg2);
        s_feature_PE149_3.write(reg3);
        s_feature_PE150_0.write(reg0);
        s_feature_PE150_1.write(reg1);
        s_feature_PE150_2.write(reg2);
        s_feature_PE150_3.write(reg3);
        s_feature_PE151_0.write(reg0);
        s_feature_PE151_1.write(reg1);
        s_feature_PE151_2.write(reg2);
        s_feature_PE151_3.write(reg3);
        s_feature_PE152_0.write(reg0);
        s_feature_PE152_1.write(reg1);
        s_feature_PE152_2.write(reg2);
        s_feature_PE152_3.write(reg3);
        s_feature_PE153_0.write(reg0);
        s_feature_PE153_1.write(reg1);
        s_feature_PE153_2.write(reg2);
        s_feature_PE153_3.write(reg3);
        s_feature_PE154_0.write(reg0);
        s_feature_PE154_1.write(reg1);
        s_feature_PE154_2.write(reg2);
        s_feature_PE154_3.write(reg3);
        s_feature_PE155_0.write(reg0);
        s_feature_PE155_1.write(reg1);
        s_feature_PE155_2.write(reg2);
        s_feature_PE155_3.write(reg3);
        s_feature_PE156_0.write(reg0);
        s_feature_PE156_1.write(reg1);
        s_feature_PE156_2.write(reg2);
        s_feature_PE156_3.write(reg3);
        s_feature_PE157_0.write(reg0);
        s_feature_PE157_1.write(reg1);
        s_feature_PE157_2.write(reg2);
        s_feature_PE157_3.write(reg3);
        s_feature_PE158_0.write(reg0);
        s_feature_PE158_1.write(reg1);
        s_feature_PE158_2.write(reg2);
        s_feature_PE158_3.write(reg3);
        s_feature_PE159_0.write(reg0);
        s_feature_PE159_1.write(reg1);
        s_feature_PE159_2.write(reg2);
        s_feature_PE159_3.write(reg3);
        s_feature_PE160_0.write(reg0);
        s_feature_PE160_1.write(reg1);
        s_feature_PE160_2.write(reg2);
        s_feature_PE160_3.write(reg3);
        s_feature_PE161_0.write(reg0);
        s_feature_PE161_1.write(reg1);
        s_feature_PE161_2.write(reg2);
        s_feature_PE161_3.write(reg3);
        s_feature_PE162_0.write(reg0);
        s_feature_PE162_1.write(reg1);
        s_feature_PE162_2.write(reg2);
        s_feature_PE162_3.write(reg3);
        s_feature_PE163_0.write(reg0);
        s_feature_PE163_1.write(reg1);
        s_feature_PE163_2.write(reg2);
        s_feature_PE163_3.write(reg3);
        s_feature_PE164_0.write(reg0);
        s_feature_PE164_1.write(reg1);
        s_feature_PE164_2.write(reg2);
        s_feature_PE164_3.write(reg3);
        s_feature_PE165_0.write(reg0);
        s_feature_PE165_1.write(reg1);
        s_feature_PE165_2.write(reg2);
        s_feature_PE165_3.write(reg3);
        s_feature_PE166_0.write(reg0);
        s_feature_PE166_1.write(reg1);
        s_feature_PE166_2.write(reg2);
        s_feature_PE166_3.write(reg3);
        s_feature_PE167_0.write(reg0);
        s_feature_PE167_1.write(reg1);
        s_feature_PE167_2.write(reg2);
        s_feature_PE167_3.write(reg3);
        s_feature_PE168_0.write(reg0);
        s_feature_PE168_1.write(reg1);
        s_feature_PE168_2.write(reg2);
        s_feature_PE168_3.write(reg3);
        s_feature_PE169_0.write(reg0);
        s_feature_PE169_1.write(reg1);
        s_feature_PE169_2.write(reg2);
        s_feature_PE169_3.write(reg3);
        s_feature_PE170_0.write(reg0);
        s_feature_PE170_1.write(reg1);
        s_feature_PE170_2.write(reg2);
        s_feature_PE170_3.write(reg3);
        s_feature_PE171_0.write(reg0);
        s_feature_PE171_1.write(reg1);
        s_feature_PE171_2.write(reg2);
        s_feature_PE171_3.write(reg3);
        s_feature_PE172_0.write(reg0);
        s_feature_PE172_1.write(reg1);
        s_feature_PE172_2.write(reg2);
        s_feature_PE172_3.write(reg3);
        s_feature_PE173_0.write(reg0);
        s_feature_PE173_1.write(reg1);
        s_feature_PE173_2.write(reg2);
        s_feature_PE173_3.write(reg3);
        s_feature_PE174_0.write(reg0);
        s_feature_PE174_1.write(reg1);
        s_feature_PE174_2.write(reg2);
        s_feature_PE174_3.write(reg3);
        s_feature_PE175_0.write(reg0);
        s_feature_PE175_1.write(reg1);
        s_feature_PE175_2.write(reg2);
        s_feature_PE175_3.write(reg3);
        s_feature_PE176_0.write(reg0);
        s_feature_PE176_1.write(reg1);
        s_feature_PE176_2.write(reg2);
        s_feature_PE176_3.write(reg3);
        s_feature_PE177_0.write(reg0);
        s_feature_PE177_1.write(reg1);
        s_feature_PE177_2.write(reg2);
        s_feature_PE177_3.write(reg3);
        s_feature_PE178_0.write(reg0);
        s_feature_PE178_1.write(reg1);
        s_feature_PE178_2.write(reg2);
        s_feature_PE178_3.write(reg3);
        s_feature_PE179_0.write(reg0);
        s_feature_PE179_1.write(reg1);
        s_feature_PE179_2.write(reg2);
        s_feature_PE179_3.write(reg3);
        s_feature_PE180_0.write(reg0);
        s_feature_PE180_1.write(reg1);
        s_feature_PE180_2.write(reg2);
        s_feature_PE180_3.write(reg3);
        s_feature_PE181_0.write(reg0);
        s_feature_PE181_1.write(reg1);
        s_feature_PE181_2.write(reg2);
        s_feature_PE181_3.write(reg3);
        s_feature_PE182_0.write(reg0);
        s_feature_PE182_1.write(reg1);
        s_feature_PE182_2.write(reg2);
        s_feature_PE182_3.write(reg3);
        s_feature_PE183_0.write(reg0);
        s_feature_PE183_1.write(reg1);
        s_feature_PE183_2.write(reg2);
        s_feature_PE183_3.write(reg3);
        s_feature_PE184_0.write(reg0);
        s_feature_PE184_1.write(reg1);
        s_feature_PE184_2.write(reg2);
        s_feature_PE184_3.write(reg3);
        s_feature_PE185_0.write(reg0);
        s_feature_PE185_1.write(reg1);
        s_feature_PE185_2.write(reg2);
        s_feature_PE185_3.write(reg3);
        s_feature_PE186_0.write(reg0);
        s_feature_PE186_1.write(reg1);
        s_feature_PE186_2.write(reg2);
        s_feature_PE186_3.write(reg3);
        s_feature_PE187_0.write(reg0);
        s_feature_PE187_1.write(reg1);
        s_feature_PE187_2.write(reg2);
        s_feature_PE187_3.write(reg3);
        s_feature_PE188_0.write(reg0);
        s_feature_PE188_1.write(reg1);
        s_feature_PE188_2.write(reg2);
        s_feature_PE188_3.write(reg3);
        s_feature_PE189_0.write(reg0);
        s_feature_PE189_1.write(reg1);
        s_feature_PE189_2.write(reg2);
        s_feature_PE189_3.write(reg3);
        s_feature_PE190_0.write(reg0);
        s_feature_PE190_1.write(reg1);
        s_feature_PE190_2.write(reg2);
        s_feature_PE190_3.write(reg3);
        s_feature_PE191_0.write(reg0);
        s_feature_PE191_1.write(reg1);
        s_feature_PE191_2.write(reg2);
        s_feature_PE191_3.write(reg3);
        s_feature_PE192_0.write(reg0);
        s_feature_PE192_1.write(reg1);
        s_feature_PE192_2.write(reg2);
        s_feature_PE192_3.write(reg3);
        s_feature_PE193_0.write(reg0);
        s_feature_PE193_1.write(reg1);
        s_feature_PE193_2.write(reg2);
        s_feature_PE193_3.write(reg3);
        s_feature_PE194_0.write(reg0);
        s_feature_PE194_1.write(reg1);
        s_feature_PE194_2.write(reg2);
        s_feature_PE194_3.write(reg3);
        s_feature_PE195_0.write(reg0);
        s_feature_PE195_1.write(reg1);
        s_feature_PE195_2.write(reg2);
        s_feature_PE195_3.write(reg3);
        s_feature_PE196_0.write(reg0);
        s_feature_PE196_1.write(reg1);
        s_feature_PE196_2.write(reg2);
        s_feature_PE196_3.write(reg3);
        s_feature_PE197_0.write(reg0);
        s_feature_PE197_1.write(reg1);
        s_feature_PE197_2.write(reg2);
        s_feature_PE197_3.write(reg3);
        s_feature_PE198_0.write(reg0);
        s_feature_PE198_1.write(reg1);
        s_feature_PE198_2.write(reg2);
        s_feature_PE198_3.write(reg3);
        s_feature_PE199_0.write(reg0);
        s_feature_PE199_1.write(reg1);
        s_feature_PE199_2.write(reg2);
        s_feature_PE199_3.write(reg3);
        s_feature_PE200_0.write(reg0);
        s_feature_PE200_1.write(reg1);
        s_feature_PE200_2.write(reg2);
        s_feature_PE200_3.write(reg3);
        s_feature_PE201_0.write(reg0);
        s_feature_PE201_1.write(reg1);
        s_feature_PE201_2.write(reg2);
        s_feature_PE201_3.write(reg3);
        s_feature_PE202_0.write(reg0);
        s_feature_PE202_1.write(reg1);
        s_feature_PE202_2.write(reg2);
        s_feature_PE202_3.write(reg3);
        s_feature_PE203_0.write(reg0);
        s_feature_PE203_1.write(reg1);
        s_feature_PE203_2.write(reg2);
        s_feature_PE203_3.write(reg3);
        s_feature_PE204_0.write(reg0);
        s_feature_PE204_1.write(reg1);
        s_feature_PE204_2.write(reg2);
        s_feature_PE204_3.write(reg3);
        s_feature_PE205_0.write(reg0);
        s_feature_PE205_1.write(reg1);
        s_feature_PE205_2.write(reg2);
        s_feature_PE205_3.write(reg3);
        s_feature_PE206_0.write(reg0);
        s_feature_PE206_1.write(reg1);
        s_feature_PE206_2.write(reg2);
        s_feature_PE206_3.write(reg3);
        s_feature_PE207_0.write(reg0);
        s_feature_PE207_1.write(reg1);
        s_feature_PE207_2.write(reg2);
        s_feature_PE207_3.write(reg3);
        s_feature_PE208_0.write(reg0);
        s_feature_PE208_1.write(reg1);
        s_feature_PE208_2.write(reg2);
        s_feature_PE208_3.write(reg3);
        s_feature_PE209_0.write(reg0);
        s_feature_PE209_1.write(reg1);
        s_feature_PE209_2.write(reg2);
        s_feature_PE209_3.write(reg3);
        s_feature_PE210_0.write(reg0);
        s_feature_PE210_1.write(reg1);
        s_feature_PE210_2.write(reg2);
        s_feature_PE210_3.write(reg3);
        s_feature_PE211_0.write(reg0);
        s_feature_PE211_1.write(reg1);
        s_feature_PE211_2.write(reg2);
        s_feature_PE211_3.write(reg3);
        s_feature_PE212_0.write(reg0);
        s_feature_PE212_1.write(reg1);
        s_feature_PE212_2.write(reg2);
        s_feature_PE212_3.write(reg3);
        s_feature_PE213_0.write(reg0);
        s_feature_PE213_1.write(reg1);
        s_feature_PE213_2.write(reg2);
        s_feature_PE213_3.write(reg3);
        s_feature_PE214_0.write(reg0);
        s_feature_PE214_1.write(reg1);
        s_feature_PE214_2.write(reg2);
        s_feature_PE214_3.write(reg3);
        s_feature_PE215_0.write(reg0);
        s_feature_PE215_1.write(reg1);
        s_feature_PE215_2.write(reg2);
        s_feature_PE215_3.write(reg3);
    }
}

template<const int FEATURE_SIZE>
void replicate_feature_512PEs_108PE(
    STREAM<ap_uint<512> >& s_feature_in, 
    STREAM<W_TYPE>& s_feature_PE0_0, STREAM<W_TYPE>& s_feature_PE0_1,
    STREAM<W_TYPE>& s_feature_PE0_2, STREAM<W_TYPE>& s_feature_PE0_3,
    STREAM<W_TYPE>& s_feature_PE1_0, STREAM<W_TYPE>& s_feature_PE1_1,
    STREAM<W_TYPE>& s_feature_PE1_2, STREAM<W_TYPE>& s_feature_PE1_3,
    STREAM<W_TYPE>& s_feature_PE2_0, STREAM<W_TYPE>& s_feature_PE2_1,
    STREAM<W_TYPE>& s_feature_PE2_2, STREAM<W_TYPE>& s_feature_PE2_3,
    STREAM<W_TYPE>& s_feature_PE3_0, STREAM<W_TYPE>& s_feature_PE3_1,
    STREAM<W_TYPE>& s_feature_PE3_2, STREAM<W_TYPE>& s_feature_PE3_3,
    STREAM<W_TYPE>& s_feature_PE4_0, STREAM<W_TYPE>& s_feature_PE4_1,
    STREAM<W_TYPE>& s_feature_PE4_2, STREAM<W_TYPE>& s_feature_PE4_3,
    STREAM<W_TYPE>& s_feature_PE5_0, STREAM<W_TYPE>& s_feature_PE5_1,
    STREAM<W_TYPE>& s_feature_PE5_2, STREAM<W_TYPE>& s_feature_PE5_3,
    STREAM<W_TYPE>& s_feature_PE6_0, STREAM<W_TYPE>& s_feature_PE6_1,
    STREAM<W_TYPE>& s_feature_PE6_2, STREAM<W_TYPE>& s_feature_PE6_3,
    STREAM<W_TYPE>& s_feature_PE7_0, STREAM<W_TYPE>& s_feature_PE7_1,
    STREAM<W_TYPE>& s_feature_PE7_2, STREAM<W_TYPE>& s_feature_PE7_3,
    STREAM<W_TYPE>& s_feature_PE8_0, STREAM<W_TYPE>& s_feature_PE8_1,
    STREAM<W_TYPE>& s_feature_PE8_2, STREAM<W_TYPE>& s_feature_PE8_3,
    STREAM<W_TYPE>& s_feature_PE9_0, STREAM<W_TYPE>& s_feature_PE9_1,
    STREAM<W_TYPE>& s_feature_PE9_2, STREAM<W_TYPE>& s_feature_PE9_3,
    STREAM<W_TYPE>& s_feature_PE10_0, STREAM<W_TYPE>& s_feature_PE10_1,
    STREAM<W_TYPE>& s_feature_PE10_2, STREAM<W_TYPE>& s_feature_PE10_3,
    STREAM<W_TYPE>& s_feature_PE11_0, STREAM<W_TYPE>& s_feature_PE11_1,
    STREAM<W_TYPE>& s_feature_PE11_2, STREAM<W_TYPE>& s_feature_PE11_3,
    STREAM<W_TYPE>& s_feature_PE12_0, STREAM<W_TYPE>& s_feature_PE12_1,
    STREAM<W_TYPE>& s_feature_PE12_2, STREAM<W_TYPE>& s_feature_PE12_3,
    STREAM<W_TYPE>& s_feature_PE13_0, STREAM<W_TYPE>& s_feature_PE13_1,
    STREAM<W_TYPE>& s_feature_PE13_2, STREAM<W_TYPE>& s_feature_PE13_3,
    STREAM<W_TYPE>& s_feature_PE14_0, STREAM<W_TYPE>& s_feature_PE14_1,
    STREAM<W_TYPE>& s_feature_PE14_2, STREAM<W_TYPE>& s_feature_PE14_3,
    STREAM<W_TYPE>& s_feature_PE15_0, STREAM<W_TYPE>& s_feature_PE15_1,
    STREAM<W_TYPE>& s_feature_PE15_2, STREAM<W_TYPE>& s_feature_PE15_3,
    STREAM<W_TYPE>& s_feature_PE16_0, STREAM<W_TYPE>& s_feature_PE16_1,
    STREAM<W_TYPE>& s_feature_PE16_2, STREAM<W_TYPE>& s_feature_PE16_3,
    STREAM<W_TYPE>& s_feature_PE17_0, STREAM<W_TYPE>& s_feature_PE17_1,
    STREAM<W_TYPE>& s_feature_PE17_2, STREAM<W_TYPE>& s_feature_PE17_3,
    STREAM<W_TYPE>& s_feature_PE18_0, STREAM<W_TYPE>& s_feature_PE18_1,
    STREAM<W_TYPE>& s_feature_PE18_2, STREAM<W_TYPE>& s_feature_PE18_3,
    STREAM<W_TYPE>& s_feature_PE19_0, STREAM<W_TYPE>& s_feature_PE19_1,
    STREAM<W_TYPE>& s_feature_PE19_2, STREAM<W_TYPE>& s_feature_PE19_3,
    STREAM<W_TYPE>& s_feature_PE20_0, STREAM<W_TYPE>& s_feature_PE20_1,
    STREAM<W_TYPE>& s_feature_PE20_2, STREAM<W_TYPE>& s_feature_PE20_3,
    STREAM<W_TYPE>& s_feature_PE21_0, STREAM<W_TYPE>& s_feature_PE21_1,
    STREAM<W_TYPE>& s_feature_PE21_2, STREAM<W_TYPE>& s_feature_PE21_3,
    STREAM<W_TYPE>& s_feature_PE22_0, STREAM<W_TYPE>& s_feature_PE22_1,
    STREAM<W_TYPE>& s_feature_PE22_2, STREAM<W_TYPE>& s_feature_PE22_3,
    STREAM<W_TYPE>& s_feature_PE23_0, STREAM<W_TYPE>& s_feature_PE23_1,
    STREAM<W_TYPE>& s_feature_PE23_2, STREAM<W_TYPE>& s_feature_PE23_3,
    STREAM<W_TYPE>& s_feature_PE24_0, STREAM<W_TYPE>& s_feature_PE24_1,
    STREAM<W_TYPE>& s_feature_PE24_2, STREAM<W_TYPE>& s_feature_PE24_3,
    STREAM<W_TYPE>& s_feature_PE25_0, STREAM<W_TYPE>& s_feature_PE25_1,
    STREAM<W_TYPE>& s_feature_PE25_2, STREAM<W_TYPE>& s_feature_PE25_3,
    STREAM<W_TYPE>& s_feature_PE26_0, STREAM<W_TYPE>& s_feature_PE26_1,
    STREAM<W_TYPE>& s_feature_PE26_2, STREAM<W_TYPE>& s_feature_PE26_3,
    STREAM<W_TYPE>& s_feature_PE27_0, STREAM<W_TYPE>& s_feature_PE27_1,
    STREAM<W_TYPE>& s_feature_PE27_2, STREAM<W_TYPE>& s_feature_PE27_3,
    STREAM<W_TYPE>& s_feature_PE28_0, STREAM<W_TYPE>& s_feature_PE28_1,
    STREAM<W_TYPE>& s_feature_PE28_2, STREAM<W_TYPE>& s_feature_PE28_3,
    STREAM<W_TYPE>& s_feature_PE29_0, STREAM<W_TYPE>& s_feature_PE29_1,
    STREAM<W_TYPE>& s_feature_PE29_2, STREAM<W_TYPE>& s_feature_PE29_3,
    STREAM<W_TYPE>& s_feature_PE30_0, STREAM<W_TYPE>& s_feature_PE30_1,
    STREAM<W_TYPE>& s_feature_PE30_2, STREAM<W_TYPE>& s_feature_PE30_3,
    STREAM<W_TYPE>& s_feature_PE31_0, STREAM<W_TYPE>& s_feature_PE31_1,
    STREAM<W_TYPE>& s_feature_PE31_2, STREAM<W_TYPE>& s_feature_PE31_3,
    STREAM<W_TYPE>& s_feature_PE32_0, STREAM<W_TYPE>& s_feature_PE32_1,
    STREAM<W_TYPE>& s_feature_PE32_2, STREAM<W_TYPE>& s_feature_PE32_3,
    STREAM<W_TYPE>& s_feature_PE33_0, STREAM<W_TYPE>& s_feature_PE33_1,
    STREAM<W_TYPE>& s_feature_PE33_2, STREAM<W_TYPE>& s_feature_PE33_3,
    STREAM<W_TYPE>& s_feature_PE34_0, STREAM<W_TYPE>& s_feature_PE34_1,
    STREAM<W_TYPE>& s_feature_PE34_2, STREAM<W_TYPE>& s_feature_PE34_3,
    STREAM<W_TYPE>& s_feature_PE35_0, STREAM<W_TYPE>& s_feature_PE35_1,
    STREAM<W_TYPE>& s_feature_PE35_2, STREAM<W_TYPE>& s_feature_PE35_3,
    STREAM<W_TYPE>& s_feature_PE36_0, STREAM<W_TYPE>& s_feature_PE36_1,
    STREAM<W_TYPE>& s_feature_PE36_2, STREAM<W_TYPE>& s_feature_PE36_3,
    STREAM<W_TYPE>& s_feature_PE37_0, STREAM<W_TYPE>& s_feature_PE37_1,
    STREAM<W_TYPE>& s_feature_PE37_2, STREAM<W_TYPE>& s_feature_PE37_3,
    STREAM<W_TYPE>& s_feature_PE38_0, STREAM<W_TYPE>& s_feature_PE38_1,
    STREAM<W_TYPE>& s_feature_PE38_2, STREAM<W_TYPE>& s_feature_PE38_3,
    STREAM<W_TYPE>& s_feature_PE39_0, STREAM<W_TYPE>& s_feature_PE39_1,
    STREAM<W_TYPE>& s_feature_PE39_2, STREAM<W_TYPE>& s_feature_PE39_3,
    STREAM<W_TYPE>& s_feature_PE40_0, STREAM<W_TYPE>& s_feature_PE40_1,
    STREAM<W_TYPE>& s_feature_PE40_2, STREAM<W_TYPE>& s_feature_PE40_3,
    STREAM<W_TYPE>& s_feature_PE41_0, STREAM<W_TYPE>& s_feature_PE41_1,
    STREAM<W_TYPE>& s_feature_PE41_2, STREAM<W_TYPE>& s_feature_PE41_3,
    STREAM<W_TYPE>& s_feature_PE42_0, STREAM<W_TYPE>& s_feature_PE42_1,
    STREAM<W_TYPE>& s_feature_PE42_2, STREAM<W_TYPE>& s_feature_PE42_3,
    STREAM<W_TYPE>& s_feature_PE43_0, STREAM<W_TYPE>& s_feature_PE43_1,
    STREAM<W_TYPE>& s_feature_PE43_2, STREAM<W_TYPE>& s_feature_PE43_3,
    STREAM<W_TYPE>& s_feature_PE44_0, STREAM<W_TYPE>& s_feature_PE44_1,
    STREAM<W_TYPE>& s_feature_PE44_2, STREAM<W_TYPE>& s_feature_PE44_3,
    STREAM<W_TYPE>& s_feature_PE45_0, STREAM<W_TYPE>& s_feature_PE45_1,
    STREAM<W_TYPE>& s_feature_PE45_2, STREAM<W_TYPE>& s_feature_PE45_3,
    STREAM<W_TYPE>& s_feature_PE46_0, STREAM<W_TYPE>& s_feature_PE46_1,
    STREAM<W_TYPE>& s_feature_PE46_2, STREAM<W_TYPE>& s_feature_PE46_3,
    STREAM<W_TYPE>& s_feature_PE47_0, STREAM<W_TYPE>& s_feature_PE47_1,
    STREAM<W_TYPE>& s_feature_PE47_2, STREAM<W_TYPE>& s_feature_PE47_3,
    STREAM<W_TYPE>& s_feature_PE48_0, STREAM<W_TYPE>& s_feature_PE48_1,
    STREAM<W_TYPE>& s_feature_PE48_2, STREAM<W_TYPE>& s_feature_PE48_3,
    STREAM<W_TYPE>& s_feature_PE49_0, STREAM<W_TYPE>& s_feature_PE49_1,
    STREAM<W_TYPE>& s_feature_PE49_2, STREAM<W_TYPE>& s_feature_PE49_3,
    STREAM<W_TYPE>& s_feature_PE50_0, STREAM<W_TYPE>& s_feature_PE50_1,
    STREAM<W_TYPE>& s_feature_PE50_2, STREAM<W_TYPE>& s_feature_PE50_3,
    STREAM<W_TYPE>& s_feature_PE51_0, STREAM<W_TYPE>& s_feature_PE51_1,
    STREAM<W_TYPE>& s_feature_PE51_2, STREAM<W_TYPE>& s_feature_PE51_3,
    STREAM<W_TYPE>& s_feature_PE52_0, STREAM<W_TYPE>& s_feature_PE52_1,
    STREAM<W_TYPE>& s_feature_PE52_2, STREAM<W_TYPE>& s_feature_PE52_3,
    STREAM<W_TYPE>& s_feature_PE53_0, STREAM<W_TYPE>& s_feature_PE53_1,
    STREAM<W_TYPE>& s_feature_PE53_2, STREAM<W_TYPE>& s_feature_PE53_3,
    STREAM<W_TYPE>& s_feature_PE54_0, STREAM<W_TYPE>& s_feature_PE54_1,
    STREAM<W_TYPE>& s_feature_PE54_2, STREAM<W_TYPE>& s_feature_PE54_3,
    STREAM<W_TYPE>& s_feature_PE55_0, STREAM<W_TYPE>& s_feature_PE55_1,
    STREAM<W_TYPE>& s_feature_PE55_2, STREAM<W_TYPE>& s_feature_PE55_3,
    STREAM<W_TYPE>& s_feature_PE56_0, STREAM<W_TYPE>& s_feature_PE56_1,
    STREAM<W_TYPE>& s_feature_PE56_2, STREAM<W_TYPE>& s_feature_PE56_3,
    STREAM<W_TYPE>& s_feature_PE57_0, STREAM<W_TYPE>& s_feature_PE57_1,
    STREAM<W_TYPE>& s_feature_PE57_2, STREAM<W_TYPE>& s_feature_PE57_3,
    STREAM<W_TYPE>& s_feature_PE58_0, STREAM<W_TYPE>& s_feature_PE58_1,
    STREAM<W_TYPE>& s_feature_PE58_2, STREAM<W_TYPE>& s_feature_PE58_3,
    STREAM<W_TYPE>& s_feature_PE59_0, STREAM<W_TYPE>& s_feature_PE59_1,
    STREAM<W_TYPE>& s_feature_PE59_2, STREAM<W_TYPE>& s_feature_PE59_3,
    STREAM<W_TYPE>& s_feature_PE60_0, STREAM<W_TYPE>& s_feature_PE60_1,
    STREAM<W_TYPE>& s_feature_PE60_2, STREAM<W_TYPE>& s_feature_PE60_3,
    STREAM<W_TYPE>& s_feature_PE61_0, STREAM<W_TYPE>& s_feature_PE61_1,
    STREAM<W_TYPE>& s_feature_PE61_2, STREAM<W_TYPE>& s_feature_PE61_3,
    STREAM<W_TYPE>& s_feature_PE62_0, STREAM<W_TYPE>& s_feature_PE62_1,
    STREAM<W_TYPE>& s_feature_PE62_2, STREAM<W_TYPE>& s_feature_PE62_3,
    STREAM<W_TYPE>& s_feature_PE63_0, STREAM<W_TYPE>& s_feature_PE63_1,
    STREAM<W_TYPE>& s_feature_PE63_2, STREAM<W_TYPE>& s_feature_PE63_3,
    STREAM<W_TYPE>& s_feature_PE64_0, STREAM<W_TYPE>& s_feature_PE64_1,
    STREAM<W_TYPE>& s_feature_PE64_2, STREAM<W_TYPE>& s_feature_PE64_3,
    STREAM<W_TYPE>& s_feature_PE65_0, STREAM<W_TYPE>& s_feature_PE65_1,
    STREAM<W_TYPE>& s_feature_PE65_2, STREAM<W_TYPE>& s_feature_PE65_3,
    STREAM<W_TYPE>& s_feature_PE66_0, STREAM<W_TYPE>& s_feature_PE66_1,
    STREAM<W_TYPE>& s_feature_PE66_2, STREAM<W_TYPE>& s_feature_PE66_3,
    STREAM<W_TYPE>& s_feature_PE67_0, STREAM<W_TYPE>& s_feature_PE67_1,
    STREAM<W_TYPE>& s_feature_PE67_2, STREAM<W_TYPE>& s_feature_PE67_3,
    STREAM<W_TYPE>& s_feature_PE68_0, STREAM<W_TYPE>& s_feature_PE68_1,
    STREAM<W_TYPE>& s_feature_PE68_2, STREAM<W_TYPE>& s_feature_PE68_3,
    STREAM<W_TYPE>& s_feature_PE69_0, STREAM<W_TYPE>& s_feature_PE69_1,
    STREAM<W_TYPE>& s_feature_PE69_2, STREAM<W_TYPE>& s_feature_PE69_3,
    STREAM<W_TYPE>& s_feature_PE70_0, STREAM<W_TYPE>& s_feature_PE70_1,
    STREAM<W_TYPE>& s_feature_PE70_2, STREAM<W_TYPE>& s_feature_PE70_3,
    STREAM<W_TYPE>& s_feature_PE71_0, STREAM<W_TYPE>& s_feature_PE71_1,
    STREAM<W_TYPE>& s_feature_PE71_2, STREAM<W_TYPE>& s_feature_PE71_3,
    STREAM<W_TYPE>& s_feature_PE72_0, STREAM<W_TYPE>& s_feature_PE72_1,
    STREAM<W_TYPE>& s_feature_PE72_2, STREAM<W_TYPE>& s_feature_PE72_3,
    STREAM<W_TYPE>& s_feature_PE73_0, STREAM<W_TYPE>& s_feature_PE73_1,
    STREAM<W_TYPE>& s_feature_PE73_2, STREAM<W_TYPE>& s_feature_PE73_3,
    STREAM<W_TYPE>& s_feature_PE74_0, STREAM<W_TYPE>& s_feature_PE74_1,
    STREAM<W_TYPE>& s_feature_PE74_2, STREAM<W_TYPE>& s_feature_PE74_3,
    STREAM<W_TYPE>& s_feature_PE75_0, STREAM<W_TYPE>& s_feature_PE75_1,
    STREAM<W_TYPE>& s_feature_PE75_2, STREAM<W_TYPE>& s_feature_PE75_3,
    STREAM<W_TYPE>& s_feature_PE76_0, STREAM<W_TYPE>& s_feature_PE76_1,
    STREAM<W_TYPE>& s_feature_PE76_2, STREAM<W_TYPE>& s_feature_PE76_3,
    STREAM<W_TYPE>& s_feature_PE77_0, STREAM<W_TYPE>& s_feature_PE77_1,
    STREAM<W_TYPE>& s_feature_PE77_2, STREAM<W_TYPE>& s_feature_PE77_3,
    STREAM<W_TYPE>& s_feature_PE78_0, STREAM<W_TYPE>& s_feature_PE78_1,
    STREAM<W_TYPE>& s_feature_PE78_2, STREAM<W_TYPE>& s_feature_PE78_3,
    STREAM<W_TYPE>& s_feature_PE79_0, STREAM<W_TYPE>& s_feature_PE79_1,
    STREAM<W_TYPE>& s_feature_PE79_2, STREAM<W_TYPE>& s_feature_PE79_3,
    STREAM<W_TYPE>& s_feature_PE80_0, STREAM<W_TYPE>& s_feature_PE80_1,
    STREAM<W_TYPE>& s_feature_PE80_2, STREAM<W_TYPE>& s_feature_PE80_3,
    STREAM<W_TYPE>& s_feature_PE81_0, STREAM<W_TYPE>& s_feature_PE81_1,
    STREAM<W_TYPE>& s_feature_PE81_2, STREAM<W_TYPE>& s_feature_PE81_3,
    STREAM<W_TYPE>& s_feature_PE82_0, STREAM<W_TYPE>& s_feature_PE82_1,
    STREAM<W_TYPE>& s_feature_PE82_2, STREAM<W_TYPE>& s_feature_PE82_3,
    STREAM<W_TYPE>& s_feature_PE83_0, STREAM<W_TYPE>& s_feature_PE83_1,
    STREAM<W_TYPE>& s_feature_PE83_2, STREAM<W_TYPE>& s_feature_PE83_3,
    STREAM<W_TYPE>& s_feature_PE84_0, STREAM<W_TYPE>& s_feature_PE84_1,
    STREAM<W_TYPE>& s_feature_PE84_2, STREAM<W_TYPE>& s_feature_PE84_3,
    STREAM<W_TYPE>& s_feature_PE85_0, STREAM<W_TYPE>& s_feature_PE85_1,
    STREAM<W_TYPE>& s_feature_PE85_2, STREAM<W_TYPE>& s_feature_PE85_3,
    STREAM<W_TYPE>& s_feature_PE86_0, STREAM<W_TYPE>& s_feature_PE86_1,
    STREAM<W_TYPE>& s_feature_PE86_2, STREAM<W_TYPE>& s_feature_PE86_3,
    STREAM<W_TYPE>& s_feature_PE87_0, STREAM<W_TYPE>& s_feature_PE87_1,
    STREAM<W_TYPE>& s_feature_PE87_2, STREAM<W_TYPE>& s_feature_PE87_3,
    STREAM<W_TYPE>& s_feature_PE88_0, STREAM<W_TYPE>& s_feature_PE88_1,
    STREAM<W_TYPE>& s_feature_PE88_2, STREAM<W_TYPE>& s_feature_PE88_3,
    STREAM<W_TYPE>& s_feature_PE89_0, STREAM<W_TYPE>& s_feature_PE89_1,
    STREAM<W_TYPE>& s_feature_PE89_2, STREAM<W_TYPE>& s_feature_PE89_3,
    STREAM<W_TYPE>& s_feature_PE90_0, STREAM<W_TYPE>& s_feature_PE90_1,
    STREAM<W_TYPE>& s_feature_PE90_2, STREAM<W_TYPE>& s_feature_PE90_3,
    STREAM<W_TYPE>& s_feature_PE91_0, STREAM<W_TYPE>& s_feature_PE91_1,
    STREAM<W_TYPE>& s_feature_PE91_2, STREAM<W_TYPE>& s_feature_PE91_3,
    STREAM<W_TYPE>& s_feature_PE92_0, STREAM<W_TYPE>& s_feature_PE92_1,
    STREAM<W_TYPE>& s_feature_PE92_2, STREAM<W_TYPE>& s_feature_PE92_3,
    STREAM<W_TYPE>& s_feature_PE93_0, STREAM<W_TYPE>& s_feature_PE93_1,
    STREAM<W_TYPE>& s_feature_PE93_2, STREAM<W_TYPE>& s_feature_PE93_3,
    STREAM<W_TYPE>& s_feature_PE94_0, STREAM<W_TYPE>& s_feature_PE94_1,
    STREAM<W_TYPE>& s_feature_PE94_2, STREAM<W_TYPE>& s_feature_PE94_3,
    STREAM<W_TYPE>& s_feature_PE95_0, STREAM<W_TYPE>& s_feature_PE95_1,
    STREAM<W_TYPE>& s_feature_PE95_2, STREAM<W_TYPE>& s_feature_PE95_3,
    STREAM<W_TYPE>& s_feature_PE96_0, STREAM<W_TYPE>& s_feature_PE96_1,
    STREAM<W_TYPE>& s_feature_PE96_2, STREAM<W_TYPE>& s_feature_PE96_3,
    STREAM<W_TYPE>& s_feature_PE97_0, STREAM<W_TYPE>& s_feature_PE97_1,
    STREAM<W_TYPE>& s_feature_PE97_2, STREAM<W_TYPE>& s_feature_PE97_3,
    STREAM<W_TYPE>& s_feature_PE98_0, STREAM<W_TYPE>& s_feature_PE98_1,
    STREAM<W_TYPE>& s_feature_PE98_2, STREAM<W_TYPE>& s_feature_PE98_3,
    STREAM<W_TYPE>& s_feature_PE99_0, STREAM<W_TYPE>& s_feature_PE99_1,
    STREAM<W_TYPE>& s_feature_PE99_2, STREAM<W_TYPE>& s_feature_PE99_3,
    STREAM<W_TYPE>& s_feature_PE100_0, STREAM<W_TYPE>& s_feature_PE100_1,
    STREAM<W_TYPE>& s_feature_PE100_2, STREAM<W_TYPE>& s_feature_PE100_3,
    STREAM<W_TYPE>& s_feature_PE101_0, STREAM<W_TYPE>& s_feature_PE101_1,
    STREAM<W_TYPE>& s_feature_PE101_2, STREAM<W_TYPE>& s_feature_PE101_3,
    STREAM<W_TYPE>& s_feature_PE102_0, STREAM<W_TYPE>& s_feature_PE102_1,
    STREAM<W_TYPE>& s_feature_PE102_2, STREAM<W_TYPE>& s_feature_PE102_3,
    STREAM<W_TYPE>& s_feature_PE103_0, STREAM<W_TYPE>& s_feature_PE103_1,
    STREAM<W_TYPE>& s_feature_PE103_2, STREAM<W_TYPE>& s_feature_PE103_3,
    STREAM<W_TYPE>& s_feature_PE104_0, STREAM<W_TYPE>& s_feature_PE104_1,
    STREAM<W_TYPE>& s_feature_PE104_2, STREAM<W_TYPE>& s_feature_PE104_3,
    STREAM<W_TYPE>& s_feature_PE105_0, STREAM<W_TYPE>& s_feature_PE105_1,
    STREAM<W_TYPE>& s_feature_PE105_2, STREAM<W_TYPE>& s_feature_PE105_3,
    STREAM<W_TYPE>& s_feature_PE106_0, STREAM<W_TYPE>& s_feature_PE106_1,
    STREAM<W_TYPE>& s_feature_PE106_2, STREAM<W_TYPE>& s_feature_PE106_3,
    STREAM<W_TYPE>& s_feature_PE107_0, STREAM<W_TYPE>& s_feature_PE107_1,
    STREAM<W_TYPE>& s_feature_PE107_2, STREAM<W_TYPE>& s_feature_PE107_3
) {

    for (int i = 0; i < BATCH_NUM * BATCH_SIZE * FEATURE_SIZE / INTS_PER_W / 4; i++) {
        #pragma HLS pipeline II=1

        ap_uint<512>  reg = s_feature_in.read();
        W_TYPE reg0 = reg.range(127, 0);
        W_TYPE reg1 = reg.range(255, 128);
        W_TYPE reg2 = reg.range(383, 256);
        W_TYPE reg3 = reg.range(511, 255);

        s_feature_PE0_0.write(reg0);
        s_feature_PE0_1.write(reg1);
        s_feature_PE0_2.write(reg2);
        s_feature_PE0_3.write(reg3);
        s_feature_PE1_0.write(reg0);
        s_feature_PE1_1.write(reg1);
        s_feature_PE1_2.write(reg2);
        s_feature_PE1_3.write(reg3);
        s_feature_PE2_0.write(reg0);
        s_feature_PE2_1.write(reg1);
        s_feature_PE2_2.write(reg2);
        s_feature_PE2_3.write(reg3);
        s_feature_PE3_0.write(reg0);
        s_feature_PE3_1.write(reg1);
        s_feature_PE3_2.write(reg2);
        s_feature_PE3_3.write(reg3);
        s_feature_PE4_0.write(reg0);
        s_feature_PE4_1.write(reg1);
        s_feature_PE4_2.write(reg2);
        s_feature_PE4_3.write(reg3);
        s_feature_PE5_0.write(reg0);
        s_feature_PE5_1.write(reg1);
        s_feature_PE5_2.write(reg2);
        s_feature_PE5_3.write(reg3);
        s_feature_PE6_0.write(reg0);
        s_feature_PE6_1.write(reg1);
        s_feature_PE6_2.write(reg2);
        s_feature_PE6_3.write(reg3);
        s_feature_PE7_0.write(reg0);
        s_feature_PE7_1.write(reg1);
        s_feature_PE7_2.write(reg2);
        s_feature_PE7_3.write(reg3);
        s_feature_PE8_0.write(reg0);
        s_feature_PE8_1.write(reg1);
        s_feature_PE8_2.write(reg2);
        s_feature_PE8_3.write(reg3);
        s_feature_PE9_0.write(reg0);
        s_feature_PE9_1.write(reg1);
        s_feature_PE9_2.write(reg2);
        s_feature_PE9_3.write(reg3);
        s_feature_PE10_0.write(reg0);
        s_feature_PE10_1.write(reg1);
        s_feature_PE10_2.write(reg2);
        s_feature_PE10_3.write(reg3);
        s_feature_PE11_0.write(reg0);
        s_feature_PE11_1.write(reg1);
        s_feature_PE11_2.write(reg2);
        s_feature_PE11_3.write(reg3);
        s_feature_PE12_0.write(reg0);
        s_feature_PE12_1.write(reg1);
        s_feature_PE12_2.write(reg2);
        s_feature_PE12_3.write(reg3);
        s_feature_PE13_0.write(reg0);
        s_feature_PE13_1.write(reg1);
        s_feature_PE13_2.write(reg2);
        s_feature_PE13_3.write(reg3);
        s_feature_PE14_0.write(reg0);
        s_feature_PE14_1.write(reg1);
        s_feature_PE14_2.write(reg2);
        s_feature_PE14_3.write(reg3);
        s_feature_PE15_0.write(reg0);
        s_feature_PE15_1.write(reg1);
        s_feature_PE15_2.write(reg2);
        s_feature_PE15_3.write(reg3);
        s_feature_PE16_0.write(reg0);
        s_feature_PE16_1.write(reg1);
        s_feature_PE16_2.write(reg2);
        s_feature_PE16_3.write(reg3);
        s_feature_PE17_0.write(reg0);
        s_feature_PE17_1.write(reg1);
        s_feature_PE17_2.write(reg2);
        s_feature_PE17_3.write(reg3);
        s_feature_PE18_0.write(reg0);
        s_feature_PE18_1.write(reg1);
        s_feature_PE18_2.write(reg2);
        s_feature_PE18_3.write(reg3);
        s_feature_PE19_0.write(reg0);
        s_feature_PE19_1.write(reg1);
        s_feature_PE19_2.write(reg2);
        s_feature_PE19_3.write(reg3);
        s_feature_PE20_0.write(reg0);
        s_feature_PE20_1.write(reg1);
        s_feature_PE20_2.write(reg2);
        s_feature_PE20_3.write(reg3);
        s_feature_PE21_0.write(reg0);
        s_feature_PE21_1.write(reg1);
        s_feature_PE21_2.write(reg2);
        s_feature_PE21_3.write(reg3);
        s_feature_PE22_0.write(reg0);
        s_feature_PE22_1.write(reg1);
        s_feature_PE22_2.write(reg2);
        s_feature_PE22_3.write(reg3);
        s_feature_PE23_0.write(reg0);
        s_feature_PE23_1.write(reg1);
        s_feature_PE23_2.write(reg2);
        s_feature_PE23_3.write(reg3);
        s_feature_PE24_0.write(reg0);
        s_feature_PE24_1.write(reg1);
        s_feature_PE24_2.write(reg2);
        s_feature_PE24_3.write(reg3);
        s_feature_PE25_0.write(reg0);
        s_feature_PE25_1.write(reg1);
        s_feature_PE25_2.write(reg2);
        s_feature_PE25_3.write(reg3);
        s_feature_PE26_0.write(reg0);
        s_feature_PE26_1.write(reg1);
        s_feature_PE26_2.write(reg2);
        s_feature_PE26_3.write(reg3);
        s_feature_PE27_0.write(reg0);
        s_feature_PE27_1.write(reg1);
        s_feature_PE27_2.write(reg2);
        s_feature_PE27_3.write(reg3);
        s_feature_PE28_0.write(reg0);
        s_feature_PE28_1.write(reg1);
        s_feature_PE28_2.write(reg2);
        s_feature_PE28_3.write(reg3);
        s_feature_PE29_0.write(reg0);
        s_feature_PE29_1.write(reg1);
        s_feature_PE29_2.write(reg2);
        s_feature_PE29_3.write(reg3);
        s_feature_PE30_0.write(reg0);
        s_feature_PE30_1.write(reg1);
        s_feature_PE30_2.write(reg2);
        s_feature_PE30_3.write(reg3);
        s_feature_PE31_0.write(reg0);
        s_feature_PE31_1.write(reg1);
        s_feature_PE31_2.write(reg2);
        s_feature_PE31_3.write(reg3);
        s_feature_PE32_0.write(reg0);
        s_feature_PE32_1.write(reg1);
        s_feature_PE32_2.write(reg2);
        s_feature_PE32_3.write(reg3);
        s_feature_PE33_0.write(reg0);
        s_feature_PE33_1.write(reg1);
        s_feature_PE33_2.write(reg2);
        s_feature_PE33_3.write(reg3);
        s_feature_PE34_0.write(reg0);
        s_feature_PE34_1.write(reg1);
        s_feature_PE34_2.write(reg2);
        s_feature_PE34_3.write(reg3);
        s_feature_PE35_0.write(reg0);
        s_feature_PE35_1.write(reg1);
        s_feature_PE35_2.write(reg2);
        s_feature_PE35_3.write(reg3);
        s_feature_PE36_0.write(reg0);
        s_feature_PE36_1.write(reg1);
        s_feature_PE36_2.write(reg2);
        s_feature_PE36_3.write(reg3);
        s_feature_PE37_0.write(reg0);
        s_feature_PE37_1.write(reg1);
        s_feature_PE37_2.write(reg2);
        s_feature_PE37_3.write(reg3);
        s_feature_PE38_0.write(reg0);
        s_feature_PE38_1.write(reg1);
        s_feature_PE38_2.write(reg2);
        s_feature_PE38_3.write(reg3);
        s_feature_PE39_0.write(reg0);
        s_feature_PE39_1.write(reg1);
        s_feature_PE39_2.write(reg2);
        s_feature_PE39_3.write(reg3);
        s_feature_PE40_0.write(reg0);
        s_feature_PE40_1.write(reg1);
        s_feature_PE40_2.write(reg2);
        s_feature_PE40_3.write(reg3);
        s_feature_PE41_0.write(reg0);
        s_feature_PE41_1.write(reg1);
        s_feature_PE41_2.write(reg2);
        s_feature_PE41_3.write(reg3);
        s_feature_PE42_0.write(reg0);
        s_feature_PE42_1.write(reg1);
        s_feature_PE42_2.write(reg2);
        s_feature_PE42_3.write(reg3);
        s_feature_PE43_0.write(reg0);
        s_feature_PE43_1.write(reg1);
        s_feature_PE43_2.write(reg2);
        s_feature_PE43_3.write(reg3);
        s_feature_PE44_0.write(reg0);
        s_feature_PE44_1.write(reg1);
        s_feature_PE44_2.write(reg2);
        s_feature_PE44_3.write(reg3);
        s_feature_PE45_0.write(reg0);
        s_feature_PE45_1.write(reg1);
        s_feature_PE45_2.write(reg2);
        s_feature_PE45_3.write(reg3);
        s_feature_PE46_0.write(reg0);
        s_feature_PE46_1.write(reg1);
        s_feature_PE46_2.write(reg2);
        s_feature_PE46_3.write(reg3);
        s_feature_PE47_0.write(reg0);
        s_feature_PE47_1.write(reg1);
        s_feature_PE47_2.write(reg2);
        s_feature_PE47_3.write(reg3);
        s_feature_PE48_0.write(reg0);
        s_feature_PE48_1.write(reg1);
        s_feature_PE48_2.write(reg2);
        s_feature_PE48_3.write(reg3);
        s_feature_PE49_0.write(reg0);
        s_feature_PE49_1.write(reg1);
        s_feature_PE49_2.write(reg2);
        s_feature_PE49_3.write(reg3);
        s_feature_PE50_0.write(reg0);
        s_feature_PE50_1.write(reg1);
        s_feature_PE50_2.write(reg2);
        s_feature_PE50_3.write(reg3);
        s_feature_PE51_0.write(reg0);
        s_feature_PE51_1.write(reg1);
        s_feature_PE51_2.write(reg2);
        s_feature_PE51_3.write(reg3);
        s_feature_PE52_0.write(reg0);
        s_feature_PE52_1.write(reg1);
        s_feature_PE52_2.write(reg2);
        s_feature_PE52_3.write(reg3);
        s_feature_PE53_0.write(reg0);
        s_feature_PE53_1.write(reg1);
        s_feature_PE53_2.write(reg2);
        s_feature_PE53_3.write(reg3);
        s_feature_PE54_0.write(reg0);
        s_feature_PE54_1.write(reg1);
        s_feature_PE54_2.write(reg2);
        s_feature_PE54_3.write(reg3);
        s_feature_PE55_0.write(reg0);
        s_feature_PE55_1.write(reg1);
        s_feature_PE55_2.write(reg2);
        s_feature_PE55_3.write(reg3);
        s_feature_PE56_0.write(reg0);
        s_feature_PE56_1.write(reg1);
        s_feature_PE56_2.write(reg2);
        s_feature_PE56_3.write(reg3);
        s_feature_PE57_0.write(reg0);
        s_feature_PE57_1.write(reg1);
        s_feature_PE57_2.write(reg2);
        s_feature_PE57_3.write(reg3);
        s_feature_PE58_0.write(reg0);
        s_feature_PE58_1.write(reg1);
        s_feature_PE58_2.write(reg2);
        s_feature_PE58_3.write(reg3);
        s_feature_PE59_0.write(reg0);
        s_feature_PE59_1.write(reg1);
        s_feature_PE59_2.write(reg2);
        s_feature_PE59_3.write(reg3);
        s_feature_PE60_0.write(reg0);
        s_feature_PE60_1.write(reg1);
        s_feature_PE60_2.write(reg2);
        s_feature_PE60_3.write(reg3);
        s_feature_PE61_0.write(reg0);
        s_feature_PE61_1.write(reg1);
        s_feature_PE61_2.write(reg2);
        s_feature_PE61_3.write(reg3);
        s_feature_PE62_0.write(reg0);
        s_feature_PE62_1.write(reg1);
        s_feature_PE62_2.write(reg2);
        s_feature_PE62_3.write(reg3);
        s_feature_PE63_0.write(reg0);
        s_feature_PE63_1.write(reg1);
        s_feature_PE63_2.write(reg2);
        s_feature_PE63_3.write(reg3);
        s_feature_PE64_0.write(reg0);
        s_feature_PE64_1.write(reg1);
        s_feature_PE64_2.write(reg2);
        s_feature_PE64_3.write(reg3);
        s_feature_PE65_0.write(reg0);
        s_feature_PE65_1.write(reg1);
        s_feature_PE65_2.write(reg2);
        s_feature_PE65_3.write(reg3);
        s_feature_PE66_0.write(reg0);
        s_feature_PE66_1.write(reg1);
        s_feature_PE66_2.write(reg2);
        s_feature_PE66_3.write(reg3);
        s_feature_PE67_0.write(reg0);
        s_feature_PE67_1.write(reg1);
        s_feature_PE67_2.write(reg2);
        s_feature_PE67_3.write(reg3);
        s_feature_PE68_0.write(reg0);
        s_feature_PE68_1.write(reg1);
        s_feature_PE68_2.write(reg2);
        s_feature_PE68_3.write(reg3);
        s_feature_PE69_0.write(reg0);
        s_feature_PE69_1.write(reg1);
        s_feature_PE69_2.write(reg2);
        s_feature_PE69_3.write(reg3);
        s_feature_PE70_0.write(reg0);
        s_feature_PE70_1.write(reg1);
        s_feature_PE70_2.write(reg2);
        s_feature_PE70_3.write(reg3);
        s_feature_PE71_0.write(reg0);
        s_feature_PE71_1.write(reg1);
        s_feature_PE71_2.write(reg2);
        s_feature_PE71_3.write(reg3);
        s_feature_PE72_0.write(reg0);
        s_feature_PE72_1.write(reg1);
        s_feature_PE72_2.write(reg2);
        s_feature_PE72_3.write(reg3);
        s_feature_PE73_0.write(reg0);
        s_feature_PE73_1.write(reg1);
        s_feature_PE73_2.write(reg2);
        s_feature_PE73_3.write(reg3);
        s_feature_PE74_0.write(reg0);
        s_feature_PE74_1.write(reg1);
        s_feature_PE74_2.write(reg2);
        s_feature_PE74_3.write(reg3);
        s_feature_PE75_0.write(reg0);
        s_feature_PE75_1.write(reg1);
        s_feature_PE75_2.write(reg2);
        s_feature_PE75_3.write(reg3);
        s_feature_PE76_0.write(reg0);
        s_feature_PE76_1.write(reg1);
        s_feature_PE76_2.write(reg2);
        s_feature_PE76_3.write(reg3);
        s_feature_PE77_0.write(reg0);
        s_feature_PE77_1.write(reg1);
        s_feature_PE77_2.write(reg2);
        s_feature_PE77_3.write(reg3);
        s_feature_PE78_0.write(reg0);
        s_feature_PE78_1.write(reg1);
        s_feature_PE78_2.write(reg2);
        s_feature_PE78_3.write(reg3);
        s_feature_PE79_0.write(reg0);
        s_feature_PE79_1.write(reg1);
        s_feature_PE79_2.write(reg2);
        s_feature_PE79_3.write(reg3);
        s_feature_PE80_0.write(reg0);
        s_feature_PE80_1.write(reg1);
        s_feature_PE80_2.write(reg2);
        s_feature_PE80_3.write(reg3);
        s_feature_PE81_0.write(reg0);
        s_feature_PE81_1.write(reg1);
        s_feature_PE81_2.write(reg2);
        s_feature_PE81_3.write(reg3);
        s_feature_PE82_0.write(reg0);
        s_feature_PE82_1.write(reg1);
        s_feature_PE82_2.write(reg2);
        s_feature_PE82_3.write(reg3);
        s_feature_PE83_0.write(reg0);
        s_feature_PE83_1.write(reg1);
        s_feature_PE83_2.write(reg2);
        s_feature_PE83_3.write(reg3);
        s_feature_PE84_0.write(reg0);
        s_feature_PE84_1.write(reg1);
        s_feature_PE84_2.write(reg2);
        s_feature_PE84_3.write(reg3);
        s_feature_PE85_0.write(reg0);
        s_feature_PE85_1.write(reg1);
        s_feature_PE85_2.write(reg2);
        s_feature_PE85_3.write(reg3);
        s_feature_PE86_0.write(reg0);
        s_feature_PE86_1.write(reg1);
        s_feature_PE86_2.write(reg2);
        s_feature_PE86_3.write(reg3);
        s_feature_PE87_0.write(reg0);
        s_feature_PE87_1.write(reg1);
        s_feature_PE87_2.write(reg2);
        s_feature_PE87_3.write(reg3);
        s_feature_PE88_0.write(reg0);
        s_feature_PE88_1.write(reg1);
        s_feature_PE88_2.write(reg2);
        s_feature_PE88_3.write(reg3);
        s_feature_PE89_0.write(reg0);
        s_feature_PE89_1.write(reg1);
        s_feature_PE89_2.write(reg2);
        s_feature_PE89_3.write(reg3);
        s_feature_PE90_0.write(reg0);
        s_feature_PE90_1.write(reg1);
        s_feature_PE90_2.write(reg2);
        s_feature_PE90_3.write(reg3);
        s_feature_PE91_0.write(reg0);
        s_feature_PE91_1.write(reg1);
        s_feature_PE91_2.write(reg2);
        s_feature_PE91_3.write(reg3);
        s_feature_PE92_0.write(reg0);
        s_feature_PE92_1.write(reg1);
        s_feature_PE92_2.write(reg2);
        s_feature_PE92_3.write(reg3);
        s_feature_PE93_0.write(reg0);
        s_feature_PE93_1.write(reg1);
        s_feature_PE93_2.write(reg2);
        s_feature_PE93_3.write(reg3);
        s_feature_PE94_0.write(reg0);
        s_feature_PE94_1.write(reg1);
        s_feature_PE94_2.write(reg2);
        s_feature_PE94_3.write(reg3);
        s_feature_PE95_0.write(reg0);
        s_feature_PE95_1.write(reg1);
        s_feature_PE95_2.write(reg2);
        s_feature_PE95_3.write(reg3);
        s_feature_PE96_0.write(reg0);
        s_feature_PE96_1.write(reg1);
        s_feature_PE96_2.write(reg2);
        s_feature_PE96_3.write(reg3);
        s_feature_PE97_0.write(reg0);
        s_feature_PE97_1.write(reg1);
        s_feature_PE97_2.write(reg2);
        s_feature_PE97_3.write(reg3);
        s_feature_PE98_0.write(reg0);
        s_feature_PE98_1.write(reg1);
        s_feature_PE98_2.write(reg2);
        s_feature_PE98_3.write(reg3);
        s_feature_PE99_0.write(reg0);
        s_feature_PE99_1.write(reg1);
        s_feature_PE99_2.write(reg2);
        s_feature_PE99_3.write(reg3);
        s_feature_PE100_0.write(reg0);
        s_feature_PE100_1.write(reg1);
        s_feature_PE100_2.write(reg2);
        s_feature_PE100_3.write(reg3);
        s_feature_PE101_0.write(reg0);
        s_feature_PE101_1.write(reg1);
        s_feature_PE101_2.write(reg2);
        s_feature_PE101_3.write(reg3);
        s_feature_PE102_0.write(reg0);
        s_feature_PE102_1.write(reg1);
        s_feature_PE102_2.write(reg2);
        s_feature_PE102_3.write(reg3);
        s_feature_PE103_0.write(reg0);
        s_feature_PE103_1.write(reg1);
        s_feature_PE103_2.write(reg2);
        s_feature_PE103_3.write(reg3);
        s_feature_PE104_0.write(reg0);
        s_feature_PE104_1.write(reg1);
        s_feature_PE104_2.write(reg2);
        s_feature_PE104_3.write(reg3);
        s_feature_PE105_0.write(reg0);
        s_feature_PE105_1.write(reg1);
        s_feature_PE105_2.write(reg2);
        s_feature_PE105_3.write(reg3);
        s_feature_PE106_0.write(reg0);
        s_feature_PE106_1.write(reg1);
        s_feature_PE106_2.write(reg2);
        s_feature_PE106_3.write(reg3);
        s_feature_PE107_0.write(reg0);
        s_feature_PE107_1.write(reg1);
        s_feature_PE107_2.write(reg2);
        s_feature_PE107_3.write(reg3);
    }
}

template<const int FEATURE_SIZE>
void replicate_feature_512PEs_54PE(
    STREAM<ap_uint<512> >& s_feature_in, 
    STREAM<W_TYPE>& s_feature_PE0_0, STREAM<W_TYPE>& s_feature_PE0_1,
    STREAM<W_TYPE>& s_feature_PE0_2, STREAM<W_TYPE>& s_feature_PE0_3,
    STREAM<W_TYPE>& s_feature_PE1_0, STREAM<W_TYPE>& s_feature_PE1_1,
    STREAM<W_TYPE>& s_feature_PE1_2, STREAM<W_TYPE>& s_feature_PE1_3,
    STREAM<W_TYPE>& s_feature_PE2_0, STREAM<W_TYPE>& s_feature_PE2_1,
    STREAM<W_TYPE>& s_feature_PE2_2, STREAM<W_TYPE>& s_feature_PE2_3,
    STREAM<W_TYPE>& s_feature_PE3_0, STREAM<W_TYPE>& s_feature_PE3_1,
    STREAM<W_TYPE>& s_feature_PE3_2, STREAM<W_TYPE>& s_feature_PE3_3,
    STREAM<W_TYPE>& s_feature_PE4_0, STREAM<W_TYPE>& s_feature_PE4_1,
    STREAM<W_TYPE>& s_feature_PE4_2, STREAM<W_TYPE>& s_feature_PE4_3,
    STREAM<W_TYPE>& s_feature_PE5_0, STREAM<W_TYPE>& s_feature_PE5_1,
    STREAM<W_TYPE>& s_feature_PE5_2, STREAM<W_TYPE>& s_feature_PE5_3,
    STREAM<W_TYPE>& s_feature_PE6_0, STREAM<W_TYPE>& s_feature_PE6_1,
    STREAM<W_TYPE>& s_feature_PE6_2, STREAM<W_TYPE>& s_feature_PE6_3,
    STREAM<W_TYPE>& s_feature_PE7_0, STREAM<W_TYPE>& s_feature_PE7_1,
    STREAM<W_TYPE>& s_feature_PE7_2, STREAM<W_TYPE>& s_feature_PE7_3,
    STREAM<W_TYPE>& s_feature_PE8_0, STREAM<W_TYPE>& s_feature_PE8_1,
    STREAM<W_TYPE>& s_feature_PE8_2, STREAM<W_TYPE>& s_feature_PE8_3,
    STREAM<W_TYPE>& s_feature_PE9_0, STREAM<W_TYPE>& s_feature_PE9_1,
    STREAM<W_TYPE>& s_feature_PE9_2, STREAM<W_TYPE>& s_feature_PE9_3,
    STREAM<W_TYPE>& s_feature_PE10_0, STREAM<W_TYPE>& s_feature_PE10_1,
    STREAM<W_TYPE>& s_feature_PE10_2, STREAM<W_TYPE>& s_feature_PE10_3,
    STREAM<W_TYPE>& s_feature_PE11_0, STREAM<W_TYPE>& s_feature_PE11_1,
    STREAM<W_TYPE>& s_feature_PE11_2, STREAM<W_TYPE>& s_feature_PE11_3,
    STREAM<W_TYPE>& s_feature_PE12_0, STREAM<W_TYPE>& s_feature_PE12_1,
    STREAM<W_TYPE>& s_feature_PE12_2, STREAM<W_TYPE>& s_feature_PE12_3,
    STREAM<W_TYPE>& s_feature_PE13_0, STREAM<W_TYPE>& s_feature_PE13_1,
    STREAM<W_TYPE>& s_feature_PE13_2, STREAM<W_TYPE>& s_feature_PE13_3,
    STREAM<W_TYPE>& s_feature_PE14_0, STREAM<W_TYPE>& s_feature_PE14_1,
    STREAM<W_TYPE>& s_feature_PE14_2, STREAM<W_TYPE>& s_feature_PE14_3,
    STREAM<W_TYPE>& s_feature_PE15_0, STREAM<W_TYPE>& s_feature_PE15_1,
    STREAM<W_TYPE>& s_feature_PE15_2, STREAM<W_TYPE>& s_feature_PE15_3,
    STREAM<W_TYPE>& s_feature_PE16_0, STREAM<W_TYPE>& s_feature_PE16_1,
    STREAM<W_TYPE>& s_feature_PE16_2, STREAM<W_TYPE>& s_feature_PE16_3,
    STREAM<W_TYPE>& s_feature_PE17_0, STREAM<W_TYPE>& s_feature_PE17_1,
    STREAM<W_TYPE>& s_feature_PE17_2, STREAM<W_TYPE>& s_feature_PE17_3,
    STREAM<W_TYPE>& s_feature_PE18_0, STREAM<W_TYPE>& s_feature_PE18_1,
    STREAM<W_TYPE>& s_feature_PE18_2, STREAM<W_TYPE>& s_feature_PE18_3,
    STREAM<W_TYPE>& s_feature_PE19_0, STREAM<W_TYPE>& s_feature_PE19_1,
    STREAM<W_TYPE>& s_feature_PE19_2, STREAM<W_TYPE>& s_feature_PE19_3,
    STREAM<W_TYPE>& s_feature_PE20_0, STREAM<W_TYPE>& s_feature_PE20_1,
    STREAM<W_TYPE>& s_feature_PE20_2, STREAM<W_TYPE>& s_feature_PE20_3,
    STREAM<W_TYPE>& s_feature_PE21_0, STREAM<W_TYPE>& s_feature_PE21_1,
    STREAM<W_TYPE>& s_feature_PE21_2, STREAM<W_TYPE>& s_feature_PE21_3,
    STREAM<W_TYPE>& s_feature_PE22_0, STREAM<W_TYPE>& s_feature_PE22_1,
    STREAM<W_TYPE>& s_feature_PE22_2, STREAM<W_TYPE>& s_feature_PE22_3,
    STREAM<W_TYPE>& s_feature_PE23_0, STREAM<W_TYPE>& s_feature_PE23_1,
    STREAM<W_TYPE>& s_feature_PE23_2, STREAM<W_TYPE>& s_feature_PE23_3,
    STREAM<W_TYPE>& s_feature_PE24_0, STREAM<W_TYPE>& s_feature_PE24_1,
    STREAM<W_TYPE>& s_feature_PE24_2, STREAM<W_TYPE>& s_feature_PE24_3,
    STREAM<W_TYPE>& s_feature_PE25_0, STREAM<W_TYPE>& s_feature_PE25_1,
    STREAM<W_TYPE>& s_feature_PE25_2, STREAM<W_TYPE>& s_feature_PE25_3,
    STREAM<W_TYPE>& s_feature_PE26_0, STREAM<W_TYPE>& s_feature_PE26_1,
    STREAM<W_TYPE>& s_feature_PE26_2, STREAM<W_TYPE>& s_feature_PE26_3,
    STREAM<W_TYPE>& s_feature_PE27_0, STREAM<W_TYPE>& s_feature_PE27_1,
    STREAM<W_TYPE>& s_feature_PE27_2, STREAM<W_TYPE>& s_feature_PE27_3,
    STREAM<W_TYPE>& s_feature_PE28_0, STREAM<W_TYPE>& s_feature_PE28_1,
    STREAM<W_TYPE>& s_feature_PE28_2, STREAM<W_TYPE>& s_feature_PE28_3,
    STREAM<W_TYPE>& s_feature_PE29_0, STREAM<W_TYPE>& s_feature_PE29_1,
    STREAM<W_TYPE>& s_feature_PE29_2, STREAM<W_TYPE>& s_feature_PE29_3,
    STREAM<W_TYPE>& s_feature_PE30_0, STREAM<W_TYPE>& s_feature_PE30_1,
    STREAM<W_TYPE>& s_feature_PE30_2, STREAM<W_TYPE>& s_feature_PE30_3,
    STREAM<W_TYPE>& s_feature_PE31_0, STREAM<W_TYPE>& s_feature_PE31_1,
    STREAM<W_TYPE>& s_feature_PE31_2, STREAM<W_TYPE>& s_feature_PE31_3,
    STREAM<W_TYPE>& s_feature_PE32_0, STREAM<W_TYPE>& s_feature_PE32_1,
    STREAM<W_TYPE>& s_feature_PE32_2, STREAM<W_TYPE>& s_feature_PE32_3,
    STREAM<W_TYPE>& s_feature_PE33_0, STREAM<W_TYPE>& s_feature_PE33_1,
    STREAM<W_TYPE>& s_feature_PE33_2, STREAM<W_TYPE>& s_feature_PE33_3,
    STREAM<W_TYPE>& s_feature_PE34_0, STREAM<W_TYPE>& s_feature_PE34_1,
    STREAM<W_TYPE>& s_feature_PE34_2, STREAM<W_TYPE>& s_feature_PE34_3,
    STREAM<W_TYPE>& s_feature_PE35_0, STREAM<W_TYPE>& s_feature_PE35_1,
    STREAM<W_TYPE>& s_feature_PE35_2, STREAM<W_TYPE>& s_feature_PE35_3,
    STREAM<W_TYPE>& s_feature_PE36_0, STREAM<W_TYPE>& s_feature_PE36_1,
    STREAM<W_TYPE>& s_feature_PE36_2, STREAM<W_TYPE>& s_feature_PE36_3,
    STREAM<W_TYPE>& s_feature_PE37_0, STREAM<W_TYPE>& s_feature_PE37_1,
    STREAM<W_TYPE>& s_feature_PE37_2, STREAM<W_TYPE>& s_feature_PE37_3,
    STREAM<W_TYPE>& s_feature_PE38_0, STREAM<W_TYPE>& s_feature_PE38_1,
    STREAM<W_TYPE>& s_feature_PE38_2, STREAM<W_TYPE>& s_feature_PE38_3,
    STREAM<W_TYPE>& s_feature_PE39_0, STREAM<W_TYPE>& s_feature_PE39_1,
    STREAM<W_TYPE>& s_feature_PE39_2, STREAM<W_TYPE>& s_feature_PE39_3,
    STREAM<W_TYPE>& s_feature_PE40_0, STREAM<W_TYPE>& s_feature_PE40_1,
    STREAM<W_TYPE>& s_feature_PE40_2, STREAM<W_TYPE>& s_feature_PE40_3,
    STREAM<W_TYPE>& s_feature_PE41_0, STREAM<W_TYPE>& s_feature_PE41_1,
    STREAM<W_TYPE>& s_feature_PE41_2, STREAM<W_TYPE>& s_feature_PE41_3,
    STREAM<W_TYPE>& s_feature_PE42_0, STREAM<W_TYPE>& s_feature_PE42_1,
    STREAM<W_TYPE>& s_feature_PE42_2, STREAM<W_TYPE>& s_feature_PE42_3,
    STREAM<W_TYPE>& s_feature_PE43_0, STREAM<W_TYPE>& s_feature_PE43_1,
    STREAM<W_TYPE>& s_feature_PE43_2, STREAM<W_TYPE>& s_feature_PE43_3,
    STREAM<W_TYPE>& s_feature_PE44_0, STREAM<W_TYPE>& s_feature_PE44_1,
    STREAM<W_TYPE>& s_feature_PE44_2, STREAM<W_TYPE>& s_feature_PE44_3,
    STREAM<W_TYPE>& s_feature_PE45_0, STREAM<W_TYPE>& s_feature_PE45_1,
    STREAM<W_TYPE>& s_feature_PE45_2, STREAM<W_TYPE>& s_feature_PE45_3,
    STREAM<W_TYPE>& s_feature_PE46_0, STREAM<W_TYPE>& s_feature_PE46_1,
    STREAM<W_TYPE>& s_feature_PE46_2, STREAM<W_TYPE>& s_feature_PE46_3,
    STREAM<W_TYPE>& s_feature_PE47_0, STREAM<W_TYPE>& s_feature_PE47_1,
    STREAM<W_TYPE>& s_feature_PE47_2, STREAM<W_TYPE>& s_feature_PE47_3,
    STREAM<W_TYPE>& s_feature_PE48_0, STREAM<W_TYPE>& s_feature_PE48_1,
    STREAM<W_TYPE>& s_feature_PE48_2, STREAM<W_TYPE>& s_feature_PE48_3,
    STREAM<W_TYPE>& s_feature_PE49_0, STREAM<W_TYPE>& s_feature_PE49_1,
    STREAM<W_TYPE>& s_feature_PE49_2, STREAM<W_TYPE>& s_feature_PE49_3,
    STREAM<W_TYPE>& s_feature_PE50_0, STREAM<W_TYPE>& s_feature_PE50_1,
    STREAM<W_TYPE>& s_feature_PE50_2, STREAM<W_TYPE>& s_feature_PE50_3,
    STREAM<W_TYPE>& s_feature_PE51_0, STREAM<W_TYPE>& s_feature_PE51_1,
    STREAM<W_TYPE>& s_feature_PE51_2, STREAM<W_TYPE>& s_feature_PE51_3,
    STREAM<W_TYPE>& s_feature_PE52_0, STREAM<W_TYPE>& s_feature_PE52_1,
    STREAM<W_TYPE>& s_feature_PE52_2, STREAM<W_TYPE>& s_feature_PE52_3,
    STREAM<W_TYPE>& s_feature_PE53_0, STREAM<W_TYPE>& s_feature_PE53_1,
    STREAM<W_TYPE>& s_feature_PE53_2, STREAM<W_TYPE>& s_feature_PE53_3){

    for (int i = 0; i < BATCH_NUM * BATCH_SIZE * FEATURE_SIZE / INTS_PER_W / 4; i++) {
        #pragma HLS pipeline II=1

        ap_uint<512>  reg = s_feature_in.read();
        W_TYPE reg0 = reg.range(127, 0);
        W_TYPE reg1 = reg.range(255, 128);
        W_TYPE reg2 = reg.range(383, 256);
        W_TYPE reg3 = reg.range(511, 255);

        s_feature_PE0_0.write(reg0);
        s_feature_PE0_1.write(reg1);
        s_feature_PE0_2.write(reg2);
        s_feature_PE0_3.write(reg3);
        s_feature_PE1_0.write(reg0);
        s_feature_PE1_1.write(reg1);
        s_feature_PE1_2.write(reg2);
        s_feature_PE1_3.write(reg3);
        s_feature_PE2_0.write(reg0);
        s_feature_PE2_1.write(reg1);
        s_feature_PE2_2.write(reg2);
        s_feature_PE2_3.write(reg3);
        s_feature_PE3_0.write(reg0);
        s_feature_PE3_1.write(reg1);
        s_feature_PE3_2.write(reg2);
        s_feature_PE3_3.write(reg3);
        s_feature_PE4_0.write(reg0);
        s_feature_PE4_1.write(reg1);
        s_feature_PE4_2.write(reg2);
        s_feature_PE4_3.write(reg3);
        s_feature_PE5_0.write(reg0);
        s_feature_PE5_1.write(reg1);
        s_feature_PE5_2.write(reg2);
        s_feature_PE5_3.write(reg3);
        s_feature_PE6_0.write(reg0);
        s_feature_PE6_1.write(reg1);
        s_feature_PE6_2.write(reg2);
        s_feature_PE6_3.write(reg3);
        s_feature_PE7_0.write(reg0);
        s_feature_PE7_1.write(reg1);
        s_feature_PE7_2.write(reg2);
        s_feature_PE7_3.write(reg3);
        s_feature_PE8_0.write(reg0);
        s_feature_PE8_1.write(reg1);
        s_feature_PE8_2.write(reg2);
        s_feature_PE8_3.write(reg3);
        s_feature_PE9_0.write(reg0);
        s_feature_PE9_1.write(reg1);
        s_feature_PE9_2.write(reg2);
        s_feature_PE9_3.write(reg3);
        s_feature_PE10_0.write(reg0);
        s_feature_PE10_1.write(reg1);
        s_feature_PE10_2.write(reg2);
        s_feature_PE10_3.write(reg3);
        s_feature_PE11_0.write(reg0);
        s_feature_PE11_1.write(reg1);
        s_feature_PE11_2.write(reg2);
        s_feature_PE11_3.write(reg3);
        s_feature_PE12_0.write(reg0);
        s_feature_PE12_1.write(reg1);
        s_feature_PE12_2.write(reg2);
        s_feature_PE12_3.write(reg3);
        s_feature_PE13_0.write(reg0);
        s_feature_PE13_1.write(reg1);
        s_feature_PE13_2.write(reg2);
        s_feature_PE13_3.write(reg3);
        s_feature_PE14_0.write(reg0);
        s_feature_PE14_1.write(reg1);
        s_feature_PE14_2.write(reg2);
        s_feature_PE14_3.write(reg3);
        s_feature_PE15_0.write(reg0);
        s_feature_PE15_1.write(reg1);
        s_feature_PE15_2.write(reg2);
        s_feature_PE15_3.write(reg3);
        s_feature_PE16_0.write(reg0);
        s_feature_PE16_1.write(reg1);
        s_feature_PE16_2.write(reg2);
        s_feature_PE16_3.write(reg3);
        s_feature_PE17_0.write(reg0);
        s_feature_PE17_1.write(reg1);
        s_feature_PE17_2.write(reg2);
        s_feature_PE17_3.write(reg3);
        s_feature_PE18_0.write(reg0);
        s_feature_PE18_1.write(reg1);
        s_feature_PE18_2.write(reg2);
        s_feature_PE18_3.write(reg3);
        s_feature_PE19_0.write(reg0);
        s_feature_PE19_1.write(reg1);
        s_feature_PE19_2.write(reg2);
        s_feature_PE19_3.write(reg3);
        s_feature_PE20_0.write(reg0);
        s_feature_PE20_1.write(reg1);
        s_feature_PE20_2.write(reg2);
        s_feature_PE20_3.write(reg3);
        s_feature_PE21_0.write(reg0);
        s_feature_PE21_1.write(reg1);
        s_feature_PE21_2.write(reg2);
        s_feature_PE21_3.write(reg3);
        s_feature_PE22_0.write(reg0);
        s_feature_PE22_1.write(reg1);
        s_feature_PE22_2.write(reg2);
        s_feature_PE22_3.write(reg3);
        s_feature_PE23_0.write(reg0);
        s_feature_PE23_1.write(reg1);
        s_feature_PE23_2.write(reg2);
        s_feature_PE23_3.write(reg3);
        s_feature_PE24_0.write(reg0);
        s_feature_PE24_1.write(reg1);
        s_feature_PE24_2.write(reg2);
        s_feature_PE24_3.write(reg3);
        s_feature_PE25_0.write(reg0);
        s_feature_PE25_1.write(reg1);
        s_feature_PE25_2.write(reg2);
        s_feature_PE25_3.write(reg3);
        s_feature_PE26_0.write(reg0);
        s_feature_PE26_1.write(reg1);
        s_feature_PE26_2.write(reg2);
        s_feature_PE26_3.write(reg3);
        s_feature_PE27_0.write(reg0);
        s_feature_PE27_1.write(reg1);
        s_feature_PE27_2.write(reg2);
        s_feature_PE27_3.write(reg3);
        s_feature_PE28_0.write(reg0);
        s_feature_PE28_1.write(reg1);
        s_feature_PE28_2.write(reg2);
        s_feature_PE28_3.write(reg3);
        s_feature_PE29_0.write(reg0);
        s_feature_PE29_1.write(reg1);
        s_feature_PE29_2.write(reg2);
        s_feature_PE29_3.write(reg3);
        s_feature_PE30_0.write(reg0);
        s_feature_PE30_1.write(reg1);
        s_feature_PE30_2.write(reg2);
        s_feature_PE30_3.write(reg3);
        s_feature_PE31_0.write(reg0);
        s_feature_PE31_1.write(reg1);
        s_feature_PE31_2.write(reg2);
        s_feature_PE31_3.write(reg3);
        s_feature_PE32_0.write(reg0);
        s_feature_PE32_1.write(reg1);
        s_feature_PE32_2.write(reg2);
        s_feature_PE32_3.write(reg3);
        s_feature_PE33_0.write(reg0);
        s_feature_PE33_1.write(reg1);
        s_feature_PE33_2.write(reg2);
        s_feature_PE33_3.write(reg3);
        s_feature_PE34_0.write(reg0);
        s_feature_PE34_1.write(reg1);
        s_feature_PE34_2.write(reg2);
        s_feature_PE34_3.write(reg3);
        s_feature_PE35_0.write(reg0);
        s_feature_PE35_1.write(reg1);
        s_feature_PE35_2.write(reg2);
        s_feature_PE35_3.write(reg3);
        s_feature_PE36_0.write(reg0);
        s_feature_PE36_1.write(reg1);
        s_feature_PE36_2.write(reg2);
        s_feature_PE36_3.write(reg3);
        s_feature_PE37_0.write(reg0);
        s_feature_PE37_1.write(reg1);
        s_feature_PE37_2.write(reg2);
        s_feature_PE37_3.write(reg3);
        s_feature_PE38_0.write(reg0);
        s_feature_PE38_1.write(reg1);
        s_feature_PE38_2.write(reg2);
        s_feature_PE38_3.write(reg3);
        s_feature_PE39_0.write(reg0);
        s_feature_PE39_1.write(reg1);
        s_feature_PE39_2.write(reg2);
        s_feature_PE39_3.write(reg3);
        s_feature_PE40_0.write(reg0);
        s_feature_PE40_1.write(reg1);
        s_feature_PE40_2.write(reg2);
        s_feature_PE40_3.write(reg3);
        s_feature_PE41_0.write(reg0);
        s_feature_PE41_1.write(reg1);
        s_feature_PE41_2.write(reg2);
        s_feature_PE41_3.write(reg3);
        s_feature_PE42_0.write(reg0);
        s_feature_PE42_1.write(reg1);
        s_feature_PE42_2.write(reg2);
        s_feature_PE42_3.write(reg3);
        s_feature_PE43_0.write(reg0);
        s_feature_PE43_1.write(reg1);
        s_feature_PE43_2.write(reg2);
        s_feature_PE43_3.write(reg3);
        s_feature_PE44_0.write(reg0);
        s_feature_PE44_1.write(reg1);
        s_feature_PE44_2.write(reg2);
        s_feature_PE44_3.write(reg3);
        s_feature_PE45_0.write(reg0);
        s_feature_PE45_1.write(reg1);
        s_feature_PE45_2.write(reg2);
        s_feature_PE45_3.write(reg3);
        s_feature_PE46_0.write(reg0);
        s_feature_PE46_1.write(reg1);
        s_feature_PE46_2.write(reg2);
        s_feature_PE46_3.write(reg3);
        s_feature_PE47_0.write(reg0);
        s_feature_PE47_1.write(reg1);
        s_feature_PE47_2.write(reg2);
        s_feature_PE47_3.write(reg3);
        s_feature_PE48_0.write(reg0);
        s_feature_PE48_1.write(reg1);
        s_feature_PE48_2.write(reg2);
        s_feature_PE48_3.write(reg3);
        s_feature_PE49_0.write(reg0);
        s_feature_PE49_1.write(reg1);
        s_feature_PE49_2.write(reg2);
        s_feature_PE49_3.write(reg3);
        s_feature_PE50_0.write(reg0);
        s_feature_PE50_1.write(reg1);
        s_feature_PE50_2.write(reg2);
        s_feature_PE50_3.write(reg3);
        s_feature_PE51_0.write(reg0);
        s_feature_PE51_1.write(reg1);
        s_feature_PE51_2.write(reg2);
        s_feature_PE51_3.write(reg3);
        s_feature_PE52_0.write(reg0);
        s_feature_PE52_1.write(reg1);
        s_feature_PE52_2.write(reg2);
        s_feature_PE52_3.write(reg3);
        s_feature_PE53_0.write(reg0);
        s_feature_PE53_1.write(reg1);
        s_feature_PE53_2.write(reg2);
        s_feature_PE53_3.write(reg3);
    }
}

template<const int FEATURE_SIZE>
void replicate_feature_512PEs_36PE(
    STREAM<ap_uint<512> >& s_feature_in, 
    STREAM<W_TYPE>& s_feature_PE0_0, STREAM<W_TYPE>& s_feature_PE0_1,
    STREAM<W_TYPE>& s_feature_PE0_2, STREAM<W_TYPE>& s_feature_PE0_3,
    STREAM<W_TYPE>& s_feature_PE1_0, STREAM<W_TYPE>& s_feature_PE1_1,
    STREAM<W_TYPE>& s_feature_PE1_2, STREAM<W_TYPE>& s_feature_PE1_3,
    STREAM<W_TYPE>& s_feature_PE2_0, STREAM<W_TYPE>& s_feature_PE2_1,
    STREAM<W_TYPE>& s_feature_PE2_2, STREAM<W_TYPE>& s_feature_PE2_3,
    STREAM<W_TYPE>& s_feature_PE3_0, STREAM<W_TYPE>& s_feature_PE3_1,
    STREAM<W_TYPE>& s_feature_PE3_2, STREAM<W_TYPE>& s_feature_PE3_3,
    STREAM<W_TYPE>& s_feature_PE4_0, STREAM<W_TYPE>& s_feature_PE4_1,
    STREAM<W_TYPE>& s_feature_PE4_2, STREAM<W_TYPE>& s_feature_PE4_3,
    STREAM<W_TYPE>& s_feature_PE5_0, STREAM<W_TYPE>& s_feature_PE5_1,
    STREAM<W_TYPE>& s_feature_PE5_2, STREAM<W_TYPE>& s_feature_PE5_3,
    STREAM<W_TYPE>& s_feature_PE6_0, STREAM<W_TYPE>& s_feature_PE6_1,
    STREAM<W_TYPE>& s_feature_PE6_2, STREAM<W_TYPE>& s_feature_PE6_3,
    STREAM<W_TYPE>& s_feature_PE7_0, STREAM<W_TYPE>& s_feature_PE7_1,
    STREAM<W_TYPE>& s_feature_PE7_2, STREAM<W_TYPE>& s_feature_PE7_3,
    STREAM<W_TYPE>& s_feature_PE8_0, STREAM<W_TYPE>& s_feature_PE8_1,
    STREAM<W_TYPE>& s_feature_PE8_2, STREAM<W_TYPE>& s_feature_PE8_3,
    STREAM<W_TYPE>& s_feature_PE9_0, STREAM<W_TYPE>& s_feature_PE9_1,
    STREAM<W_TYPE>& s_feature_PE9_2, STREAM<W_TYPE>& s_feature_PE9_3,
    STREAM<W_TYPE>& s_feature_PE10_0, STREAM<W_TYPE>& s_feature_PE10_1,
    STREAM<W_TYPE>& s_feature_PE10_2, STREAM<W_TYPE>& s_feature_PE10_3,
    STREAM<W_TYPE>& s_feature_PE11_0, STREAM<W_TYPE>& s_feature_PE11_1,
    STREAM<W_TYPE>& s_feature_PE11_2, STREAM<W_TYPE>& s_feature_PE11_3,
    STREAM<W_TYPE>& s_feature_PE12_0, STREAM<W_TYPE>& s_feature_PE12_1,
    STREAM<W_TYPE>& s_feature_PE12_2, STREAM<W_TYPE>& s_feature_PE12_3,
    STREAM<W_TYPE>& s_feature_PE13_0, STREAM<W_TYPE>& s_feature_PE13_1,
    STREAM<W_TYPE>& s_feature_PE13_2, STREAM<W_TYPE>& s_feature_PE13_3,
    STREAM<W_TYPE>& s_feature_PE14_0, STREAM<W_TYPE>& s_feature_PE14_1,
    STREAM<W_TYPE>& s_feature_PE14_2, STREAM<W_TYPE>& s_feature_PE14_3,
    STREAM<W_TYPE>& s_feature_PE15_0, STREAM<W_TYPE>& s_feature_PE15_1,
    STREAM<W_TYPE>& s_feature_PE15_2, STREAM<W_TYPE>& s_feature_PE15_3,
    STREAM<W_TYPE>& s_feature_PE16_0, STREAM<W_TYPE>& s_feature_PE16_1,
    STREAM<W_TYPE>& s_feature_PE16_2, STREAM<W_TYPE>& s_feature_PE16_3,
    STREAM<W_TYPE>& s_feature_PE17_0, STREAM<W_TYPE>& s_feature_PE17_1,
    STREAM<W_TYPE>& s_feature_PE17_2, STREAM<W_TYPE>& s_feature_PE17_3,
    STREAM<W_TYPE>& s_feature_PE18_0, STREAM<W_TYPE>& s_feature_PE18_1,
    STREAM<W_TYPE>& s_feature_PE18_2, STREAM<W_TYPE>& s_feature_PE18_3,
    STREAM<W_TYPE>& s_feature_PE19_0, STREAM<W_TYPE>& s_feature_PE19_1,
    STREAM<W_TYPE>& s_feature_PE19_2, STREAM<W_TYPE>& s_feature_PE19_3,
    STREAM<W_TYPE>& s_feature_PE20_0, STREAM<W_TYPE>& s_feature_PE20_1,
    STREAM<W_TYPE>& s_feature_PE20_2, STREAM<W_TYPE>& s_feature_PE20_3,
    STREAM<W_TYPE>& s_feature_PE21_0, STREAM<W_TYPE>& s_feature_PE21_1,
    STREAM<W_TYPE>& s_feature_PE21_2, STREAM<W_TYPE>& s_feature_PE21_3,
    STREAM<W_TYPE>& s_feature_PE22_0, STREAM<W_TYPE>& s_feature_PE22_1,
    STREAM<W_TYPE>& s_feature_PE22_2, STREAM<W_TYPE>& s_feature_PE22_3,
    STREAM<W_TYPE>& s_feature_PE23_0, STREAM<W_TYPE>& s_feature_PE23_1,
    STREAM<W_TYPE>& s_feature_PE23_2, STREAM<W_TYPE>& s_feature_PE23_3,
    STREAM<W_TYPE>& s_feature_PE24_0, STREAM<W_TYPE>& s_feature_PE24_1,
    STREAM<W_TYPE>& s_feature_PE24_2, STREAM<W_TYPE>& s_feature_PE24_3,
    STREAM<W_TYPE>& s_feature_PE25_0, STREAM<W_TYPE>& s_feature_PE25_1,
    STREAM<W_TYPE>& s_feature_PE25_2, STREAM<W_TYPE>& s_feature_PE25_3,
    STREAM<W_TYPE>& s_feature_PE26_0, STREAM<W_TYPE>& s_feature_PE26_1,
    STREAM<W_TYPE>& s_feature_PE26_2, STREAM<W_TYPE>& s_feature_PE26_3,
    STREAM<W_TYPE>& s_feature_PE27_0, STREAM<W_TYPE>& s_feature_PE27_1,
    STREAM<W_TYPE>& s_feature_PE27_2, STREAM<W_TYPE>& s_feature_PE27_3,
    STREAM<W_TYPE>& s_feature_PE28_0, STREAM<W_TYPE>& s_feature_PE28_1,
    STREAM<W_TYPE>& s_feature_PE28_2, STREAM<W_TYPE>& s_feature_PE28_3,
    STREAM<W_TYPE>& s_feature_PE29_0, STREAM<W_TYPE>& s_feature_PE29_1,
    STREAM<W_TYPE>& s_feature_PE29_2, STREAM<W_TYPE>& s_feature_PE29_3,
    STREAM<W_TYPE>& s_feature_PE30_0, STREAM<W_TYPE>& s_feature_PE30_1,
    STREAM<W_TYPE>& s_feature_PE30_2, STREAM<W_TYPE>& s_feature_PE30_3,
    STREAM<W_TYPE>& s_feature_PE31_0, STREAM<W_TYPE>& s_feature_PE31_1,
    STREAM<W_TYPE>& s_feature_PE31_2, STREAM<W_TYPE>& s_feature_PE31_3,
    STREAM<W_TYPE>& s_feature_PE32_0, STREAM<W_TYPE>& s_feature_PE32_1,
    STREAM<W_TYPE>& s_feature_PE32_2, STREAM<W_TYPE>& s_feature_PE32_3,
    STREAM<W_TYPE>& s_feature_PE33_0, STREAM<W_TYPE>& s_feature_PE33_1,
    STREAM<W_TYPE>& s_feature_PE33_2, STREAM<W_TYPE>& s_feature_PE33_3,
    STREAM<W_TYPE>& s_feature_PE34_0, STREAM<W_TYPE>& s_feature_PE34_1,
    STREAM<W_TYPE>& s_feature_PE34_2, STREAM<W_TYPE>& s_feature_PE34_3,
    STREAM<W_TYPE>& s_feature_PE35_0, STREAM<W_TYPE>& s_feature_PE35_1,
    STREAM<W_TYPE>& s_feature_PE35_2, STREAM<W_TYPE>& s_feature_PE35_3){

    for (int i = 0; i < BATCH_NUM * BATCH_SIZE * FEATURE_SIZE / INTS_PER_W / 4; i++) {
        #pragma HLS pipeline II=1

        ap_uint<512>  reg = s_feature_in.read();
        W_TYPE reg0 = reg.range(127, 0);
        W_TYPE reg1 = reg.range(255, 128);
        W_TYPE reg2 = reg.range(383, 256);
        W_TYPE reg3 = reg.range(511, 255);

        s_feature_PE0_0.write(reg0);
        s_feature_PE0_1.write(reg1);
        s_feature_PE0_2.write(reg2);
        s_feature_PE0_3.write(reg3);
        s_feature_PE1_0.write(reg0);
        s_feature_PE1_1.write(reg1);
        s_feature_PE1_2.write(reg2);
        s_feature_PE1_3.write(reg3);
        s_feature_PE2_0.write(reg0);
        s_feature_PE2_1.write(reg1);
        s_feature_PE2_2.write(reg2);
        s_feature_PE2_3.write(reg3);
        s_feature_PE3_0.write(reg0);
        s_feature_PE3_1.write(reg1);
        s_feature_PE3_2.write(reg2);
        s_feature_PE3_3.write(reg3);
        s_feature_PE4_0.write(reg0);
        s_feature_PE4_1.write(reg1);
        s_feature_PE4_2.write(reg2);
        s_feature_PE4_3.write(reg3);
        s_feature_PE5_0.write(reg0);
        s_feature_PE5_1.write(reg1);
        s_feature_PE5_2.write(reg2);
        s_feature_PE5_3.write(reg3);
        s_feature_PE6_0.write(reg0);
        s_feature_PE6_1.write(reg1);
        s_feature_PE6_2.write(reg2);
        s_feature_PE6_3.write(reg3);
        s_feature_PE7_0.write(reg0);
        s_feature_PE7_1.write(reg1);
        s_feature_PE7_2.write(reg2);
        s_feature_PE7_3.write(reg3);
        s_feature_PE8_0.write(reg0);
        s_feature_PE8_1.write(reg1);
        s_feature_PE8_2.write(reg2);
        s_feature_PE8_3.write(reg3);
        s_feature_PE9_0.write(reg0);
        s_feature_PE9_1.write(reg1);
        s_feature_PE9_2.write(reg2);
        s_feature_PE9_3.write(reg3);
        s_feature_PE10_0.write(reg0);
        s_feature_PE10_1.write(reg1);
        s_feature_PE10_2.write(reg2);
        s_feature_PE10_3.write(reg3);
        s_feature_PE11_0.write(reg0);
        s_feature_PE11_1.write(reg1);
        s_feature_PE11_2.write(reg2);
        s_feature_PE11_3.write(reg3);
        s_feature_PE12_0.write(reg0);
        s_feature_PE12_1.write(reg1);
        s_feature_PE12_2.write(reg2);
        s_feature_PE12_3.write(reg3);
        s_feature_PE13_0.write(reg0);
        s_feature_PE13_1.write(reg1);
        s_feature_PE13_2.write(reg2);
        s_feature_PE13_3.write(reg3);
        s_feature_PE14_0.write(reg0);
        s_feature_PE14_1.write(reg1);
        s_feature_PE14_2.write(reg2);
        s_feature_PE14_3.write(reg3);
        s_feature_PE15_0.write(reg0);
        s_feature_PE15_1.write(reg1);
        s_feature_PE15_2.write(reg2);
        s_feature_PE15_3.write(reg3);
        s_feature_PE16_0.write(reg0);
        s_feature_PE16_1.write(reg1);
        s_feature_PE16_2.write(reg2);
        s_feature_PE16_3.write(reg3);
        s_feature_PE17_0.write(reg0);
        s_feature_PE17_1.write(reg1);
        s_feature_PE17_2.write(reg2);
        s_feature_PE17_3.write(reg3);
        s_feature_PE18_0.write(reg0);
        s_feature_PE18_1.write(reg1);
        s_feature_PE18_2.write(reg2);
        s_feature_PE18_3.write(reg3);
        s_feature_PE19_0.write(reg0);
        s_feature_PE19_1.write(reg1);
        s_feature_PE19_2.write(reg2);
        s_feature_PE19_3.write(reg3);
        s_feature_PE20_0.write(reg0);
        s_feature_PE20_1.write(reg1);
        s_feature_PE20_2.write(reg2);
        s_feature_PE20_3.write(reg3);
        s_feature_PE21_0.write(reg0);
        s_feature_PE21_1.write(reg1);
        s_feature_PE21_2.write(reg2);
        s_feature_PE21_3.write(reg3);
        s_feature_PE22_0.write(reg0);
        s_feature_PE22_1.write(reg1);
        s_feature_PE22_2.write(reg2);
        s_feature_PE22_3.write(reg3);
        s_feature_PE23_0.write(reg0);
        s_feature_PE23_1.write(reg1);
        s_feature_PE23_2.write(reg2);
        s_feature_PE23_3.write(reg3);
        s_feature_PE24_0.write(reg0);
        s_feature_PE24_1.write(reg1);
        s_feature_PE24_2.write(reg2);
        s_feature_PE24_3.write(reg3);
        s_feature_PE25_0.write(reg0);
        s_feature_PE25_1.write(reg1);
        s_feature_PE25_2.write(reg2);
        s_feature_PE25_3.write(reg3);
        s_feature_PE26_0.write(reg0);
        s_feature_PE26_1.write(reg1);
        s_feature_PE26_2.write(reg2);
        s_feature_PE26_3.write(reg3);
        s_feature_PE27_0.write(reg0);
        s_feature_PE27_1.write(reg1);
        s_feature_PE27_2.write(reg2);
        s_feature_PE27_3.write(reg3);
        s_feature_PE28_0.write(reg0);
        s_feature_PE28_1.write(reg1);
        s_feature_PE28_2.write(reg2);
        s_feature_PE28_3.write(reg3);
        s_feature_PE29_0.write(reg0);
        s_feature_PE29_1.write(reg1);
        s_feature_PE29_2.write(reg2);
        s_feature_PE29_3.write(reg3);
        s_feature_PE30_0.write(reg0);
        s_feature_PE30_1.write(reg1);
        s_feature_PE30_2.write(reg2);
        s_feature_PE30_3.write(reg3);
        s_feature_PE31_0.write(reg0);
        s_feature_PE31_1.write(reg1);
        s_feature_PE31_2.write(reg2);
        s_feature_PE31_3.write(reg3);
        s_feature_PE32_0.write(reg0);
        s_feature_PE32_1.write(reg1);
        s_feature_PE32_2.write(reg2);
        s_feature_PE32_3.write(reg3);
        s_feature_PE33_0.write(reg0);
        s_feature_PE33_1.write(reg1);
        s_feature_PE33_2.write(reg2);
        s_feature_PE33_3.write(reg3);
        s_feature_PE34_0.write(reg0);
        s_feature_PE34_1.write(reg1);
        s_feature_PE34_2.write(reg2);
        s_feature_PE34_3.write(reg3);
        s_feature_PE35_0.write(reg0);
        s_feature_PE35_1.write(reg1);
        s_feature_PE35_2.write(reg2);
        s_feature_PE35_3.write(reg3);
    }
}

template<const int FEATURE_SIZE, const int ROW_PER_PE>
void replicate_feature_512PEs_32PE(
    STREAM<ap_uint<512> >& s_feature_in, 
    STREAM<W_TYPE>& s_feature_PE0_0, STREAM<W_TYPE>& s_feature_PE0_1,
    STREAM<W_TYPE>& s_feature_PE1_0, STREAM<W_TYPE>& s_feature_PE1_1,
    STREAM<W_TYPE>& s_feature_PE2_0, STREAM<W_TYPE>& s_feature_PE2_1,
    STREAM<W_TYPE>& s_feature_PE3_0, STREAM<W_TYPE>& s_feature_PE3_1,
    STREAM<W_TYPE>& s_feature_PE4_0, STREAM<W_TYPE>& s_feature_PE4_1,
    STREAM<W_TYPE>& s_feature_PE5_0, STREAM<W_TYPE>& s_feature_PE5_1,
    STREAM<W_TYPE>& s_feature_PE6_0, STREAM<W_TYPE>& s_feature_PE6_1,
    STREAM<W_TYPE>& s_feature_PE7_0, STREAM<W_TYPE>& s_feature_PE7_1,
    STREAM<W_TYPE>& s_feature_PE8_0, STREAM<W_TYPE>& s_feature_PE8_1,
    STREAM<W_TYPE>& s_feature_PE9_0, STREAM<W_TYPE>& s_feature_PE9_1,
    STREAM<W_TYPE>& s_feature_PE10_0, STREAM<W_TYPE>& s_feature_PE10_1,
    STREAM<W_TYPE>& s_feature_PE11_0, STREAM<W_TYPE>& s_feature_PE11_1,
    STREAM<W_TYPE>& s_feature_PE12_0, STREAM<W_TYPE>& s_feature_PE12_1,
    STREAM<W_TYPE>& s_feature_PE13_0, STREAM<W_TYPE>& s_feature_PE13_1,
    STREAM<W_TYPE>& s_feature_PE14_0, STREAM<W_TYPE>& s_feature_PE14_1,
    STREAM<W_TYPE>& s_feature_PE15_0, STREAM<W_TYPE>& s_feature_PE15_1,
    STREAM<W_TYPE>& s_feature_PE16_0, STREAM<W_TYPE>& s_feature_PE16_1,
    STREAM<W_TYPE>& s_feature_PE17_0, STREAM<W_TYPE>& s_feature_PE17_1,
    STREAM<W_TYPE>& s_feature_PE18_0, STREAM<W_TYPE>& s_feature_PE18_1,
    STREAM<W_TYPE>& s_feature_PE19_0, STREAM<W_TYPE>& s_feature_PE19_1,
    STREAM<W_TYPE>& s_feature_PE20_0, STREAM<W_TYPE>& s_feature_PE20_1,
    STREAM<W_TYPE>& s_feature_PE21_0, STREAM<W_TYPE>& s_feature_PE21_1,
    STREAM<W_TYPE>& s_feature_PE22_0, STREAM<W_TYPE>& s_feature_PE22_1,
    STREAM<W_TYPE>& s_feature_PE23_0, STREAM<W_TYPE>& s_feature_PE23_1,
    STREAM<W_TYPE>& s_feature_PE24_0, STREAM<W_TYPE>& s_feature_PE24_1,
    STREAM<W_TYPE>& s_feature_PE25_0, STREAM<W_TYPE>& s_feature_PE25_1,
    STREAM<W_TYPE>& s_feature_PE26_0, STREAM<W_TYPE>& s_feature_PE26_1,
    STREAM<W_TYPE>& s_feature_PE27_0, STREAM<W_TYPE>& s_feature_PE27_1,
    STREAM<W_TYPE>& s_feature_PE28_0, STREAM<W_TYPE>& s_feature_PE28_1,
    STREAM<W_TYPE>& s_feature_PE29_0, STREAM<W_TYPE>& s_feature_PE29_1,
    STREAM<W_TYPE>& s_feature_PE30_0, STREAM<W_TYPE>& s_feature_PE30_1,
    STREAM<W_TYPE>& s_feature_PE31_0, STREAM<W_TYPE>& s_feature_PE31_1){

    for (int i = 0; i < BATCH_NUM * BATCH_SIZE * ROW_PER_PE * FEATURE_SIZE / INTS_PER_W / 4; i++) {
        #pragma HLS pipeline II=2

        ap_uint<512>  reg = s_feature_in.read();
        W_TYPE reg0 = reg.range(127, 0);
        W_TYPE reg1 = reg.range(255, 128);
        W_TYPE reg2 = reg.range(383, 256);
        W_TYPE reg3 = reg.range(511, 255);

        s_feature_PE0_0.write(reg0);
        s_feature_PE0_1.write(reg1);
        s_feature_PE0_0.write(reg2);
        s_feature_PE0_1.write(reg3);
        s_feature_PE1_0.write(reg0);
        s_feature_PE1_1.write(reg1);
        s_feature_PE1_0.write(reg2);
        s_feature_PE1_1.write(reg3);
        s_feature_PE2_0.write(reg0);
        s_feature_PE2_1.write(reg1);
        s_feature_PE2_0.write(reg2);
        s_feature_PE2_1.write(reg3);
        s_feature_PE3_0.write(reg0);
        s_feature_PE3_1.write(reg1);
        s_feature_PE3_0.write(reg2);
        s_feature_PE3_1.write(reg3);
        s_feature_PE4_0.write(reg0);
        s_feature_PE4_1.write(reg1);
        s_feature_PE4_0.write(reg2);
        s_feature_PE4_1.write(reg3);
        s_feature_PE5_0.write(reg0);
        s_feature_PE5_1.write(reg1);
        s_feature_PE5_0.write(reg2);
        s_feature_PE5_1.write(reg3);
        s_feature_PE6_0.write(reg0);
        s_feature_PE6_1.write(reg1);
        s_feature_PE6_0.write(reg2);
        s_feature_PE6_1.write(reg3);
        s_feature_PE7_0.write(reg0);
        s_feature_PE7_1.write(reg1);
        s_feature_PE7_0.write(reg2);
        s_feature_PE7_1.write(reg3);
        s_feature_PE8_0.write(reg0);
        s_feature_PE8_1.write(reg1);
        s_feature_PE8_0.write(reg2);
        s_feature_PE8_1.write(reg3);
        s_feature_PE9_0.write(reg0);
        s_feature_PE9_1.write(reg1);
        s_feature_PE9_0.write(reg2);
        s_feature_PE9_1.write(reg3);
        s_feature_PE10_0.write(reg0);
        s_feature_PE10_1.write(reg1);
        s_feature_PE10_0.write(reg2);
        s_feature_PE10_1.write(reg3);
        s_feature_PE11_0.write(reg0);
        s_feature_PE11_1.write(reg1);
        s_feature_PE11_0.write(reg2);
        s_feature_PE11_1.write(reg3);
        s_feature_PE12_0.write(reg0);
        s_feature_PE12_1.write(reg1);
        s_feature_PE12_0.write(reg2);
        s_feature_PE12_1.write(reg3);
        s_feature_PE13_0.write(reg0);
        s_feature_PE13_1.write(reg1);
        s_feature_PE13_0.write(reg2);
        s_feature_PE13_1.write(reg3);
        s_feature_PE14_0.write(reg0);
        s_feature_PE14_1.write(reg1);
        s_feature_PE14_0.write(reg2);
        s_feature_PE14_1.write(reg3);
        s_feature_PE15_0.write(reg0);
        s_feature_PE15_1.write(reg1);
        s_feature_PE15_0.write(reg2);
        s_feature_PE15_1.write(reg3);
        s_feature_PE16_0.write(reg0);
        s_feature_PE16_1.write(reg1);
        s_feature_PE16_0.write(reg2);
        s_feature_PE16_1.write(reg3);
        s_feature_PE17_0.write(reg0);
        s_feature_PE17_1.write(reg1);
        s_feature_PE17_0.write(reg2);
        s_feature_PE17_1.write(reg3);
        s_feature_PE18_0.write(reg0);
        s_feature_PE18_1.write(reg1);
        s_feature_PE18_0.write(reg2);
        s_feature_PE18_1.write(reg3);
        s_feature_PE19_0.write(reg0);
        s_feature_PE19_1.write(reg1);
        s_feature_PE19_0.write(reg2);
        s_feature_PE19_1.write(reg3);
        s_feature_PE20_0.write(reg0);
        s_feature_PE20_1.write(reg1);
        s_feature_PE20_0.write(reg2);
        s_feature_PE20_1.write(reg3);
        s_feature_PE21_0.write(reg0);
        s_feature_PE21_1.write(reg1);
        s_feature_PE21_0.write(reg2);
        s_feature_PE21_1.write(reg3);
        s_feature_PE22_0.write(reg0);
        s_feature_PE22_1.write(reg1);
        s_feature_PE22_0.write(reg2);
        s_feature_PE22_1.write(reg3);
        s_feature_PE23_0.write(reg0);
        s_feature_PE23_1.write(reg1);
        s_feature_PE23_0.write(reg2);
        s_feature_PE23_1.write(reg3);
        s_feature_PE24_0.write(reg0);
        s_feature_PE24_1.write(reg1);
        s_feature_PE24_0.write(reg2);
        s_feature_PE24_1.write(reg3);
        s_feature_PE25_0.write(reg0);
        s_feature_PE25_1.write(reg1);
        s_feature_PE25_0.write(reg2);
        s_feature_PE25_1.write(reg3);
        s_feature_PE26_0.write(reg0);
        s_feature_PE26_1.write(reg1);
        s_feature_PE26_0.write(reg2);
        s_feature_PE26_1.write(reg3);
        s_feature_PE27_0.write(reg0);
        s_feature_PE27_1.write(reg1);
        s_feature_PE27_0.write(reg2);
        s_feature_PE27_1.write(reg3);
        s_feature_PE28_0.write(reg0);
        s_feature_PE28_1.write(reg1);
        s_feature_PE28_0.write(reg2);
        s_feature_PE28_1.write(reg3);
        s_feature_PE29_0.write(reg0);
        s_feature_PE29_1.write(reg1);
        s_feature_PE29_0.write(reg2);
        s_feature_PE29_1.write(reg3);
        s_feature_PE30_0.write(reg0);
        s_feature_PE30_1.write(reg1);
        s_feature_PE30_0.write(reg2);
        s_feature_PE30_1.write(reg3);
        s_feature_PE31_0.write(reg0);
        s_feature_PE31_1.write(reg1);
        s_feature_PE31_0.write(reg2);
        s_feature_PE31_1.write(reg3);
    }
}

template<const int FEATURE_SIZE>
void replicate_feature_512PEs_16PE(
    STREAM<ap_uint<512> >& s_feature_in, 
    STREAM<W_TYPE>& s_feature_PE0_0, STREAM<W_TYPE>& s_feature_PE0_1,
    STREAM<W_TYPE>& s_feature_PE1_0, STREAM<W_TYPE>& s_feature_PE1_1,
    STREAM<W_TYPE>& s_feature_PE2_0, STREAM<W_TYPE>& s_feature_PE2_1,
    STREAM<W_TYPE>& s_feature_PE3_0, STREAM<W_TYPE>& s_feature_PE3_1,
    STREAM<W_TYPE>& s_feature_PE4_0, STREAM<W_TYPE>& s_feature_PE4_1,
    STREAM<W_TYPE>& s_feature_PE5_0, STREAM<W_TYPE>& s_feature_PE5_1,
    STREAM<W_TYPE>& s_feature_PE6_0, STREAM<W_TYPE>& s_feature_PE6_1,
    STREAM<W_TYPE>& s_feature_PE7_0, STREAM<W_TYPE>& s_feature_PE7_1,
    STREAM<W_TYPE>& s_feature_PE8_0, STREAM<W_TYPE>& s_feature_PE8_1,
    STREAM<W_TYPE>& s_feature_PE9_0, STREAM<W_TYPE>& s_feature_PE9_1,
    STREAM<W_TYPE>& s_feature_PE10_0, STREAM<W_TYPE>& s_feature_PE10_1,
    STREAM<W_TYPE>& s_feature_PE11_0, STREAM<W_TYPE>& s_feature_PE11_1,
    STREAM<W_TYPE>& s_feature_PE12_0, STREAM<W_TYPE>& s_feature_PE12_1,
    STREAM<W_TYPE>& s_feature_PE13_0, STREAM<W_TYPE>& s_feature_PE13_1,
    STREAM<W_TYPE>& s_feature_PE14_0, STREAM<W_TYPE>& s_feature_PE14_1,
    STREAM<W_TYPE>& s_feature_PE15_0, STREAM<W_TYPE>& s_feature_PE15_1){

    for (int i = 0; i < BATCH_NUM * BATCH_SIZE * FEATURE_SIZE / INTS_PER_W / 4; i++) {
        #pragma HLS pipeline II=2

        ap_uint<512>  reg = s_feature_in.read();
        W_TYPE reg0 = reg.range(127, 0);
        W_TYPE reg1 = reg.range(255, 128);
        W_TYPE reg2 = reg.range(383, 256);
        W_TYPE reg3 = reg.range(511, 255);

        s_feature_PE0_0.write(reg0);
        s_feature_PE0_1.write(reg1);
        s_feature_PE0_0.write(reg2);
        s_feature_PE0_1.write(reg3);
        s_feature_PE1_0.write(reg0);
        s_feature_PE1_1.write(reg1);
        s_feature_PE1_0.write(reg2);
        s_feature_PE1_1.write(reg3);
        s_feature_PE2_0.write(reg0);
        s_feature_PE2_1.write(reg1);
        s_feature_PE2_0.write(reg2);
        s_feature_PE2_1.write(reg3);
        s_feature_PE3_0.write(reg0);
        s_feature_PE3_1.write(reg1);
        s_feature_PE3_0.write(reg2);
        s_feature_PE3_1.write(reg3);
        s_feature_PE4_0.write(reg0);
        s_feature_PE4_1.write(reg1);
        s_feature_PE4_0.write(reg2);
        s_feature_PE4_1.write(reg3);
        s_feature_PE5_0.write(reg0);
        s_feature_PE5_1.write(reg1);
        s_feature_PE5_0.write(reg2);
        s_feature_PE5_1.write(reg3);
        s_feature_PE6_0.write(reg0);
        s_feature_PE6_1.write(reg1);
        s_feature_PE6_0.write(reg2);
        s_feature_PE6_1.write(reg3);
        s_feature_PE7_0.write(reg0);
        s_feature_PE7_1.write(reg1);
        s_feature_PE7_0.write(reg2);
        s_feature_PE7_1.write(reg3);
        s_feature_PE8_0.write(reg0);
        s_feature_PE8_1.write(reg1);
        s_feature_PE8_0.write(reg2);
        s_feature_PE8_1.write(reg3);
        s_feature_PE9_0.write(reg0);
        s_feature_PE9_1.write(reg1);
        s_feature_PE9_0.write(reg2);
        s_feature_PE9_1.write(reg3);
        s_feature_PE10_0.write(reg0);
        s_feature_PE10_1.write(reg1);
        s_feature_PE10_0.write(reg2);
        s_feature_PE10_1.write(reg3);
        s_feature_PE11_0.write(reg0);
        s_feature_PE11_1.write(reg1);
        s_feature_PE11_0.write(reg2);
        s_feature_PE11_1.write(reg3);
        s_feature_PE12_0.write(reg0);
        s_feature_PE12_1.write(reg1);
        s_feature_PE12_0.write(reg2);
        s_feature_PE12_1.write(reg3);
        s_feature_PE13_0.write(reg0);
        s_feature_PE13_1.write(reg1);
        s_feature_PE13_0.write(reg2);
        s_feature_PE13_1.write(reg3);
        s_feature_PE14_0.write(reg0);
        s_feature_PE14_1.write(reg1);
        s_feature_PE14_0.write(reg2);
        s_feature_PE14_1.write(reg3);
        s_feature_PE15_0.write(reg0);
        s_feature_PE15_1.write(reg1);
        s_feature_PE15_0.write(reg2);
        s_feature_PE15_1.write(reg3);
    }
}


template<const int FEATURE_SIZE>
void replicate_feature_512PEs_29PE(
    STREAM<ap_uint<512> >& s_feature_in, 
    STREAM<W_TYPE>& s_feature_PE0_0, STREAM<W_TYPE>& s_feature_PE0_1,
    STREAM<W_TYPE>& s_feature_PE0_2, STREAM<W_TYPE>& s_feature_PE0_3,
    STREAM<W_TYPE>& s_feature_PE1_0, STREAM<W_TYPE>& s_feature_PE1_1,
    STREAM<W_TYPE>& s_feature_PE1_2, STREAM<W_TYPE>& s_feature_PE1_3,
    STREAM<W_TYPE>& s_feature_PE2_0, STREAM<W_TYPE>& s_feature_PE2_1,
    STREAM<W_TYPE>& s_feature_PE2_2, STREAM<W_TYPE>& s_feature_PE2_3,
    STREAM<W_TYPE>& s_feature_PE3_0, STREAM<W_TYPE>& s_feature_PE3_1,
    STREAM<W_TYPE>& s_feature_PE3_2, STREAM<W_TYPE>& s_feature_PE3_3,
    STREAM<W_TYPE>& s_feature_PE4_0, STREAM<W_TYPE>& s_feature_PE4_1,
    STREAM<W_TYPE>& s_feature_PE4_2, STREAM<W_TYPE>& s_feature_PE4_3,
    STREAM<W_TYPE>& s_feature_PE5_0, STREAM<W_TYPE>& s_feature_PE5_1,
    STREAM<W_TYPE>& s_feature_PE5_2, STREAM<W_TYPE>& s_feature_PE5_3,
    STREAM<W_TYPE>& s_feature_PE6_0, STREAM<W_TYPE>& s_feature_PE6_1,
    STREAM<W_TYPE>& s_feature_PE6_2, STREAM<W_TYPE>& s_feature_PE6_3,
    STREAM<W_TYPE>& s_feature_PE7_0, STREAM<W_TYPE>& s_feature_PE7_1,
    STREAM<W_TYPE>& s_feature_PE7_2, STREAM<W_TYPE>& s_feature_PE7_3,
    STREAM<W_TYPE>& s_feature_PE8_0, STREAM<W_TYPE>& s_feature_PE8_1,
    STREAM<W_TYPE>& s_feature_PE8_2, STREAM<W_TYPE>& s_feature_PE8_3,
    STREAM<W_TYPE>& s_feature_PE9_0, STREAM<W_TYPE>& s_feature_PE9_1,
    STREAM<W_TYPE>& s_feature_PE9_2, STREAM<W_TYPE>& s_feature_PE9_3,
    STREAM<W_TYPE>& s_feature_PE10_0, STREAM<W_TYPE>& s_feature_PE10_1,
    STREAM<W_TYPE>& s_feature_PE10_2, STREAM<W_TYPE>& s_feature_PE10_3,
    STREAM<W_TYPE>& s_feature_PE11_0, STREAM<W_TYPE>& s_feature_PE11_1,
    STREAM<W_TYPE>& s_feature_PE11_2, STREAM<W_TYPE>& s_feature_PE11_3,
    STREAM<W_TYPE>& s_feature_PE12_0, STREAM<W_TYPE>& s_feature_PE12_1,
    STREAM<W_TYPE>& s_feature_PE12_2, STREAM<W_TYPE>& s_feature_PE12_3,
    STREAM<W_TYPE>& s_feature_PE13_0, STREAM<W_TYPE>& s_feature_PE13_1,
    STREAM<W_TYPE>& s_feature_PE13_2, STREAM<W_TYPE>& s_feature_PE13_3,
    STREAM<W_TYPE>& s_feature_PE14_0, STREAM<W_TYPE>& s_feature_PE14_1,
    STREAM<W_TYPE>& s_feature_PE14_2, STREAM<W_TYPE>& s_feature_PE14_3,
    STREAM<W_TYPE>& s_feature_PE15_0, STREAM<W_TYPE>& s_feature_PE15_1,
    STREAM<W_TYPE>& s_feature_PE15_2, STREAM<W_TYPE>& s_feature_PE15_3,
    STREAM<W_TYPE>& s_feature_PE16_0, STREAM<W_TYPE>& s_feature_PE16_1,
    STREAM<W_TYPE>& s_feature_PE16_2, STREAM<W_TYPE>& s_feature_PE16_3,
    STREAM<W_TYPE>& s_feature_PE17_0, STREAM<W_TYPE>& s_feature_PE17_1,
    STREAM<W_TYPE>& s_feature_PE17_2, STREAM<W_TYPE>& s_feature_PE17_3,
    STREAM<W_TYPE>& s_feature_PE18_0, STREAM<W_TYPE>& s_feature_PE18_1,
    STREAM<W_TYPE>& s_feature_PE18_2, STREAM<W_TYPE>& s_feature_PE18_3,
    STREAM<W_TYPE>& s_feature_PE19_0, STREAM<W_TYPE>& s_feature_PE19_1,
    STREAM<W_TYPE>& s_feature_PE19_2, STREAM<W_TYPE>& s_feature_PE19_3,
    STREAM<W_TYPE>& s_feature_PE20_0, STREAM<W_TYPE>& s_feature_PE20_1,
    STREAM<W_TYPE>& s_feature_PE20_2, STREAM<W_TYPE>& s_feature_PE20_3,
    STREAM<W_TYPE>& s_feature_PE21_0, STREAM<W_TYPE>& s_feature_PE21_1,
    STREAM<W_TYPE>& s_feature_PE21_2, STREAM<W_TYPE>& s_feature_PE21_3,
    STREAM<W_TYPE>& s_feature_PE22_0, STREAM<W_TYPE>& s_feature_PE22_1,
    STREAM<W_TYPE>& s_feature_PE22_2, STREAM<W_TYPE>& s_feature_PE22_3,
    STREAM<W_TYPE>& s_feature_PE23_0, STREAM<W_TYPE>& s_feature_PE23_1,
    STREAM<W_TYPE>& s_feature_PE23_2, STREAM<W_TYPE>& s_feature_PE23_3,
    STREAM<W_TYPE>& s_feature_PE24_0, STREAM<W_TYPE>& s_feature_PE24_1,
    STREAM<W_TYPE>& s_feature_PE24_2, STREAM<W_TYPE>& s_feature_PE24_3,
    STREAM<W_TYPE>& s_feature_PE25_0, STREAM<W_TYPE>& s_feature_PE25_1,
    STREAM<W_TYPE>& s_feature_PE25_2, STREAM<W_TYPE>& s_feature_PE25_3,
    STREAM<W_TYPE>& s_feature_PE26_0, STREAM<W_TYPE>& s_feature_PE26_1,
    STREAM<W_TYPE>& s_feature_PE26_2, STREAM<W_TYPE>& s_feature_PE26_3,
    STREAM<W_TYPE>& s_feature_PE27_0, STREAM<W_TYPE>& s_feature_PE27_1,
    STREAM<W_TYPE>& s_feature_PE27_2, STREAM<W_TYPE>& s_feature_PE27_3,
    STREAM<W_TYPE>& s_feature_PE28_0, STREAM<W_TYPE>& s_feature_PE28_1,
    STREAM<W_TYPE>& s_feature_PE28_2, STREAM<W_TYPE>& s_feature_PE28_3){

    for (int i = 0; i < BATCH_NUM * BATCH_SIZE * FEATURE_SIZE / INTS_PER_W / 4; i++) {
        #pragma HLS pipeline II=1

        ap_uint<512>  reg = s_feature_in.read();
        W_TYPE reg0 = reg.range(127, 0);
        W_TYPE reg1 = reg.range(255, 128);
        W_TYPE reg2 = reg.range(383, 256);
        W_TYPE reg3 = reg.range(511, 255);

        s_feature_PE0_0.write(reg0);
        s_feature_PE0_1.write(reg1);
        s_feature_PE0_2.write(reg2);
        s_feature_PE0_3.write(reg3);
        s_feature_PE1_0.write(reg0);
        s_feature_PE1_1.write(reg1);
        s_feature_PE1_2.write(reg2);
        s_feature_PE1_3.write(reg3);
        s_feature_PE2_0.write(reg0);
        s_feature_PE2_1.write(reg1);
        s_feature_PE2_2.write(reg2);
        s_feature_PE2_3.write(reg3);
        s_feature_PE3_0.write(reg0);
        s_feature_PE3_1.write(reg1);
        s_feature_PE3_2.write(reg2);
        s_feature_PE3_3.write(reg3);
        s_feature_PE4_0.write(reg0);
        s_feature_PE4_1.write(reg1);
        s_feature_PE4_2.write(reg2);
        s_feature_PE4_3.write(reg3);
        s_feature_PE5_0.write(reg0);
        s_feature_PE5_1.write(reg1);
        s_feature_PE5_2.write(reg2);
        s_feature_PE5_3.write(reg3);
        s_feature_PE6_0.write(reg0);
        s_feature_PE6_1.write(reg1);
        s_feature_PE6_2.write(reg2);
        s_feature_PE6_3.write(reg3);
        s_feature_PE7_0.write(reg0);
        s_feature_PE7_1.write(reg1);
        s_feature_PE7_2.write(reg2);
        s_feature_PE7_3.write(reg3);
        s_feature_PE8_0.write(reg0);
        s_feature_PE8_1.write(reg1);
        s_feature_PE8_2.write(reg2);
        s_feature_PE8_3.write(reg3);
        s_feature_PE9_0.write(reg0);
        s_feature_PE9_1.write(reg1);
        s_feature_PE9_2.write(reg2);
        s_feature_PE9_3.write(reg3);
        s_feature_PE10_0.write(reg0);
        s_feature_PE10_1.write(reg1);
        s_feature_PE10_2.write(reg2);
        s_feature_PE10_3.write(reg3);
        s_feature_PE11_0.write(reg0);
        s_feature_PE11_1.write(reg1);
        s_feature_PE11_2.write(reg2);
        s_feature_PE11_3.write(reg3);
        s_feature_PE12_0.write(reg0);
        s_feature_PE12_1.write(reg1);
        s_feature_PE12_2.write(reg2);
        s_feature_PE12_3.write(reg3);
        s_feature_PE13_0.write(reg0);
        s_feature_PE13_1.write(reg1);
        s_feature_PE13_2.write(reg2);
        s_feature_PE13_3.write(reg3);
        s_feature_PE14_0.write(reg0);
        s_feature_PE14_1.write(reg1);
        s_feature_PE14_2.write(reg2);
        s_feature_PE14_3.write(reg3);
        s_feature_PE15_0.write(reg0);
        s_feature_PE15_1.write(reg1);
        s_feature_PE15_2.write(reg2);
        s_feature_PE15_3.write(reg3);
        s_feature_PE16_0.write(reg0);
        s_feature_PE16_1.write(reg1);
        s_feature_PE16_2.write(reg2);
        s_feature_PE16_3.write(reg3);
        s_feature_PE17_0.write(reg0);
        s_feature_PE17_1.write(reg1);
        s_feature_PE17_2.write(reg2);
        s_feature_PE17_3.write(reg3);
        s_feature_PE18_0.write(reg0);
        s_feature_PE18_1.write(reg1);
        s_feature_PE18_2.write(reg2);
        s_feature_PE18_3.write(reg3);
        s_feature_PE19_0.write(reg0);
        s_feature_PE19_1.write(reg1);
        s_feature_PE19_2.write(reg2);
        s_feature_PE19_3.write(reg3);
        s_feature_PE20_0.write(reg0);
        s_feature_PE20_1.write(reg1);
        s_feature_PE20_2.write(reg2);
        s_feature_PE20_3.write(reg3);
        s_feature_PE21_0.write(reg0);
        s_feature_PE21_1.write(reg1);
        s_feature_PE21_2.write(reg2);
        s_feature_PE21_3.write(reg3);
        s_feature_PE22_0.write(reg0);
        s_feature_PE22_1.write(reg1);
        s_feature_PE22_2.write(reg2);
        s_feature_PE22_3.write(reg3);
        s_feature_PE23_0.write(reg0);
        s_feature_PE23_1.write(reg1);
        s_feature_PE23_2.write(reg2);
        s_feature_PE23_3.write(reg3);
        s_feature_PE24_0.write(reg0);
        s_feature_PE24_1.write(reg1);
        s_feature_PE24_2.write(reg2);
        s_feature_PE24_3.write(reg3);
        s_feature_PE25_0.write(reg0);
        s_feature_PE25_1.write(reg1);
        s_feature_PE25_2.write(reg2);
        s_feature_PE25_3.write(reg3);
        s_feature_PE26_0.write(reg0);
        s_feature_PE26_1.write(reg1);
        s_feature_PE26_2.write(reg2);
        s_feature_PE26_3.write(reg3);
        s_feature_PE27_0.write(reg0);
        s_feature_PE27_1.write(reg1);
        s_feature_PE27_2.write(reg2);
        s_feature_PE27_3.write(reg3);
        s_feature_PE28_0.write(reg0);
        s_feature_PE28_1.write(reg1);
        s_feature_PE28_2.write(reg2);
        s_feature_PE28_3.write(reg3);
    }
}

template<>
void matmul_PE_UNROLL8<ROOT_HIDDEN_SIZE1, ROOT_ROW_PER_PE2, WEIGHT_BRAM>(
    STREAM<W_TYPE>& s_feature_PE_0,
    STREAM<W_TYPE>& s_feature_PE_1,
    STREAM<D_TYPE>& s_result_PE) {
#pragma HLS inline off

    W_TYPE weights_transpose_local[ROOT_ROW_PER_PE2 * ROOT_HIDDEN_SIZE1 / INTS_PER_W];
#pragma HLS resource variable=weights_transpose_local core=RAM_2P_BRAM

    init_weights<ROOT_HIDDEN_SIZE1, ROOT_ROW_PER_PE2, WEIGHT_BRAM>(weights_transpose_local);

    item_loop:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {

        row_loop:
        for (int result_idx = 0; result_idx < ROOT_ROW_PER_PE2; result_idx++) {
            
            D_TYPE result = 0;
            dot_product:
            // NOTE: manually unroll 2 here
            for (int d = 0; d < ROOT_HIDDEN_SIZE1 / INTS_PER_W / 2; d++) {
                #pragma HLS pipeline II=1
                W_TYPE reg_f_0 = s_feature_PE_0.read();
                W_TYPE reg_f_1 = s_feature_PE_1.read();
                W_TYPE reg_w_0 = weights_transpose_local[
                    result_idx * ROOT_HIDDEN_SIZE1 / INTS_PER_W / 2 + 2 * d];
                W_TYPE reg_w_1 = weights_transpose_local[
                    result_idx * ROOT_HIDDEN_SIZE1 / INTS_PER_W / 2 + 2 * d + 1];

                D_TYPE first_f_0 = reg_f_0.range(31, 0);
                D_TYPE second_f_0 = reg_f_0.range(63, 32);
                D_TYPE third_f_0 = reg_f_0.range(95, 64);
                D_TYPE fourth_f_0 = reg_f_0.range(127, 96);

                D_TYPE first_w_0= reg_w_0.range(31, 0);
                D_TYPE second_w_0 = reg_w_0.range(63, 32);
                D_TYPE third_w_0 = reg_w_0.range(95, 64);
                D_TYPE fourth_w_0 = reg_w_0.range(127, 96);

                D_TYPE first_f_1 = reg_f_1.range(31, 0);
                D_TYPE second_f_1 = reg_f_1.range(63, 32);
                D_TYPE third_f_1 = reg_f_1.range(95, 64);
                D_TYPE fourth_f_1 = reg_f_1.range(127, 96);

                D_TYPE first_w_1= reg_w_1.range(31, 0);
                D_TYPE second_w_1 = reg_w_1.range(63, 32);
                D_TYPE third_w_1 = reg_w_1.range(95, 64);
                D_TYPE fourth_w_1 = reg_w_1.range(127, 96);

                
                result += 
                    first_f_0 * first_w_0 + second_f_0 * second_w_0 + 
                    third_f_0 * third_w_0 + fourth_f_0 * fourth_w_0 + 
                    first_f_1 * first_w_1 + second_f_1 * second_w_1 + 
                    third_f_1 * third_w_1 + fourth_f_1 * fourth_w_1;
            }
            s_result_PE.write(result);
        }
    }
} 

template<>
void matmul_PE_UNROLL8<ROOT_HIDDEN_SIZE1, ROOT_ROW_PER_PE2, WEIGHT_URAM>(
    STREAM<W_TYPE>& s_feature_PE_0,
    STREAM<W_TYPE>& s_feature_PE_1,
    STREAM<D_TYPE>& s_result_PE) {
#pragma HLS inline off

    W_TYPE weights_transpose_local[ROOT_ROW_PER_PE2 * ROOT_HIDDEN_SIZE1 / INTS_PER_W];
#pragma HLS resource variable=weights_transpose_local core=RAM_2P_URAM

    init_weights<ROOT_HIDDEN_SIZE1, ROOT_ROW_PER_PE2, WEIGHT_URAM>(weights_transpose_local);

    item_loop:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {

        row_loop:
        for (int result_idx = 0; result_idx < ROOT_ROW_PER_PE2; result_idx++) {
            
            D_TYPE result = 0;
            dot_product:
            // NOTE: manually unroll 2 here
            for (int d = 0; d < ROOT_HIDDEN_SIZE1 / INTS_PER_W / 2; d++) {
                #pragma HLS pipeline II=1
                W_TYPE reg_f_0 = s_feature_PE_0.read();
                W_TYPE reg_f_1 = s_feature_PE_1.read();
                W_TYPE reg_w_0 = weights_transpose_local[
                    result_idx * ROOT_HIDDEN_SIZE1 / INTS_PER_W / 2 + 2 * d];
                W_TYPE reg_w_1 = weights_transpose_local[
                    result_idx * ROOT_HIDDEN_SIZE1 / INTS_PER_W / 2 + 2 * d + 1];

                D_TYPE first_f_0 = reg_f_0.range(31, 0);
                D_TYPE second_f_0 = reg_f_0.range(63, 32);
                D_TYPE third_f_0 = reg_f_0.range(95, 64);
                D_TYPE fourth_f_0 = reg_f_0.range(127, 96);

                D_TYPE first_w_0= reg_w_0.range(31, 0);
                D_TYPE second_w_0 = reg_w_0.range(63, 32);
                D_TYPE third_w_0 = reg_w_0.range(95, 64);
                D_TYPE fourth_w_0 = reg_w_0.range(127, 96);

                D_TYPE first_f_1 = reg_f_1.range(31, 0);
                D_TYPE second_f_1 = reg_f_1.range(63, 32);
                D_TYPE third_f_1 = reg_f_1.range(95, 64);
                D_TYPE fourth_f_1 = reg_f_1.range(127, 96);

                D_TYPE first_w_1= reg_w_1.range(31, 0);
                D_TYPE second_w_1 = reg_w_1.range(63, 32);
                D_TYPE third_w_1 = reg_w_1.range(95, 64);
                D_TYPE fourth_w_1 = reg_w_1.range(127, 96);

                
                result += 
                    first_f_0 * first_w_0 + second_f_0 * second_w_0 + 
                    third_f_0 * third_w_0 + fourth_f_0 * fourth_w_0 + 
                    first_f_1 * first_w_1 + second_f_1 * second_w_1 + 
                    third_f_1 * third_w_1 + fourth_f_1 * fourth_w_1;
            }
            s_result_PE.write(result);
        }
    }
} 

template<>
void init_weights<ROOT_HIDDEN_SIZE1, ROOT_ROW_PER_PE2, WEIGHT_BRAM>(W_TYPE* weights_transpose_local) {

    D_TYPE row_template_even[ROOT_HIDDEN_SIZE1] = 
      { 0,  0,  0,  0,  0,  0,  0, -1,  0,  1,  0,  0, -1,  0,  0,  0, 
        1,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
       -1,  0,  0,  0,  0,  0,  0,  0, -1,  0, -1,  0,  0, -1,  0,  0, 
        0,  0,  0,  0,  0,  0,  0, -1, -1,  0,  0,  0,  0, -1,  0,  0, 
        0,  0,  1,  0,  0,  0,  0,  0,  0,  0, -1,  1,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  1,  0, -1, -1,  0, -1, 
       -1,  1,  0,  0,  0,  0, -1,  0,  0, -1,  0,  1,  0,  0, -1,  1, 
        0,  0,  1,  0,  0,  0,  0,  0, -1,  0, -1,  0,  0,  1, -1,  0, 
        0,  0,  0,  0,  1,  0,  1, -1,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0, -1,  0,  1,  0,  0,  1, -1,  0,  0,  1,  1, 
        0,  0,  0,  0,  0,  1,  0,  1,  1,  1,  0,  0,  0,  0,  0,  0, 
        1,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  0,  1,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1, -1,  1,  0,  0, -1, 
       -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0, 
        0,  0,  0,  0,  1,  0,  0,  0,  0,  0, -1,  1,  0,  0,  0,  0, 
       -1, -1,  0,  0, -1,  0,  0,  0,  0,  0,  0,  0,  1, -1,  0,  0,
        0,  0,  0,  0,  0,  0,  0, -1,  0,  1,  0,  0, -1,  0,  0,  0, 
        1,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
       -1,  0,  0,  0,  0,  0,  0,  0, -1,  0, -1,  0,  0, -1,  0,  0, 
        0,  0,  0,  0,  0,  0,  0, -1, -1,  0,  0,  0,  0, -1,  0,  0, 
        0,  0,  1,  0,  0,  0,  0,  0,  0,  0, -1,  1,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  1,  0, -1, -1,  0, -1, 
       -1,  1,  0,  0,  0,  0, -1,  0,  0, -1,  0,  1,  0,  0, -1,  1, 
        0,  0,  1,  0,  0,  0,  0,  0, -1,  0, -1,  0,  0,  1, -1,  0, 
        0,  0,  0,  0,  1,  0,  1, -1,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0, -1,  0,  1,  0,  0,  1, -1,  0,  0,  1,  1, 
        0,  0,  0,  0,  0,  1,  0,  1,  1,  1,  0,  0,  0,  0,  0,  0, 
        1,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  0,  1,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1, -1,  1,  0,  0, -1, 
       -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0
        };

    // load weights, convert to wide type
    for (int i = 0; i < ROOT_HIDDEN_SIZE1 / INTS_PER_W; i++) {
        #pragma HLS pipeline II=1
        W_TYPE reg_even;
        reg_even.range(31, 0) = row_template_even[INTS_PER_W * i];
        reg_even.range(63, 32) = row_template_even[INTS_PER_W * i + 1];
        reg_even.range(95, 64) = row_template_even[INTS_PER_W * i + 2];
        reg_even.range(127, 96) = row_template_even[INTS_PER_W * i + 3];

        weights_transpose_local[i] = reg_even;
    }

}

template<>
void init_weights<ROOT_HIDDEN_SIZE1, ROOT_ROW_PER_PE2, WEIGHT_URAM>(W_TYPE* weights_transpose_local) {

    D_TYPE row_template_odd[ROOT_HIDDEN_SIZE1] = 
      { 1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0, 
        1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0, -1, -1,  0, 
        0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  1,  0,  0,  0,  0, 
        0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  1,  0,  0,  0,  0,  1,  0, -1,  0,  0,  1,  0, -1,  0, 
       -1,  0,  0,  0,  1,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0, 
        0,  0,  0,  0, -1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0, -1,  0, 
        0,  0,  0, -1,  0, -1,  1,  1,  0,  0,  0, -1,  0,  0, -1,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  1,  0,  0, 
        0,  0,  0,  0,  0, -1, -1,  0,  1,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0, 
        1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1, -1,  0,  0,  1,
        1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0, 
        1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0, -1, -1,  0, 
        0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  1,  0,  0,  0,  0, 
        0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  1,  0,  0,  0,  0,  1,  0, -1,  0,  0,  1,  0, -1,  0, 
       -1,  0,  0,  0,  1,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0, 
        0,  0,  0,  0, -1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0, -1,  0, 
        0,  0,  0, -1,  0, -1,  1,  1,  0,  0,  0, -1,  0,  0, -1,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  1,  0,  0, 
        0,  0,  0,  0,  0, -1, -1,  0,  1,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0
        };

    // load weights, convert to wide type
    for (int i = 0; i < ROOT_HIDDEN_SIZE1 / INTS_PER_W; i++) {
        #pragma HLS pipeline II=1
        W_TYPE reg_odd;
        reg_odd.range(31, 0) = row_template_odd[INTS_PER_W * i];
        reg_odd.range(63, 32) = row_template_odd[INTS_PER_W * i + 1];
        reg_odd.range(95, 64) = row_template_odd[INTS_PER_W * i + 2];
        reg_odd.range(127, 96) = row_template_odd[INTS_PER_W * i + 3];
        weights_transpose_local[i] = reg_odd;
    }
}


template<const int ROW_PER_PE>
void gather_results_512PEs_216PE(
    STREAM<D_TYPE>& s_result_PE0, STREAM<D_TYPE>& s_result_PE1, 
    STREAM<D_TYPE>& s_result_PE2, STREAM<D_TYPE>& s_result_PE3, 
    STREAM<D_TYPE>& s_result_PE4, STREAM<D_TYPE>& s_result_PE5, 
    STREAM<D_TYPE>& s_result_PE6, STREAM<D_TYPE>& s_result_PE7, 
    STREAM<D_TYPE>& s_result_PE8, STREAM<D_TYPE>& s_result_PE9, 
    STREAM<D_TYPE>& s_result_PE10, STREAM<D_TYPE>& s_result_PE11, 
    STREAM<D_TYPE>& s_result_PE12, STREAM<D_TYPE>& s_result_PE13, 
    STREAM<D_TYPE>& s_result_PE14, STREAM<D_TYPE>& s_result_PE15, 
    STREAM<D_TYPE>& s_result_PE16, STREAM<D_TYPE>& s_result_PE17, 
    STREAM<D_TYPE>& s_result_PE18, STREAM<D_TYPE>& s_result_PE19, 
    STREAM<D_TYPE>& s_result_PE20, STREAM<D_TYPE>& s_result_PE21, 
    STREAM<D_TYPE>& s_result_PE22, STREAM<D_TYPE>& s_result_PE23, 
    STREAM<D_TYPE>& s_result_PE24, STREAM<D_TYPE>& s_result_PE25, 
    STREAM<D_TYPE>& s_result_PE26, STREAM<D_TYPE>& s_result_PE27, 
    STREAM<D_TYPE>& s_result_PE28, STREAM<D_TYPE>& s_result_PE29, 
    STREAM<D_TYPE>& s_result_PE30, STREAM<D_TYPE>& s_result_PE31, 
    STREAM<D_TYPE>& s_result_PE32, STREAM<D_TYPE>& s_result_PE33, 
    STREAM<D_TYPE>& s_result_PE34, STREAM<D_TYPE>& s_result_PE35, 
    STREAM<D_TYPE>& s_result_PE36, STREAM<D_TYPE>& s_result_PE37, 
    STREAM<D_TYPE>& s_result_PE38, STREAM<D_TYPE>& s_result_PE39, 
    STREAM<D_TYPE>& s_result_PE40, STREAM<D_TYPE>& s_result_PE41, 
    STREAM<D_TYPE>& s_result_PE42, STREAM<D_TYPE>& s_result_PE43, 
    STREAM<D_TYPE>& s_result_PE44, STREAM<D_TYPE>& s_result_PE45, 
    STREAM<D_TYPE>& s_result_PE46, STREAM<D_TYPE>& s_result_PE47, 
    STREAM<D_TYPE>& s_result_PE48, STREAM<D_TYPE>& s_result_PE49, 
    STREAM<D_TYPE>& s_result_PE50, STREAM<D_TYPE>& s_result_PE51, 
    STREAM<D_TYPE>& s_result_PE52, STREAM<D_TYPE>& s_result_PE53, 
    STREAM<D_TYPE>& s_result_PE54, STREAM<D_TYPE>& s_result_PE55, 
    STREAM<D_TYPE>& s_result_PE56, STREAM<D_TYPE>& s_result_PE57, 
    STREAM<D_TYPE>& s_result_PE58, STREAM<D_TYPE>& s_result_PE59, 
    STREAM<D_TYPE>& s_result_PE60, STREAM<D_TYPE>& s_result_PE61, 
    STREAM<D_TYPE>& s_result_PE62, STREAM<D_TYPE>& s_result_PE63, 
    STREAM<D_TYPE>& s_result_PE64, STREAM<D_TYPE>& s_result_PE65, 
    STREAM<D_TYPE>& s_result_PE66, STREAM<D_TYPE>& s_result_PE67, 
    STREAM<D_TYPE>& s_result_PE68, STREAM<D_TYPE>& s_result_PE69, 
    STREAM<D_TYPE>& s_result_PE70, STREAM<D_TYPE>& s_result_PE71, 
    STREAM<D_TYPE>& s_result_PE72, STREAM<D_TYPE>& s_result_PE73, 
    STREAM<D_TYPE>& s_result_PE74, STREAM<D_TYPE>& s_result_PE75, 
    STREAM<D_TYPE>& s_result_PE76, STREAM<D_TYPE>& s_result_PE77, 
    STREAM<D_TYPE>& s_result_PE78, STREAM<D_TYPE>& s_result_PE79, 
    STREAM<D_TYPE>& s_result_PE80, STREAM<D_TYPE>& s_result_PE81, 
    STREAM<D_TYPE>& s_result_PE82, STREAM<D_TYPE>& s_result_PE83, 
    STREAM<D_TYPE>& s_result_PE84, STREAM<D_TYPE>& s_result_PE85, 
    STREAM<D_TYPE>& s_result_PE86, STREAM<D_TYPE>& s_result_PE87, 
    STREAM<D_TYPE>& s_result_PE88, STREAM<D_TYPE>& s_result_PE89, 
    STREAM<D_TYPE>& s_result_PE90, STREAM<D_TYPE>& s_result_PE91, 
    STREAM<D_TYPE>& s_result_PE92, STREAM<D_TYPE>& s_result_PE93, 
    STREAM<D_TYPE>& s_result_PE94, STREAM<D_TYPE>& s_result_PE95, 
    STREAM<D_TYPE>& s_result_PE96, STREAM<D_TYPE>& s_result_PE97, 
    STREAM<D_TYPE>& s_result_PE98, STREAM<D_TYPE>& s_result_PE99, 
    STREAM<D_TYPE>& s_result_PE100, STREAM<D_TYPE>& s_result_PE101, 
    STREAM<D_TYPE>& s_result_PE102, STREAM<D_TYPE>& s_result_PE103, 
    STREAM<D_TYPE>& s_result_PE104, STREAM<D_TYPE>& s_result_PE105, 
    STREAM<D_TYPE>& s_result_PE106, STREAM<D_TYPE>& s_result_PE107, 
    STREAM<D_TYPE>& s_result_PE108, STREAM<D_TYPE>& s_result_PE109, 
    STREAM<D_TYPE>& s_result_PE110, STREAM<D_TYPE>& s_result_PE111, 
    STREAM<D_TYPE>& s_result_PE112, STREAM<D_TYPE>& s_result_PE113, 
    STREAM<D_TYPE>& s_result_PE114, STREAM<D_TYPE>& s_result_PE115, 
    STREAM<D_TYPE>& s_result_PE116, STREAM<D_TYPE>& s_result_PE117, 
    STREAM<D_TYPE>& s_result_PE118, STREAM<D_TYPE>& s_result_PE119, 
    STREAM<D_TYPE>& s_result_PE120, STREAM<D_TYPE>& s_result_PE121, 
    STREAM<D_TYPE>& s_result_PE122, STREAM<D_TYPE>& s_result_PE123, 
    STREAM<D_TYPE>& s_result_PE124, STREAM<D_TYPE>& s_result_PE125, 
    STREAM<D_TYPE>& s_result_PE126, STREAM<D_TYPE>& s_result_PE127, 
    STREAM<D_TYPE>& s_result_PE128, STREAM<D_TYPE>& s_result_PE129,
    STREAM<D_TYPE>& s_result_PE130, STREAM<D_TYPE>& s_result_PE131,
    STREAM<D_TYPE>& s_result_PE132, STREAM<D_TYPE>& s_result_PE133,
    STREAM<D_TYPE>& s_result_PE134, STREAM<D_TYPE>& s_result_PE135,
    STREAM<D_TYPE>& s_result_PE136, STREAM<D_TYPE>& s_result_PE137,
    STREAM<D_TYPE>& s_result_PE138, STREAM<D_TYPE>& s_result_PE139,
    STREAM<D_TYPE>& s_result_PE140, STREAM<D_TYPE>& s_result_PE141,
    STREAM<D_TYPE>& s_result_PE142, STREAM<D_TYPE>& s_result_PE143,
    STREAM<D_TYPE>& s_result_PE144, STREAM<D_TYPE>& s_result_PE145,
    STREAM<D_TYPE>& s_result_PE146, STREAM<D_TYPE>& s_result_PE147,
    STREAM<D_TYPE>& s_result_PE148, STREAM<D_TYPE>& s_result_PE149,
    STREAM<D_TYPE>& s_result_PE150, STREAM<D_TYPE>& s_result_PE151,
    STREAM<D_TYPE>& s_result_PE152, STREAM<D_TYPE>& s_result_PE153,
    STREAM<D_TYPE>& s_result_PE154, STREAM<D_TYPE>& s_result_PE155,
    STREAM<D_TYPE>& s_result_PE156, STREAM<D_TYPE>& s_result_PE157,
    STREAM<D_TYPE>& s_result_PE158, STREAM<D_TYPE>& s_result_PE159,
    STREAM<D_TYPE>& s_result_PE160, STREAM<D_TYPE>& s_result_PE161,
    STREAM<D_TYPE>& s_result_PE162, STREAM<D_TYPE>& s_result_PE163,
    STREAM<D_TYPE>& s_result_PE164, STREAM<D_TYPE>& s_result_PE165,
    STREAM<D_TYPE>& s_result_PE166, STREAM<D_TYPE>& s_result_PE167,
    STREAM<D_TYPE>& s_result_PE168, STREAM<D_TYPE>& s_result_PE169,
    STREAM<D_TYPE>& s_result_PE170, STREAM<D_TYPE>& s_result_PE171,
    STREAM<D_TYPE>& s_result_PE172, STREAM<D_TYPE>& s_result_PE173,
    STREAM<D_TYPE>& s_result_PE174, STREAM<D_TYPE>& s_result_PE175,
    STREAM<D_TYPE>& s_result_PE176, STREAM<D_TYPE>& s_result_PE177,
    STREAM<D_TYPE>& s_result_PE178, STREAM<D_TYPE>& s_result_PE179,
    STREAM<D_TYPE>& s_result_PE180, STREAM<D_TYPE>& s_result_PE181,
    STREAM<D_TYPE>& s_result_PE182, STREAM<D_TYPE>& s_result_PE183,
    STREAM<D_TYPE>& s_result_PE184, STREAM<D_TYPE>& s_result_PE185,
    STREAM<D_TYPE>& s_result_PE186, STREAM<D_TYPE>& s_result_PE187,
    STREAM<D_TYPE>& s_result_PE188, STREAM<D_TYPE>& s_result_PE189,
    STREAM<D_TYPE>& s_result_PE190, STREAM<D_TYPE>& s_result_PE191,
    STREAM<D_TYPE>& s_result_PE192, STREAM<D_TYPE>& s_result_PE193,
    STREAM<D_TYPE>& s_result_PE194, STREAM<D_TYPE>& s_result_PE195,
    STREAM<D_TYPE>& s_result_PE196, STREAM<D_TYPE>& s_result_PE197,
    STREAM<D_TYPE>& s_result_PE198, STREAM<D_TYPE>& s_result_PE199,
    STREAM<D_TYPE>& s_result_PE200, STREAM<D_TYPE>& s_result_PE201, 
    STREAM<D_TYPE>& s_result_PE202, STREAM<D_TYPE>& s_result_PE203, 
    STREAM<D_TYPE>& s_result_PE204, STREAM<D_TYPE>& s_result_PE205, 
    STREAM<D_TYPE>& s_result_PE206, STREAM<D_TYPE>& s_result_PE207, 
    STREAM<D_TYPE>& s_result_PE208, STREAM<D_TYPE>& s_result_PE209, 
    STREAM<D_TYPE>& s_result_PE210, STREAM<D_TYPE>& s_result_PE211, 
    STREAM<D_TYPE>& s_result_PE212, STREAM<D_TYPE>& s_result_PE213, 
    STREAM<D_TYPE>& s_result_PE214, STREAM<D_TYPE>& s_result_PE215,
    STREAM<ap_uint<512> >& s_result_all) {
     
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        #pragma HLS pipeline II=26  // write 1 result_all per CC

        ap_uint<512> reg0, reg1, reg2, reg3, reg4, reg5, reg6, reg7, 
            reg8, reg9, reg10, reg11, reg12, reg13, reg14, reg15, 
            reg16, reg17, reg18, reg19, reg20, reg21, reg22, reg23, 
            reg24, reg25, reg26;

        reg0.range(31, 0) = s_result_PE0.read() + 1;
        reg0.range(63, 32) = s_result_PE0.read() + 1;
        reg0.range(95, 64) = s_result_PE1.read() + 1;
        reg0.range(127, 96) = s_result_PE1.read() + 1;
        reg0.range(159, 128) = s_result_PE2.read() + 1;
        reg0.range(191, 160) = s_result_PE2.read() + 1;
        reg0.range(223, 192) = s_result_PE3.read() + 1;
        reg0.range(255, 224) = s_result_PE3.read() + 1;
        reg0.range(287, 256) = s_result_PE4.read() + 1;
        reg0.range(319, 288) = s_result_PE4.read() + 1;
        reg0.range(351, 320) = s_result_PE5.read() + 1;
        reg0.range(383, 352) = s_result_PE5.read() + 1;
        reg0.range(415, 384) = s_result_PE6.read() + 1;
        reg0.range(447, 416) = s_result_PE6.read() + 1;
        reg0.range(479, 448) = s_result_PE7.read() + 1;
        reg0.range(511, 480) = s_result_PE7.read() + 1;
        s_result_all.write(reg0);

        reg1.range(31, 0) = s_result_PE8.read() + 1;
        reg1.range(63, 32) = s_result_PE8.read() + 1;
        reg1.range(95, 64) = s_result_PE9.read() + 1;
        reg1.range(127, 96) = s_result_PE9.read() + 1;
        reg1.range(159, 128) = s_result_PE10.read() + 1;
        reg1.range(191, 160) = s_result_PE10.read() + 1;
        reg1.range(223, 192) = s_result_PE11.read() + 1;
        reg1.range(255, 224) = s_result_PE11.read() + 1;
        reg1.range(287, 256) = s_result_PE12.read() + 1;
        reg1.range(319, 288) = s_result_PE12.read() + 1;
        reg1.range(351, 320) = s_result_PE13.read() + 1;
        reg1.range(383, 352) = s_result_PE13.read() + 1;
        reg1.range(415, 384) = s_result_PE14.read() + 1;
        reg1.range(447, 416) = s_result_PE14.read() + 1;
        reg1.range(479, 448) = s_result_PE15.read() + 1;
        reg1.range(511, 480) = s_result_PE15.read() + 1;
        s_result_all.write(reg1);

        reg2.range(31, 0) = s_result_PE16.read() + 1;
        reg2.range(63, 32) = s_result_PE16.read() + 1;
        reg2.range(95, 64) = s_result_PE17.read() + 1;
        reg2.range(127, 96) = s_result_PE17.read() + 1;
        reg2.range(159, 128) = s_result_PE18.read() + 1;
        reg2.range(191, 160) = s_result_PE18.read() + 1;
        reg2.range(223, 192) = s_result_PE19.read() + 1;
        reg2.range(255, 224) = s_result_PE19.read() + 1;
        reg2.range(287, 256) = s_result_PE20.read() + 1;
        reg2.range(319, 288) = s_result_PE20.read() + 1;
        reg2.range(351, 320) = s_result_PE21.read() + 1;
        reg2.range(383, 352) = s_result_PE21.read() + 1;
        reg2.range(415, 384) = s_result_PE22.read() + 1;
        reg2.range(447, 416) = s_result_PE22.read() + 1;
        reg2.range(479, 448) = s_result_PE23.read() + 1;
        reg2.range(511, 480) = s_result_PE23.read() + 1;
        s_result_all.write(reg2);

        reg3.range(31, 0) = s_result_PE24.read() + 1;
        reg3.range(63, 32) = s_result_PE24.read() + 1;
        reg3.range(95, 64) = s_result_PE25.read() + 1;
        reg3.range(127, 96) = s_result_PE25.read() + 1;
        reg3.range(159, 128) = s_result_PE26.read() + 1;
        reg3.range(191, 160) = s_result_PE26.read() + 1;
        reg3.range(223, 192) = s_result_PE27.read() + 1;
        reg3.range(255, 224) = s_result_PE27.read() + 1;
        reg3.range(287, 256) = s_result_PE28.read() + 1;
        reg3.range(319, 288) = s_result_PE28.read() + 1;
        reg3.range(351, 320) = s_result_PE29.read() + 1;
        reg3.range(383, 352) = s_result_PE29.read() + 1;
        reg3.range(415, 384) = s_result_PE30.read() + 1;
        reg3.range(447, 416) = s_result_PE30.read() + 1;
        reg3.range(479, 448) = s_result_PE31.read() + 1;
        reg3.range(511, 480) = s_result_PE31.read() + 1;
        s_result_all.write(reg3);

        reg4.range(31, 0) = s_result_PE32.read() + 1;
        reg4.range(63, 32) = s_result_PE32.read() + 1;
        reg4.range(95, 64) = s_result_PE33.read() + 1;
        reg4.range(127, 96) = s_result_PE33.read() + 1;
        reg4.range(159, 128) = s_result_PE34.read() + 1;
        reg4.range(191, 160) = s_result_PE34.read() + 1;
        reg4.range(223, 192) = s_result_PE35.read() + 1;
        reg4.range(255, 224) = s_result_PE35.read() + 1;
        reg4.range(287, 256) = s_result_PE36.read() + 1;
        reg4.range(319, 288) = s_result_PE36.read() + 1;
        reg4.range(351, 320) = s_result_PE37.read() + 1;
        reg4.range(383, 352) = s_result_PE37.read() + 1;
        reg4.range(415, 384) = s_result_PE38.read() + 1;
        reg4.range(447, 416) = s_result_PE38.read() + 1;
        reg4.range(479, 448) = s_result_PE39.read() + 1;
        reg4.range(511, 480) = s_result_PE39.read() + 1;
        s_result_all.write(reg4);

        reg5.range(31, 0) = s_result_PE40.read() + 1;
        reg5.range(63, 32) = s_result_PE40.read() + 1;
        reg5.range(95, 64) = s_result_PE41.read() + 1;
        reg5.range(127, 96) = s_result_PE41.read() + 1;
        reg5.range(159, 128) = s_result_PE42.read() + 1;
        reg5.range(191, 160) = s_result_PE42.read() + 1;
        reg5.range(223, 192) = s_result_PE43.read() + 1;
        reg5.range(255, 224) = s_result_PE43.read() + 1;
        reg5.range(287, 256) = s_result_PE44.read() + 1;
        reg5.range(319, 288) = s_result_PE44.read() + 1;
        reg5.range(351, 320) = s_result_PE45.read() + 1;
        reg5.range(383, 352) = s_result_PE45.read() + 1;
        reg5.range(415, 384) = s_result_PE46.read() + 1;
        reg5.range(447, 416) = s_result_PE46.read() + 1;
        reg5.range(479, 448) = s_result_PE47.read() + 1;
        reg5.range(511, 480) = s_result_PE47.read() + 1;
        s_result_all.write(reg5);

        reg6.range(31, 0) = s_result_PE48.read() + 1;
        reg6.range(63, 32) = s_result_PE48.read() + 1;
        reg6.range(95, 64) = s_result_PE49.read() + 1;
        reg6.range(127, 96) = s_result_PE49.read() + 1;
        reg6.range(159, 128) = s_result_PE50.read() + 1;
        reg6.range(191, 160) = s_result_PE50.read() + 1;
        reg6.range(223, 192) = s_result_PE51.read() + 1;
        reg6.range(255, 224) = s_result_PE51.read() + 1;
        reg6.range(287, 256) = s_result_PE52.read() + 1;
        reg6.range(319, 288) = s_result_PE52.read() + 1;
        reg6.range(351, 320) = s_result_PE53.read() + 1;
        reg6.range(383, 352) = s_result_PE53.read() + 1;
        reg6.range(415, 384) = s_result_PE54.read() + 1;
        reg6.range(447, 416) = s_result_PE54.read() + 1;
        reg6.range(479, 448) = s_result_PE55.read() + 1;
        reg6.range(511, 480) = s_result_PE55.read() + 1;
        s_result_all.write(reg6);

        reg7.range(31, 0) = s_result_PE56.read() + 1;
        reg7.range(63, 32) = s_result_PE56.read() + 1;
        reg7.range(95, 64) = s_result_PE57.read() + 1;
        reg7.range(127, 96) = s_result_PE57.read() + 1;
        reg7.range(159, 128) = s_result_PE58.read() + 1;
        reg7.range(191, 160) = s_result_PE58.read() + 1;
        reg7.range(223, 192) = s_result_PE59.read() + 1;
        reg7.range(255, 224) = s_result_PE59.read() + 1;
        reg7.range(287, 256) = s_result_PE60.read() + 1;
        reg7.range(319, 288) = s_result_PE60.read() + 1;
        reg7.range(351, 320) = s_result_PE61.read() + 1;
        reg7.range(383, 352) = s_result_PE61.read() + 1;
        reg7.range(415, 384) = s_result_PE62.read() + 1;
        reg7.range(447, 416) = s_result_PE62.read() + 1;
        reg7.range(479, 448) = s_result_PE63.read() + 1;
        reg7.range(511, 480) = s_result_PE63.read() + 1;
        s_result_all.write(reg7);

        reg8.range(31, 0) = s_result_PE64.read() + 1;
        reg8.range(63, 32) = s_result_PE64.read() + 1;
        reg8.range(95, 64) = s_result_PE65.read() + 1;
        reg8.range(127, 96) = s_result_PE65.read() + 1;
        reg8.range(159, 128) = s_result_PE66.read() + 1;
        reg8.range(191, 160) = s_result_PE66.read() + 1;
        reg8.range(223, 192) = s_result_PE67.read() + 1;
        reg8.range(255, 224) = s_result_PE67.read() + 1;
        reg8.range(287, 256) = s_result_PE68.read() + 1;
        reg8.range(319, 288) = s_result_PE68.read() + 1;
        reg8.range(351, 320) = s_result_PE69.read() + 1;
        reg8.range(383, 352) = s_result_PE69.read() + 1;
        reg8.range(415, 384) = s_result_PE70.read() + 1;
        reg8.range(447, 416) = s_result_PE70.read() + 1;
        reg8.range(479, 448) = s_result_PE71.read() + 1;
        reg8.range(511, 480) = s_result_PE71.read() + 1;
        s_result_all.write(reg8);

        reg9.range(31, 0) = s_result_PE72.read() + 1;
        reg9.range(63, 32) = s_result_PE72.read() + 1;
        reg9.range(95, 64) = s_result_PE73.read() + 1;
        reg9.range(127, 96) = s_result_PE73.read() + 1;
        reg9.range(159, 128) = s_result_PE74.read() + 1;
        reg9.range(191, 160) = s_result_PE74.read() + 1;
        reg9.range(223, 192) = s_result_PE75.read() + 1;
        reg9.range(255, 224) = s_result_PE75.read() + 1;
        reg9.range(287, 256) = s_result_PE76.read() + 1;
        reg9.range(319, 288) = s_result_PE76.read() + 1;
        reg9.range(351, 320) = s_result_PE77.read() + 1;
        reg9.range(383, 352) = s_result_PE77.read() + 1;
        reg9.range(415, 384) = s_result_PE78.read() + 1;
        reg9.range(447, 416) = s_result_PE78.read() + 1;
        reg9.range(479, 448) = s_result_PE79.read() + 1;
        reg9.range(511, 480) = s_result_PE79.read() + 1;
        s_result_all.write(reg9);

        reg10.range(31, 0) = s_result_PE80.read() + 1;
        reg10.range(63, 32) = s_result_PE80.read() + 1;
        reg10.range(95, 64) = s_result_PE81.read() + 1;
        reg10.range(127, 96) = s_result_PE81.read() + 1;
        reg10.range(159, 128) = s_result_PE82.read() + 1;
        reg10.range(191, 160) = s_result_PE82.read() + 1;
        reg10.range(223, 192) = s_result_PE83.read() + 1;
        reg10.range(255, 224) = s_result_PE83.read() + 1;
        reg10.range(287, 256) = s_result_PE84.read() + 1;
        reg10.range(319, 288) = s_result_PE84.read() + 1;
        reg10.range(351, 320) = s_result_PE85.read() + 1;
        reg10.range(383, 352) = s_result_PE85.read() + 1;
        reg10.range(415, 384) = s_result_PE86.read() + 1;
        reg10.range(447, 416) = s_result_PE86.read() + 1;
        reg10.range(479, 448) = s_result_PE87.read() + 1;
        reg10.range(511, 480) = s_result_PE87.read() + 1;
        s_result_all.write(reg10);

        reg11.range(31, 0) = s_result_PE88.read() + 1;
        reg11.range(63, 32) = s_result_PE88.read() + 1;
        reg11.range(95, 64) = s_result_PE89.read() + 1;
        reg11.range(127, 96) = s_result_PE89.read() + 1;
        reg11.range(159, 128) = s_result_PE90.read() + 1;
        reg11.range(191, 160) = s_result_PE90.read() + 1;
        reg11.range(223, 192) = s_result_PE91.read() + 1;
        reg11.range(255, 224) = s_result_PE91.read() + 1;
        reg11.range(287, 256) = s_result_PE92.read() + 1;
        reg11.range(319, 288) = s_result_PE92.read() + 1;
        reg11.range(351, 320) = s_result_PE93.read() + 1;
        reg11.range(383, 352) = s_result_PE93.read() + 1;
        reg11.range(415, 384) = s_result_PE94.read() + 1;
        reg11.range(447, 416) = s_result_PE94.read() + 1;
        reg11.range(479, 448) = s_result_PE95.read() + 1;
        reg11.range(511, 480) = s_result_PE95.read() + 1;
        s_result_all.write(reg11);

        reg12.range(31, 0) = s_result_PE96.read() + 1;
        reg12.range(63, 32) = s_result_PE96.read() + 1;
        reg12.range(95, 64) = s_result_PE97.read() + 1;
        reg12.range(127, 96) = s_result_PE97.read() + 1;
        reg12.range(159, 128) = s_result_PE98.read() + 1;
        reg12.range(191, 160) = s_result_PE98.read() + 1;
        reg12.range(223, 192) = s_result_PE99.read() + 1;
        reg12.range(255, 224) = s_result_PE99.read() + 1;
        reg12.range(287, 256) = s_result_PE100.read() + 1;
        reg12.range(319, 288) = s_result_PE100.read() + 1;
        reg12.range(351, 320) = s_result_PE101.read() + 1;
        reg12.range(383, 352) = s_result_PE101.read() + 1;
        reg12.range(415, 384) = s_result_PE102.read() + 1;
        reg12.range(447, 416) = s_result_PE102.read() + 1;
        reg12.range(479, 448) = s_result_PE103.read() + 1;
        reg12.range(511, 480) = s_result_PE103.read() + 1;
        s_result_all.write(reg12);

        reg13.range(31, 0) = s_result_PE104.read() + 1;
        reg13.range(63, 32) = s_result_PE104.read() + 1;
        reg13.range(95, 64) = s_result_PE105.read() + 1;
        reg13.range(127, 96) = s_result_PE105.read() + 1;
        reg13.range(159, 128) = s_result_PE106.read() + 1;
        reg13.range(191, 160) = s_result_PE106.read() + 1;
        reg13.range(223, 192) = s_result_PE107.read() + 1;
        reg13.range(255, 224) = s_result_PE107.read() + 1;
        reg13.range(287, 256) = s_result_PE108.read() + 1;
        reg13.range(319, 288) = s_result_PE108.read() + 1;
        reg13.range(351, 320) = s_result_PE109.read() + 1;
        reg13.range(383, 352) = s_result_PE109.read() + 1;
        reg13.range(415, 384) = s_result_PE110.read() + 1;
        reg13.range(447, 416) = s_result_PE110.read() + 1;
        reg13.range(479, 448) = s_result_PE111.read() + 1;
        reg13.range(511, 480) = s_result_PE111.read() + 1;
        s_result_all.write(reg13);

        reg14.range(31, 0) = s_result_PE112.read() + 1;
        reg14.range(63, 32) = s_result_PE112.read() + 1;
        reg14.range(95, 64) = s_result_PE113.read() + 1;
        reg14.range(127, 96) = s_result_PE113.read() + 1;
        reg14.range(159, 128) = s_result_PE114.read() + 1;
        reg14.range(191, 160) = s_result_PE114.read() + 1;
        reg14.range(223, 192) = s_result_PE115.read() + 1;
        reg14.range(255, 224) = s_result_PE115.read() + 1;
        reg14.range(287, 256) = s_result_PE116.read() + 1;
        reg14.range(319, 288) = s_result_PE116.read() + 1;
        reg14.range(351, 320) = s_result_PE117.read() + 1;
        reg14.range(383, 352) = s_result_PE117.read() + 1;
        reg14.range(415, 384) = s_result_PE118.read() + 1;
        reg14.range(447, 416) = s_result_PE118.read() + 1;
        reg14.range(479, 448) = s_result_PE119.read() + 1;
        reg14.range(511, 480) = s_result_PE119.read() + 1;
        s_result_all.write(reg14);

        reg15.range(31, 0) = s_result_PE120.read() + 1;
        reg15.range(63, 32) = s_result_PE120.read() + 1;
        reg15.range(95, 64) = s_result_PE121.read() + 1;
        reg15.range(127, 96) = s_result_PE121.read() + 1;
        reg15.range(159, 128) = s_result_PE122.read() + 1;
        reg15.range(191, 160) = s_result_PE122.read() + 1;
        reg15.range(223, 192) = s_result_PE123.read() + 1;
        reg15.range(255, 224) = s_result_PE123.read() + 1;
        reg15.range(287, 256) = s_result_PE124.read() + 1;
        reg15.range(319, 288) = s_result_PE124.read() + 1;
        reg15.range(351, 320) = s_result_PE125.read() + 1;
        reg15.range(383, 352) = s_result_PE125.read() + 1;
        reg15.range(415, 384) = s_result_PE126.read() + 1;
        reg15.range(447, 416) = s_result_PE126.read() + 1;
        reg15.range(479, 448) = s_result_PE127.read() + 1;
        reg15.range(511, 480) = s_result_PE127.read() + 1;
        s_result_all.write(reg15);

        reg16.range(31, 0) = s_result_PE128.read() + 1;
        reg16.range(63, 32) = s_result_PE128.read() + 1;
        reg16.range(95, 64) = s_result_PE129.read() + 1;
        reg16.range(127, 96) = s_result_PE129.read() + 1;
        reg16.range(159, 128) = s_result_PE130.read() + 1;
        reg16.range(191, 160) = s_result_PE130.read() + 1;
        reg16.range(223, 192) = s_result_PE131.read() + 1;
        reg16.range(255, 224) = s_result_PE131.read() + 1;
        reg16.range(287, 256) = s_result_PE132.read() + 1;
        reg16.range(319, 288) = s_result_PE132.read() + 1;
        reg16.range(351, 320) = s_result_PE133.read() + 1;
        reg16.range(383, 352) = s_result_PE133.read() + 1;
        reg16.range(415, 384) = s_result_PE134.read() + 1;
        reg16.range(447, 416) = s_result_PE134.read() + 1;
        reg16.range(479, 448) = s_result_PE135.read() + 1;
        reg16.range(511, 480) = s_result_PE135.read() + 1;
        s_result_all.write(reg16);

        reg17.range(31, 0) = s_result_PE136.read() + 1;
        reg17.range(63, 32) = s_result_PE136.read() + 1;
        reg17.range(95, 64) = s_result_PE137.read() + 1;
        reg17.range(127, 96) = s_result_PE137.read() + 1;
        reg17.range(159, 128) = s_result_PE138.read() + 1;
        reg17.range(191, 160) = s_result_PE138.read() + 1;
        reg17.range(223, 192) = s_result_PE139.read() + 1;
        reg17.range(255, 224) = s_result_PE139.read() + 1;
        reg17.range(287, 256) = s_result_PE140.read() + 1;
        reg17.range(319, 288) = s_result_PE140.read() + 1;
        reg17.range(351, 320) = s_result_PE141.read() + 1;
        reg17.range(383, 352) = s_result_PE141.read() + 1;
        reg17.range(415, 384) = s_result_PE142.read() + 1;
        reg17.range(447, 416) = s_result_PE142.read() + 1;
        reg17.range(479, 448) = s_result_PE143.read() + 1;
        reg17.range(511, 480) = s_result_PE143.read() + 1;
        s_result_all.write(reg17);

        reg18.range(31, 0) = s_result_PE144.read() + 1;
        reg18.range(63, 32) = s_result_PE144.read() + 1;
        reg18.range(95, 64) = s_result_PE145.read() + 1;
        reg18.range(127, 96) = s_result_PE145.read() + 1;
        reg18.range(159, 128) = s_result_PE146.read() + 1;
        reg18.range(191, 160) = s_result_PE146.read() + 1;
        reg18.range(223, 192) = s_result_PE147.read() + 1;
        reg18.range(255, 224) = s_result_PE147.read() + 1;
        reg18.range(287, 256) = s_result_PE148.read() + 1;
        reg18.range(319, 288) = s_result_PE148.read() + 1;
        reg18.range(351, 320) = s_result_PE149.read() + 1;
        reg18.range(383, 352) = s_result_PE149.read() + 1;
        reg18.range(415, 384) = s_result_PE150.read() + 1;
        reg18.range(447, 416) = s_result_PE150.read() + 1;
        reg18.range(479, 448) = s_result_PE151.read() + 1;
        reg18.range(511, 480) = s_result_PE151.read() + 1;
        s_result_all.write(reg18);

        reg19.range(31, 0) = s_result_PE152.read() + 1;
        reg19.range(63, 32) = s_result_PE152.read() + 1;
        reg19.range(95, 64) = s_result_PE153.read() + 1;
        reg19.range(127, 96) = s_result_PE153.read() + 1;
        reg19.range(159, 128) = s_result_PE154.read() + 1;
        reg19.range(191, 160) = s_result_PE154.read() + 1;
        reg19.range(223, 192) = s_result_PE155.read() + 1;
        reg19.range(255, 224) = s_result_PE155.read() + 1;
        reg19.range(287, 256) = s_result_PE156.read() + 1;
        reg19.range(319, 288) = s_result_PE156.read() + 1;
        reg19.range(351, 320) = s_result_PE157.read() + 1;
        reg19.range(383, 352) = s_result_PE157.read() + 1;
        reg19.range(415, 384) = s_result_PE158.read() + 1;
        reg19.range(447, 416) = s_result_PE158.read() + 1;
        reg19.range(479, 448) = s_result_PE159.read() + 1;
        reg19.range(511, 480) = s_result_PE159.read() + 1;
        s_result_all.write(reg19);

        reg20.range(31, 0) = s_result_PE160.read() + 1;
        reg20.range(63, 32) = s_result_PE160.read() + 1;
        reg20.range(95, 64) = s_result_PE161.read() + 1;
        reg20.range(127, 96) = s_result_PE161.read() + 1;
        reg20.range(159, 128) = s_result_PE162.read() + 1;
        reg20.range(191, 160) = s_result_PE162.read() + 1;
        reg20.range(223, 192) = s_result_PE163.read() + 1;
        reg20.range(255, 224) = s_result_PE163.read() + 1;
        reg20.range(287, 256) = s_result_PE164.read() + 1;
        reg20.range(319, 288) = s_result_PE164.read() + 1;
        reg20.range(351, 320) = s_result_PE165.read() + 1;
        reg20.range(383, 352) = s_result_PE165.read() + 1;
        reg20.range(415, 384) = s_result_PE166.read() + 1;
        reg20.range(447, 416) = s_result_PE166.read() + 1;
        reg20.range(479, 448) = s_result_PE167.read() + 1;
        reg20.range(511, 480) = s_result_PE167.read() + 1;
        s_result_all.write(reg20);

        reg21.range(31, 0) = s_result_PE168.read() + 1;
        reg21.range(63, 32) = s_result_PE168.read() + 1;
        reg21.range(95, 64) = s_result_PE169.read() + 1;
        reg21.range(127, 96) = s_result_PE169.read() + 1;
        reg21.range(159, 128) = s_result_PE170.read() + 1;
        reg21.range(191, 160) = s_result_PE170.read() + 1;
        reg21.range(223, 192) = s_result_PE171.read() + 1;
        reg21.range(255, 224) = s_result_PE171.read() + 1;
        reg21.range(287, 256) = s_result_PE172.read() + 1;
        reg21.range(319, 288) = s_result_PE172.read() + 1;
        reg21.range(351, 320) = s_result_PE173.read() + 1;
        reg21.range(383, 352) = s_result_PE173.read() + 1;
        reg21.range(415, 384) = s_result_PE174.read() + 1;
        reg21.range(447, 416) = s_result_PE174.read() + 1;
        reg21.range(479, 448) = s_result_PE175.read() + 1;
        reg21.range(511, 480) = s_result_PE175.read() + 1;
        s_result_all.write(reg21);

        reg22.range(31, 0) = s_result_PE176.read() + 1;
        reg22.range(63, 32) = s_result_PE176.read() + 1;
        reg22.range(95, 64) = s_result_PE177.read() + 1;
        reg22.range(127, 96) = s_result_PE177.read() + 1;
        reg22.range(159, 128) = s_result_PE178.read() + 1;
        reg22.range(191, 160) = s_result_PE178.read() + 1;
        reg22.range(223, 192) = s_result_PE179.read() + 1;
        reg22.range(255, 224) = s_result_PE179.read() + 1;
        reg22.range(287, 256) = s_result_PE180.read() + 1;
        reg22.range(319, 288) = s_result_PE180.read() + 1;
        reg22.range(351, 320) = s_result_PE181.read() + 1;
        reg22.range(383, 352) = s_result_PE181.read() + 1;
        reg22.range(415, 384) = s_result_PE182.read() + 1;
        reg22.range(447, 416) = s_result_PE182.read() + 1;
        reg22.range(479, 448) = s_result_PE183.read() + 1;
        reg22.range(511, 480) = s_result_PE183.read() + 1;
        s_result_all.write(reg22);

        reg23.range(31, 0) = s_result_PE184.read() + 1;
        reg23.range(63, 32) = s_result_PE184.read() + 1;
        reg23.range(95, 64) = s_result_PE185.read() + 1;
        reg23.range(127, 96) = s_result_PE185.read() + 1;
        reg23.range(159, 128) = s_result_PE186.read() + 1;
        reg23.range(191, 160) = s_result_PE186.read() + 1;
        reg23.range(223, 192) = s_result_PE187.read() + 1;
        reg23.range(255, 224) = s_result_PE187.read() + 1;
        reg23.range(287, 256) = s_result_PE188.read() + 1;
        reg23.range(319, 288) = s_result_PE188.read() + 1;
        reg23.range(351, 320) = s_result_PE189.read() + 1;
        reg23.range(383, 352) = s_result_PE189.read() + 1;
        reg23.range(415, 384) = s_result_PE190.read() + 1;
        reg23.range(447, 416) = s_result_PE190.read() + 1;
        reg23.range(479, 448) = s_result_PE191.read() + 1;
        reg23.range(511, 480) = s_result_PE191.read() + 1;
        s_result_all.write(reg23);

        reg24.range(31, 0) = s_result_PE192.read() + 1;
        reg24.range(63, 32) = s_result_PE192.read() + 1;
        reg24.range(95, 64) = s_result_PE193.read() + 1;
        reg24.range(127, 96) = s_result_PE193.read() + 1;
        reg24.range(159, 128) = s_result_PE194.read() + 1;
        reg24.range(191, 160) = s_result_PE194.read() + 1;
        reg24.range(223, 192) = s_result_PE195.read() + 1;
        reg24.range(255, 224) = s_result_PE195.read() + 1;
        reg24.range(287, 256) = s_result_PE196.read() + 1;
        reg24.range(319, 288) = s_result_PE196.read() + 1;
        reg24.range(351, 320) = s_result_PE197.read() + 1;
        reg24.range(383, 352) = s_result_PE197.read() + 1;
        reg24.range(415, 384) = s_result_PE198.read() + 1;
        reg24.range(447, 416) = s_result_PE198.read() + 1;
        reg24.range(479, 448) = s_result_PE199.read() + 1;
        reg24.range(511, 480) = s_result_PE199.read() + 1;
        s_result_all.write(reg24);

        reg25.range(31, 0)    = s_result_PE200.read() + 1;
        reg25.range(63, 32)   = s_result_PE200.read() + 1;
        reg25.range(95, 64)   = s_result_PE201.read() + 1;
        reg25.range(127, 96)  = s_result_PE201.read() + 1;
        reg25.range(159, 128) = s_result_PE202.read() + 1;
        reg25.range(191, 160) = s_result_PE202.read() + 1;
        reg25.range(223, 192) = s_result_PE203.read() + 1;
        reg25.range(255, 224) = s_result_PE203.read() + 1;
        reg25.range(287, 256) = s_result_PE204.read() + 1;
        reg25.range(319, 288) = s_result_PE204.read() + 1;
        reg25.range(351, 320) = s_result_PE205.read() + 1;
        reg25.range(383, 352) = s_result_PE205.read() + 1;
        reg25.range(415, 384) = s_result_PE206.read() + 1;
        reg25.range(447, 416) = s_result_PE206.read() + 1;
        reg25.range(479, 448) = s_result_PE207.read() + 1;
        reg25.range(511, 480) = s_result_PE207.read() + 1;
        s_result_all.write(reg25);

        reg26.range(31, 0)    = s_result_PE208.read() + 1;
        reg26.range(63, 32)   = s_result_PE208.read() + 1;
        reg26.range(95, 64)   = s_result_PE209.read() + 1;
        reg26.range(127, 96)  = s_result_PE209.read() + 1;
        reg26.range(159, 128) = s_result_PE210.read() + 1;
        reg26.range(191, 160) = s_result_PE210.read() + 1;
        reg26.range(223, 192) = s_result_PE211.read() + 1;
        reg26.range(255, 224) = s_result_PE211.read() + 1;
        reg26.range(287, 256) = s_result_PE212.read() + 1;
        reg26.range(319, 288) = s_result_PE212.read() + 1;
        reg26.range(351, 320) = s_result_PE213.read() + 1;
        reg26.range(383, 352) = s_result_PE213.read() + 1;
        reg26.range(415, 384) = s_result_PE214.read() + 1;
        reg26.range(447, 416) = s_result_PE214.read() + 1;
        reg26.range(479, 448) = s_result_PE215.read() + 1;
        reg26.range(511, 480) = s_result_PE215.read() + 1;
        s_result_all.write(reg26);
    }
}

template<const int ROW_PER_PE>
void gather_results_512PEs_224PE(
    STREAM<D_TYPE>& s_result_PE0, STREAM<D_TYPE>& s_result_PE1, 
    STREAM<D_TYPE>& s_result_PE2, STREAM<D_TYPE>& s_result_PE3, 
    STREAM<D_TYPE>& s_result_PE4, STREAM<D_TYPE>& s_result_PE5, 
    STREAM<D_TYPE>& s_result_PE6, STREAM<D_TYPE>& s_result_PE7, 
    STREAM<D_TYPE>& s_result_PE8, STREAM<D_TYPE>& s_result_PE9, 
    STREAM<D_TYPE>& s_result_PE10, STREAM<D_TYPE>& s_result_PE11, 
    STREAM<D_TYPE>& s_result_PE12, STREAM<D_TYPE>& s_result_PE13, 
    STREAM<D_TYPE>& s_result_PE14, STREAM<D_TYPE>& s_result_PE15, 
    STREAM<D_TYPE>& s_result_PE16, STREAM<D_TYPE>& s_result_PE17, 
    STREAM<D_TYPE>& s_result_PE18, STREAM<D_TYPE>& s_result_PE19, 
    STREAM<D_TYPE>& s_result_PE20, STREAM<D_TYPE>& s_result_PE21, 
    STREAM<D_TYPE>& s_result_PE22, STREAM<D_TYPE>& s_result_PE23, 
    STREAM<D_TYPE>& s_result_PE24, STREAM<D_TYPE>& s_result_PE25, 
    STREAM<D_TYPE>& s_result_PE26, STREAM<D_TYPE>& s_result_PE27, 
    STREAM<D_TYPE>& s_result_PE28, STREAM<D_TYPE>& s_result_PE29, 
    STREAM<D_TYPE>& s_result_PE30, STREAM<D_TYPE>& s_result_PE31, 
    STREAM<D_TYPE>& s_result_PE32, STREAM<D_TYPE>& s_result_PE33, 
    STREAM<D_TYPE>& s_result_PE34, STREAM<D_TYPE>& s_result_PE35, 
    STREAM<D_TYPE>& s_result_PE36, STREAM<D_TYPE>& s_result_PE37, 
    STREAM<D_TYPE>& s_result_PE38, STREAM<D_TYPE>& s_result_PE39, 
    STREAM<D_TYPE>& s_result_PE40, STREAM<D_TYPE>& s_result_PE41, 
    STREAM<D_TYPE>& s_result_PE42, STREAM<D_TYPE>& s_result_PE43, 
    STREAM<D_TYPE>& s_result_PE44, STREAM<D_TYPE>& s_result_PE45, 
    STREAM<D_TYPE>& s_result_PE46, STREAM<D_TYPE>& s_result_PE47, 
    STREAM<D_TYPE>& s_result_PE48, STREAM<D_TYPE>& s_result_PE49, 
    STREAM<D_TYPE>& s_result_PE50, STREAM<D_TYPE>& s_result_PE51, 
    STREAM<D_TYPE>& s_result_PE52, STREAM<D_TYPE>& s_result_PE53, 
    STREAM<D_TYPE>& s_result_PE54, STREAM<D_TYPE>& s_result_PE55, 
    STREAM<D_TYPE>& s_result_PE56, STREAM<D_TYPE>& s_result_PE57, 
    STREAM<D_TYPE>& s_result_PE58, STREAM<D_TYPE>& s_result_PE59, 
    STREAM<D_TYPE>& s_result_PE60, STREAM<D_TYPE>& s_result_PE61, 
    STREAM<D_TYPE>& s_result_PE62, STREAM<D_TYPE>& s_result_PE63, 
    STREAM<D_TYPE>& s_result_PE64, STREAM<D_TYPE>& s_result_PE65, 
    STREAM<D_TYPE>& s_result_PE66, STREAM<D_TYPE>& s_result_PE67, 
    STREAM<D_TYPE>& s_result_PE68, STREAM<D_TYPE>& s_result_PE69, 
    STREAM<D_TYPE>& s_result_PE70, STREAM<D_TYPE>& s_result_PE71, 
    STREAM<D_TYPE>& s_result_PE72, STREAM<D_TYPE>& s_result_PE73, 
    STREAM<D_TYPE>& s_result_PE74, STREAM<D_TYPE>& s_result_PE75, 
    STREAM<D_TYPE>& s_result_PE76, STREAM<D_TYPE>& s_result_PE77, 
    STREAM<D_TYPE>& s_result_PE78, STREAM<D_TYPE>& s_result_PE79, 
    STREAM<D_TYPE>& s_result_PE80, STREAM<D_TYPE>& s_result_PE81, 
    STREAM<D_TYPE>& s_result_PE82, STREAM<D_TYPE>& s_result_PE83, 
    STREAM<D_TYPE>& s_result_PE84, STREAM<D_TYPE>& s_result_PE85, 
    STREAM<D_TYPE>& s_result_PE86, STREAM<D_TYPE>& s_result_PE87, 
    STREAM<D_TYPE>& s_result_PE88, STREAM<D_TYPE>& s_result_PE89, 
    STREAM<D_TYPE>& s_result_PE90, STREAM<D_TYPE>& s_result_PE91, 
    STREAM<D_TYPE>& s_result_PE92, STREAM<D_TYPE>& s_result_PE93, 
    STREAM<D_TYPE>& s_result_PE94, STREAM<D_TYPE>& s_result_PE95, 
    STREAM<D_TYPE>& s_result_PE96, STREAM<D_TYPE>& s_result_PE97, 
    STREAM<D_TYPE>& s_result_PE98, STREAM<D_TYPE>& s_result_PE99, 
    STREAM<D_TYPE>& s_result_PE100, STREAM<D_TYPE>& s_result_PE101, 
    STREAM<D_TYPE>& s_result_PE102, STREAM<D_TYPE>& s_result_PE103, 
    STREAM<D_TYPE>& s_result_PE104, STREAM<D_TYPE>& s_result_PE105, 
    STREAM<D_TYPE>& s_result_PE106, STREAM<D_TYPE>& s_result_PE107, 
    STREAM<D_TYPE>& s_result_PE108, STREAM<D_TYPE>& s_result_PE109, 
    STREAM<D_TYPE>& s_result_PE110, STREAM<D_TYPE>& s_result_PE111, 
    STREAM<D_TYPE>& s_result_PE112, STREAM<D_TYPE>& s_result_PE113, 
    STREAM<D_TYPE>& s_result_PE114, STREAM<D_TYPE>& s_result_PE115, 
    STREAM<D_TYPE>& s_result_PE116, STREAM<D_TYPE>& s_result_PE117, 
    STREAM<D_TYPE>& s_result_PE118, STREAM<D_TYPE>& s_result_PE119, 
    STREAM<D_TYPE>& s_result_PE120, STREAM<D_TYPE>& s_result_PE121, 
    STREAM<D_TYPE>& s_result_PE122, STREAM<D_TYPE>& s_result_PE123, 
    STREAM<D_TYPE>& s_result_PE124, STREAM<D_TYPE>& s_result_PE125, 
    STREAM<D_TYPE>& s_result_PE126, STREAM<D_TYPE>& s_result_PE127, 
    STREAM<D_TYPE>& s_result_PE128, STREAM<D_TYPE>& s_result_PE129,
    STREAM<D_TYPE>& s_result_PE130, STREAM<D_TYPE>& s_result_PE131,
    STREAM<D_TYPE>& s_result_PE132, STREAM<D_TYPE>& s_result_PE133,
    STREAM<D_TYPE>& s_result_PE134, STREAM<D_TYPE>& s_result_PE135,
    STREAM<D_TYPE>& s_result_PE136, STREAM<D_TYPE>& s_result_PE137,
    STREAM<D_TYPE>& s_result_PE138, STREAM<D_TYPE>& s_result_PE139,
    STREAM<D_TYPE>& s_result_PE140, STREAM<D_TYPE>& s_result_PE141,
    STREAM<D_TYPE>& s_result_PE142, STREAM<D_TYPE>& s_result_PE143,
    STREAM<D_TYPE>& s_result_PE144, STREAM<D_TYPE>& s_result_PE145,
    STREAM<D_TYPE>& s_result_PE146, STREAM<D_TYPE>& s_result_PE147,
    STREAM<D_TYPE>& s_result_PE148, STREAM<D_TYPE>& s_result_PE149,
    STREAM<D_TYPE>& s_result_PE150, STREAM<D_TYPE>& s_result_PE151,
    STREAM<D_TYPE>& s_result_PE152, STREAM<D_TYPE>& s_result_PE153,
    STREAM<D_TYPE>& s_result_PE154, STREAM<D_TYPE>& s_result_PE155,
    STREAM<D_TYPE>& s_result_PE156, STREAM<D_TYPE>& s_result_PE157,
    STREAM<D_TYPE>& s_result_PE158, STREAM<D_TYPE>& s_result_PE159,
    STREAM<D_TYPE>& s_result_PE160, STREAM<D_TYPE>& s_result_PE161,
    STREAM<D_TYPE>& s_result_PE162, STREAM<D_TYPE>& s_result_PE163,
    STREAM<D_TYPE>& s_result_PE164, STREAM<D_TYPE>& s_result_PE165,
    STREAM<D_TYPE>& s_result_PE166, STREAM<D_TYPE>& s_result_PE167,
    STREAM<D_TYPE>& s_result_PE168, STREAM<D_TYPE>& s_result_PE169,
    STREAM<D_TYPE>& s_result_PE170, STREAM<D_TYPE>& s_result_PE171,
    STREAM<D_TYPE>& s_result_PE172, STREAM<D_TYPE>& s_result_PE173,
    STREAM<D_TYPE>& s_result_PE174, STREAM<D_TYPE>& s_result_PE175,
    STREAM<D_TYPE>& s_result_PE176, STREAM<D_TYPE>& s_result_PE177,
    STREAM<D_TYPE>& s_result_PE178, STREAM<D_TYPE>& s_result_PE179,
    STREAM<D_TYPE>& s_result_PE180, STREAM<D_TYPE>& s_result_PE181,
    STREAM<D_TYPE>& s_result_PE182, STREAM<D_TYPE>& s_result_PE183,
    STREAM<D_TYPE>& s_result_PE184, STREAM<D_TYPE>& s_result_PE185,
    STREAM<D_TYPE>& s_result_PE186, STREAM<D_TYPE>& s_result_PE187,
    STREAM<D_TYPE>& s_result_PE188, STREAM<D_TYPE>& s_result_PE189,
    STREAM<D_TYPE>& s_result_PE190, STREAM<D_TYPE>& s_result_PE191,
    STREAM<D_TYPE>& s_result_PE192, STREAM<D_TYPE>& s_result_PE193,
    STREAM<D_TYPE>& s_result_PE194, STREAM<D_TYPE>& s_result_PE195,
    STREAM<D_TYPE>& s_result_PE196, STREAM<D_TYPE>& s_result_PE197,
    STREAM<D_TYPE>& s_result_PE198, STREAM<D_TYPE>& s_result_PE199,
    STREAM<D_TYPE>& s_result_PE200, STREAM<D_TYPE>& s_result_PE201, 
    STREAM<D_TYPE>& s_result_PE202, STREAM<D_TYPE>& s_result_PE203, 
    STREAM<D_TYPE>& s_result_PE204, STREAM<D_TYPE>& s_result_PE205, 
    STREAM<D_TYPE>& s_result_PE206, STREAM<D_TYPE>& s_result_PE207, 
    STREAM<D_TYPE>& s_result_PE208, STREAM<D_TYPE>& s_result_PE209, 
    STREAM<D_TYPE>& s_result_PE210, STREAM<D_TYPE>& s_result_PE211, 
    STREAM<D_TYPE>& s_result_PE212, STREAM<D_TYPE>& s_result_PE213, 
    STREAM<D_TYPE>& s_result_PE214, STREAM<D_TYPE>& s_result_PE215,
    STREAM<D_TYPE>& s_result_PE216, STREAM<D_TYPE>& s_result_PE217, 
    STREAM<D_TYPE>& s_result_PE218, STREAM<D_TYPE>& s_result_PE219, 
    STREAM<D_TYPE>& s_result_PE220, STREAM<D_TYPE>& s_result_PE221, 
    STREAM<D_TYPE>& s_result_PE222, STREAM<D_TYPE>& s_result_PE223, 
    STREAM<ap_uint<512> >& s_result_all) {
     
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        #pragma HLS pipeline II=28  // write 1 result_all per CC

        ap_uint<512> reg0, reg1, reg2, reg3, reg4, reg5, reg6, reg7, 
            reg8, reg9, reg10, reg11, reg12, reg13, reg14, reg15, 
            reg16, reg17, reg18, reg19, reg20, reg21, reg22, reg23, 
            reg24, reg25, reg26, reg27;

        reg0.range(31, 0) = s_result_PE0.read() + 1;
        reg0.range(63, 32) = s_result_PE0.read() + 1;
        reg0.range(95, 64) = s_result_PE1.read() + 1;
        reg0.range(127, 96) = s_result_PE1.read() + 1;
        reg0.range(159, 128) = s_result_PE2.read() + 1;
        reg0.range(191, 160) = s_result_PE2.read() + 1;
        reg0.range(223, 192) = s_result_PE3.read() + 1;
        reg0.range(255, 224) = s_result_PE3.read() + 1;
        reg0.range(287, 256) = s_result_PE4.read() + 1;
        reg0.range(319, 288) = s_result_PE4.read() + 1;
        reg0.range(351, 320) = s_result_PE5.read() + 1;
        reg0.range(383, 352) = s_result_PE5.read() + 1;
        reg0.range(415, 384) = s_result_PE6.read() + 1;
        reg0.range(447, 416) = s_result_PE6.read() + 1;
        reg0.range(479, 448) = s_result_PE7.read() + 1;
        reg0.range(511, 480) = s_result_PE7.read() + 1;
        s_result_all.write(reg0);

        reg1.range(31, 0) = s_result_PE8.read() + 1;
        reg1.range(63, 32) = s_result_PE8.read() + 1;
        reg1.range(95, 64) = s_result_PE9.read() + 1;
        reg1.range(127, 96) = s_result_PE9.read() + 1;
        reg1.range(159, 128) = s_result_PE10.read() + 1;
        reg1.range(191, 160) = s_result_PE10.read() + 1;
        reg1.range(223, 192) = s_result_PE11.read() + 1;
        reg1.range(255, 224) = s_result_PE11.read() + 1;
        reg1.range(287, 256) = s_result_PE12.read() + 1;
        reg1.range(319, 288) = s_result_PE12.read() + 1;
        reg1.range(351, 320) = s_result_PE13.read() + 1;
        reg1.range(383, 352) = s_result_PE13.read() + 1;
        reg1.range(415, 384) = s_result_PE14.read() + 1;
        reg1.range(447, 416) = s_result_PE14.read() + 1;
        reg1.range(479, 448) = s_result_PE15.read() + 1;
        reg1.range(511, 480) = s_result_PE15.read() + 1;
        s_result_all.write(reg1);

        reg2.range(31, 0) = s_result_PE16.read() + 1;
        reg2.range(63, 32) = s_result_PE16.read() + 1;
        reg2.range(95, 64) = s_result_PE17.read() + 1;
        reg2.range(127, 96) = s_result_PE17.read() + 1;
        reg2.range(159, 128) = s_result_PE18.read() + 1;
        reg2.range(191, 160) = s_result_PE18.read() + 1;
        reg2.range(223, 192) = s_result_PE19.read() + 1;
        reg2.range(255, 224) = s_result_PE19.read() + 1;
        reg2.range(287, 256) = s_result_PE20.read() + 1;
        reg2.range(319, 288) = s_result_PE20.read() + 1;
        reg2.range(351, 320) = s_result_PE21.read() + 1;
        reg2.range(383, 352) = s_result_PE21.read() + 1;
        reg2.range(415, 384) = s_result_PE22.read() + 1;
        reg2.range(447, 416) = s_result_PE22.read() + 1;
        reg2.range(479, 448) = s_result_PE23.read() + 1;
        reg2.range(511, 480) = s_result_PE23.read() + 1;
        s_result_all.write(reg2);

        reg3.range(31, 0) = s_result_PE24.read() + 1;
        reg3.range(63, 32) = s_result_PE24.read() + 1;
        reg3.range(95, 64) = s_result_PE25.read() + 1;
        reg3.range(127, 96) = s_result_PE25.read() + 1;
        reg3.range(159, 128) = s_result_PE26.read() + 1;
        reg3.range(191, 160) = s_result_PE26.read() + 1;
        reg3.range(223, 192) = s_result_PE27.read() + 1;
        reg3.range(255, 224) = s_result_PE27.read() + 1;
        reg3.range(287, 256) = s_result_PE28.read() + 1;
        reg3.range(319, 288) = s_result_PE28.read() + 1;
        reg3.range(351, 320) = s_result_PE29.read() + 1;
        reg3.range(383, 352) = s_result_PE29.read() + 1;
        reg3.range(415, 384) = s_result_PE30.read() + 1;
        reg3.range(447, 416) = s_result_PE30.read() + 1;
        reg3.range(479, 448) = s_result_PE31.read() + 1;
        reg3.range(511, 480) = s_result_PE31.read() + 1;
        s_result_all.write(reg3);

        reg4.range(31, 0) = s_result_PE32.read() + 1;
        reg4.range(63, 32) = s_result_PE32.read() + 1;
        reg4.range(95, 64) = s_result_PE33.read() + 1;
        reg4.range(127, 96) = s_result_PE33.read() + 1;
        reg4.range(159, 128) = s_result_PE34.read() + 1;
        reg4.range(191, 160) = s_result_PE34.read() + 1;
        reg4.range(223, 192) = s_result_PE35.read() + 1;
        reg4.range(255, 224) = s_result_PE35.read() + 1;
        reg4.range(287, 256) = s_result_PE36.read() + 1;
        reg4.range(319, 288) = s_result_PE36.read() + 1;
        reg4.range(351, 320) = s_result_PE37.read() + 1;
        reg4.range(383, 352) = s_result_PE37.read() + 1;
        reg4.range(415, 384) = s_result_PE38.read() + 1;
        reg4.range(447, 416) = s_result_PE38.read() + 1;
        reg4.range(479, 448) = s_result_PE39.read() + 1;
        reg4.range(511, 480) = s_result_PE39.read() + 1;
        s_result_all.write(reg4);

        reg5.range(31, 0) = s_result_PE40.read() + 1;
        reg5.range(63, 32) = s_result_PE40.read() + 1;
        reg5.range(95, 64) = s_result_PE41.read() + 1;
        reg5.range(127, 96) = s_result_PE41.read() + 1;
        reg5.range(159, 128) = s_result_PE42.read() + 1;
        reg5.range(191, 160) = s_result_PE42.read() + 1;
        reg5.range(223, 192) = s_result_PE43.read() + 1;
        reg5.range(255, 224) = s_result_PE43.read() + 1;
        reg5.range(287, 256) = s_result_PE44.read() + 1;
        reg5.range(319, 288) = s_result_PE44.read() + 1;
        reg5.range(351, 320) = s_result_PE45.read() + 1;
        reg5.range(383, 352) = s_result_PE45.read() + 1;
        reg5.range(415, 384) = s_result_PE46.read() + 1;
        reg5.range(447, 416) = s_result_PE46.read() + 1;
        reg5.range(479, 448) = s_result_PE47.read() + 1;
        reg5.range(511, 480) = s_result_PE47.read() + 1;
        s_result_all.write(reg5);

        reg6.range(31, 0) = s_result_PE48.read() + 1;
        reg6.range(63, 32) = s_result_PE48.read() + 1;
        reg6.range(95, 64) = s_result_PE49.read() + 1;
        reg6.range(127, 96) = s_result_PE49.read() + 1;
        reg6.range(159, 128) = s_result_PE50.read() + 1;
        reg6.range(191, 160) = s_result_PE50.read() + 1;
        reg6.range(223, 192) = s_result_PE51.read() + 1;
        reg6.range(255, 224) = s_result_PE51.read() + 1;
        reg6.range(287, 256) = s_result_PE52.read() + 1;
        reg6.range(319, 288) = s_result_PE52.read() + 1;
        reg6.range(351, 320) = s_result_PE53.read() + 1;
        reg6.range(383, 352) = s_result_PE53.read() + 1;
        reg6.range(415, 384) = s_result_PE54.read() + 1;
        reg6.range(447, 416) = s_result_PE54.read() + 1;
        reg6.range(479, 448) = s_result_PE55.read() + 1;
        reg6.range(511, 480) = s_result_PE55.read() + 1;
        s_result_all.write(reg6);

        reg7.range(31, 0) = s_result_PE56.read() + 1;
        reg7.range(63, 32) = s_result_PE56.read() + 1;
        reg7.range(95, 64) = s_result_PE57.read() + 1;
        reg7.range(127, 96) = s_result_PE57.read() + 1;
        reg7.range(159, 128) = s_result_PE58.read() + 1;
        reg7.range(191, 160) = s_result_PE58.read() + 1;
        reg7.range(223, 192) = s_result_PE59.read() + 1;
        reg7.range(255, 224) = s_result_PE59.read() + 1;
        reg7.range(287, 256) = s_result_PE60.read() + 1;
        reg7.range(319, 288) = s_result_PE60.read() + 1;
        reg7.range(351, 320) = s_result_PE61.read() + 1;
        reg7.range(383, 352) = s_result_PE61.read() + 1;
        reg7.range(415, 384) = s_result_PE62.read() + 1;
        reg7.range(447, 416) = s_result_PE62.read() + 1;
        reg7.range(479, 448) = s_result_PE63.read() + 1;
        reg7.range(511, 480) = s_result_PE63.read() + 1;
        s_result_all.write(reg7);

        reg8.range(31, 0) = s_result_PE64.read() + 1;
        reg8.range(63, 32) = s_result_PE64.read() + 1;
        reg8.range(95, 64) = s_result_PE65.read() + 1;
        reg8.range(127, 96) = s_result_PE65.read() + 1;
        reg8.range(159, 128) = s_result_PE66.read() + 1;
        reg8.range(191, 160) = s_result_PE66.read() + 1;
        reg8.range(223, 192) = s_result_PE67.read() + 1;
        reg8.range(255, 224) = s_result_PE67.read() + 1;
        reg8.range(287, 256) = s_result_PE68.read() + 1;
        reg8.range(319, 288) = s_result_PE68.read() + 1;
        reg8.range(351, 320) = s_result_PE69.read() + 1;
        reg8.range(383, 352) = s_result_PE69.read() + 1;
        reg8.range(415, 384) = s_result_PE70.read() + 1;
        reg8.range(447, 416) = s_result_PE70.read() + 1;
        reg8.range(479, 448) = s_result_PE71.read() + 1;
        reg8.range(511, 480) = s_result_PE71.read() + 1;
        s_result_all.write(reg8);

        reg9.range(31, 0) = s_result_PE72.read() + 1;
        reg9.range(63, 32) = s_result_PE72.read() + 1;
        reg9.range(95, 64) = s_result_PE73.read() + 1;
        reg9.range(127, 96) = s_result_PE73.read() + 1;
        reg9.range(159, 128) = s_result_PE74.read() + 1;
        reg9.range(191, 160) = s_result_PE74.read() + 1;
        reg9.range(223, 192) = s_result_PE75.read() + 1;
        reg9.range(255, 224) = s_result_PE75.read() + 1;
        reg9.range(287, 256) = s_result_PE76.read() + 1;
        reg9.range(319, 288) = s_result_PE76.read() + 1;
        reg9.range(351, 320) = s_result_PE77.read() + 1;
        reg9.range(383, 352) = s_result_PE77.read() + 1;
        reg9.range(415, 384) = s_result_PE78.read() + 1;
        reg9.range(447, 416) = s_result_PE78.read() + 1;
        reg9.range(479, 448) = s_result_PE79.read() + 1;
        reg9.range(511, 480) = s_result_PE79.read() + 1;
        s_result_all.write(reg9);

        reg10.range(31, 0) = s_result_PE80.read() + 1;
        reg10.range(63, 32) = s_result_PE80.read() + 1;
        reg10.range(95, 64) = s_result_PE81.read() + 1;
        reg10.range(127, 96) = s_result_PE81.read() + 1;
        reg10.range(159, 128) = s_result_PE82.read() + 1;
        reg10.range(191, 160) = s_result_PE82.read() + 1;
        reg10.range(223, 192) = s_result_PE83.read() + 1;
        reg10.range(255, 224) = s_result_PE83.read() + 1;
        reg10.range(287, 256) = s_result_PE84.read() + 1;
        reg10.range(319, 288) = s_result_PE84.read() + 1;
        reg10.range(351, 320) = s_result_PE85.read() + 1;
        reg10.range(383, 352) = s_result_PE85.read() + 1;
        reg10.range(415, 384) = s_result_PE86.read() + 1;
        reg10.range(447, 416) = s_result_PE86.read() + 1;
        reg10.range(479, 448) = s_result_PE87.read() + 1;
        reg10.range(511, 480) = s_result_PE87.read() + 1;
        s_result_all.write(reg10);

        reg11.range(31, 0) = s_result_PE88.read() + 1;
        reg11.range(63, 32) = s_result_PE88.read() + 1;
        reg11.range(95, 64) = s_result_PE89.read() + 1;
        reg11.range(127, 96) = s_result_PE89.read() + 1;
        reg11.range(159, 128) = s_result_PE90.read() + 1;
        reg11.range(191, 160) = s_result_PE90.read() + 1;
        reg11.range(223, 192) = s_result_PE91.read() + 1;
        reg11.range(255, 224) = s_result_PE91.read() + 1;
        reg11.range(287, 256) = s_result_PE92.read() + 1;
        reg11.range(319, 288) = s_result_PE92.read() + 1;
        reg11.range(351, 320) = s_result_PE93.read() + 1;
        reg11.range(383, 352) = s_result_PE93.read() + 1;
        reg11.range(415, 384) = s_result_PE94.read() + 1;
        reg11.range(447, 416) = s_result_PE94.read() + 1;
        reg11.range(479, 448) = s_result_PE95.read() + 1;
        reg11.range(511, 480) = s_result_PE95.read() + 1;
        s_result_all.write(reg11);

        reg12.range(31, 0) = s_result_PE96.read() + 1;
        reg12.range(63, 32) = s_result_PE96.read() + 1;
        reg12.range(95, 64) = s_result_PE97.read() + 1;
        reg12.range(127, 96) = s_result_PE97.read() + 1;
        reg12.range(159, 128) = s_result_PE98.read() + 1;
        reg12.range(191, 160) = s_result_PE98.read() + 1;
        reg12.range(223, 192) = s_result_PE99.read() + 1;
        reg12.range(255, 224) = s_result_PE99.read() + 1;
        reg12.range(287, 256) = s_result_PE100.read() + 1;
        reg12.range(319, 288) = s_result_PE100.read() + 1;
        reg12.range(351, 320) = s_result_PE101.read() + 1;
        reg12.range(383, 352) = s_result_PE101.read() + 1;
        reg12.range(415, 384) = s_result_PE102.read() + 1;
        reg12.range(447, 416) = s_result_PE102.read() + 1;
        reg12.range(479, 448) = s_result_PE103.read() + 1;
        reg12.range(511, 480) = s_result_PE103.read() + 1;
        s_result_all.write(reg12);

        reg13.range(31, 0) = s_result_PE104.read() + 1;
        reg13.range(63, 32) = s_result_PE104.read() + 1;
        reg13.range(95, 64) = s_result_PE105.read() + 1;
        reg13.range(127, 96) = s_result_PE105.read() + 1;
        reg13.range(159, 128) = s_result_PE106.read() + 1;
        reg13.range(191, 160) = s_result_PE106.read() + 1;
        reg13.range(223, 192) = s_result_PE107.read() + 1;
        reg13.range(255, 224) = s_result_PE107.read() + 1;
        reg13.range(287, 256) = s_result_PE108.read() + 1;
        reg13.range(319, 288) = s_result_PE108.read() + 1;
        reg13.range(351, 320) = s_result_PE109.read() + 1;
        reg13.range(383, 352) = s_result_PE109.read() + 1;
        reg13.range(415, 384) = s_result_PE110.read() + 1;
        reg13.range(447, 416) = s_result_PE110.read() + 1;
        reg13.range(479, 448) = s_result_PE111.read() + 1;
        reg13.range(511, 480) = s_result_PE111.read() + 1;
        s_result_all.write(reg13);

        reg14.range(31, 0) = s_result_PE112.read() + 1;
        reg14.range(63, 32) = s_result_PE112.read() + 1;
        reg14.range(95, 64) = s_result_PE113.read() + 1;
        reg14.range(127, 96) = s_result_PE113.read() + 1;
        reg14.range(159, 128) = s_result_PE114.read() + 1;
        reg14.range(191, 160) = s_result_PE114.read() + 1;
        reg14.range(223, 192) = s_result_PE115.read() + 1;
        reg14.range(255, 224) = s_result_PE115.read() + 1;
        reg14.range(287, 256) = s_result_PE116.read() + 1;
        reg14.range(319, 288) = s_result_PE116.read() + 1;
        reg14.range(351, 320) = s_result_PE117.read() + 1;
        reg14.range(383, 352) = s_result_PE117.read() + 1;
        reg14.range(415, 384) = s_result_PE118.read() + 1;
        reg14.range(447, 416) = s_result_PE118.read() + 1;
        reg14.range(479, 448) = s_result_PE119.read() + 1;
        reg14.range(511, 480) = s_result_PE119.read() + 1;
        s_result_all.write(reg14);

        reg15.range(31, 0) = s_result_PE120.read() + 1;
        reg15.range(63, 32) = s_result_PE120.read() + 1;
        reg15.range(95, 64) = s_result_PE121.read() + 1;
        reg15.range(127, 96) = s_result_PE121.read() + 1;
        reg15.range(159, 128) = s_result_PE122.read() + 1;
        reg15.range(191, 160) = s_result_PE122.read() + 1;
        reg15.range(223, 192) = s_result_PE123.read() + 1;
        reg15.range(255, 224) = s_result_PE123.read() + 1;
        reg15.range(287, 256) = s_result_PE124.read() + 1;
        reg15.range(319, 288) = s_result_PE124.read() + 1;
        reg15.range(351, 320) = s_result_PE125.read() + 1;
        reg15.range(383, 352) = s_result_PE125.read() + 1;
        reg15.range(415, 384) = s_result_PE126.read() + 1;
        reg15.range(447, 416) = s_result_PE126.read() + 1;
        reg15.range(479, 448) = s_result_PE127.read() + 1;
        reg15.range(511, 480) = s_result_PE127.read() + 1;
        s_result_all.write(reg15);

        reg16.range(31, 0) = s_result_PE128.read() + 1;
        reg16.range(63, 32) = s_result_PE128.read() + 1;
        reg16.range(95, 64) = s_result_PE129.read() + 1;
        reg16.range(127, 96) = s_result_PE129.read() + 1;
        reg16.range(159, 128) = s_result_PE130.read() + 1;
        reg16.range(191, 160) = s_result_PE130.read() + 1;
        reg16.range(223, 192) = s_result_PE131.read() + 1;
        reg16.range(255, 224) = s_result_PE131.read() + 1;
        reg16.range(287, 256) = s_result_PE132.read() + 1;
        reg16.range(319, 288) = s_result_PE132.read() + 1;
        reg16.range(351, 320) = s_result_PE133.read() + 1;
        reg16.range(383, 352) = s_result_PE133.read() + 1;
        reg16.range(415, 384) = s_result_PE134.read() + 1;
        reg16.range(447, 416) = s_result_PE134.read() + 1;
        reg16.range(479, 448) = s_result_PE135.read() + 1;
        reg16.range(511, 480) = s_result_PE135.read() + 1;
        s_result_all.write(reg16);

        reg17.range(31, 0) = s_result_PE136.read() + 1;
        reg17.range(63, 32) = s_result_PE136.read() + 1;
        reg17.range(95, 64) = s_result_PE137.read() + 1;
        reg17.range(127, 96) = s_result_PE137.read() + 1;
        reg17.range(159, 128) = s_result_PE138.read() + 1;
        reg17.range(191, 160) = s_result_PE138.read() + 1;
        reg17.range(223, 192) = s_result_PE139.read() + 1;
        reg17.range(255, 224) = s_result_PE139.read() + 1;
        reg17.range(287, 256) = s_result_PE140.read() + 1;
        reg17.range(319, 288) = s_result_PE140.read() + 1;
        reg17.range(351, 320) = s_result_PE141.read() + 1;
        reg17.range(383, 352) = s_result_PE141.read() + 1;
        reg17.range(415, 384) = s_result_PE142.read() + 1;
        reg17.range(447, 416) = s_result_PE142.read() + 1;
        reg17.range(479, 448) = s_result_PE143.read() + 1;
        reg17.range(511, 480) = s_result_PE143.read() + 1;
        s_result_all.write(reg17);

        reg18.range(31, 0) = s_result_PE144.read() + 1;
        reg18.range(63, 32) = s_result_PE144.read() + 1;
        reg18.range(95, 64) = s_result_PE145.read() + 1;
        reg18.range(127, 96) = s_result_PE145.read() + 1;
        reg18.range(159, 128) = s_result_PE146.read() + 1;
        reg18.range(191, 160) = s_result_PE146.read() + 1;
        reg18.range(223, 192) = s_result_PE147.read() + 1;
        reg18.range(255, 224) = s_result_PE147.read() + 1;
        reg18.range(287, 256) = s_result_PE148.read() + 1;
        reg18.range(319, 288) = s_result_PE148.read() + 1;
        reg18.range(351, 320) = s_result_PE149.read() + 1;
        reg18.range(383, 352) = s_result_PE149.read() + 1;
        reg18.range(415, 384) = s_result_PE150.read() + 1;
        reg18.range(447, 416) = s_result_PE150.read() + 1;
        reg18.range(479, 448) = s_result_PE151.read() + 1;
        reg18.range(511, 480) = s_result_PE151.read() + 1;
        s_result_all.write(reg18);

        reg19.range(31, 0) = s_result_PE152.read() + 1;
        reg19.range(63, 32) = s_result_PE152.read() + 1;
        reg19.range(95, 64) = s_result_PE153.read() + 1;
        reg19.range(127, 96) = s_result_PE153.read() + 1;
        reg19.range(159, 128) = s_result_PE154.read() + 1;
        reg19.range(191, 160) = s_result_PE154.read() + 1;
        reg19.range(223, 192) = s_result_PE155.read() + 1;
        reg19.range(255, 224) = s_result_PE155.read() + 1;
        reg19.range(287, 256) = s_result_PE156.read() + 1;
        reg19.range(319, 288) = s_result_PE156.read() + 1;
        reg19.range(351, 320) = s_result_PE157.read() + 1;
        reg19.range(383, 352) = s_result_PE157.read() + 1;
        reg19.range(415, 384) = s_result_PE158.read() + 1;
        reg19.range(447, 416) = s_result_PE158.read() + 1;
        reg19.range(479, 448) = s_result_PE159.read() + 1;
        reg19.range(511, 480) = s_result_PE159.read() + 1;
        s_result_all.write(reg19);

        reg20.range(31, 0) = s_result_PE160.read() + 1;
        reg20.range(63, 32) = s_result_PE160.read() + 1;
        reg20.range(95, 64) = s_result_PE161.read() + 1;
        reg20.range(127, 96) = s_result_PE161.read() + 1;
        reg20.range(159, 128) = s_result_PE162.read() + 1;
        reg20.range(191, 160) = s_result_PE162.read() + 1;
        reg20.range(223, 192) = s_result_PE163.read() + 1;
        reg20.range(255, 224) = s_result_PE163.read() + 1;
        reg20.range(287, 256) = s_result_PE164.read() + 1;
        reg20.range(319, 288) = s_result_PE164.read() + 1;
        reg20.range(351, 320) = s_result_PE165.read() + 1;
        reg20.range(383, 352) = s_result_PE165.read() + 1;
        reg20.range(415, 384) = s_result_PE166.read() + 1;
        reg20.range(447, 416) = s_result_PE166.read() + 1;
        reg20.range(479, 448) = s_result_PE167.read() + 1;
        reg20.range(511, 480) = s_result_PE167.read() + 1;
        s_result_all.write(reg20);

        reg21.range(31, 0) = s_result_PE168.read() + 1;
        reg21.range(63, 32) = s_result_PE168.read() + 1;
        reg21.range(95, 64) = s_result_PE169.read() + 1;
        reg21.range(127, 96) = s_result_PE169.read() + 1;
        reg21.range(159, 128) = s_result_PE170.read() + 1;
        reg21.range(191, 160) = s_result_PE170.read() + 1;
        reg21.range(223, 192) = s_result_PE171.read() + 1;
        reg21.range(255, 224) = s_result_PE171.read() + 1;
        reg21.range(287, 256) = s_result_PE172.read() + 1;
        reg21.range(319, 288) = s_result_PE172.read() + 1;
        reg21.range(351, 320) = s_result_PE173.read() + 1;
        reg21.range(383, 352) = s_result_PE173.read() + 1;
        reg21.range(415, 384) = s_result_PE174.read() + 1;
        reg21.range(447, 416) = s_result_PE174.read() + 1;
        reg21.range(479, 448) = s_result_PE175.read() + 1;
        reg21.range(511, 480) = s_result_PE175.read() + 1;
        s_result_all.write(reg21);

        reg22.range(31, 0) = s_result_PE176.read() + 1;
        reg22.range(63, 32) = s_result_PE176.read() + 1;
        reg22.range(95, 64) = s_result_PE177.read() + 1;
        reg22.range(127, 96) = s_result_PE177.read() + 1;
        reg22.range(159, 128) = s_result_PE178.read() + 1;
        reg22.range(191, 160) = s_result_PE178.read() + 1;
        reg22.range(223, 192) = s_result_PE179.read() + 1;
        reg22.range(255, 224) = s_result_PE179.read() + 1;
        reg22.range(287, 256) = s_result_PE180.read() + 1;
        reg22.range(319, 288) = s_result_PE180.read() + 1;
        reg22.range(351, 320) = s_result_PE181.read() + 1;
        reg22.range(383, 352) = s_result_PE181.read() + 1;
        reg22.range(415, 384) = s_result_PE182.read() + 1;
        reg22.range(447, 416) = s_result_PE182.read() + 1;
        reg22.range(479, 448) = s_result_PE183.read() + 1;
        reg22.range(511, 480) = s_result_PE183.read() + 1;
        s_result_all.write(reg22);

        reg23.range(31, 0) = s_result_PE184.read() + 1;
        reg23.range(63, 32) = s_result_PE184.read() + 1;
        reg23.range(95, 64) = s_result_PE185.read() + 1;
        reg23.range(127, 96) = s_result_PE185.read() + 1;
        reg23.range(159, 128) = s_result_PE186.read() + 1;
        reg23.range(191, 160) = s_result_PE186.read() + 1;
        reg23.range(223, 192) = s_result_PE187.read() + 1;
        reg23.range(255, 224) = s_result_PE187.read() + 1;
        reg23.range(287, 256) = s_result_PE188.read() + 1;
        reg23.range(319, 288) = s_result_PE188.read() + 1;
        reg23.range(351, 320) = s_result_PE189.read() + 1;
        reg23.range(383, 352) = s_result_PE189.read() + 1;
        reg23.range(415, 384) = s_result_PE190.read() + 1;
        reg23.range(447, 416) = s_result_PE190.read() + 1;
        reg23.range(479, 448) = s_result_PE191.read() + 1;
        reg23.range(511, 480) = s_result_PE191.read() + 1;
        s_result_all.write(reg23);

        reg24.range(31, 0) = s_result_PE192.read() + 1;
        reg24.range(63, 32) = s_result_PE192.read() + 1;
        reg24.range(95, 64) = s_result_PE193.read() + 1;
        reg24.range(127, 96) = s_result_PE193.read() + 1;
        reg24.range(159, 128) = s_result_PE194.read() + 1;
        reg24.range(191, 160) = s_result_PE194.read() + 1;
        reg24.range(223, 192) = s_result_PE195.read() + 1;
        reg24.range(255, 224) = s_result_PE195.read() + 1;
        reg24.range(287, 256) = s_result_PE196.read() + 1;
        reg24.range(319, 288) = s_result_PE196.read() + 1;
        reg24.range(351, 320) = s_result_PE197.read() + 1;
        reg24.range(383, 352) = s_result_PE197.read() + 1;
        reg24.range(415, 384) = s_result_PE198.read() + 1;
        reg24.range(447, 416) = s_result_PE198.read() + 1;
        reg24.range(479, 448) = s_result_PE199.read() + 1;
        reg24.range(511, 480) = s_result_PE199.read() + 1;
        s_result_all.write(reg24);

        reg25.range(31, 0)    = s_result_PE200.read() + 1;
        reg25.range(63, 32)   = s_result_PE200.read() + 1;
        reg25.range(95, 64)   = s_result_PE201.read() + 1;
        reg25.range(127, 96)  = s_result_PE201.read() + 1;
        reg25.range(159, 128) = s_result_PE202.read() + 1;
        reg25.range(191, 160) = s_result_PE202.read() + 1;
        reg25.range(223, 192) = s_result_PE203.read() + 1;
        reg25.range(255, 224) = s_result_PE203.read() + 1;
        reg25.range(287, 256) = s_result_PE204.read() + 1;
        reg25.range(319, 288) = s_result_PE204.read() + 1;
        reg25.range(351, 320) = s_result_PE205.read() + 1;
        reg25.range(383, 352) = s_result_PE205.read() + 1;
        reg25.range(415, 384) = s_result_PE206.read() + 1;
        reg25.range(447, 416) = s_result_PE206.read() + 1;
        reg25.range(479, 448) = s_result_PE207.read() + 1;
        reg25.range(511, 480) = s_result_PE207.read() + 1;
        s_result_all.write(reg25);

        reg26.range(31, 0)    = s_result_PE208.read() + 1;
        reg26.range(63, 32)   = s_result_PE208.read() + 1;
        reg26.range(95, 64)   = s_result_PE209.read() + 1;
        reg26.range(127, 96)  = s_result_PE209.read() + 1;
        reg26.range(159, 128) = s_result_PE210.read() + 1;
        reg26.range(191, 160) = s_result_PE210.read() + 1;
        reg26.range(223, 192) = s_result_PE211.read() + 1;
        reg26.range(255, 224) = s_result_PE211.read() + 1;
        reg26.range(287, 256) = s_result_PE212.read() + 1;
        reg26.range(319, 288) = s_result_PE212.read() + 1;
        reg26.range(351, 320) = s_result_PE213.read() + 1;
        reg26.range(383, 352) = s_result_PE213.read() + 1;
        reg26.range(415, 384) = s_result_PE214.read() + 1;
        reg26.range(447, 416) = s_result_PE214.read() + 1;
        reg26.range(479, 448) = s_result_PE215.read() + 1;
        reg26.range(511, 480) = s_result_PE215.read() + 1;
        s_result_all.write(reg26);

        reg27.range(31, 0) = s_result_PE216.read() + 1;
        reg27.range(63, 32) = s_result_PE216.read() + 1;
        reg27.range(95, 64) = s_result_PE217.read() + 1;
        reg27.range(127, 96) = s_result_PE217.read() + 1;
        reg27.range(159, 128) = s_result_PE218.read() + 1;
        reg27.range(191, 160) = s_result_PE218.read() + 1;
        reg27.range(223, 192) = s_result_PE219.read() + 1;
        reg27.range(255, 224) = s_result_PE219.read() + 1;
        reg27.range(287, 256) = s_result_PE220.read() + 1;
        reg27.range(319, 288) = s_result_PE220.read() + 1;
        reg27.range(351, 320) = s_result_PE221.read() + 1;
        reg27.range(383, 352) = s_result_PE221.read() + 1;
        reg27.range(415, 384) = s_result_PE222.read() + 1;
        reg27.range(447, 416) = s_result_PE222.read() + 1;
        reg27.range(479, 448) = s_result_PE223.read() + 1;
        reg27.range(511, 480) = s_result_PE223.read() + 1;
        s_result_all.write(reg27);
    }
}

template<const int ROW_PER_PE>
void gather_results_512PEs_256PE(
    STREAM<D_TYPE>& s_result_PE0, STREAM<D_TYPE>& s_result_PE1, 
    STREAM<D_TYPE>& s_result_PE2, STREAM<D_TYPE>& s_result_PE3, 
    STREAM<D_TYPE>& s_result_PE4, STREAM<D_TYPE>& s_result_PE5, 
    STREAM<D_TYPE>& s_result_PE6, STREAM<D_TYPE>& s_result_PE7, 
    STREAM<D_TYPE>& s_result_PE8, STREAM<D_TYPE>& s_result_PE9, 
    STREAM<D_TYPE>& s_result_PE10, STREAM<D_TYPE>& s_result_PE11, 
    STREAM<D_TYPE>& s_result_PE12, STREAM<D_TYPE>& s_result_PE13, 
    STREAM<D_TYPE>& s_result_PE14, STREAM<D_TYPE>& s_result_PE15, 
    STREAM<D_TYPE>& s_result_PE16, STREAM<D_TYPE>& s_result_PE17, 
    STREAM<D_TYPE>& s_result_PE18, STREAM<D_TYPE>& s_result_PE19, 
    STREAM<D_TYPE>& s_result_PE20, STREAM<D_TYPE>& s_result_PE21, 
    STREAM<D_TYPE>& s_result_PE22, STREAM<D_TYPE>& s_result_PE23, 
    STREAM<D_TYPE>& s_result_PE24, STREAM<D_TYPE>& s_result_PE25, 
    STREAM<D_TYPE>& s_result_PE26, STREAM<D_TYPE>& s_result_PE27, 
    STREAM<D_TYPE>& s_result_PE28, STREAM<D_TYPE>& s_result_PE29, 
    STREAM<D_TYPE>& s_result_PE30, STREAM<D_TYPE>& s_result_PE31, 
    STREAM<D_TYPE>& s_result_PE32, STREAM<D_TYPE>& s_result_PE33, 
    STREAM<D_TYPE>& s_result_PE34, STREAM<D_TYPE>& s_result_PE35, 
    STREAM<D_TYPE>& s_result_PE36, STREAM<D_TYPE>& s_result_PE37, 
    STREAM<D_TYPE>& s_result_PE38, STREAM<D_TYPE>& s_result_PE39, 
    STREAM<D_TYPE>& s_result_PE40, STREAM<D_TYPE>& s_result_PE41, 
    STREAM<D_TYPE>& s_result_PE42, STREAM<D_TYPE>& s_result_PE43, 
    STREAM<D_TYPE>& s_result_PE44, STREAM<D_TYPE>& s_result_PE45, 
    STREAM<D_TYPE>& s_result_PE46, STREAM<D_TYPE>& s_result_PE47, 
    STREAM<D_TYPE>& s_result_PE48, STREAM<D_TYPE>& s_result_PE49, 
    STREAM<D_TYPE>& s_result_PE50, STREAM<D_TYPE>& s_result_PE51, 
    STREAM<D_TYPE>& s_result_PE52, STREAM<D_TYPE>& s_result_PE53, 
    STREAM<D_TYPE>& s_result_PE54, STREAM<D_TYPE>& s_result_PE55, 
    STREAM<D_TYPE>& s_result_PE56, STREAM<D_TYPE>& s_result_PE57, 
    STREAM<D_TYPE>& s_result_PE58, STREAM<D_TYPE>& s_result_PE59, 
    STREAM<D_TYPE>& s_result_PE60, STREAM<D_TYPE>& s_result_PE61, 
    STREAM<D_TYPE>& s_result_PE62, STREAM<D_TYPE>& s_result_PE63, 
    STREAM<D_TYPE>& s_result_PE64, STREAM<D_TYPE>& s_result_PE65, 
    STREAM<D_TYPE>& s_result_PE66, STREAM<D_TYPE>& s_result_PE67, 
    STREAM<D_TYPE>& s_result_PE68, STREAM<D_TYPE>& s_result_PE69, 
    STREAM<D_TYPE>& s_result_PE70, STREAM<D_TYPE>& s_result_PE71, 
    STREAM<D_TYPE>& s_result_PE72, STREAM<D_TYPE>& s_result_PE73, 
    STREAM<D_TYPE>& s_result_PE74, STREAM<D_TYPE>& s_result_PE75, 
    STREAM<D_TYPE>& s_result_PE76, STREAM<D_TYPE>& s_result_PE77, 
    STREAM<D_TYPE>& s_result_PE78, STREAM<D_TYPE>& s_result_PE79, 
    STREAM<D_TYPE>& s_result_PE80, STREAM<D_TYPE>& s_result_PE81, 
    STREAM<D_TYPE>& s_result_PE82, STREAM<D_TYPE>& s_result_PE83, 
    STREAM<D_TYPE>& s_result_PE84, STREAM<D_TYPE>& s_result_PE85, 
    STREAM<D_TYPE>& s_result_PE86, STREAM<D_TYPE>& s_result_PE87, 
    STREAM<D_TYPE>& s_result_PE88, STREAM<D_TYPE>& s_result_PE89, 
    STREAM<D_TYPE>& s_result_PE90, STREAM<D_TYPE>& s_result_PE91, 
    STREAM<D_TYPE>& s_result_PE92, STREAM<D_TYPE>& s_result_PE93, 
    STREAM<D_TYPE>& s_result_PE94, STREAM<D_TYPE>& s_result_PE95, 
    STREAM<D_TYPE>& s_result_PE96, STREAM<D_TYPE>& s_result_PE97, 
    STREAM<D_TYPE>& s_result_PE98, STREAM<D_TYPE>& s_result_PE99, 
    STREAM<D_TYPE>& s_result_PE100, STREAM<D_TYPE>& s_result_PE101, 
    STREAM<D_TYPE>& s_result_PE102, STREAM<D_TYPE>& s_result_PE103, 
    STREAM<D_TYPE>& s_result_PE104, STREAM<D_TYPE>& s_result_PE105, 
    STREAM<D_TYPE>& s_result_PE106, STREAM<D_TYPE>& s_result_PE107, 
    STREAM<D_TYPE>& s_result_PE108, STREAM<D_TYPE>& s_result_PE109, 
    STREAM<D_TYPE>& s_result_PE110, STREAM<D_TYPE>& s_result_PE111, 
    STREAM<D_TYPE>& s_result_PE112, STREAM<D_TYPE>& s_result_PE113, 
    STREAM<D_TYPE>& s_result_PE114, STREAM<D_TYPE>& s_result_PE115, 
    STREAM<D_TYPE>& s_result_PE116, STREAM<D_TYPE>& s_result_PE117, 
    STREAM<D_TYPE>& s_result_PE118, STREAM<D_TYPE>& s_result_PE119, 
    STREAM<D_TYPE>& s_result_PE120, STREAM<D_TYPE>& s_result_PE121, 
    STREAM<D_TYPE>& s_result_PE122, STREAM<D_TYPE>& s_result_PE123, 
    STREAM<D_TYPE>& s_result_PE124, STREAM<D_TYPE>& s_result_PE125, 
    STREAM<D_TYPE>& s_result_PE126, STREAM<D_TYPE>& s_result_PE127, 
    STREAM<D_TYPE>& s_result_PE128, STREAM<D_TYPE>& s_result_PE129,
    STREAM<D_TYPE>& s_result_PE130, STREAM<D_TYPE>& s_result_PE131,
    STREAM<D_TYPE>& s_result_PE132, STREAM<D_TYPE>& s_result_PE133,
    STREAM<D_TYPE>& s_result_PE134, STREAM<D_TYPE>& s_result_PE135,
    STREAM<D_TYPE>& s_result_PE136, STREAM<D_TYPE>& s_result_PE137,
    STREAM<D_TYPE>& s_result_PE138, STREAM<D_TYPE>& s_result_PE139,
    STREAM<D_TYPE>& s_result_PE140, STREAM<D_TYPE>& s_result_PE141,
    STREAM<D_TYPE>& s_result_PE142, STREAM<D_TYPE>& s_result_PE143,
    STREAM<D_TYPE>& s_result_PE144, STREAM<D_TYPE>& s_result_PE145,
    STREAM<D_TYPE>& s_result_PE146, STREAM<D_TYPE>& s_result_PE147,
    STREAM<D_TYPE>& s_result_PE148, STREAM<D_TYPE>& s_result_PE149,
    STREAM<D_TYPE>& s_result_PE150, STREAM<D_TYPE>& s_result_PE151,
    STREAM<D_TYPE>& s_result_PE152, STREAM<D_TYPE>& s_result_PE153,
    STREAM<D_TYPE>& s_result_PE154, STREAM<D_TYPE>& s_result_PE155,
    STREAM<D_TYPE>& s_result_PE156, STREAM<D_TYPE>& s_result_PE157,
    STREAM<D_TYPE>& s_result_PE158, STREAM<D_TYPE>& s_result_PE159,
    STREAM<D_TYPE>& s_result_PE160, STREAM<D_TYPE>& s_result_PE161,
    STREAM<D_TYPE>& s_result_PE162, STREAM<D_TYPE>& s_result_PE163,
    STREAM<D_TYPE>& s_result_PE164, STREAM<D_TYPE>& s_result_PE165,
    STREAM<D_TYPE>& s_result_PE166, STREAM<D_TYPE>& s_result_PE167,
    STREAM<D_TYPE>& s_result_PE168, STREAM<D_TYPE>& s_result_PE169,
    STREAM<D_TYPE>& s_result_PE170, STREAM<D_TYPE>& s_result_PE171,
    STREAM<D_TYPE>& s_result_PE172, STREAM<D_TYPE>& s_result_PE173,
    STREAM<D_TYPE>& s_result_PE174, STREAM<D_TYPE>& s_result_PE175,
    STREAM<D_TYPE>& s_result_PE176, STREAM<D_TYPE>& s_result_PE177,
    STREAM<D_TYPE>& s_result_PE178, STREAM<D_TYPE>& s_result_PE179,
    STREAM<D_TYPE>& s_result_PE180, STREAM<D_TYPE>& s_result_PE181,
    STREAM<D_TYPE>& s_result_PE182, STREAM<D_TYPE>& s_result_PE183,
    STREAM<D_TYPE>& s_result_PE184, STREAM<D_TYPE>& s_result_PE185,
    STREAM<D_TYPE>& s_result_PE186, STREAM<D_TYPE>& s_result_PE187,
    STREAM<D_TYPE>& s_result_PE188, STREAM<D_TYPE>& s_result_PE189,
    STREAM<D_TYPE>& s_result_PE190, STREAM<D_TYPE>& s_result_PE191,
    STREAM<D_TYPE>& s_result_PE192, STREAM<D_TYPE>& s_result_PE193,
    STREAM<D_TYPE>& s_result_PE194, STREAM<D_TYPE>& s_result_PE195,
    STREAM<D_TYPE>& s_result_PE196, STREAM<D_TYPE>& s_result_PE197,
    STREAM<D_TYPE>& s_result_PE198, STREAM<D_TYPE>& s_result_PE199,
    STREAM<D_TYPE>& s_result_PE200, STREAM<D_TYPE>& s_result_PE201, 
    STREAM<D_TYPE>& s_result_PE202, STREAM<D_TYPE>& s_result_PE203, 
    STREAM<D_TYPE>& s_result_PE204, STREAM<D_TYPE>& s_result_PE205, 
    STREAM<D_TYPE>& s_result_PE206, STREAM<D_TYPE>& s_result_PE207, 
    STREAM<D_TYPE>& s_result_PE208, STREAM<D_TYPE>& s_result_PE209, 
    STREAM<D_TYPE>& s_result_PE210, STREAM<D_TYPE>& s_result_PE211, 
    STREAM<D_TYPE>& s_result_PE212, STREAM<D_TYPE>& s_result_PE213, 
    STREAM<D_TYPE>& s_result_PE214, STREAM<D_TYPE>& s_result_PE215,
    STREAM<D_TYPE>& s_result_PE216, STREAM<D_TYPE>& s_result_PE217, 
    STREAM<D_TYPE>& s_result_PE218, STREAM<D_TYPE>& s_result_PE219, 
    STREAM<D_TYPE>& s_result_PE220, STREAM<D_TYPE>& s_result_PE221, 
    STREAM<D_TYPE>& s_result_PE222, STREAM<D_TYPE>& s_result_PE223, 
    STREAM<D_TYPE>& s_result_PE224, STREAM<D_TYPE>& s_result_PE225, 
    STREAM<D_TYPE>& s_result_PE226, STREAM<D_TYPE>& s_result_PE227,
    STREAM<D_TYPE>& s_result_PE228, STREAM<D_TYPE>& s_result_PE229,
    STREAM<D_TYPE>& s_result_PE230, STREAM<D_TYPE>& s_result_PE231,
    STREAM<D_TYPE>& s_result_PE232, STREAM<D_TYPE>& s_result_PE233,
    STREAM<D_TYPE>& s_result_PE234, STREAM<D_TYPE>& s_result_PE235,
    STREAM<D_TYPE>& s_result_PE236, STREAM<D_TYPE>& s_result_PE237,
    STREAM<D_TYPE>& s_result_PE238, STREAM<D_TYPE>& s_result_PE239,
    STREAM<D_TYPE>& s_result_PE240, STREAM<D_TYPE>& s_result_PE241,
    STREAM<D_TYPE>& s_result_PE242, STREAM<D_TYPE>& s_result_PE243,
    STREAM<D_TYPE>& s_result_PE244, STREAM<D_TYPE>& s_result_PE245,
    STREAM<D_TYPE>& s_result_PE246, STREAM<D_TYPE>& s_result_PE247,
    STREAM<D_TYPE>& s_result_PE248, STREAM<D_TYPE>& s_result_PE249,
    STREAM<D_TYPE>& s_result_PE250, STREAM<D_TYPE>& s_result_PE251,
    STREAM<D_TYPE>& s_result_PE252, STREAM<D_TYPE>& s_result_PE253,
    STREAM<D_TYPE>& s_result_PE254, STREAM<D_TYPE>& s_result_PE255,
    STREAM<ap_uint<512> >& s_result_all) {
     
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        #pragma HLS pipeline II=32  // write 1 result_all per CC

        ap_uint<512> reg0, reg1, reg2, reg3, reg4, reg5, reg6, reg7, 
            reg8, reg9, reg10, reg11, reg12, reg13, reg14, reg15, 
            reg16, reg17, reg18, reg19, reg20, reg21, reg22, reg23, 
            reg24, reg25, reg26, reg27, reg28, reg29, reg30, reg31;

        reg0.range(31, 0) = s_result_PE0.read() + 1;
        reg0.range(63, 32) = s_result_PE0.read() + 1;
        reg0.range(95, 64) = s_result_PE1.read() + 1;
        reg0.range(127, 96) = s_result_PE1.read() + 1;
        reg0.range(159, 128) = s_result_PE2.read() + 1;
        reg0.range(191, 160) = s_result_PE2.read() + 1;
        reg0.range(223, 192) = s_result_PE3.read() + 1;
        reg0.range(255, 224) = s_result_PE3.read() + 1;
        reg0.range(287, 256) = s_result_PE4.read() + 1;
        reg0.range(319, 288) = s_result_PE4.read() + 1;
        reg0.range(351, 320) = s_result_PE5.read() + 1;
        reg0.range(383, 352) = s_result_PE5.read() + 1;
        reg0.range(415, 384) = s_result_PE6.read() + 1;
        reg0.range(447, 416) = s_result_PE6.read() + 1;
        reg0.range(479, 448) = s_result_PE7.read() + 1;
        reg0.range(511, 480) = s_result_PE7.read() + 1;
        s_result_all.write(reg0);

        reg1.range(31, 0) = s_result_PE8.read() + 1;
        reg1.range(63, 32) = s_result_PE8.read() + 1;
        reg1.range(95, 64) = s_result_PE9.read() + 1;
        reg1.range(127, 96) = s_result_PE9.read() + 1;
        reg1.range(159, 128) = s_result_PE10.read() + 1;
        reg1.range(191, 160) = s_result_PE10.read() + 1;
        reg1.range(223, 192) = s_result_PE11.read() + 1;
        reg1.range(255, 224) = s_result_PE11.read() + 1;
        reg1.range(287, 256) = s_result_PE12.read() + 1;
        reg1.range(319, 288) = s_result_PE12.read() + 1;
        reg1.range(351, 320) = s_result_PE13.read() + 1;
        reg1.range(383, 352) = s_result_PE13.read() + 1;
        reg1.range(415, 384) = s_result_PE14.read() + 1;
        reg1.range(447, 416) = s_result_PE14.read() + 1;
        reg1.range(479, 448) = s_result_PE15.read() + 1;
        reg1.range(511, 480) = s_result_PE15.read() + 1;
        s_result_all.write(reg1);

        reg2.range(31, 0) = s_result_PE16.read() + 1;
        reg2.range(63, 32) = s_result_PE16.read() + 1;
        reg2.range(95, 64) = s_result_PE17.read() + 1;
        reg2.range(127, 96) = s_result_PE17.read() + 1;
        reg2.range(159, 128) = s_result_PE18.read() + 1;
        reg2.range(191, 160) = s_result_PE18.read() + 1;
        reg2.range(223, 192) = s_result_PE19.read() + 1;
        reg2.range(255, 224) = s_result_PE19.read() + 1;
        reg2.range(287, 256) = s_result_PE20.read() + 1;
        reg2.range(319, 288) = s_result_PE20.read() + 1;
        reg2.range(351, 320) = s_result_PE21.read() + 1;
        reg2.range(383, 352) = s_result_PE21.read() + 1;
        reg2.range(415, 384) = s_result_PE22.read() + 1;
        reg2.range(447, 416) = s_result_PE22.read() + 1;
        reg2.range(479, 448) = s_result_PE23.read() + 1;
        reg2.range(511, 480) = s_result_PE23.read() + 1;
        s_result_all.write(reg2);

        reg3.range(31, 0) = s_result_PE24.read() + 1;
        reg3.range(63, 32) = s_result_PE24.read() + 1;
        reg3.range(95, 64) = s_result_PE25.read() + 1;
        reg3.range(127, 96) = s_result_PE25.read() + 1;
        reg3.range(159, 128) = s_result_PE26.read() + 1;
        reg3.range(191, 160) = s_result_PE26.read() + 1;
        reg3.range(223, 192) = s_result_PE27.read() + 1;
        reg3.range(255, 224) = s_result_PE27.read() + 1;
        reg3.range(287, 256) = s_result_PE28.read() + 1;
        reg3.range(319, 288) = s_result_PE28.read() + 1;
        reg3.range(351, 320) = s_result_PE29.read() + 1;
        reg3.range(383, 352) = s_result_PE29.read() + 1;
        reg3.range(415, 384) = s_result_PE30.read() + 1;
        reg3.range(447, 416) = s_result_PE30.read() + 1;
        reg3.range(479, 448) = s_result_PE31.read() + 1;
        reg3.range(511, 480) = s_result_PE31.read() + 1;
        s_result_all.write(reg3);

        reg4.range(31, 0) = s_result_PE32.read() + 1;
        reg4.range(63, 32) = s_result_PE32.read() + 1;
        reg4.range(95, 64) = s_result_PE33.read() + 1;
        reg4.range(127, 96) = s_result_PE33.read() + 1;
        reg4.range(159, 128) = s_result_PE34.read() + 1;
        reg4.range(191, 160) = s_result_PE34.read() + 1;
        reg4.range(223, 192) = s_result_PE35.read() + 1;
        reg4.range(255, 224) = s_result_PE35.read() + 1;
        reg4.range(287, 256) = s_result_PE36.read() + 1;
        reg4.range(319, 288) = s_result_PE36.read() + 1;
        reg4.range(351, 320) = s_result_PE37.read() + 1;
        reg4.range(383, 352) = s_result_PE37.read() + 1;
        reg4.range(415, 384) = s_result_PE38.read() + 1;
        reg4.range(447, 416) = s_result_PE38.read() + 1;
        reg4.range(479, 448) = s_result_PE39.read() + 1;
        reg4.range(511, 480) = s_result_PE39.read() + 1;
        s_result_all.write(reg4);

        reg5.range(31, 0) = s_result_PE40.read() + 1;
        reg5.range(63, 32) = s_result_PE40.read() + 1;
        reg5.range(95, 64) = s_result_PE41.read() + 1;
        reg5.range(127, 96) = s_result_PE41.read() + 1;
        reg5.range(159, 128) = s_result_PE42.read() + 1;
        reg5.range(191, 160) = s_result_PE42.read() + 1;
        reg5.range(223, 192) = s_result_PE43.read() + 1;
        reg5.range(255, 224) = s_result_PE43.read() + 1;
        reg5.range(287, 256) = s_result_PE44.read() + 1;
        reg5.range(319, 288) = s_result_PE44.read() + 1;
        reg5.range(351, 320) = s_result_PE45.read() + 1;
        reg5.range(383, 352) = s_result_PE45.read() + 1;
        reg5.range(415, 384) = s_result_PE46.read() + 1;
        reg5.range(447, 416) = s_result_PE46.read() + 1;
        reg5.range(479, 448) = s_result_PE47.read() + 1;
        reg5.range(511, 480) = s_result_PE47.read() + 1;
        s_result_all.write(reg5);

        reg6.range(31, 0) = s_result_PE48.read() + 1;
        reg6.range(63, 32) = s_result_PE48.read() + 1;
        reg6.range(95, 64) = s_result_PE49.read() + 1;
        reg6.range(127, 96) = s_result_PE49.read() + 1;
        reg6.range(159, 128) = s_result_PE50.read() + 1;
        reg6.range(191, 160) = s_result_PE50.read() + 1;
        reg6.range(223, 192) = s_result_PE51.read() + 1;
        reg6.range(255, 224) = s_result_PE51.read() + 1;
        reg6.range(287, 256) = s_result_PE52.read() + 1;
        reg6.range(319, 288) = s_result_PE52.read() + 1;
        reg6.range(351, 320) = s_result_PE53.read() + 1;
        reg6.range(383, 352) = s_result_PE53.read() + 1;
        reg6.range(415, 384) = s_result_PE54.read() + 1;
        reg6.range(447, 416) = s_result_PE54.read() + 1;
        reg6.range(479, 448) = s_result_PE55.read() + 1;
        reg6.range(511, 480) = s_result_PE55.read() + 1;
        s_result_all.write(reg6);

        reg7.range(31, 0) = s_result_PE56.read() + 1;
        reg7.range(63, 32) = s_result_PE56.read() + 1;
        reg7.range(95, 64) = s_result_PE57.read() + 1;
        reg7.range(127, 96) = s_result_PE57.read() + 1;
        reg7.range(159, 128) = s_result_PE58.read() + 1;
        reg7.range(191, 160) = s_result_PE58.read() + 1;
        reg7.range(223, 192) = s_result_PE59.read() + 1;
        reg7.range(255, 224) = s_result_PE59.read() + 1;
        reg7.range(287, 256) = s_result_PE60.read() + 1;
        reg7.range(319, 288) = s_result_PE60.read() + 1;
        reg7.range(351, 320) = s_result_PE61.read() + 1;
        reg7.range(383, 352) = s_result_PE61.read() + 1;
        reg7.range(415, 384) = s_result_PE62.read() + 1;
        reg7.range(447, 416) = s_result_PE62.read() + 1;
        reg7.range(479, 448) = s_result_PE63.read() + 1;
        reg7.range(511, 480) = s_result_PE63.read() + 1;
        s_result_all.write(reg7);

        reg8.range(31, 0) = s_result_PE64.read() + 1;
        reg8.range(63, 32) = s_result_PE64.read() + 1;
        reg8.range(95, 64) = s_result_PE65.read() + 1;
        reg8.range(127, 96) = s_result_PE65.read() + 1;
        reg8.range(159, 128) = s_result_PE66.read() + 1;
        reg8.range(191, 160) = s_result_PE66.read() + 1;
        reg8.range(223, 192) = s_result_PE67.read() + 1;
        reg8.range(255, 224) = s_result_PE67.read() + 1;
        reg8.range(287, 256) = s_result_PE68.read() + 1;
        reg8.range(319, 288) = s_result_PE68.read() + 1;
        reg8.range(351, 320) = s_result_PE69.read() + 1;
        reg8.range(383, 352) = s_result_PE69.read() + 1;
        reg8.range(415, 384) = s_result_PE70.read() + 1;
        reg8.range(447, 416) = s_result_PE70.read() + 1;
        reg8.range(479, 448) = s_result_PE71.read() + 1;
        reg8.range(511, 480) = s_result_PE71.read() + 1;
        s_result_all.write(reg8);

        reg9.range(31, 0) = s_result_PE72.read() + 1;
        reg9.range(63, 32) = s_result_PE72.read() + 1;
        reg9.range(95, 64) = s_result_PE73.read() + 1;
        reg9.range(127, 96) = s_result_PE73.read() + 1;
        reg9.range(159, 128) = s_result_PE74.read() + 1;
        reg9.range(191, 160) = s_result_PE74.read() + 1;
        reg9.range(223, 192) = s_result_PE75.read() + 1;
        reg9.range(255, 224) = s_result_PE75.read() + 1;
        reg9.range(287, 256) = s_result_PE76.read() + 1;
        reg9.range(319, 288) = s_result_PE76.read() + 1;
        reg9.range(351, 320) = s_result_PE77.read() + 1;
        reg9.range(383, 352) = s_result_PE77.read() + 1;
        reg9.range(415, 384) = s_result_PE78.read() + 1;
        reg9.range(447, 416) = s_result_PE78.read() + 1;
        reg9.range(479, 448) = s_result_PE79.read() + 1;
        reg9.range(511, 480) = s_result_PE79.read() + 1;
        s_result_all.write(reg9);

        reg10.range(31, 0) = s_result_PE80.read() + 1;
        reg10.range(63, 32) = s_result_PE80.read() + 1;
        reg10.range(95, 64) = s_result_PE81.read() + 1;
        reg10.range(127, 96) = s_result_PE81.read() + 1;
        reg10.range(159, 128) = s_result_PE82.read() + 1;
        reg10.range(191, 160) = s_result_PE82.read() + 1;
        reg10.range(223, 192) = s_result_PE83.read() + 1;
        reg10.range(255, 224) = s_result_PE83.read() + 1;
        reg10.range(287, 256) = s_result_PE84.read() + 1;
        reg10.range(319, 288) = s_result_PE84.read() + 1;
        reg10.range(351, 320) = s_result_PE85.read() + 1;
        reg10.range(383, 352) = s_result_PE85.read() + 1;
        reg10.range(415, 384) = s_result_PE86.read() + 1;
        reg10.range(447, 416) = s_result_PE86.read() + 1;
        reg10.range(479, 448) = s_result_PE87.read() + 1;
        reg10.range(511, 480) = s_result_PE87.read() + 1;
        s_result_all.write(reg10);

        reg11.range(31, 0) = s_result_PE88.read() + 1;
        reg11.range(63, 32) = s_result_PE88.read() + 1;
        reg11.range(95, 64) = s_result_PE89.read() + 1;
        reg11.range(127, 96) = s_result_PE89.read() + 1;
        reg11.range(159, 128) = s_result_PE90.read() + 1;
        reg11.range(191, 160) = s_result_PE90.read() + 1;
        reg11.range(223, 192) = s_result_PE91.read() + 1;
        reg11.range(255, 224) = s_result_PE91.read() + 1;
        reg11.range(287, 256) = s_result_PE92.read() + 1;
        reg11.range(319, 288) = s_result_PE92.read() + 1;
        reg11.range(351, 320) = s_result_PE93.read() + 1;
        reg11.range(383, 352) = s_result_PE93.read() + 1;
        reg11.range(415, 384) = s_result_PE94.read() + 1;
        reg11.range(447, 416) = s_result_PE94.read() + 1;
        reg11.range(479, 448) = s_result_PE95.read() + 1;
        reg11.range(511, 480) = s_result_PE95.read() + 1;
        s_result_all.write(reg11);

        reg12.range(31, 0) = s_result_PE96.read() + 1;
        reg12.range(63, 32) = s_result_PE96.read() + 1;
        reg12.range(95, 64) = s_result_PE97.read() + 1;
        reg12.range(127, 96) = s_result_PE97.read() + 1;
        reg12.range(159, 128) = s_result_PE98.read() + 1;
        reg12.range(191, 160) = s_result_PE98.read() + 1;
        reg12.range(223, 192) = s_result_PE99.read() + 1;
        reg12.range(255, 224) = s_result_PE99.read() + 1;
        reg12.range(287, 256) = s_result_PE100.read() + 1;
        reg12.range(319, 288) = s_result_PE100.read() + 1;
        reg12.range(351, 320) = s_result_PE101.read() + 1;
        reg12.range(383, 352) = s_result_PE101.read() + 1;
        reg12.range(415, 384) = s_result_PE102.read() + 1;
        reg12.range(447, 416) = s_result_PE102.read() + 1;
        reg12.range(479, 448) = s_result_PE103.read() + 1;
        reg12.range(511, 480) = s_result_PE103.read() + 1;
        s_result_all.write(reg12);

        reg13.range(31, 0) = s_result_PE104.read() + 1;
        reg13.range(63, 32) = s_result_PE104.read() + 1;
        reg13.range(95, 64) = s_result_PE105.read() + 1;
        reg13.range(127, 96) = s_result_PE105.read() + 1;
        reg13.range(159, 128) = s_result_PE106.read() + 1;
        reg13.range(191, 160) = s_result_PE106.read() + 1;
        reg13.range(223, 192) = s_result_PE107.read() + 1;
        reg13.range(255, 224) = s_result_PE107.read() + 1;
        reg13.range(287, 256) = s_result_PE108.read() + 1;
        reg13.range(319, 288) = s_result_PE108.read() + 1;
        reg13.range(351, 320) = s_result_PE109.read() + 1;
        reg13.range(383, 352) = s_result_PE109.read() + 1;
        reg13.range(415, 384) = s_result_PE110.read() + 1;
        reg13.range(447, 416) = s_result_PE110.read() + 1;
        reg13.range(479, 448) = s_result_PE111.read() + 1;
        reg13.range(511, 480) = s_result_PE111.read() + 1;
        s_result_all.write(reg13);

        reg14.range(31, 0) = s_result_PE112.read() + 1;
        reg14.range(63, 32) = s_result_PE112.read() + 1;
        reg14.range(95, 64) = s_result_PE113.read() + 1;
        reg14.range(127, 96) = s_result_PE113.read() + 1;
        reg14.range(159, 128) = s_result_PE114.read() + 1;
        reg14.range(191, 160) = s_result_PE114.read() + 1;
        reg14.range(223, 192) = s_result_PE115.read() + 1;
        reg14.range(255, 224) = s_result_PE115.read() + 1;
        reg14.range(287, 256) = s_result_PE116.read() + 1;
        reg14.range(319, 288) = s_result_PE116.read() + 1;
        reg14.range(351, 320) = s_result_PE117.read() + 1;
        reg14.range(383, 352) = s_result_PE117.read() + 1;
        reg14.range(415, 384) = s_result_PE118.read() + 1;
        reg14.range(447, 416) = s_result_PE118.read() + 1;
        reg14.range(479, 448) = s_result_PE119.read() + 1;
        reg14.range(511, 480) = s_result_PE119.read() + 1;
        s_result_all.write(reg14);

        reg15.range(31, 0) = s_result_PE120.read() + 1;
        reg15.range(63, 32) = s_result_PE120.read() + 1;
        reg15.range(95, 64) = s_result_PE121.read() + 1;
        reg15.range(127, 96) = s_result_PE121.read() + 1;
        reg15.range(159, 128) = s_result_PE122.read() + 1;
        reg15.range(191, 160) = s_result_PE122.read() + 1;
        reg15.range(223, 192) = s_result_PE123.read() + 1;
        reg15.range(255, 224) = s_result_PE123.read() + 1;
        reg15.range(287, 256) = s_result_PE124.read() + 1;
        reg15.range(319, 288) = s_result_PE124.read() + 1;
        reg15.range(351, 320) = s_result_PE125.read() + 1;
        reg15.range(383, 352) = s_result_PE125.read() + 1;
        reg15.range(415, 384) = s_result_PE126.read() + 1;
        reg15.range(447, 416) = s_result_PE126.read() + 1;
        reg15.range(479, 448) = s_result_PE127.read() + 1;
        reg15.range(511, 480) = s_result_PE127.read() + 1;
        s_result_all.write(reg15);

        reg16.range(31, 0) = s_result_PE128.read() + 1;
        reg16.range(63, 32) = s_result_PE128.read() + 1;
        reg16.range(95, 64) = s_result_PE129.read() + 1;
        reg16.range(127, 96) = s_result_PE129.read() + 1;
        reg16.range(159, 128) = s_result_PE130.read() + 1;
        reg16.range(191, 160) = s_result_PE130.read() + 1;
        reg16.range(223, 192) = s_result_PE131.read() + 1;
        reg16.range(255, 224) = s_result_PE131.read() + 1;
        reg16.range(287, 256) = s_result_PE132.read() + 1;
        reg16.range(319, 288) = s_result_PE132.read() + 1;
        reg16.range(351, 320) = s_result_PE133.read() + 1;
        reg16.range(383, 352) = s_result_PE133.read() + 1;
        reg16.range(415, 384) = s_result_PE134.read() + 1;
        reg16.range(447, 416) = s_result_PE134.read() + 1;
        reg16.range(479, 448) = s_result_PE135.read() + 1;
        reg16.range(511, 480) = s_result_PE135.read() + 1;
        s_result_all.write(reg16);

        reg17.range(31, 0) = s_result_PE136.read() + 1;
        reg17.range(63, 32) = s_result_PE136.read() + 1;
        reg17.range(95, 64) = s_result_PE137.read() + 1;
        reg17.range(127, 96) = s_result_PE137.read() + 1;
        reg17.range(159, 128) = s_result_PE138.read() + 1;
        reg17.range(191, 160) = s_result_PE138.read() + 1;
        reg17.range(223, 192) = s_result_PE139.read() + 1;
        reg17.range(255, 224) = s_result_PE139.read() + 1;
        reg17.range(287, 256) = s_result_PE140.read() + 1;
        reg17.range(319, 288) = s_result_PE140.read() + 1;
        reg17.range(351, 320) = s_result_PE141.read() + 1;
        reg17.range(383, 352) = s_result_PE141.read() + 1;
        reg17.range(415, 384) = s_result_PE142.read() + 1;
        reg17.range(447, 416) = s_result_PE142.read() + 1;
        reg17.range(479, 448) = s_result_PE143.read() + 1;
        reg17.range(511, 480) = s_result_PE143.read() + 1;
        s_result_all.write(reg17);

        reg18.range(31, 0) = s_result_PE144.read() + 1;
        reg18.range(63, 32) = s_result_PE144.read() + 1;
        reg18.range(95, 64) = s_result_PE145.read() + 1;
        reg18.range(127, 96) = s_result_PE145.read() + 1;
        reg18.range(159, 128) = s_result_PE146.read() + 1;
        reg18.range(191, 160) = s_result_PE146.read() + 1;
        reg18.range(223, 192) = s_result_PE147.read() + 1;
        reg18.range(255, 224) = s_result_PE147.read() + 1;
        reg18.range(287, 256) = s_result_PE148.read() + 1;
        reg18.range(319, 288) = s_result_PE148.read() + 1;
        reg18.range(351, 320) = s_result_PE149.read() + 1;
        reg18.range(383, 352) = s_result_PE149.read() + 1;
        reg18.range(415, 384) = s_result_PE150.read() + 1;
        reg18.range(447, 416) = s_result_PE150.read() + 1;
        reg18.range(479, 448) = s_result_PE151.read() + 1;
        reg18.range(511, 480) = s_result_PE151.read() + 1;
        s_result_all.write(reg18);

        reg19.range(31, 0) = s_result_PE152.read() + 1;
        reg19.range(63, 32) = s_result_PE152.read() + 1;
        reg19.range(95, 64) = s_result_PE153.read() + 1;
        reg19.range(127, 96) = s_result_PE153.read() + 1;
        reg19.range(159, 128) = s_result_PE154.read() + 1;
        reg19.range(191, 160) = s_result_PE154.read() + 1;
        reg19.range(223, 192) = s_result_PE155.read() + 1;
        reg19.range(255, 224) = s_result_PE155.read() + 1;
        reg19.range(287, 256) = s_result_PE156.read() + 1;
        reg19.range(319, 288) = s_result_PE156.read() + 1;
        reg19.range(351, 320) = s_result_PE157.read() + 1;
        reg19.range(383, 352) = s_result_PE157.read() + 1;
        reg19.range(415, 384) = s_result_PE158.read() + 1;
        reg19.range(447, 416) = s_result_PE158.read() + 1;
        reg19.range(479, 448) = s_result_PE159.read() + 1;
        reg19.range(511, 480) = s_result_PE159.read() + 1;
        s_result_all.write(reg19);

        reg20.range(31, 0) = s_result_PE160.read() + 1;
        reg20.range(63, 32) = s_result_PE160.read() + 1;
        reg20.range(95, 64) = s_result_PE161.read() + 1;
        reg20.range(127, 96) = s_result_PE161.read() + 1;
        reg20.range(159, 128) = s_result_PE162.read() + 1;
        reg20.range(191, 160) = s_result_PE162.read() + 1;
        reg20.range(223, 192) = s_result_PE163.read() + 1;
        reg20.range(255, 224) = s_result_PE163.read() + 1;
        reg20.range(287, 256) = s_result_PE164.read() + 1;
        reg20.range(319, 288) = s_result_PE164.read() + 1;
        reg20.range(351, 320) = s_result_PE165.read() + 1;
        reg20.range(383, 352) = s_result_PE165.read() + 1;
        reg20.range(415, 384) = s_result_PE166.read() + 1;
        reg20.range(447, 416) = s_result_PE166.read() + 1;
        reg20.range(479, 448) = s_result_PE167.read() + 1;
        reg20.range(511, 480) = s_result_PE167.read() + 1;
        s_result_all.write(reg20);

        reg21.range(31, 0) = s_result_PE168.read() + 1;
        reg21.range(63, 32) = s_result_PE168.read() + 1;
        reg21.range(95, 64) = s_result_PE169.read() + 1;
        reg21.range(127, 96) = s_result_PE169.read() + 1;
        reg21.range(159, 128) = s_result_PE170.read() + 1;
        reg21.range(191, 160) = s_result_PE170.read() + 1;
        reg21.range(223, 192) = s_result_PE171.read() + 1;
        reg21.range(255, 224) = s_result_PE171.read() + 1;
        reg21.range(287, 256) = s_result_PE172.read() + 1;
        reg21.range(319, 288) = s_result_PE172.read() + 1;
        reg21.range(351, 320) = s_result_PE173.read() + 1;
        reg21.range(383, 352) = s_result_PE173.read() + 1;
        reg21.range(415, 384) = s_result_PE174.read() + 1;
        reg21.range(447, 416) = s_result_PE174.read() + 1;
        reg21.range(479, 448) = s_result_PE175.read() + 1;
        reg21.range(511, 480) = s_result_PE175.read() + 1;
        s_result_all.write(reg21);

        reg22.range(31, 0) = s_result_PE176.read() + 1;
        reg22.range(63, 32) = s_result_PE176.read() + 1;
        reg22.range(95, 64) = s_result_PE177.read() + 1;
        reg22.range(127, 96) = s_result_PE177.read() + 1;
        reg22.range(159, 128) = s_result_PE178.read() + 1;
        reg22.range(191, 160) = s_result_PE178.read() + 1;
        reg22.range(223, 192) = s_result_PE179.read() + 1;
        reg22.range(255, 224) = s_result_PE179.read() + 1;
        reg22.range(287, 256) = s_result_PE180.read() + 1;
        reg22.range(319, 288) = s_result_PE180.read() + 1;
        reg22.range(351, 320) = s_result_PE181.read() + 1;
        reg22.range(383, 352) = s_result_PE181.read() + 1;
        reg22.range(415, 384) = s_result_PE182.read() + 1;
        reg22.range(447, 416) = s_result_PE182.read() + 1;
        reg22.range(479, 448) = s_result_PE183.read() + 1;
        reg22.range(511, 480) = s_result_PE183.read() + 1;
        s_result_all.write(reg22);

        reg23.range(31, 0) = s_result_PE184.read() + 1;
        reg23.range(63, 32) = s_result_PE184.read() + 1;
        reg23.range(95, 64) = s_result_PE185.read() + 1;
        reg23.range(127, 96) = s_result_PE185.read() + 1;
        reg23.range(159, 128) = s_result_PE186.read() + 1;
        reg23.range(191, 160) = s_result_PE186.read() + 1;
        reg23.range(223, 192) = s_result_PE187.read() + 1;
        reg23.range(255, 224) = s_result_PE187.read() + 1;
        reg23.range(287, 256) = s_result_PE188.read() + 1;
        reg23.range(319, 288) = s_result_PE188.read() + 1;
        reg23.range(351, 320) = s_result_PE189.read() + 1;
        reg23.range(383, 352) = s_result_PE189.read() + 1;
        reg23.range(415, 384) = s_result_PE190.read() + 1;
        reg23.range(447, 416) = s_result_PE190.read() + 1;
        reg23.range(479, 448) = s_result_PE191.read() + 1;
        reg23.range(511, 480) = s_result_PE191.read() + 1;
        s_result_all.write(reg23);

        reg24.range(31, 0) = s_result_PE192.read() + 1;
        reg24.range(63, 32) = s_result_PE192.read() + 1;
        reg24.range(95, 64) = s_result_PE193.read() + 1;
        reg24.range(127, 96) = s_result_PE193.read() + 1;
        reg24.range(159, 128) = s_result_PE194.read() + 1;
        reg24.range(191, 160) = s_result_PE194.read() + 1;
        reg24.range(223, 192) = s_result_PE195.read() + 1;
        reg24.range(255, 224) = s_result_PE195.read() + 1;
        reg24.range(287, 256) = s_result_PE196.read() + 1;
        reg24.range(319, 288) = s_result_PE196.read() + 1;
        reg24.range(351, 320) = s_result_PE197.read() + 1;
        reg24.range(383, 352) = s_result_PE197.read() + 1;
        reg24.range(415, 384) = s_result_PE198.read() + 1;
        reg24.range(447, 416) = s_result_PE198.read() + 1;
        reg24.range(479, 448) = s_result_PE199.read() + 1;
        reg24.range(511, 480) = s_result_PE199.read() + 1;
        s_result_all.write(reg24);

        reg25.range(31, 0)    = s_result_PE200.read() + 1;
        reg25.range(63, 32)   = s_result_PE200.read() + 1;
        reg25.range(95, 64)   = s_result_PE201.read() + 1;
        reg25.range(127, 96)  = s_result_PE201.read() + 1;
        reg25.range(159, 128) = s_result_PE202.read() + 1;
        reg25.range(191, 160) = s_result_PE202.read() + 1;
        reg25.range(223, 192) = s_result_PE203.read() + 1;
        reg25.range(255, 224) = s_result_PE203.read() + 1;
        reg25.range(287, 256) = s_result_PE204.read() + 1;
        reg25.range(319, 288) = s_result_PE204.read() + 1;
        reg25.range(351, 320) = s_result_PE205.read() + 1;
        reg25.range(383, 352) = s_result_PE205.read() + 1;
        reg25.range(415, 384) = s_result_PE206.read() + 1;
        reg25.range(447, 416) = s_result_PE206.read() + 1;
        reg25.range(479, 448) = s_result_PE207.read() + 1;
        reg25.range(511, 480) = s_result_PE207.read() + 1;
        s_result_all.write(reg25);

        reg26.range(31, 0)    = s_result_PE208.read() + 1;
        reg26.range(63, 32)   = s_result_PE208.read() + 1;
        reg26.range(95, 64)   = s_result_PE209.read() + 1;
        reg26.range(127, 96)  = s_result_PE209.read() + 1;
        reg26.range(159, 128) = s_result_PE210.read() + 1;
        reg26.range(191, 160) = s_result_PE210.read() + 1;
        reg26.range(223, 192) = s_result_PE211.read() + 1;
        reg26.range(255, 224) = s_result_PE211.read() + 1;
        reg26.range(287, 256) = s_result_PE212.read() + 1;
        reg26.range(319, 288) = s_result_PE212.read() + 1;
        reg26.range(351, 320) = s_result_PE213.read() + 1;
        reg26.range(383, 352) = s_result_PE213.read() + 1;
        reg26.range(415, 384) = s_result_PE214.read() + 1;
        reg26.range(447, 416) = s_result_PE214.read() + 1;
        reg26.range(479, 448) = s_result_PE215.read() + 1;
        reg26.range(511, 480) = s_result_PE215.read() + 1;
        s_result_all.write(reg26);

        reg27.range(31, 0) = s_result_PE216.read() + 1;
        reg27.range(63, 32) = s_result_PE216.read() + 1;
        reg27.range(95, 64) = s_result_PE217.read() + 1;
        reg27.range(127, 96) = s_result_PE217.read() + 1;
        reg27.range(159, 128) = s_result_PE218.read() + 1;
        reg27.range(191, 160) = s_result_PE218.read() + 1;
        reg27.range(223, 192) = s_result_PE219.read() + 1;
        reg27.range(255, 224) = s_result_PE219.read() + 1;
        reg27.range(287, 256) = s_result_PE220.read() + 1;
        reg27.range(319, 288) = s_result_PE220.read() + 1;
        reg27.range(351, 320) = s_result_PE221.read() + 1;
        reg27.range(383, 352) = s_result_PE221.read() + 1;
        reg27.range(415, 384) = s_result_PE222.read() + 1;
        reg27.range(447, 416) = s_result_PE222.read() + 1;
        reg27.range(479, 448) = s_result_PE223.read() + 1;
        reg27.range(511, 480) = s_result_PE223.read() + 1;
        s_result_all.write(reg27);

        reg28.range(31, 0) = s_result_PE224.read() + 1;
        reg28.range(63, 32) = s_result_PE224.read() + 1;
        reg28.range(95, 64) = s_result_PE225.read() + 1;
        reg28.range(127, 96) = s_result_PE225.read() + 1;
        reg28.range(159, 128) = s_result_PE226.read() + 1;
        reg28.range(191, 160) = s_result_PE226.read() + 1;
        reg28.range(223, 192) = s_result_PE227.read() + 1;
        reg28.range(255, 224) = s_result_PE227.read() + 1;
        reg28.range(287, 256) = s_result_PE228.read() + 1;
        reg28.range(319, 288) = s_result_PE228.read() + 1;
        reg28.range(351, 320) = s_result_PE229.read() + 1;
        reg28.range(383, 352) = s_result_PE229.read() + 1;
        reg28.range(415, 384) = s_result_PE230.read() + 1;
        reg28.range(447, 416) = s_result_PE230.read() + 1;
        reg28.range(479, 448) = s_result_PE231.read() + 1;
        reg28.range(511, 480) = s_result_PE231.read() + 1;
        s_result_all.write(reg28);

        reg29.range(31, 0) = s_result_PE232.read() + 1;
        reg29.range(63, 32) = s_result_PE232.read() + 1;
        reg29.range(95, 64) = s_result_PE233.read() + 1;
        reg29.range(127, 96) = s_result_PE233.read() + 1;
        reg29.range(159, 128) = s_result_PE234.read() + 1;
        reg29.range(191, 160) = s_result_PE234.read() + 1;
        reg29.range(223, 192) = s_result_PE235.read() + 1;
        reg29.range(255, 224) = s_result_PE235.read() + 1;
        reg29.range(287, 256) = s_result_PE236.read() + 1;
        reg29.range(319, 288) = s_result_PE236.read() + 1;
        reg29.range(351, 320) = s_result_PE237.read() + 1;
        reg29.range(383, 352) = s_result_PE237.read() + 1;
        reg29.range(415, 384) = s_result_PE238.read() + 1;
        reg29.range(447, 416) = s_result_PE238.read() + 1;
        reg29.range(479, 448) = s_result_PE239.read() + 1;
        reg29.range(511, 480) = s_result_PE239.read() + 1;
        s_result_all.write(reg29);

        reg30.range(31, 0) = s_result_PE240.read() + 1;
        reg30.range(63, 32) = s_result_PE240.read() + 1;
        reg30.range(95, 64) = s_result_PE241.read() + 1;
        reg30.range(127, 96) = s_result_PE241.read() + 1;
        reg30.range(159, 128) = s_result_PE242.read() + 1;
        reg30.range(191, 160) = s_result_PE242.read() + 1;
        reg30.range(223, 192) = s_result_PE243.read() + 1;
        reg30.range(255, 224) = s_result_PE243.read() + 1;
        reg30.range(287, 256) = s_result_PE244.read() + 1;
        reg30.range(319, 288) = s_result_PE244.read() + 1;
        reg30.range(351, 320) = s_result_PE245.read() + 1;
        reg30.range(383, 352) = s_result_PE245.read() + 1;
        reg30.range(415, 384) = s_result_PE246.read() + 1;
        reg30.range(447, 416) = s_result_PE246.read() + 1;
        reg30.range(479, 448) = s_result_PE247.read() + 1;
        reg30.range(511, 480) = s_result_PE247.read() + 1;
        s_result_all.write(reg30);

        reg31.range(31, 0) = s_result_PE248.read() + 1;
        reg31.range(63, 32) = s_result_PE248.read() + 1;
        reg31.range(95, 64) = s_result_PE249.read() + 1;
        reg31.range(127, 96) = s_result_PE249.read() + 1;
        reg31.range(159, 128) = s_result_PE250.read() + 1;
        reg31.range(191, 160) = s_result_PE250.read() + 1;
        reg31.range(223, 192) = s_result_PE251.read() + 1;
        reg31.range(255, 224) = s_result_PE251.read() + 1;
        reg31.range(287, 256) = s_result_PE252.read() + 1;
        reg31.range(319, 288) = s_result_PE252.read() + 1;
        reg31.range(351, 320) = s_result_PE253.read() + 1;
        reg31.range(383, 352) = s_result_PE253.read() + 1;
        reg31.range(415, 384) = s_result_PE254.read() + 1;
        reg31.range(447, 416) = s_result_PE254.read() + 1;
        reg31.range(479, 448) = s_result_PE255.read() + 1;
        reg31.range(511, 480) = s_result_PE255.read() + 1;
        s_result_all.write(reg31);
    }
}

template<const int ROW_PER_PE>
void gather_results_48PEs(
    STREAM<D_TYPE>& s_result_PE0, STREAM<D_TYPE>& s_result_PE1, 
    STREAM<D_TYPE>& s_result_PE2, STREAM<D_TYPE>& s_result_PE3, 
    STREAM<D_TYPE>& s_result_PE4, STREAM<D_TYPE>& s_result_PE5, 
    STREAM<D_TYPE>& s_result_PE6, STREAM<D_TYPE>& s_result_PE7, 
    STREAM<D_TYPE>& s_result_PE8, STREAM<D_TYPE>& s_result_PE9, 
    STREAM<D_TYPE>& s_result_PE10, STREAM<D_TYPE>& s_result_PE11, 
    STREAM<D_TYPE>& s_result_PE12, STREAM<D_TYPE>& s_result_PE13, 
    STREAM<D_TYPE>& s_result_PE14, STREAM<D_TYPE>& s_result_PE15, 
    STREAM<D_TYPE>& s_result_PE16, STREAM<D_TYPE>& s_result_PE17, 
    STREAM<D_TYPE>& s_result_PE18, STREAM<D_TYPE>& s_result_PE19, 
    STREAM<D_TYPE>& s_result_PE20, STREAM<D_TYPE>& s_result_PE21, 
    STREAM<D_TYPE>& s_result_PE22, STREAM<D_TYPE>& s_result_PE23, 
    STREAM<D_TYPE>& s_result_PE24, STREAM<D_TYPE>& s_result_PE25, 
    STREAM<D_TYPE>& s_result_PE26, STREAM<D_TYPE>& s_result_PE27, 
    STREAM<D_TYPE>& s_result_PE28, STREAM<D_TYPE>& s_result_PE29, 
    STREAM<D_TYPE>& s_result_PE30, STREAM<D_TYPE>& s_result_PE31, 
    STREAM<D_TYPE>& s_result_PE32, STREAM<D_TYPE>& s_result_PE33, 
    STREAM<D_TYPE>& s_result_PE34, STREAM<D_TYPE>& s_result_PE35, 
    STREAM<D_TYPE>& s_result_PE36, STREAM<D_TYPE>& s_result_PE37, 
    STREAM<D_TYPE>& s_result_PE38, STREAM<D_TYPE>& s_result_PE39, 
    STREAM<D_TYPE>& s_result_PE40, STREAM<D_TYPE>& s_result_PE41, 
    STREAM<D_TYPE>& s_result_PE42, STREAM<D_TYPE>& s_result_PE43, 
    STREAM<D_TYPE>& s_result_PE44, STREAM<D_TYPE>& s_result_PE45, 
    STREAM<D_TYPE>& s_result_PE46, STREAM<D_TYPE>& s_result_PE47, 
    STREAM<ap_uint<512> >& s_result_all) {
     
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        #pragma HLS pipeline II=3  // write 1 result_all per CC

        W_TYPE reg0, reg1, reg2;

        reg0.range(31, 0)    = s_result_PE0.read() + 1;
        reg0.range(63, 32)   = s_result_PE1.read() + 1;
        reg0.range(95, 64)   = s_result_PE2.read() + 1;
        reg0.range(127, 96)  = s_result_PE3.read() + 1;
        reg0.range(159, 128) = s_result_PE4.read() + 1;
        reg0.range(191, 160) = s_result_PE5.read() + 1;
        reg0.range(223, 192) = s_result_PE6.read() + 1;
        reg0.range(255, 224) = s_result_PE7.read() + 1;
        reg0.range(287, 256) = s_result_PE8.read() + 1;
        reg0.range(319, 288) = s_result_PE9.read() + 1;
        reg0.range(351, 320) = s_result_PE10.read() + 1;
        reg0.range(383, 352) = s_result_PE11.read() + 1;
        reg0.range(415, 384) = s_result_PE12.read() + 1;
        reg0.range(447, 416) = s_result_PE13.read() + 1;
        reg0.range(479, 448) = s_result_PE14.read() + 1;
        reg0.range(511, 480) = s_result_PE15.read() + 1;
        s_result_all.write(reg0);

        reg1.range(31, 0)    = s_result_PE16.read() + 1;
        reg1.range(63, 32)   = s_result_PE17.read() + 1;
        reg1.range(95, 64)   = s_result_PE18.read() + 1;
        reg1.range(127, 96)  = s_result_PE19.read() + 1;
        reg1.range(159, 128) = s_result_PE20.read() + 1;
        reg1.range(191, 160) = s_result_PE21.read() + 1;
        reg1.range(223, 192) = s_result_PE22.read() + 1;
        reg1.range(255, 224) = s_result_PE23.read() + 1;
        reg1.range(287, 256) = s_result_PE24.read() + 1;
        reg1.range(319, 288) = s_result_PE25.read() + 1;
        reg1.range(351, 320) = s_result_PE26.read() + 1;
        reg1.range(383, 352) = s_result_PE27.read() + 1;
        reg1.range(415, 384) = s_result_PE28.read() + 1;
        reg1.range(447, 416) = s_result_PE29.read() + 1;
        reg1.range(479, 448) = s_result_PE30.read() + 1;
        reg1.range(511, 480) = s_result_PE31.read() + 1;
        s_result_all.write(reg1);

        reg2.range(31, 0)    = s_result_PE32.read() + 1;
        reg2.range(63, 32)   = s_result_PE33.read() + 1;
        reg2.range(95, 64)   = s_result_PE34.read() + 1;
        reg2.range(127, 96)  = s_result_PE35.read() + 1;
        reg2.range(159, 128) = s_result_PE36.read() + 1;
        reg2.range(191, 160) = s_result_PE37.read() + 1;
        reg2.range(223, 192) = s_result_PE38.read() + 1;
        reg2.range(255, 224) = s_result_PE39.read() + 1;
        reg2.range(287, 256) = s_result_PE40.read() + 1;
        reg2.range(319, 288) = s_result_PE41.read() + 1;
        reg2.range(351, 320) = s_result_PE42.read() + 1;
        reg2.range(383, 352) = s_result_PE43.read() + 1;
        reg2.range(415, 384) = s_result_PE44.read() + 1;
        reg2.range(447, 416) = s_result_PE45.read() + 1;
        reg2.range(479, 448) = s_result_PE46.read() + 1;
        reg2.range(511, 480) = s_result_PE47.read() + 1;
        s_result_all.write(reg2);
    }
}

template<const int ROW_PER_PE>
void gather_results_32PEs(
    STREAM<D_TYPE>& s_result_PE0, STREAM<D_TYPE>& s_result_PE1, 
    STREAM<D_TYPE>& s_result_PE2, STREAM<D_TYPE>& s_result_PE3, 
    STREAM<D_TYPE>& s_result_PE4, STREAM<D_TYPE>& s_result_PE5, 
    STREAM<D_TYPE>& s_result_PE6, STREAM<D_TYPE>& s_result_PE7, 
    STREAM<D_TYPE>& s_result_PE8, STREAM<D_TYPE>& s_result_PE9, 
    STREAM<D_TYPE>& s_result_PE10, STREAM<D_TYPE>& s_result_PE11, 
    STREAM<D_TYPE>& s_result_PE12, STREAM<D_TYPE>& s_result_PE13, 
    STREAM<D_TYPE>& s_result_PE14, STREAM<D_TYPE>& s_result_PE15, 
    STREAM<D_TYPE>& s_result_PE16, STREAM<D_TYPE>& s_result_PE17, 
    STREAM<D_TYPE>& s_result_PE18, STREAM<D_TYPE>& s_result_PE19, 
    STREAM<D_TYPE>& s_result_PE20, STREAM<D_TYPE>& s_result_PE21, 
    STREAM<D_TYPE>& s_result_PE22, STREAM<D_TYPE>& s_result_PE23, 
    STREAM<D_TYPE>& s_result_PE24, STREAM<D_TYPE>& s_result_PE25, 
    STREAM<D_TYPE>& s_result_PE26, STREAM<D_TYPE>& s_result_PE27, 
    STREAM<D_TYPE>& s_result_PE28, STREAM<D_TYPE>& s_result_PE29, 
    STREAM<D_TYPE>& s_result_PE30, STREAM<D_TYPE>& s_result_PE31, 
    STREAM<ap_uint<512> >& s_result_all) {
     
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {

        for (int j = 0; j < ROW_PER_PE; j++) {
            #pragma HLS pipeline II=2  // write 1 result_all per CC

            ap_uint<512> reg0, reg1;

            reg0.range(31, 0)    = s_result_PE0.read() + 1;
            reg0.range(63, 32)   = s_result_PE1.read() + 1;
            reg0.range(95, 64)   = s_result_PE2.read() + 1;
            reg0.range(127, 96)  = s_result_PE3.read() + 1;
            reg0.range(159, 128) = s_result_PE4.read() + 1;
            reg0.range(191, 160) = s_result_PE5.read() + 1;
            reg0.range(223, 192) = s_result_PE6.read() + 1;
            reg0.range(255, 224) = s_result_PE7.read() + 1;
            reg0.range(287, 256) = s_result_PE8.read() + 1;
            reg0.range(319, 288) = s_result_PE9.read() + 1;
            reg0.range(351, 320) = s_result_PE10.read() + 1;
            reg0.range(383, 352) = s_result_PE11.read() + 1;
            reg0.range(415, 384) = s_result_PE12.read() + 1;
            reg0.range(447, 416) = s_result_PE13.read() + 1;
            reg0.range(479, 448) = s_result_PE14.read() + 1;
            reg0.range(511, 480) = s_result_PE15.read() + 1;
            s_result_all.write(reg0);

            reg1.range(31, 0)    = s_result_PE16.read() + 1;
            reg1.range(63, 32)   = s_result_PE17.read() + 1;
            reg1.range(95, 64)   = s_result_PE18.read() + 1;
            reg1.range(127, 96)  = s_result_PE19.read() + 1;
            reg1.range(159, 128) = s_result_PE20.read() + 1;
            reg1.range(191, 160) = s_result_PE21.read() + 1;
            reg1.range(223, 192) = s_result_PE22.read() + 1;
            reg1.range(255, 224) = s_result_PE23.read() + 1;
            reg1.range(287, 256) = s_result_PE24.read() + 1;
            reg1.range(319, 288) = s_result_PE25.read() + 1;
            reg1.range(351, 320) = s_result_PE26.read() + 1;
            reg1.range(383, 352) = s_result_PE27.read() + 1;
            reg1.range(415, 384) = s_result_PE28.read() + 1;
            reg1.range(447, 416) = s_result_PE29.read() + 1;
            reg1.range(479, 448) = s_result_PE30.read() + 1;
            reg1.range(511, 480) = s_result_PE31.read() + 1;
            s_result_all.write(reg1);
        }
        #ifndef ACCL_SYNTHESIS
            std::cout <<"reduce root gather_results_32PEs item:"<<item<<std::endl;
        #endif
    }
}

template<const int ROW_PER_PE>
void gather_results_208PEs(
    STREAM<D_TYPE>& s_result_PE0, STREAM<D_TYPE>& s_result_PE1, 
    STREAM<D_TYPE>& s_result_PE2, STREAM<D_TYPE>& s_result_PE3, 
    STREAM<D_TYPE>& s_result_PE4, STREAM<D_TYPE>& s_result_PE5, 
    STREAM<D_TYPE>& s_result_PE6, STREAM<D_TYPE>& s_result_PE7, 
    STREAM<D_TYPE>& s_result_PE8, STREAM<D_TYPE>& s_result_PE9, 
    STREAM<D_TYPE>& s_result_PE10, STREAM<D_TYPE>& s_result_PE11, 
    STREAM<D_TYPE>& s_result_PE12, STREAM<D_TYPE>& s_result_PE13, 
    STREAM<D_TYPE>& s_result_PE14, STREAM<D_TYPE>& s_result_PE15, 
    STREAM<D_TYPE>& s_result_PE16, STREAM<D_TYPE>& s_result_PE17, 
    STREAM<D_TYPE>& s_result_PE18, STREAM<D_TYPE>& s_result_PE19, 
    STREAM<D_TYPE>& s_result_PE20, STREAM<D_TYPE>& s_result_PE21, 
    STREAM<D_TYPE>& s_result_PE22, STREAM<D_TYPE>& s_result_PE23, 
    STREAM<D_TYPE>& s_result_PE24, STREAM<D_TYPE>& s_result_PE25, 
    STREAM<D_TYPE>& s_result_PE26, STREAM<D_TYPE>& s_result_PE27, 
    STREAM<D_TYPE>& s_result_PE28, STREAM<D_TYPE>& s_result_PE29, 
    STREAM<D_TYPE>& s_result_PE30, STREAM<D_TYPE>& s_result_PE31, 
    STREAM<D_TYPE>& s_result_PE32, STREAM<D_TYPE>& s_result_PE33, 
    STREAM<D_TYPE>& s_result_PE34, STREAM<D_TYPE>& s_result_PE35, 
    STREAM<D_TYPE>& s_result_PE36, STREAM<D_TYPE>& s_result_PE37, 
    STREAM<D_TYPE>& s_result_PE38, STREAM<D_TYPE>& s_result_PE39, 
    STREAM<D_TYPE>& s_result_PE40, STREAM<D_TYPE>& s_result_PE41, 
    STREAM<D_TYPE>& s_result_PE42, STREAM<D_TYPE>& s_result_PE43, 
    STREAM<D_TYPE>& s_result_PE44, STREAM<D_TYPE>& s_result_PE45, 
    STREAM<D_TYPE>& s_result_PE46, STREAM<D_TYPE>& s_result_PE47, 
    STREAM<D_TYPE>& s_result_PE48, STREAM<D_TYPE>& s_result_PE49, 
    STREAM<D_TYPE>& s_result_PE50, STREAM<D_TYPE>& s_result_PE51, 
    STREAM<D_TYPE>& s_result_PE52, STREAM<D_TYPE>& s_result_PE53, 
    STREAM<D_TYPE>& s_result_PE54, STREAM<D_TYPE>& s_result_PE55, 
    STREAM<D_TYPE>& s_result_PE56, STREAM<D_TYPE>& s_result_PE57, 
    STREAM<D_TYPE>& s_result_PE58, STREAM<D_TYPE>& s_result_PE59, 
    STREAM<D_TYPE>& s_result_PE60, STREAM<D_TYPE>& s_result_PE61, 
    STREAM<D_TYPE>& s_result_PE62, STREAM<D_TYPE>& s_result_PE63, 
    STREAM<D_TYPE>& s_result_PE64, STREAM<D_TYPE>& s_result_PE65, 
    STREAM<D_TYPE>& s_result_PE66, STREAM<D_TYPE>& s_result_PE67, 
    STREAM<D_TYPE>& s_result_PE68, STREAM<D_TYPE>& s_result_PE69, 
    STREAM<D_TYPE>& s_result_PE70, STREAM<D_TYPE>& s_result_PE71, 
    STREAM<D_TYPE>& s_result_PE72, STREAM<D_TYPE>& s_result_PE73, 
    STREAM<D_TYPE>& s_result_PE74, STREAM<D_TYPE>& s_result_PE75, 
    STREAM<D_TYPE>& s_result_PE76, STREAM<D_TYPE>& s_result_PE77, 
    STREAM<D_TYPE>& s_result_PE78, STREAM<D_TYPE>& s_result_PE79, 
    STREAM<D_TYPE>& s_result_PE80, STREAM<D_TYPE>& s_result_PE81, 
    STREAM<D_TYPE>& s_result_PE82, STREAM<D_TYPE>& s_result_PE83, 
    STREAM<D_TYPE>& s_result_PE84, STREAM<D_TYPE>& s_result_PE85, 
    STREAM<D_TYPE>& s_result_PE86, STREAM<D_TYPE>& s_result_PE87, 
    STREAM<D_TYPE>& s_result_PE88, STREAM<D_TYPE>& s_result_PE89, 
    STREAM<D_TYPE>& s_result_PE90, STREAM<D_TYPE>& s_result_PE91, 
    STREAM<D_TYPE>& s_result_PE92, STREAM<D_TYPE>& s_result_PE93, 
    STREAM<D_TYPE>& s_result_PE94, STREAM<D_TYPE>& s_result_PE95, 
    STREAM<D_TYPE>& s_result_PE96, STREAM<D_TYPE>& s_result_PE97, 
    STREAM<D_TYPE>& s_result_PE98, STREAM<D_TYPE>& s_result_PE99, 
    STREAM<D_TYPE>& s_result_PE100, STREAM<D_TYPE>& s_result_PE101, 
    STREAM<D_TYPE>& s_result_PE102, STREAM<D_TYPE>& s_result_PE103, 
    STREAM<D_TYPE>& s_result_PE104, STREAM<D_TYPE>& s_result_PE105, 
    STREAM<D_TYPE>& s_result_PE106, STREAM<D_TYPE>& s_result_PE107, 
    STREAM<D_TYPE>& s_result_PE108, STREAM<D_TYPE>& s_result_PE109, 
    STREAM<D_TYPE>& s_result_PE110, STREAM<D_TYPE>& s_result_PE111, 
    STREAM<D_TYPE>& s_result_PE112, STREAM<D_TYPE>& s_result_PE113, 
    STREAM<D_TYPE>& s_result_PE114, STREAM<D_TYPE>& s_result_PE115, 
    STREAM<D_TYPE>& s_result_PE116, STREAM<D_TYPE>& s_result_PE117, 
    STREAM<D_TYPE>& s_result_PE118, STREAM<D_TYPE>& s_result_PE119, 
    STREAM<D_TYPE>& s_result_PE120, STREAM<D_TYPE>& s_result_PE121, 
    STREAM<D_TYPE>& s_result_PE122, STREAM<D_TYPE>& s_result_PE123, 
    STREAM<D_TYPE>& s_result_PE124, STREAM<D_TYPE>& s_result_PE125, 
    STREAM<D_TYPE>& s_result_PE126, STREAM<D_TYPE>& s_result_PE127, 
    STREAM<D_TYPE>& s_result_PE128, STREAM<D_TYPE>& s_result_PE129,
    STREAM<D_TYPE>& s_result_PE130, STREAM<D_TYPE>& s_result_PE131,
    STREAM<D_TYPE>& s_result_PE132, STREAM<D_TYPE>& s_result_PE133,
    STREAM<D_TYPE>& s_result_PE134, STREAM<D_TYPE>& s_result_PE135,
    STREAM<D_TYPE>& s_result_PE136, STREAM<D_TYPE>& s_result_PE137,
    STREAM<D_TYPE>& s_result_PE138, STREAM<D_TYPE>& s_result_PE139,
    STREAM<D_TYPE>& s_result_PE140, STREAM<D_TYPE>& s_result_PE141,
    STREAM<D_TYPE>& s_result_PE142, STREAM<D_TYPE>& s_result_PE143,
    STREAM<D_TYPE>& s_result_PE144, STREAM<D_TYPE>& s_result_PE145,
    STREAM<D_TYPE>& s_result_PE146, STREAM<D_TYPE>& s_result_PE147,
    STREAM<D_TYPE>& s_result_PE148, STREAM<D_TYPE>& s_result_PE149,
    STREAM<D_TYPE>& s_result_PE150, STREAM<D_TYPE>& s_result_PE151,
    STREAM<D_TYPE>& s_result_PE152, STREAM<D_TYPE>& s_result_PE153,
    STREAM<D_TYPE>& s_result_PE154, STREAM<D_TYPE>& s_result_PE155,
    STREAM<D_TYPE>& s_result_PE156, STREAM<D_TYPE>& s_result_PE157,
    STREAM<D_TYPE>& s_result_PE158, STREAM<D_TYPE>& s_result_PE159,
    STREAM<D_TYPE>& s_result_PE160, STREAM<D_TYPE>& s_result_PE161,
    STREAM<D_TYPE>& s_result_PE162, STREAM<D_TYPE>& s_result_PE163,
    STREAM<D_TYPE>& s_result_PE164, STREAM<D_TYPE>& s_result_PE165,
    STREAM<D_TYPE>& s_result_PE166, STREAM<D_TYPE>& s_result_PE167,
    STREAM<D_TYPE>& s_result_PE168, STREAM<D_TYPE>& s_result_PE169,
    STREAM<D_TYPE>& s_result_PE170, STREAM<D_TYPE>& s_result_PE171,
    STREAM<D_TYPE>& s_result_PE172, STREAM<D_TYPE>& s_result_PE173,
    STREAM<D_TYPE>& s_result_PE174, STREAM<D_TYPE>& s_result_PE175,
    STREAM<D_TYPE>& s_result_PE176, STREAM<D_TYPE>& s_result_PE177,
    STREAM<D_TYPE>& s_result_PE178, STREAM<D_TYPE>& s_result_PE179,
    STREAM<D_TYPE>& s_result_PE180, STREAM<D_TYPE>& s_result_PE181,
    STREAM<D_TYPE>& s_result_PE182, STREAM<D_TYPE>& s_result_PE183,
    STREAM<D_TYPE>& s_result_PE184, STREAM<D_TYPE>& s_result_PE185,
    STREAM<D_TYPE>& s_result_PE186, STREAM<D_TYPE>& s_result_PE187,
    STREAM<D_TYPE>& s_result_PE188, STREAM<D_TYPE>& s_result_PE189,
    STREAM<D_TYPE>& s_result_PE190, STREAM<D_TYPE>& s_result_PE191,
    STREAM<D_TYPE>& s_result_PE192, STREAM<D_TYPE>& s_result_PE193,
    STREAM<D_TYPE>& s_result_PE194, STREAM<D_TYPE>& s_result_PE195,
    STREAM<D_TYPE>& s_result_PE196, STREAM<D_TYPE>& s_result_PE197,
    STREAM<D_TYPE>& s_result_PE198, STREAM<D_TYPE>& s_result_PE199,
    STREAM<D_TYPE>& s_result_PE200, STREAM<D_TYPE>& s_result_PE201, 
    STREAM<D_TYPE>& s_result_PE202, STREAM<D_TYPE>& s_result_PE203, 
    STREAM<D_TYPE>& s_result_PE204, STREAM<D_TYPE>& s_result_PE205, 
    STREAM<D_TYPE>& s_result_PE206, STREAM<D_TYPE>& s_result_PE207, 
    STREAM<ap_uint<512> >& s_result_all) {
     
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        #pragma HLS pipeline II=13  // write 1 result_all per CC

        ap_uint<512> reg0, reg1, reg2, reg3, reg4, reg5, reg6, reg7, 
            reg8, reg9, reg10, reg11, reg12;

        reg0.range(31, 0)    = s_result_PE0.read() + 1;
        reg0.range(63, 32)   = s_result_PE1.read() + 1;
        reg0.range(95, 64)   = s_result_PE2.read() + 1;
        reg0.range(127, 96)  = s_result_PE3.read() + 1;
        reg0.range(159, 128) = s_result_PE4.read() + 1;
        reg0.range(191, 160) = s_result_PE5.read() + 1;
        reg0.range(223, 192) = s_result_PE6.read() + 1;
        reg0.range(255, 224) = s_result_PE7.read() + 1;
        reg0.range(287, 256) = s_result_PE8.read() + 1;
        reg0.range(319, 288) = s_result_PE9.read() + 1;
        reg0.range(351, 320) = s_result_PE10.read() + 1;
        reg0.range(383, 352) = s_result_PE11.read() + 1;
        reg0.range(415, 384) = s_result_PE12.read() + 1;
        reg0.range(447, 416) = s_result_PE13.read() + 1;
        reg0.range(479, 448) = s_result_PE14.read() + 1;
        reg0.range(511, 480) = s_result_PE15.read() + 1;
        s_result_all.write(reg0);

        reg1.range(31, 0)    = s_result_PE16.read() + 1;
        reg1.range(63, 32)   = s_result_PE17.read() + 1;
        reg1.range(95, 64)   = s_result_PE18.read() + 1;
        reg1.range(127, 96)  = s_result_PE19.read() + 1;
        reg1.range(159, 128) = s_result_PE20.read() + 1;
        reg1.range(191, 160) = s_result_PE21.read() + 1;
        reg1.range(223, 192) = s_result_PE22.read() + 1;
        reg1.range(255, 224) = s_result_PE23.read() + 1;
        reg1.range(287, 256) = s_result_PE24.read() + 1;
        reg1.range(319, 288) = s_result_PE25.read() + 1;
        reg1.range(351, 320) = s_result_PE26.read() + 1;
        reg1.range(383, 352) = s_result_PE27.read() + 1;
        reg1.range(415, 384) = s_result_PE28.read() + 1;
        reg1.range(447, 416) = s_result_PE29.read() + 1;
        reg1.range(479, 448) = s_result_PE30.read() + 1;
        reg1.range(511, 480) = s_result_PE31.read() + 1;
        s_result_all.write(reg1);

        reg2.range(31, 0)    = s_result_PE32.read() + 1;
        reg2.range(63, 32)   = s_result_PE33.read() + 1;
        reg2.range(95, 64)   = s_result_PE34.read() + 1;
        reg2.range(127, 96)  = s_result_PE35.read() + 1;
        reg2.range(159, 128) = s_result_PE36.read() + 1;
        reg2.range(191, 160) = s_result_PE37.read() + 1;
        reg2.range(223, 192) = s_result_PE38.read() + 1;
        reg2.range(255, 224) = s_result_PE39.read() + 1;
        reg2.range(287, 256) = s_result_PE40.read() + 1;
        reg2.range(319, 288) = s_result_PE41.read() + 1;
        reg2.range(351, 320) = s_result_PE42.read() + 1;
        reg2.range(383, 352) = s_result_PE43.read() + 1;
        reg2.range(415, 384) = s_result_PE44.read() + 1;
        reg2.range(447, 416) = s_result_PE45.read() + 1;
        reg2.range(479, 448) = s_result_PE46.read() + 1;
        reg2.range(511, 480) = s_result_PE47.read() + 1;
        s_result_all.write(reg2);

        reg3.range(31, 0)    = s_result_PE48.read() + 1;
        reg3.range(63, 32)   = s_result_PE49.read() + 1;
        reg3.range(95, 64)   = s_result_PE50.read() + 1;
        reg3.range(127, 96)  = s_result_PE51.read() + 1;
        reg3.range(159, 128) = s_result_PE52.read() + 1;
        reg3.range(191, 160) = s_result_PE53.read() + 1;
        reg3.range(223, 192) = s_result_PE54.read() + 1;
        reg3.range(255, 224) = s_result_PE55.read() + 1;
        reg3.range(287, 256) = s_result_PE56.read() + 1;
        reg3.range(319, 288) = s_result_PE57.read() + 1;
        reg3.range(351, 320) = s_result_PE58.read() + 1;
        reg3.range(383, 352) = s_result_PE59.read() + 1;
        reg3.range(415, 384) = s_result_PE60.read() + 1;
        reg3.range(447, 416) = s_result_PE61.read() + 1;
        reg3.range(479, 448) = s_result_PE62.read() + 1;
        reg3.range(511, 480) = s_result_PE63.read() + 1;
        s_result_all.write(reg3);

        reg4.range(31, 0)    = s_result_PE64.read() + 1;
        reg4.range(63, 32)   = s_result_PE65.read() + 1;
        reg4.range(95, 64)   = s_result_PE66.read() + 1;
        reg4.range(127, 96)  = s_result_PE67.read() + 1;
        reg4.range(159, 128) = s_result_PE68.read() + 1;
        reg4.range(191, 160) = s_result_PE69.read() + 1;
        reg4.range(223, 192) = s_result_PE70.read() + 1;
        reg4.range(255, 224) = s_result_PE71.read() + 1;
        reg4.range(287, 256) = s_result_PE72.read() + 1;
        reg4.range(319, 288) = s_result_PE73.read() + 1;
        reg4.range(351, 320) = s_result_PE74.read() + 1;
        reg4.range(383, 352) = s_result_PE75.read() + 1;
        reg4.range(415, 384) = s_result_PE76.read() + 1;
        reg4.range(447, 416) = s_result_PE77.read() + 1;
        reg4.range(479, 448) = s_result_PE78.read() + 1;
        reg4.range(511, 480) = s_result_PE79.read() + 1;
        s_result_all.write(reg4);

        reg5.range(31, 0)    = s_result_PE80.read() + 1;
        reg5.range(63, 32)   = s_result_PE81.read() + 1;
        reg5.range(95, 64)   = s_result_PE82.read() + 1;
        reg5.range(127, 96)  = s_result_PE83.read() + 1;
        reg5.range(159, 128) = s_result_PE84.read() + 1;
        reg5.range(191, 160) = s_result_PE85.read() + 1;
        reg5.range(223, 192) = s_result_PE86.read() + 1;
        reg5.range(255, 224) = s_result_PE87.read() + 1;
        reg5.range(287, 256) = s_result_PE88.read() + 1;
        reg5.range(319, 288) = s_result_PE89.read() + 1;
        reg5.range(351, 320) = s_result_PE90.read() + 1;
        reg5.range(383, 352) = s_result_PE91.read() + 1;
        reg5.range(415, 384) = s_result_PE92.read() + 1;
        reg5.range(447, 416) = s_result_PE93.read() + 1;
        reg5.range(479, 448) = s_result_PE94.read() + 1;
        reg5.range(511, 480) = s_result_PE95.read() + 1;
        s_result_all.write(reg5);

        reg6.range(31, 0)    = s_result_PE96.read() + 1;
        reg6.range(63, 32)   = s_result_PE97.read() + 1;
        reg6.range(95, 64)   = s_result_PE98.read() + 1;
        reg6.range(127, 96)  = s_result_PE99.read() + 1;
        reg6.range(159, 128) = s_result_PE100.read() + 1;
        reg6.range(191, 160) = s_result_PE101.read() + 1;
        reg6.range(223, 192) = s_result_PE102.read() + 1;
        reg6.range(255, 224) = s_result_PE103.read() + 1;
        reg6.range(287, 256) = s_result_PE104.read() + 1;
        reg6.range(319, 288) = s_result_PE105.read() + 1;
        reg6.range(351, 320) = s_result_PE106.read() + 1;
        reg6.range(383, 352) = s_result_PE107.read() + 1;
        reg6.range(415, 384) = s_result_PE108.read() + 1;
        reg6.range(447, 416) = s_result_PE109.read() + 1;
        reg6.range(479, 448) = s_result_PE110.read() + 1;
        reg6.range(511, 480) = s_result_PE111.read() + 1;
        s_result_all.write(reg6);

        reg7.range(31, 0)    = s_result_PE112.read() + 1;
        reg7.range(63, 32)   = s_result_PE113.read() + 1;
        reg7.range(95, 64)   = s_result_PE114.read() + 1;
        reg7.range(127, 96)  = s_result_PE115.read() + 1;
        reg7.range(159, 128) = s_result_PE116.read() + 1;
        reg7.range(191, 160) = s_result_PE117.read() + 1;
        reg7.range(223, 192) = s_result_PE118.read() + 1;
        reg7.range(255, 224) = s_result_PE119.read() + 1;
        reg7.range(287, 256) = s_result_PE120.read() + 1;
        reg7.range(319, 288) = s_result_PE121.read() + 1;
        reg7.range(351, 320) = s_result_PE122.read() + 1;
        reg7.range(383, 352) = s_result_PE123.read() + 1;
        reg7.range(415, 384) = s_result_PE124.read() + 1;
        reg7.range(447, 416) = s_result_PE125.read() + 1;
        reg7.range(479, 448) = s_result_PE126.read() + 1;
        reg7.range(511, 480) = s_result_PE127.read() + 1;
        s_result_all.write(reg7);

        reg8.range(31, 0)    = s_result_PE128.read() + 1;
        reg8.range(63, 32)   = s_result_PE129.read() + 1;
        reg8.range(95, 64)   = s_result_PE130.read() + 1;
        reg8.range(127, 96)  = s_result_PE131.read() + 1;
        reg8.range(159, 128) = s_result_PE132.read() + 1;
        reg8.range(191, 160) = s_result_PE133.read() + 1;
        reg8.range(223, 192) = s_result_PE134.read() + 1;
        reg8.range(255, 224) = s_result_PE135.read() + 1;
        reg8.range(287, 256) = s_result_PE136.read() + 1;
        reg8.range(319, 288) = s_result_PE137.read() + 1;
        reg8.range(351, 320) = s_result_PE138.read() + 1;
        reg8.range(383, 352) = s_result_PE139.read() + 1;
        reg8.range(415, 384) = s_result_PE140.read() + 1;
        reg8.range(447, 416) = s_result_PE141.read() + 1;
        reg8.range(479, 448) = s_result_PE142.read() + 1;
        reg8.range(511, 480) = s_result_PE143.read() + 1;
        s_result_all.write(reg8);

        reg9.range(31, 0)    = s_result_PE144.read() + 1;
        reg9.range(63, 32)   = s_result_PE145.read() + 1;
        reg9.range(95, 64)   = s_result_PE146.read() + 1;
        reg9.range(127, 96)  = s_result_PE147.read() + 1;
        reg9.range(159, 128) = s_result_PE148.read() + 1;
        reg9.range(191, 160) = s_result_PE149.read() + 1;
        reg9.range(223, 192) = s_result_PE150.read() + 1;
        reg9.range(255, 224) = s_result_PE151.read() + 1;
        reg9.range(287, 256) = s_result_PE152.read() + 1;
        reg9.range(319, 288) = s_result_PE153.read() + 1;
        reg9.range(351, 320) = s_result_PE154.read() + 1;
        reg9.range(383, 352) = s_result_PE155.read() + 1;
        reg9.range(415, 384) = s_result_PE156.read() + 1;
        reg9.range(447, 416) = s_result_PE157.read() + 1;
        reg9.range(479, 448) = s_result_PE158.read() + 1;
        reg9.range(511, 480) = s_result_PE159.read() + 1;
        s_result_all.write(reg9);

        reg10.range(31, 0)    = s_result_PE160.read() + 1;
        reg10.range(63, 32)   = s_result_PE161.read() + 1;
        reg10.range(95, 64)   = s_result_PE162.read() + 1;
        reg10.range(127, 96)  = s_result_PE163.read() + 1;
        reg10.range(159, 128) = s_result_PE164.read() + 1;
        reg10.range(191, 160) = s_result_PE165.read() + 1;
        reg10.range(223, 192) = s_result_PE166.read() + 1;
        reg10.range(255, 224) = s_result_PE167.read() + 1;
        reg10.range(287, 256) = s_result_PE168.read() + 1;
        reg10.range(319, 288) = s_result_PE169.read() + 1;
        reg10.range(351, 320) = s_result_PE170.read() + 1;
        reg10.range(383, 352) = s_result_PE171.read() + 1;
        reg10.range(415, 384) = s_result_PE172.read() + 1;
        reg10.range(447, 416) = s_result_PE173.read() + 1;
        reg10.range(479, 448) = s_result_PE174.read() + 1;
        reg10.range(511, 480) = s_result_PE175.read() + 1;
        s_result_all.write(reg10);

        reg11.range(31, 0)    = s_result_PE176.read() + 1;
        reg11.range(63, 32)   = s_result_PE177.read() + 1;
        reg11.range(95, 64)   = s_result_PE178.read() + 1;
        reg11.range(127, 96)  = s_result_PE179.read() + 1;
        reg11.range(159, 128) = s_result_PE180.read() + 1;
        reg11.range(191, 160) = s_result_PE181.read() + 1;
        reg11.range(223, 192) = s_result_PE182.read() + 1;
        reg11.range(255, 224) = s_result_PE183.read() + 1;
        reg11.range(287, 256) = s_result_PE184.read() + 1;
        reg11.range(319, 288) = s_result_PE185.read() + 1;
        reg11.range(351, 320) = s_result_PE186.read() + 1;
        reg11.range(383, 352) = s_result_PE187.read() + 1;
        reg11.range(415, 384) = s_result_PE188.read() + 1;
        reg11.range(447, 416) = s_result_PE189.read() + 1;
        reg11.range(479, 448) = s_result_PE190.read() + 1;
        reg11.range(511, 480) = s_result_PE191.read() + 1;
        s_result_all.write(reg11);

        reg12.range(31, 0)    = s_result_PE192.read() + 1;
        reg12.range(63, 32)   = s_result_PE193.read() + 1;
        reg12.range(95, 64)   = s_result_PE194.read() + 1;
        reg12.range(127, 96)  = s_result_PE195.read() + 1;
        reg12.range(159, 128) = s_result_PE196.read() + 1;
        reg12.range(191, 160) = s_result_PE197.read() + 1;
        reg12.range(223, 192) = s_result_PE198.read() + 1;
        reg12.range(255, 224) = s_result_PE199.read() + 1;
        reg12.range(287, 256) = s_result_PE200.read() + 1;
        reg12.range(319, 288) = s_result_PE201.read() + 1;
        reg12.range(351, 320) = s_result_PE202.read() + 1;
        reg12.range(383, 352) = s_result_PE203.read() + 1;
        reg12.range(415, 384) = s_result_PE204.read() + 1;
        reg12.range(447, 416) = s_result_PE205.read() + 1;
        reg12.range(479, 448) = s_result_PE206.read() + 1;
        reg12.range(511, 480) = s_result_PE207.read() + 1;
        s_result_all.write(reg12);
    }
}

template<const int ROW_PER_PE>
void gather_results_416PEs(
    STREAM<D_TYPE>& s_result_PE0, STREAM<D_TYPE>& s_result_PE1, 
    STREAM<D_TYPE>& s_result_PE2, STREAM<D_TYPE>& s_result_PE3, 
    STREAM<D_TYPE>& s_result_PE4, STREAM<D_TYPE>& s_result_PE5, 
    STREAM<D_TYPE>& s_result_PE6, STREAM<D_TYPE>& s_result_PE7, 
    STREAM<D_TYPE>& s_result_PE8, STREAM<D_TYPE>& s_result_PE9, 
    STREAM<D_TYPE>& s_result_PE10, STREAM<D_TYPE>& s_result_PE11, 
    STREAM<D_TYPE>& s_result_PE12, STREAM<D_TYPE>& s_result_PE13, 
    STREAM<D_TYPE>& s_result_PE14, STREAM<D_TYPE>& s_result_PE15, 
    STREAM<D_TYPE>& s_result_PE16, STREAM<D_TYPE>& s_result_PE17, 
    STREAM<D_TYPE>& s_result_PE18, STREAM<D_TYPE>& s_result_PE19, 
    STREAM<D_TYPE>& s_result_PE20, STREAM<D_TYPE>& s_result_PE21, 
    STREAM<D_TYPE>& s_result_PE22, STREAM<D_TYPE>& s_result_PE23, 
    STREAM<D_TYPE>& s_result_PE24, STREAM<D_TYPE>& s_result_PE25, 
    STREAM<D_TYPE>& s_result_PE26, STREAM<D_TYPE>& s_result_PE27, 
    STREAM<D_TYPE>& s_result_PE28, STREAM<D_TYPE>& s_result_PE29, 
    STREAM<D_TYPE>& s_result_PE30, STREAM<D_TYPE>& s_result_PE31, 
    STREAM<D_TYPE>& s_result_PE32, STREAM<D_TYPE>& s_result_PE33, 
    STREAM<D_TYPE>& s_result_PE34, STREAM<D_TYPE>& s_result_PE35, 
    STREAM<D_TYPE>& s_result_PE36, STREAM<D_TYPE>& s_result_PE37, 
    STREAM<D_TYPE>& s_result_PE38, STREAM<D_TYPE>& s_result_PE39, 
    STREAM<D_TYPE>& s_result_PE40, STREAM<D_TYPE>& s_result_PE41, 
    STREAM<D_TYPE>& s_result_PE42, STREAM<D_TYPE>& s_result_PE43, 
    STREAM<D_TYPE>& s_result_PE44, STREAM<D_TYPE>& s_result_PE45, 
    STREAM<D_TYPE>& s_result_PE46, STREAM<D_TYPE>& s_result_PE47, 
    STREAM<D_TYPE>& s_result_PE48, STREAM<D_TYPE>& s_result_PE49, 
    STREAM<D_TYPE>& s_result_PE50, STREAM<D_TYPE>& s_result_PE51, 
    STREAM<D_TYPE>& s_result_PE52, STREAM<D_TYPE>& s_result_PE53, 
    STREAM<D_TYPE>& s_result_PE54, STREAM<D_TYPE>& s_result_PE55, 
    STREAM<D_TYPE>& s_result_PE56, STREAM<D_TYPE>& s_result_PE57, 
    STREAM<D_TYPE>& s_result_PE58, STREAM<D_TYPE>& s_result_PE59, 
    STREAM<D_TYPE>& s_result_PE60, STREAM<D_TYPE>& s_result_PE61, 
    STREAM<D_TYPE>& s_result_PE62, STREAM<D_TYPE>& s_result_PE63, 
    STREAM<D_TYPE>& s_result_PE64, STREAM<D_TYPE>& s_result_PE65, 
    STREAM<D_TYPE>& s_result_PE66, STREAM<D_TYPE>& s_result_PE67, 
    STREAM<D_TYPE>& s_result_PE68, STREAM<D_TYPE>& s_result_PE69, 
    STREAM<D_TYPE>& s_result_PE70, STREAM<D_TYPE>& s_result_PE71, 
    STREAM<D_TYPE>& s_result_PE72, STREAM<D_TYPE>& s_result_PE73, 
    STREAM<D_TYPE>& s_result_PE74, STREAM<D_TYPE>& s_result_PE75, 
    STREAM<D_TYPE>& s_result_PE76, STREAM<D_TYPE>& s_result_PE77, 
    STREAM<D_TYPE>& s_result_PE78, STREAM<D_TYPE>& s_result_PE79, 
    STREAM<D_TYPE>& s_result_PE80, STREAM<D_TYPE>& s_result_PE81, 
    STREAM<D_TYPE>& s_result_PE82, STREAM<D_TYPE>& s_result_PE83, 
    STREAM<D_TYPE>& s_result_PE84, STREAM<D_TYPE>& s_result_PE85, 
    STREAM<D_TYPE>& s_result_PE86, STREAM<D_TYPE>& s_result_PE87, 
    STREAM<D_TYPE>& s_result_PE88, STREAM<D_TYPE>& s_result_PE89, 
    STREAM<D_TYPE>& s_result_PE90, STREAM<D_TYPE>& s_result_PE91, 
    STREAM<D_TYPE>& s_result_PE92, STREAM<D_TYPE>& s_result_PE93, 
    STREAM<D_TYPE>& s_result_PE94, STREAM<D_TYPE>& s_result_PE95, 
    STREAM<D_TYPE>& s_result_PE96, STREAM<D_TYPE>& s_result_PE97, 
    STREAM<D_TYPE>& s_result_PE98, STREAM<D_TYPE>& s_result_PE99, 
    STREAM<D_TYPE>& s_result_PE100, STREAM<D_TYPE>& s_result_PE101, 
    STREAM<D_TYPE>& s_result_PE102, STREAM<D_TYPE>& s_result_PE103, 
    STREAM<D_TYPE>& s_result_PE104, STREAM<D_TYPE>& s_result_PE105, 
    STREAM<D_TYPE>& s_result_PE106, STREAM<D_TYPE>& s_result_PE107, 
    STREAM<D_TYPE>& s_result_PE108, STREAM<D_TYPE>& s_result_PE109, 
    STREAM<D_TYPE>& s_result_PE110, STREAM<D_TYPE>& s_result_PE111, 
    STREAM<D_TYPE>& s_result_PE112, STREAM<D_TYPE>& s_result_PE113, 
    STREAM<D_TYPE>& s_result_PE114, STREAM<D_TYPE>& s_result_PE115, 
    STREAM<D_TYPE>& s_result_PE116, STREAM<D_TYPE>& s_result_PE117, 
    STREAM<D_TYPE>& s_result_PE118, STREAM<D_TYPE>& s_result_PE119, 
    STREAM<D_TYPE>& s_result_PE120, STREAM<D_TYPE>& s_result_PE121, 
    STREAM<D_TYPE>& s_result_PE122, STREAM<D_TYPE>& s_result_PE123, 
    STREAM<D_TYPE>& s_result_PE124, STREAM<D_TYPE>& s_result_PE125, 
    STREAM<D_TYPE>& s_result_PE126, STREAM<D_TYPE>& s_result_PE127, 
    STREAM<D_TYPE>& s_result_PE128, STREAM<D_TYPE>& s_result_PE129,
    STREAM<D_TYPE>& s_result_PE130, STREAM<D_TYPE>& s_result_PE131,
    STREAM<D_TYPE>& s_result_PE132, STREAM<D_TYPE>& s_result_PE133,
    STREAM<D_TYPE>& s_result_PE134, STREAM<D_TYPE>& s_result_PE135,
    STREAM<D_TYPE>& s_result_PE136, STREAM<D_TYPE>& s_result_PE137,
    STREAM<D_TYPE>& s_result_PE138, STREAM<D_TYPE>& s_result_PE139,
    STREAM<D_TYPE>& s_result_PE140, STREAM<D_TYPE>& s_result_PE141,
    STREAM<D_TYPE>& s_result_PE142, STREAM<D_TYPE>& s_result_PE143,
    STREAM<D_TYPE>& s_result_PE144, STREAM<D_TYPE>& s_result_PE145,
    STREAM<D_TYPE>& s_result_PE146, STREAM<D_TYPE>& s_result_PE147,
    STREAM<D_TYPE>& s_result_PE148, STREAM<D_TYPE>& s_result_PE149,
    STREAM<D_TYPE>& s_result_PE150, STREAM<D_TYPE>& s_result_PE151,
    STREAM<D_TYPE>& s_result_PE152, STREAM<D_TYPE>& s_result_PE153,
    STREAM<D_TYPE>& s_result_PE154, STREAM<D_TYPE>& s_result_PE155,
    STREAM<D_TYPE>& s_result_PE156, STREAM<D_TYPE>& s_result_PE157,
    STREAM<D_TYPE>& s_result_PE158, STREAM<D_TYPE>& s_result_PE159,
    STREAM<D_TYPE>& s_result_PE160, STREAM<D_TYPE>& s_result_PE161,
    STREAM<D_TYPE>& s_result_PE162, STREAM<D_TYPE>& s_result_PE163,
    STREAM<D_TYPE>& s_result_PE164, STREAM<D_TYPE>& s_result_PE165,
    STREAM<D_TYPE>& s_result_PE166, STREAM<D_TYPE>& s_result_PE167,
    STREAM<D_TYPE>& s_result_PE168, STREAM<D_TYPE>& s_result_PE169,
    STREAM<D_TYPE>& s_result_PE170, STREAM<D_TYPE>& s_result_PE171,
    STREAM<D_TYPE>& s_result_PE172, STREAM<D_TYPE>& s_result_PE173,
    STREAM<D_TYPE>& s_result_PE174, STREAM<D_TYPE>& s_result_PE175,
    STREAM<D_TYPE>& s_result_PE176, STREAM<D_TYPE>& s_result_PE177,
    STREAM<D_TYPE>& s_result_PE178, STREAM<D_TYPE>& s_result_PE179,
    STREAM<D_TYPE>& s_result_PE180, STREAM<D_TYPE>& s_result_PE181,
    STREAM<D_TYPE>& s_result_PE182, STREAM<D_TYPE>& s_result_PE183,
    STREAM<D_TYPE>& s_result_PE184, STREAM<D_TYPE>& s_result_PE185,
    STREAM<D_TYPE>& s_result_PE186, STREAM<D_TYPE>& s_result_PE187,
    STREAM<D_TYPE>& s_result_PE188, STREAM<D_TYPE>& s_result_PE189,
    STREAM<D_TYPE>& s_result_PE190, STREAM<D_TYPE>& s_result_PE191,
    STREAM<D_TYPE>& s_result_PE192, STREAM<D_TYPE>& s_result_PE193,
    STREAM<D_TYPE>& s_result_PE194, STREAM<D_TYPE>& s_result_PE195,
    STREAM<D_TYPE>& s_result_PE196, STREAM<D_TYPE>& s_result_PE197,
    STREAM<D_TYPE>& s_result_PE198, STREAM<D_TYPE>& s_result_PE199,
    STREAM<D_TYPE>& s_result_PE200, STREAM<D_TYPE>& s_result_PE201, 
    STREAM<D_TYPE>& s_result_PE202, STREAM<D_TYPE>& s_result_PE203, 
    STREAM<D_TYPE>& s_result_PE204, STREAM<D_TYPE>& s_result_PE205, 
    STREAM<D_TYPE>& s_result_PE206, STREAM<D_TYPE>& s_result_PE207, 
    STREAM<D_TYPE>& s_result_PE208, STREAM<D_TYPE>& s_result_PE209, 
    STREAM<D_TYPE>& s_result_PE210, STREAM<D_TYPE>& s_result_PE211, 
    STREAM<D_TYPE>& s_result_PE212, STREAM<D_TYPE>& s_result_PE213, 
    STREAM<D_TYPE>& s_result_PE214, STREAM<D_TYPE>& s_result_PE215,
    STREAM<D_TYPE>& s_result_PE216, STREAM<D_TYPE>& s_result_PE217, 
    STREAM<D_TYPE>& s_result_PE218, STREAM<D_TYPE>& s_result_PE219, 
    STREAM<D_TYPE>& s_result_PE220, STREAM<D_TYPE>& s_result_PE221, 
    STREAM<D_TYPE>& s_result_PE222, STREAM<D_TYPE>& s_result_PE223, 
    STREAM<D_TYPE>& s_result_PE224, STREAM<D_TYPE>& s_result_PE225, 
    STREAM<D_TYPE>& s_result_PE226, STREAM<D_TYPE>& s_result_PE227,
    STREAM<D_TYPE>& s_result_PE228, STREAM<D_TYPE>& s_result_PE229,
    STREAM<D_TYPE>& s_result_PE230, STREAM<D_TYPE>& s_result_PE231,
    STREAM<D_TYPE>& s_result_PE232, STREAM<D_TYPE>& s_result_PE233,
    STREAM<D_TYPE>& s_result_PE234, STREAM<D_TYPE>& s_result_PE235,
    STREAM<D_TYPE>& s_result_PE236, STREAM<D_TYPE>& s_result_PE237,
    STREAM<D_TYPE>& s_result_PE238, STREAM<D_TYPE>& s_result_PE239,
    STREAM<D_TYPE>& s_result_PE240, STREAM<D_TYPE>& s_result_PE241,
    STREAM<D_TYPE>& s_result_PE242, STREAM<D_TYPE>& s_result_PE243,
    STREAM<D_TYPE>& s_result_PE244, STREAM<D_TYPE>& s_result_PE245,
    STREAM<D_TYPE>& s_result_PE246, STREAM<D_TYPE>& s_result_PE247,
    STREAM<D_TYPE>& s_result_PE248, STREAM<D_TYPE>& s_result_PE249,
    STREAM<D_TYPE>& s_result_PE250, STREAM<D_TYPE>& s_result_PE251,
    STREAM<D_TYPE>& s_result_PE252, STREAM<D_TYPE>& s_result_PE253,
    STREAM<D_TYPE>& s_result_PE254, STREAM<D_TYPE>& s_result_PE255,
    STREAM<D_TYPE>& s_result_PE256, STREAM<D_TYPE>& s_result_PE257,
    STREAM<D_TYPE>& s_result_PE258, STREAM<D_TYPE>& s_result_PE259,
    STREAM<D_TYPE>& s_result_PE260, STREAM<D_TYPE>& s_result_PE261,
    STREAM<D_TYPE>& s_result_PE262, STREAM<D_TYPE>& s_result_PE263,
    STREAM<D_TYPE>& s_result_PE264, STREAM<D_TYPE>& s_result_PE265,
    STREAM<D_TYPE>& s_result_PE266, STREAM<D_TYPE>& s_result_PE267,
    STREAM<D_TYPE>& s_result_PE268, STREAM<D_TYPE>& s_result_PE269,
    STREAM<D_TYPE>& s_result_PE270, STREAM<D_TYPE>& s_result_PE271,
    STREAM<D_TYPE>& s_result_PE272, STREAM<D_TYPE>& s_result_PE273,
    STREAM<D_TYPE>& s_result_PE274, STREAM<D_TYPE>& s_result_PE275,
    STREAM<D_TYPE>& s_result_PE276, STREAM<D_TYPE>& s_result_PE277,
    STREAM<D_TYPE>& s_result_PE278, STREAM<D_TYPE>& s_result_PE279,
    STREAM<D_TYPE>& s_result_PE280, STREAM<D_TYPE>& s_result_PE281,
    STREAM<D_TYPE>& s_result_PE282, STREAM<D_TYPE>& s_result_PE283,
    STREAM<D_TYPE>& s_result_PE284, STREAM<D_TYPE>& s_result_PE285,
    STREAM<D_TYPE>& s_result_PE286, STREAM<D_TYPE>& s_result_PE287,
    STREAM<D_TYPE>& s_result_PE288, STREAM<D_TYPE>& s_result_PE289,
    STREAM<D_TYPE>& s_result_PE290, STREAM<D_TYPE>& s_result_PE291,
    STREAM<D_TYPE>& s_result_PE292, STREAM<D_TYPE>& s_result_PE293,
    STREAM<D_TYPE>& s_result_PE294, STREAM<D_TYPE>& s_result_PE295,
    STREAM<D_TYPE>& s_result_PE296, STREAM<D_TYPE>& s_result_PE297,
    STREAM<D_TYPE>& s_result_PE298, STREAM<D_TYPE>& s_result_PE299,
    STREAM<D_TYPE>& s_result_PE300, STREAM<D_TYPE>& s_result_PE301,
    STREAM<D_TYPE>& s_result_PE302, STREAM<D_TYPE>& s_result_PE303,
    STREAM<D_TYPE>& s_result_PE304, STREAM<D_TYPE>& s_result_PE305,
    STREAM<D_TYPE>& s_result_PE306, STREAM<D_TYPE>& s_result_PE307,
    STREAM<D_TYPE>& s_result_PE308, STREAM<D_TYPE>& s_result_PE309,
    STREAM<D_TYPE>& s_result_PE310, STREAM<D_TYPE>& s_result_PE311,
    STREAM<D_TYPE>& s_result_PE312, STREAM<D_TYPE>& s_result_PE313,
    STREAM<D_TYPE>& s_result_PE314, STREAM<D_TYPE>& s_result_PE315,
    STREAM<D_TYPE>& s_result_PE316, STREAM<D_TYPE>& s_result_PE317,
    STREAM<D_TYPE>& s_result_PE318, STREAM<D_TYPE>& s_result_PE319,
    STREAM<D_TYPE>& s_result_PE320, STREAM<D_TYPE>& s_result_PE321,
    STREAM<D_TYPE>& s_result_PE322, STREAM<D_TYPE>& s_result_PE323,
    STREAM<D_TYPE>& s_result_PE324, STREAM<D_TYPE>& s_result_PE325,
    STREAM<D_TYPE>& s_result_PE326, STREAM<D_TYPE>& s_result_PE327,
    STREAM<D_TYPE>& s_result_PE328, STREAM<D_TYPE>& s_result_PE329,
    STREAM<D_TYPE>& s_result_PE330, STREAM<D_TYPE>& s_result_PE331,
    STREAM<D_TYPE>& s_result_PE332, STREAM<D_TYPE>& s_result_PE333,
    STREAM<D_TYPE>& s_result_PE334, STREAM<D_TYPE>& s_result_PE335,
    STREAM<D_TYPE>& s_result_PE336, STREAM<D_TYPE>& s_result_PE337,
    STREAM<D_TYPE>& s_result_PE338, STREAM<D_TYPE>& s_result_PE339,
    STREAM<D_TYPE>& s_result_PE340, STREAM<D_TYPE>& s_result_PE341,
    STREAM<D_TYPE>& s_result_PE342, STREAM<D_TYPE>& s_result_PE343,
    STREAM<D_TYPE>& s_result_PE344, STREAM<D_TYPE>& s_result_PE345,
    STREAM<D_TYPE>& s_result_PE346, STREAM<D_TYPE>& s_result_PE347,
    STREAM<D_TYPE>& s_result_PE348, STREAM<D_TYPE>& s_result_PE349,
    STREAM<D_TYPE>& s_result_PE350, STREAM<D_TYPE>& s_result_PE351,
    STREAM<D_TYPE>& s_result_PE352, STREAM<D_TYPE>& s_result_PE353,
    STREAM<D_TYPE>& s_result_PE354, STREAM<D_TYPE>& s_result_PE355,
    STREAM<D_TYPE>& s_result_PE356, STREAM<D_TYPE>& s_result_PE357,
    STREAM<D_TYPE>& s_result_PE358, STREAM<D_TYPE>& s_result_PE359,
    STREAM<D_TYPE>& s_result_PE360, STREAM<D_TYPE>& s_result_PE361,
    STREAM<D_TYPE>& s_result_PE362, STREAM<D_TYPE>& s_result_PE363,
    STREAM<D_TYPE>& s_result_PE364, STREAM<D_TYPE>& s_result_PE365,
    STREAM<D_TYPE>& s_result_PE366, STREAM<D_TYPE>& s_result_PE367,
    STREAM<D_TYPE>& s_result_PE368, STREAM<D_TYPE>& s_result_PE369,
    STREAM<D_TYPE>& s_result_PE370, STREAM<D_TYPE>& s_result_PE371,
    STREAM<D_TYPE>& s_result_PE372, STREAM<D_TYPE>& s_result_PE373,
    STREAM<D_TYPE>& s_result_PE374, STREAM<D_TYPE>& s_result_PE375,
    STREAM<D_TYPE>& s_result_PE376, STREAM<D_TYPE>& s_result_PE377,
    STREAM<D_TYPE>& s_result_PE378, STREAM<D_TYPE>& s_result_PE379,
    STREAM<D_TYPE>& s_result_PE380, STREAM<D_TYPE>& s_result_PE381,
    STREAM<D_TYPE>& s_result_PE382, STREAM<D_TYPE>& s_result_PE383,
    STREAM<D_TYPE>& s_result_PE384, STREAM<D_TYPE>& s_result_PE385,
    STREAM<D_TYPE>& s_result_PE386, STREAM<D_TYPE>& s_result_PE387,
    STREAM<D_TYPE>& s_result_PE388, STREAM<D_TYPE>& s_result_PE389,
    STREAM<D_TYPE>& s_result_PE390, STREAM<D_TYPE>& s_result_PE391,
    STREAM<D_TYPE>& s_result_PE392, STREAM<D_TYPE>& s_result_PE393,
    STREAM<D_TYPE>& s_result_PE394, STREAM<D_TYPE>& s_result_PE395,
    STREAM<D_TYPE>& s_result_PE396, STREAM<D_TYPE>& s_result_PE397,
    STREAM<D_TYPE>& s_result_PE398, STREAM<D_TYPE>& s_result_PE399,
    STREAM<D_TYPE>& s_result_PE400, STREAM<D_TYPE>& s_result_PE401,
    STREAM<D_TYPE>& s_result_PE402, STREAM<D_TYPE>& s_result_PE403,
    STREAM<D_TYPE>& s_result_PE404, STREAM<D_TYPE>& s_result_PE405,
    STREAM<D_TYPE>& s_result_PE406, STREAM<D_TYPE>& s_result_PE407,
    STREAM<D_TYPE>& s_result_PE408, STREAM<D_TYPE>& s_result_PE409,
    STREAM<D_TYPE>& s_result_PE410, STREAM<D_TYPE>& s_result_PE411,
    STREAM<D_TYPE>& s_result_PE412, STREAM<D_TYPE>& s_result_PE413,
    STREAM<D_TYPE>& s_result_PE414, STREAM<D_TYPE>& s_result_PE415,
    STREAM<ap_uint<512> >& s_result_all) {
     
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        #pragma HLS pipeline II=26  // write 1 result_all per CC

        ap_uint<512> reg0, reg1, reg2, reg3, reg4, reg5, reg6, reg7, 
            reg8, reg9, reg10, reg11, reg12, reg13, reg14, reg15, 
            reg16, reg17, reg18, reg19, reg20, reg21, reg22, reg23, 
            reg24, reg25;

    //print("        reg",str(i),".range(31, 0)    = s_result_PE",str(16*i),".read() + 1;",sep='')
    //print("        reg",str(i),".range(63, 32)   = s_result_PE",str(16*i+1),".read() + 1;",sep='')
    //print("        reg",str(i),".range(95, 64)   = s_result_PE",str(16*i+2),".read() + 1;",sep='')
    //print("        reg",str(i),".range(127, 96)  = s_result_PE",str(16*i+3),".read() + 1;",sep='')
    //print("        reg",str(i),".range(159, 128) = s_result_PE",str(16*i+4),".read() + 1;",sep='')
    //print("        reg",str(i),".range(191, 160) = s_result_PE",str(16*i+5),".read() + 1;",sep='')
    //print("        reg",str(i),".range(223, 192) = s_result_PE",str(16*i+6),".read() + 1;",sep='')
    //print("        reg",str(i),".range(255, 224) = s_result_PE",str(16*i+7),".read() + 1;",sep='')
    //print("        reg",str(i),".range(287, 256) = s_result_PE",str(16*i+8),".read() + 1;",sep='')
    //print("        reg",str(i),".range(319, 288) = s_result_PE",str(16*i+9),".read() + 1;",sep='')
    //print("        reg",str(i),".range(351, 320) = s_result_PE",str(16*i+10),".read() + 1;",sep='')
    //print("        reg",str(i),".range(383, 352) = s_result_PE",str(16*i+11),".read() + 1;",sep='')
    //print("        reg",str(i),".range(415, 384) = s_result_PE",str(16*i+12),".read() + 1;",sep='')
    //print("        reg",str(i),".range(447, 416) = s_result_PE",str(16*i+13),".read() + 1;",sep='')
    //print("        reg",str(i),".range(479, 448) = s_result_PE",str(16*i+14),".read() + 1;",sep='')
    //print("        reg",str(i),".range(511, 480) = s_result_PE",str(16*i+15),".read() + 1;",sep='')

        reg0.range(31, 0)    = s_result_PE0.read() + 1;
        reg0.range(63, 32)   = s_result_PE1.read() + 1;
        reg0.range(95, 64)   = s_result_PE2.read() + 1;
        reg0.range(127, 96)  = s_result_PE3.read() + 1;
        reg0.range(159, 128) = s_result_PE4.read() + 1;
        reg0.range(191, 160) = s_result_PE5.read() + 1;
        reg0.range(223, 192) = s_result_PE6.read() + 1;
        reg0.range(255, 224) = s_result_PE7.read() + 1;
        reg0.range(287, 256) = s_result_PE8.read() + 1;
        reg0.range(319, 288) = s_result_PE9.read() + 1;
        reg0.range(351, 320) = s_result_PE10.read() + 1;
        reg0.range(383, 352) = s_result_PE11.read() + 1;
        reg0.range(415, 384) = s_result_PE12.read() + 1;
        reg0.range(447, 416) = s_result_PE13.read() + 1;
        reg0.range(479, 448) = s_result_PE14.read() + 1;
        reg0.range(511, 480) = s_result_PE15.read() + 1;
        s_result_all.write(reg0);

        reg1.range(31, 0)    = s_result_PE16.read() + 1;
        reg1.range(63, 32)   = s_result_PE17.read() + 1;
        reg1.range(95, 64)   = s_result_PE18.read() + 1;
        reg1.range(127, 96)  = s_result_PE19.read() + 1;
        reg1.range(159, 128) = s_result_PE20.read() + 1;
        reg1.range(191, 160) = s_result_PE21.read() + 1;
        reg1.range(223, 192) = s_result_PE22.read() + 1;
        reg1.range(255, 224) = s_result_PE23.read() + 1;
        reg1.range(287, 256) = s_result_PE24.read() + 1;
        reg1.range(319, 288) = s_result_PE25.read() + 1;
        reg1.range(351, 320) = s_result_PE26.read() + 1;
        reg1.range(383, 352) = s_result_PE27.read() + 1;
        reg1.range(415, 384) = s_result_PE28.read() + 1;
        reg1.range(447, 416) = s_result_PE29.read() + 1;
        reg1.range(479, 448) = s_result_PE30.read() + 1;
        reg1.range(511, 480) = s_result_PE31.read() + 1;
        s_result_all.write(reg1);

        reg2.range(31, 0)    = s_result_PE32.read() + 1;
        reg2.range(63, 32)   = s_result_PE33.read() + 1;
        reg2.range(95, 64)   = s_result_PE34.read() + 1;
        reg2.range(127, 96)  = s_result_PE35.read() + 1;
        reg2.range(159, 128) = s_result_PE36.read() + 1;
        reg2.range(191, 160) = s_result_PE37.read() + 1;
        reg2.range(223, 192) = s_result_PE38.read() + 1;
        reg2.range(255, 224) = s_result_PE39.read() + 1;
        reg2.range(287, 256) = s_result_PE40.read() + 1;
        reg2.range(319, 288) = s_result_PE41.read() + 1;
        reg2.range(351, 320) = s_result_PE42.read() + 1;
        reg2.range(383, 352) = s_result_PE43.read() + 1;
        reg2.range(415, 384) = s_result_PE44.read() + 1;
        reg2.range(447, 416) = s_result_PE45.read() + 1;
        reg2.range(479, 448) = s_result_PE46.read() + 1;
        reg2.range(511, 480) = s_result_PE47.read() + 1;
        s_result_all.write(reg2);

        reg3.range(31, 0)    = s_result_PE48.read() + 1;
        reg3.range(63, 32)   = s_result_PE49.read() + 1;
        reg3.range(95, 64)   = s_result_PE50.read() + 1;
        reg3.range(127, 96)  = s_result_PE51.read() + 1;
        reg3.range(159, 128) = s_result_PE52.read() + 1;
        reg3.range(191, 160) = s_result_PE53.read() + 1;
        reg3.range(223, 192) = s_result_PE54.read() + 1;
        reg3.range(255, 224) = s_result_PE55.read() + 1;
        reg3.range(287, 256) = s_result_PE56.read() + 1;
        reg3.range(319, 288) = s_result_PE57.read() + 1;
        reg3.range(351, 320) = s_result_PE58.read() + 1;
        reg3.range(383, 352) = s_result_PE59.read() + 1;
        reg3.range(415, 384) = s_result_PE60.read() + 1;
        reg3.range(447, 416) = s_result_PE61.read() + 1;
        reg3.range(479, 448) = s_result_PE62.read() + 1;
        reg3.range(511, 480) = s_result_PE63.read() + 1;
        s_result_all.write(reg3);

        reg4.range(31, 0)    = s_result_PE64.read() + 1;
        reg4.range(63, 32)   = s_result_PE65.read() + 1;
        reg4.range(95, 64)   = s_result_PE66.read() + 1;
        reg4.range(127, 96)  = s_result_PE67.read() + 1;
        reg4.range(159, 128) = s_result_PE68.read() + 1;
        reg4.range(191, 160) = s_result_PE69.read() + 1;
        reg4.range(223, 192) = s_result_PE70.read() + 1;
        reg4.range(255, 224) = s_result_PE71.read() + 1;
        reg4.range(287, 256) = s_result_PE72.read() + 1;
        reg4.range(319, 288) = s_result_PE73.read() + 1;
        reg4.range(351, 320) = s_result_PE74.read() + 1;
        reg4.range(383, 352) = s_result_PE75.read() + 1;
        reg4.range(415, 384) = s_result_PE76.read() + 1;
        reg4.range(447, 416) = s_result_PE77.read() + 1;
        reg4.range(479, 448) = s_result_PE78.read() + 1;
        reg4.range(511, 480) = s_result_PE79.read() + 1;
        s_result_all.write(reg4);

        reg5.range(31, 0)    = s_result_PE80.read() + 1;
        reg5.range(63, 32)   = s_result_PE81.read() + 1;
        reg5.range(95, 64)   = s_result_PE82.read() + 1;
        reg5.range(127, 96)  = s_result_PE83.read() + 1;
        reg5.range(159, 128) = s_result_PE84.read() + 1;
        reg5.range(191, 160) = s_result_PE85.read() + 1;
        reg5.range(223, 192) = s_result_PE86.read() + 1;
        reg5.range(255, 224) = s_result_PE87.read() + 1;
        reg5.range(287, 256) = s_result_PE88.read() + 1;
        reg5.range(319, 288) = s_result_PE89.read() + 1;
        reg5.range(351, 320) = s_result_PE90.read() + 1;
        reg5.range(383, 352) = s_result_PE91.read() + 1;
        reg5.range(415, 384) = s_result_PE92.read() + 1;
        reg5.range(447, 416) = s_result_PE93.read() + 1;
        reg5.range(479, 448) = s_result_PE94.read() + 1;
        reg5.range(511, 480) = s_result_PE95.read() + 1;
        s_result_all.write(reg5);

        reg6.range(31, 0)    = s_result_PE96.read() + 1;
        reg6.range(63, 32)   = s_result_PE97.read() + 1;
        reg6.range(95, 64)   = s_result_PE98.read() + 1;
        reg6.range(127, 96)  = s_result_PE99.read() + 1;
        reg6.range(159, 128) = s_result_PE100.read() + 1;
        reg6.range(191, 160) = s_result_PE101.read() + 1;
        reg6.range(223, 192) = s_result_PE102.read() + 1;
        reg6.range(255, 224) = s_result_PE103.read() + 1;
        reg6.range(287, 256) = s_result_PE104.read() + 1;
        reg6.range(319, 288) = s_result_PE105.read() + 1;
        reg6.range(351, 320) = s_result_PE106.read() + 1;
        reg6.range(383, 352) = s_result_PE107.read() + 1;
        reg6.range(415, 384) = s_result_PE108.read() + 1;
        reg6.range(447, 416) = s_result_PE109.read() + 1;
        reg6.range(479, 448) = s_result_PE110.read() + 1;
        reg6.range(511, 480) = s_result_PE111.read() + 1;
        s_result_all.write(reg6);

        reg7.range(31, 0)    = s_result_PE112.read() + 1;
        reg7.range(63, 32)   = s_result_PE113.read() + 1;
        reg7.range(95, 64)   = s_result_PE114.read() + 1;
        reg7.range(127, 96)  = s_result_PE115.read() + 1;
        reg7.range(159, 128) = s_result_PE116.read() + 1;
        reg7.range(191, 160) = s_result_PE117.read() + 1;
        reg7.range(223, 192) = s_result_PE118.read() + 1;
        reg7.range(255, 224) = s_result_PE119.read() + 1;
        reg7.range(287, 256) = s_result_PE120.read() + 1;
        reg7.range(319, 288) = s_result_PE121.read() + 1;
        reg7.range(351, 320) = s_result_PE122.read() + 1;
        reg7.range(383, 352) = s_result_PE123.read() + 1;
        reg7.range(415, 384) = s_result_PE124.read() + 1;
        reg7.range(447, 416) = s_result_PE125.read() + 1;
        reg7.range(479, 448) = s_result_PE126.read() + 1;
        reg7.range(511, 480) = s_result_PE127.read() + 1;
        s_result_all.write(reg7);

        reg8.range(31, 0)    = s_result_PE128.read() + 1;
        reg8.range(63, 32)   = s_result_PE129.read() + 1;
        reg8.range(95, 64)   = s_result_PE130.read() + 1;
        reg8.range(127, 96)  = s_result_PE131.read() + 1;
        reg8.range(159, 128) = s_result_PE132.read() + 1;
        reg8.range(191, 160) = s_result_PE133.read() + 1;
        reg8.range(223, 192) = s_result_PE134.read() + 1;
        reg8.range(255, 224) = s_result_PE135.read() + 1;
        reg8.range(287, 256) = s_result_PE136.read() + 1;
        reg8.range(319, 288) = s_result_PE137.read() + 1;
        reg8.range(351, 320) = s_result_PE138.read() + 1;
        reg8.range(383, 352) = s_result_PE139.read() + 1;
        reg8.range(415, 384) = s_result_PE140.read() + 1;
        reg8.range(447, 416) = s_result_PE141.read() + 1;
        reg8.range(479, 448) = s_result_PE142.read() + 1;
        reg8.range(511, 480) = s_result_PE143.read() + 1;
        s_result_all.write(reg8);

        reg9.range(31, 0)    = s_result_PE144.read() + 1;
        reg9.range(63, 32)   = s_result_PE145.read() + 1;
        reg9.range(95, 64)   = s_result_PE146.read() + 1;
        reg9.range(127, 96)  = s_result_PE147.read() + 1;
        reg9.range(159, 128) = s_result_PE148.read() + 1;
        reg9.range(191, 160) = s_result_PE149.read() + 1;
        reg9.range(223, 192) = s_result_PE150.read() + 1;
        reg9.range(255, 224) = s_result_PE151.read() + 1;
        reg9.range(287, 256) = s_result_PE152.read() + 1;
        reg9.range(319, 288) = s_result_PE153.read() + 1;
        reg9.range(351, 320) = s_result_PE154.read() + 1;
        reg9.range(383, 352) = s_result_PE155.read() + 1;
        reg9.range(415, 384) = s_result_PE156.read() + 1;
        reg9.range(447, 416) = s_result_PE157.read() + 1;
        reg9.range(479, 448) = s_result_PE158.read() + 1;
        reg9.range(511, 480) = s_result_PE159.read() + 1;
        s_result_all.write(reg9);

        reg10.range(31, 0)    = s_result_PE160.read() + 1;
        reg10.range(63, 32)   = s_result_PE161.read() + 1;
        reg10.range(95, 64)   = s_result_PE162.read() + 1;
        reg10.range(127, 96)  = s_result_PE163.read() + 1;
        reg10.range(159, 128) = s_result_PE164.read() + 1;
        reg10.range(191, 160) = s_result_PE165.read() + 1;
        reg10.range(223, 192) = s_result_PE166.read() + 1;
        reg10.range(255, 224) = s_result_PE167.read() + 1;
        reg10.range(287, 256) = s_result_PE168.read() + 1;
        reg10.range(319, 288) = s_result_PE169.read() + 1;
        reg10.range(351, 320) = s_result_PE170.read() + 1;
        reg10.range(383, 352) = s_result_PE171.read() + 1;
        reg10.range(415, 384) = s_result_PE172.read() + 1;
        reg10.range(447, 416) = s_result_PE173.read() + 1;
        reg10.range(479, 448) = s_result_PE174.read() + 1;
        reg10.range(511, 480) = s_result_PE175.read() + 1;
        s_result_all.write(reg10);

        reg11.range(31, 0)    = s_result_PE176.read() + 1;
        reg11.range(63, 32)   = s_result_PE177.read() + 1;
        reg11.range(95, 64)   = s_result_PE178.read() + 1;
        reg11.range(127, 96)  = s_result_PE179.read() + 1;
        reg11.range(159, 128) = s_result_PE180.read() + 1;
        reg11.range(191, 160) = s_result_PE181.read() + 1;
        reg11.range(223, 192) = s_result_PE182.read() + 1;
        reg11.range(255, 224) = s_result_PE183.read() + 1;
        reg11.range(287, 256) = s_result_PE184.read() + 1;
        reg11.range(319, 288) = s_result_PE185.read() + 1;
        reg11.range(351, 320) = s_result_PE186.read() + 1;
        reg11.range(383, 352) = s_result_PE187.read() + 1;
        reg11.range(415, 384) = s_result_PE188.read() + 1;
        reg11.range(447, 416) = s_result_PE189.read() + 1;
        reg11.range(479, 448) = s_result_PE190.read() + 1;
        reg11.range(511, 480) = s_result_PE191.read() + 1;
        s_result_all.write(reg11);

        reg12.range(31, 0)    = s_result_PE192.read() + 1;
        reg12.range(63, 32)   = s_result_PE193.read() + 1;
        reg12.range(95, 64)   = s_result_PE194.read() + 1;
        reg12.range(127, 96)  = s_result_PE195.read() + 1;
        reg12.range(159, 128) = s_result_PE196.read() + 1;
        reg12.range(191, 160) = s_result_PE197.read() + 1;
        reg12.range(223, 192) = s_result_PE198.read() + 1;
        reg12.range(255, 224) = s_result_PE199.read() + 1;
        reg12.range(287, 256) = s_result_PE200.read() + 1;
        reg12.range(319, 288) = s_result_PE201.read() + 1;
        reg12.range(351, 320) = s_result_PE202.read() + 1;
        reg12.range(383, 352) = s_result_PE203.read() + 1;
        reg12.range(415, 384) = s_result_PE204.read() + 1;
        reg12.range(447, 416) = s_result_PE205.read() + 1;
        reg12.range(479, 448) = s_result_PE206.read() + 1;
        reg12.range(511, 480) = s_result_PE207.read() + 1;
        s_result_all.write(reg12);

        reg13.range(31, 0)    = s_result_PE208.read() + 1;
        reg13.range(63, 32)   = s_result_PE209.read() + 1;
        reg13.range(95, 64)   = s_result_PE210.read() + 1;
        reg13.range(127, 96)  = s_result_PE211.read() + 1;
        reg13.range(159, 128) = s_result_PE212.read() + 1;
        reg13.range(191, 160) = s_result_PE213.read() + 1;
        reg13.range(223, 192) = s_result_PE214.read() + 1;
        reg13.range(255, 224) = s_result_PE215.read() + 1;
        reg13.range(287, 256) = s_result_PE216.read() + 1;
        reg13.range(319, 288) = s_result_PE217.read() + 1;
        reg13.range(351, 320) = s_result_PE218.read() + 1;
        reg13.range(383, 352) = s_result_PE219.read() + 1;
        reg13.range(415, 384) = s_result_PE220.read() + 1;
        reg13.range(447, 416) = s_result_PE221.read() + 1;
        reg13.range(479, 448) = s_result_PE222.read() + 1;
        reg13.range(511, 480) = s_result_PE223.read() + 1;
        s_result_all.write(reg13);

        reg14.range(31, 0)    = s_result_PE224.read() + 1;
        reg14.range(63, 32)   = s_result_PE225.read() + 1;
        reg14.range(95, 64)   = s_result_PE226.read() + 1;
        reg14.range(127, 96)  = s_result_PE227.read() + 1;
        reg14.range(159, 128) = s_result_PE228.read() + 1;
        reg14.range(191, 160) = s_result_PE229.read() + 1;
        reg14.range(223, 192) = s_result_PE230.read() + 1;
        reg14.range(255, 224) = s_result_PE231.read() + 1;
        reg14.range(287, 256) = s_result_PE232.read() + 1;
        reg14.range(319, 288) = s_result_PE233.read() + 1;
        reg14.range(351, 320) = s_result_PE234.read() + 1;
        reg14.range(383, 352) = s_result_PE235.read() + 1;
        reg14.range(415, 384) = s_result_PE236.read() + 1;
        reg14.range(447, 416) = s_result_PE237.read() + 1;
        reg14.range(479, 448) = s_result_PE238.read() + 1;
        reg14.range(511, 480) = s_result_PE239.read() + 1;
        s_result_all.write(reg14);

        reg15.range(31, 0)    = s_result_PE240.read() + 1;
        reg15.range(63, 32)   = s_result_PE241.read() + 1;
        reg15.range(95, 64)   = s_result_PE242.read() + 1;
        reg15.range(127, 96)  = s_result_PE243.read() + 1;
        reg15.range(159, 128) = s_result_PE244.read() + 1;
        reg15.range(191, 160) = s_result_PE245.read() + 1;
        reg15.range(223, 192) = s_result_PE246.read() + 1;
        reg15.range(255, 224) = s_result_PE247.read() + 1;
        reg15.range(287, 256) = s_result_PE248.read() + 1;
        reg15.range(319, 288) = s_result_PE249.read() + 1;
        reg15.range(351, 320) = s_result_PE250.read() + 1;
        reg15.range(383, 352) = s_result_PE251.read() + 1;
        reg15.range(415, 384) = s_result_PE252.read() + 1;
        reg15.range(447, 416) = s_result_PE253.read() + 1;
        reg15.range(479, 448) = s_result_PE254.read() + 1;
        reg15.range(511, 480) = s_result_PE255.read() + 1;
        s_result_all.write(reg15);

        reg16.range(31, 0)    = s_result_PE256.read() + 1;
        reg16.range(63, 32)   = s_result_PE257.read() + 1;
        reg16.range(95, 64)   = s_result_PE258.read() + 1;
        reg16.range(127, 96)  = s_result_PE259.read() + 1;
        reg16.range(159, 128) = s_result_PE260.read() + 1;
        reg16.range(191, 160) = s_result_PE261.read() + 1;
        reg16.range(223, 192) = s_result_PE262.read() + 1;
        reg16.range(255, 224) = s_result_PE263.read() + 1;
        reg16.range(287, 256) = s_result_PE264.read() + 1;
        reg16.range(319, 288) = s_result_PE265.read() + 1;
        reg16.range(351, 320) = s_result_PE266.read() + 1;
        reg16.range(383, 352) = s_result_PE267.read() + 1;
        reg16.range(415, 384) = s_result_PE268.read() + 1;
        reg16.range(447, 416) = s_result_PE269.read() + 1;
        reg16.range(479, 448) = s_result_PE270.read() + 1;
        reg16.range(511, 480) = s_result_PE271.read() + 1;
        s_result_all.write(reg16);

        reg17.range(31, 0)    = s_result_PE272.read() + 1;
        reg17.range(63, 32)   = s_result_PE273.read() + 1;
        reg17.range(95, 64)   = s_result_PE274.read() + 1;
        reg17.range(127, 96)  = s_result_PE275.read() + 1;
        reg17.range(159, 128) = s_result_PE276.read() + 1;
        reg17.range(191, 160) = s_result_PE277.read() + 1;
        reg17.range(223, 192) = s_result_PE278.read() + 1;
        reg17.range(255, 224) = s_result_PE279.read() + 1;
        reg17.range(287, 256) = s_result_PE280.read() + 1;
        reg17.range(319, 288) = s_result_PE281.read() + 1;
        reg17.range(351, 320) = s_result_PE282.read() + 1;
        reg17.range(383, 352) = s_result_PE283.read() + 1;
        reg17.range(415, 384) = s_result_PE284.read() + 1;
        reg17.range(447, 416) = s_result_PE285.read() + 1;
        reg17.range(479, 448) = s_result_PE286.read() + 1;
        reg17.range(511, 480) = s_result_PE287.read() + 1;
        s_result_all.write(reg17);

        reg18.range(31, 0)    = s_result_PE288.read() + 1;
        reg18.range(63, 32)   = s_result_PE289.read() + 1;
        reg18.range(95, 64)   = s_result_PE290.read() + 1;
        reg18.range(127, 96)  = s_result_PE291.read() + 1;
        reg18.range(159, 128) = s_result_PE292.read() + 1;
        reg18.range(191, 160) = s_result_PE293.read() + 1;
        reg18.range(223, 192) = s_result_PE294.read() + 1;
        reg18.range(255, 224) = s_result_PE295.read() + 1;
        reg18.range(287, 256) = s_result_PE296.read() + 1;
        reg18.range(319, 288) = s_result_PE297.read() + 1;
        reg18.range(351, 320) = s_result_PE298.read() + 1;
        reg18.range(383, 352) = s_result_PE299.read() + 1;
        reg18.range(415, 384) = s_result_PE300.read() + 1;
        reg18.range(447, 416) = s_result_PE301.read() + 1;
        reg18.range(479, 448) = s_result_PE302.read() + 1;
        reg18.range(511, 480) = s_result_PE303.read() + 1;
        s_result_all.write(reg18);

        reg19.range(31, 0)    = s_result_PE304.read() + 1;
        reg19.range(63, 32)   = s_result_PE305.read() + 1;
        reg19.range(95, 64)   = s_result_PE306.read() + 1;
        reg19.range(127, 96)  = s_result_PE307.read() + 1;
        reg19.range(159, 128) = s_result_PE308.read() + 1;
        reg19.range(191, 160) = s_result_PE309.read() + 1;
        reg19.range(223, 192) = s_result_PE310.read() + 1;
        reg19.range(255, 224) = s_result_PE311.read() + 1;
        reg19.range(287, 256) = s_result_PE312.read() + 1;
        reg19.range(319, 288) = s_result_PE313.read() + 1;
        reg19.range(351, 320) = s_result_PE314.read() + 1;
        reg19.range(383, 352) = s_result_PE315.read() + 1;
        reg19.range(415, 384) = s_result_PE316.read() + 1;
        reg19.range(447, 416) = s_result_PE317.read() + 1;
        reg19.range(479, 448) = s_result_PE318.read() + 1;
        reg19.range(511, 480) = s_result_PE319.read() + 1;
        s_result_all.write(reg19);

        reg20.range(31, 0)    = s_result_PE320.read() + 1;
        reg20.range(63, 32)   = s_result_PE321.read() + 1;
        reg20.range(95, 64)   = s_result_PE322.read() + 1;
        reg20.range(127, 96)  = s_result_PE323.read() + 1;
        reg20.range(159, 128) = s_result_PE324.read() + 1;
        reg20.range(191, 160) = s_result_PE325.read() + 1;
        reg20.range(223, 192) = s_result_PE326.read() + 1;
        reg20.range(255, 224) = s_result_PE327.read() + 1;
        reg20.range(287, 256) = s_result_PE328.read() + 1;
        reg20.range(319, 288) = s_result_PE329.read() + 1;
        reg20.range(351, 320) = s_result_PE330.read() + 1;
        reg20.range(383, 352) = s_result_PE331.read() + 1;
        reg20.range(415, 384) = s_result_PE332.read() + 1;
        reg20.range(447, 416) = s_result_PE333.read() + 1;
        reg20.range(479, 448) = s_result_PE334.read() + 1;
        reg20.range(511, 480) = s_result_PE335.read() + 1;
        s_result_all.write(reg20);

        reg21.range(31, 0)    = s_result_PE336.read() + 1;
        reg21.range(63, 32)   = s_result_PE337.read() + 1;
        reg21.range(95, 64)   = s_result_PE338.read() + 1;
        reg21.range(127, 96)  = s_result_PE339.read() + 1;
        reg21.range(159, 128) = s_result_PE340.read() + 1;
        reg21.range(191, 160) = s_result_PE341.read() + 1;
        reg21.range(223, 192) = s_result_PE342.read() + 1;
        reg21.range(255, 224) = s_result_PE343.read() + 1;
        reg21.range(287, 256) = s_result_PE344.read() + 1;
        reg21.range(319, 288) = s_result_PE345.read() + 1;
        reg21.range(351, 320) = s_result_PE346.read() + 1;
        reg21.range(383, 352) = s_result_PE347.read() + 1;
        reg21.range(415, 384) = s_result_PE348.read() + 1;
        reg21.range(447, 416) = s_result_PE349.read() + 1;
        reg21.range(479, 448) = s_result_PE350.read() + 1;
        reg21.range(511, 480) = s_result_PE351.read() + 1;
        s_result_all.write(reg21);

        reg22.range(31, 0)    = s_result_PE352.read() + 1;
        reg22.range(63, 32)   = s_result_PE353.read() + 1;
        reg22.range(95, 64)   = s_result_PE354.read() + 1;
        reg22.range(127, 96)  = s_result_PE355.read() + 1;
        reg22.range(159, 128) = s_result_PE356.read() + 1;
        reg22.range(191, 160) = s_result_PE357.read() + 1;
        reg22.range(223, 192) = s_result_PE358.read() + 1;
        reg22.range(255, 224) = s_result_PE359.read() + 1;
        reg22.range(287, 256) = s_result_PE360.read() + 1;
        reg22.range(319, 288) = s_result_PE361.read() + 1;
        reg22.range(351, 320) = s_result_PE362.read() + 1;
        reg22.range(383, 352) = s_result_PE363.read() + 1;
        reg22.range(415, 384) = s_result_PE364.read() + 1;
        reg22.range(447, 416) = s_result_PE365.read() + 1;
        reg22.range(479, 448) = s_result_PE366.read() + 1;
        reg22.range(511, 480) = s_result_PE367.read() + 1;
        s_result_all.write(reg22);

        reg23.range(31, 0)    = s_result_PE368.read() + 1;
        reg23.range(63, 32)   = s_result_PE369.read() + 1;
        reg23.range(95, 64)   = s_result_PE370.read() + 1;
        reg23.range(127, 96)  = s_result_PE371.read() + 1;
        reg23.range(159, 128) = s_result_PE372.read() + 1;
        reg23.range(191, 160) = s_result_PE373.read() + 1;
        reg23.range(223, 192) = s_result_PE374.read() + 1;
        reg23.range(255, 224) = s_result_PE375.read() + 1;
        reg23.range(287, 256) = s_result_PE376.read() + 1;
        reg23.range(319, 288) = s_result_PE377.read() + 1;
        reg23.range(351, 320) = s_result_PE378.read() + 1;
        reg23.range(383, 352) = s_result_PE379.read() + 1;
        reg23.range(415, 384) = s_result_PE380.read() + 1;
        reg23.range(447, 416) = s_result_PE381.read() + 1;
        reg23.range(479, 448) = s_result_PE382.read() + 1;
        reg23.range(511, 480) = s_result_PE383.read() + 1;
        s_result_all.write(reg23);

        reg24.range(31, 0)    = s_result_PE384.read() + 1;
        reg24.range(63, 32)   = s_result_PE385.read() + 1;
        reg24.range(95, 64)   = s_result_PE386.read() + 1;
        reg24.range(127, 96)  = s_result_PE387.read() + 1;
        reg24.range(159, 128) = s_result_PE388.read() + 1;
        reg24.range(191, 160) = s_result_PE389.read() + 1;
        reg24.range(223, 192) = s_result_PE390.read() + 1;
        reg24.range(255, 224) = s_result_PE391.read() + 1;
        reg24.range(287, 256) = s_result_PE392.read() + 1;
        reg24.range(319, 288) = s_result_PE393.read() + 1;
        reg24.range(351, 320) = s_result_PE394.read() + 1;
        reg24.range(383, 352) = s_result_PE395.read() + 1;
        reg24.range(415, 384) = s_result_PE396.read() + 1;
        reg24.range(447, 416) = s_result_PE397.read() + 1;
        reg24.range(479, 448) = s_result_PE398.read() + 1;
        reg24.range(511, 480) = s_result_PE399.read() + 1;
        s_result_all.write(reg24);

        reg25.range(31, 0)    = s_result_PE400.read() + 1;
        reg25.range(63, 32)   = s_result_PE401.read() + 1;
        reg25.range(95, 64)   = s_result_PE402.read() + 1;
        reg25.range(127, 96)  = s_result_PE403.read() + 1;
        reg25.range(159, 128) = s_result_PE404.read() + 1;
        reg25.range(191, 160) = s_result_PE405.read() + 1;
        reg25.range(223, 192) = s_result_PE406.read() + 1;
        reg25.range(255, 224) = s_result_PE407.read() + 1;
        reg25.range(287, 256) = s_result_PE408.read() + 1;
        reg25.range(319, 288) = s_result_PE409.read() + 1;
        reg25.range(351, 320) = s_result_PE410.read() + 1;
        reg25.range(383, 352) = s_result_PE411.read() + 1;
        reg25.range(415, 384) = s_result_PE412.read() + 1;
        reg25.range(447, 416) = s_result_PE413.read() + 1;
        reg25.range(479, 448) = s_result_PE414.read() + 1;
        reg25.range(511, 480) = s_result_PE415.read() + 1;
        s_result_all.write(reg25);

    }
}

template<const int ROW_PER_PE>
void gather_results_node1(
    STREAM<ap_uint<512> > & s_result1_partial_0, STREAM<ap_uint<512> > & s_result1_partial_1, 
    STREAM<ap_uint<512> > & s_result1_partial_2, STREAM<ap_uint<512> > & s_result1_partial_3, 
    STREAM<ap_uint<512> > & s_result1_partial_4, STREAM<ap_uint<512> > & s_result1_partial_5, 
    STREAM<ap_uint<512> > & s_result1_partial_6, STREAM<ap_uint<512> > & s_result1_partial_7, 
    // STREAM<ap_uint<512> > & s_result1_partial_8, STREAM<ap_uint<512> > & s_result1_partial_9, 
    // STREAM<ap_uint<512> > & s_result1_partial_10, STREAM<ap_uint<512> > & s_result1_partial_11, 
    // STREAM<ap_uint<512> > & s_result1_partial_12, STREAM<ap_uint<512> > & s_result1_partial_13, 
    // STREAM<ap_uint<512> > & s_result1_partial_14, STREAM<ap_uint<512> > & s_result1_partial_15, 
    STREAM<ap_uint<512> > & s_result_node){
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < 2 * ROW_PER_PE; i++){
            #pragma HLS pipeline II=1
            s_result_node.write(s_result1_partial_0.read());
        }
        for (int i = 0; i < 2 * ROW_PER_PE; i++){
            #pragma HLS pipeline II=1
            s_result_node.write(s_result1_partial_1.read());
        }
        for (int i = 0; i < 2 * ROW_PER_PE; i++){
            #pragma HLS pipeline II=1
            s_result_node.write(s_result1_partial_2.read());
        }
        for (int i = 0; i < 2 * ROW_PER_PE; i++){
            #pragma HLS pipeline II=1
            s_result_node.write(s_result1_partial_3.read());
        }
        for (int i = 0; i < 2 * ROW_PER_PE; i++){
            #pragma HLS pipeline II=1
            s_result_node.write(s_result1_partial_4.read());
        }
        for (int i = 0; i < 2 * ROW_PER_PE; i++){
            #pragma HLS pipeline II=1
            s_result_node.write(s_result1_partial_5.read());
        }
        for (int i = 0; i < 2 * ROW_PER_PE; i++){
            #pragma HLS pipeline II=1
            s_result_node.write(s_result1_partial_6.read());
        }
        for (int i = 0; i < 2 * ROW_PER_PE; i++){
            #pragma HLS pipeline II=1
            s_result_node.write(s_result1_partial_7.read());
        }
        // for (int i = 0; i < 2 * ROW_PER_PE; i++){
        //     #pragma HLS pipeline II=1
        //     s_result_node.write(s_result1_partial_8.read());
        // }
        // for (int i = 0; i < 2 * ROW_PER_PE; i++){
        //     #pragma HLS pipeline II=1
        //     s_result_node.write(s_result1_partial_9.read());
        // }
        // for (int i = 0; i < 2 * ROW_PER_PE; i++){
        //     #pragma HLS pipeline II=1
        //     s_result_node.write(s_result1_partial_10.read());
        // }
        // for (int i = 0; i < 2 * ROW_PER_PE; i++){
        //     #pragma HLS pipeline II=1
        //     s_result_node.write(s_result1_partial_11.read());
        // }
        // for (int i = 0; i < 2 * ROW_PER_PE; i++){
        //     #pragma HLS pipeline II=1
        //     s_result_node.write(s_result1_partial_12.read());
        // }
        // for (int i = 0; i < 2 * ROW_PER_PE; i++){
        //     #pragma HLS pipeline II=1
        //     s_result_node.write(s_result1_partial_13.read());
        // }
        // for (int i = 0; i < 2 * ROW_PER_PE; i++){
        //     #pragma HLS pipeline II=1
        //     s_result_node.write(s_result1_partial_14.read());
        // }
        // for (int i = 0; i < 2 * ROW_PER_PE; i++){
        //     #pragma HLS pipeline II=1
        //     s_result_node.write(s_result1_partial_15.read());
        // }
    }
}

void dataTransform(STREAM<ap_uint<512> > & s_result_node, STREAM<ap_uint<512> > & s_feature_send_out, STREAM<ap_uint<512> > & s_padded_zero, STREAM<ap_uint<512> > & s_data_out){

    ValidData:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {

        for (int i = 0; i < 16; i++) {
            #pragma HLS pipeline II=1
            s_data_out.write(s_result_node.read()); 
            #ifndef ACCL_SYNTHESIS
                std::cout <<"reduce root dataTransform loop1: wr_count:"<<i<<std::endl;
            #endif
        }

        // for (int i = 0; i < 64; i++){
        //     #pragma HLS pipeline II=1
        //     ap_uint<512> tmp_data_0 = s_result_node_partial.read();
        //     ap_uint<512> tmp_data_1 = s_result_node.read();
        //     ap_uint<512> tmp_data_out;
        //     for (int j = 0; j < 16; j++) {
        //         #pragma HLS unroll
        //         tmp_data_out(32*j+31, 32*j) = tmp_data_0(32*j+31, 32*j) + tmp_data_1(32*j+31, 32*j);
        //     }
        //     s_data_out.write(tmp_data_out);
        // }

        for (int i = 0; i < 48; i++) {
            #pragma HLS pipeline II=1
            s_data_out.write(s_padded_zero.read()); // padded packet
            #ifndef ACCL_SYNTHESIS
                std::cout <<"reduce root dataTransform loop2: wr_count:"<<i<<std::endl;
            #endif
        }

        for (int i = 0; i < 128; i++) {
            #pragma HLS pipeline II=1
            s_data_out.write(s_feature_send_out.read()); // padded packet
            #ifndef ACCL_SYNTHESIS
                std::cout <<"reduce root dataTransform loop3: wr_count:"<<i<<std::endl;
            #endif
        }

        // for (int i = 0; i < 192; i++) {
        //     #pragma HLS pipeline II=1
        //     if (i < 64) {
        //         s_data_out.write(s_result_node.read());
        //     }
        //     else if (i < 128) {
        //         s_data_out.write(0);
        //     }
        //     else if (i < 188) {
        //         s_data_out.write(s_embedding_table.read());
        //     }
        //     else {
        //         s_data_out.write(0);
        //     }
        // }
        // for (int i = 0; i < 2; i++) {
        //     #pragma HLS pipeline II=1
        //     s_data_out.write(0); // padded packet
        // }

    }
}

void dataTransform(STREAM<ap_uint<512> > & s_feature_in, STREAM<ap_uint<512> > & s_data_out){

    ValidData:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {

        for (int i = 0; i < 60; i++){
            #pragma HLS pipeline II=1
            ap_uint<512> tmp_data = s_feature_in.read();
            s_data_out.write(tmp_data);
        }

        for (int i = 0; i < 4; i++) {
            #pragma HLS pipeline II=1
            s_data_out.write(0); // padded packet
        }

    }
}

void stream_data_out(STREAM<ap_uint<512> >& s_data_out_buffer, STREAM<ap_uint<512> >& s_data_out)
{
#pragma HLS dataflow

    stream_data_out:
    for (int i = 0; i < BATCH_NUM * BATCH_SIZE; ++i)
    {
        for (int j = 0; j < 192; ++j)
        {
            #pragma HLS pipeline II=1
            s_data_out.write(s_data_out_buffer.read());
        }
    }
}

void pad_zero(STREAM<ap_uint<512> >& s_padded_zero)
{
#pragma HLS dataflow

    for (int i = 0; i < BATCH_NUM * BATCH_SIZE; ++i)
    {
        for (int j = 0; j < 48; ++j)
        {
            #pragma HLS pipeline II=1
            ap_uint<512> s_data = 0;
            s_padded_zero.write(s_data);
        }
    }
}

void consumeData_zero(
    STREAM<ap_uint<512> >& s_data_in_zero
) {

    for (int i = 0; i < BATCH_NUM * BATCH_SIZE; ++i)
    {
        for (int j = 0; j < 64; ++j)
        {
            #pragma HLS pipeline II=1
            s_data_in_zero.read();
        }
    }
}

}