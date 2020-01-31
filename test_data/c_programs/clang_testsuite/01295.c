typedef float float4 __attribute__((vector_size(16)));
typedef int int4 __attribute__((vector_size(16)));
typedef int4* int4p;
void test1(float4 a, int4 *result, int i) {
    result[i] = a;
}
void test2(float4 a, int4p result, int i) {
    result[i] = a;
}
typedef int a[5];
void test3() {
  typedef const a b;
  b r;
  r[0]=10;
}
int test4(const a y) {
  y[0] = 10;
}
