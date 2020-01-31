typedef float v4sf __attribute__ ((__vector_size__ (16)));
typedef int v4i32 __attribute__ ((__vector_size__ (16)));
extern test_v4sf_2(v4sf, int, v4sf);
void test_v4sf(v4sf a1, int a2, v4sf a3) {
  test_v4sf_2(a3, a2, a1);
}
extern test_v4i32_2(v4i32, int, v4i32);
void test_v4i32(v4i32 a1, int a2, v4i32 a3) {
  test_v4i32_2(a3, a2, a1);
}
