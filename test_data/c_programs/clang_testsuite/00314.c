typedef float float4 __attribute__((ext_vector_type(4)));
typedef unsigned int uint4 __attribute__((ext_vector_type(4)));
void clang_shufflevector_v_v( float4* A, float4 x, uint4 mask ) {
  *A = __builtin_shufflevector( x, mask );
}
void clang_shufflevector_v_v_c( float4* A, float4 x, float4 y) {
  *A = __builtin_shufflevector( x, y, 0, 4, 1, 5 );
}
void clang_shufflevector_v_v_undef( float4* A, float4 x, float4 y) {
  *A = __builtin_shufflevector( x, y, 0, 4, -1, 5 );
}
