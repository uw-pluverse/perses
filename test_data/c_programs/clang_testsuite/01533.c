typedef float float4 __attribute__((vector_size(16)));
float4 foo = (float4){ 1.0, 2.0, 3.0, 4.0 };
float4 foo2 = (float4){ 1.0, 2.0, 3.0, 4.0 , 5.0 };
float4 array[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
int array_sizecheck[(sizeof(array) / sizeof(float4)) == 3 ? 1 : -1];
float4 array2[2] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0,
                     9.0 };
float4 array3[2] = { {1.0, 2.0, 3.0}, 5.0, 6.0, 7.0, 8.0,
                     9.0 };
__attribute__((vector_size(16))) float f1(void) {
  __attribute__((vector_size(16))) float vec = {0.0f, 0.0f, 0.0f};
  return(vec);
}
__attribute__((vector_size(16))) float f2(
    __attribute__((vector_size(16))) float a1) {
  return(a1);
}
typedef float __attribute__((ext_vector_type (3))) float3;
int test2[sizeof(float3) == sizeof(float4) ? 1 : -1];
typedef long long __attribute__((vector_size(16))) longlong2;
typedef short __attribute__((vector_size(16))) short8;
typedef short __attribute__((vector_size(8))) short4;
void test3() {
  extern short8 test3_helper(void);
  longlong2 arr1[2] = { test3_helper(), test3_helper() };
  short4 arr2[2] = { test3_helper(), test3_helper() };
}
