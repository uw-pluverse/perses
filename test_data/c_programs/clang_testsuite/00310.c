typedef struct float4_s {
  float x, y, z, w;
} float4_t;
float4_t my_function(void) {
  float4_t t;
  return t;
};
float bar(void) {
  float4_t ret;
  ret = my_function();
  return ret.x;
}
void foo(float4_t x) {
}
void fooN(float4_t x, float4_t y, float4_t z) {
}
typedef struct nested_s {
  unsigned long long x;
  float z[64];
  float4_t t;
} nested_t;
void baz(nested_t x) {
}
