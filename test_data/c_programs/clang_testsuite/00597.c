typedef union { __int128 a; } Small;
void test1(int x0, __int128 x2_x3, __int128 x4_x5, __int128 x6_x7, Small sp) {
}
void test2(int x0, Small x2_x3, int x4, Small x6_x7, int sp, Small sp16) {
}
typedef struct { float arr[4]; } HFA;
void test3(HFA s0_s3, float s4, HFA sp, HFA sp16) {
}
typedef __attribute__((neon_vector_type(16))) signed char int8x16_t;
typedef struct { int8x16_t arr[3]; } BigHFA;
void test4(BigHFA v0_v2, BigHFA v3_v5, BigHFA sp, double sp48, BigHFA sp64) {
}
unsigned char test5(unsigned char a, signed short b) {
}
__fp16 test_half(__fp16 A) { }
struct HFA_half { __fp16 a[4]; };
struct HFA_half test_half_hfa(struct HFA_half A) { }
