typedef __attribute__(( ext_vector_type(4) )) float float4;
typedef __attribute__(( ext_vector_type(2) )) float float2;
typedef __attribute__(( ext_vector_type(4) )) int int4;
typedef __attribute__(( ext_vector_type(4) )) unsigned int uint4;
float4 foo = (float4){ 1.0, 2.0, 3.0, 4.0 };
const float4 bar = (float4){ 1.0, 2.0, 3.0, __builtin_inff() };
float4 test1(float4 V) {
  return V.wzyx+V;
}
float2 vec2, vec2_2;
float4 vec4, vec4_2;
float f;
void test2() {
    vec2 = vec4.xy;
    f = vec2.x;
    vec4 = vec4.yyyy;
    vec2.x = f;
    vec2.yx = vec2;
}
void test3(float4 *out) {
  *out = ((float4) {1.0f, 2.0f, 3.0f, 4.0f });
}
void test4(float4 *out) {
  float a = 1.0f;
  float b = 2.0f;
  float c = 3.0f;
  float d = 4.0f;
  *out = ((float4) {a,b,c,d});
}
void test5(float4 *out) {
  float a;
  float4 b;
  a = 1.0f;
  b = a;
  b = b * 5.0f;
  b = 5.0f * b;
  b *= a;
  *out = b;
}
void test6(float4 *ap, float4 *bp, float c) {
  float4 a = *ap;
  float4 b = *bp;
  a = a + b;
  a = a - b;
  a = a * b;
  a = a / b;
  a = a + c;
  a = a - c;
  a = a * c;
  a = a / c;
  a += b;
  a -= b;
  a *= b;
  a /= b;
  a += c;
  a -= c;
  a *= c;
  a /= c;
}
void test7(int4 *ap, int4 *bp, int c) {
  int4 a = *ap;
  int4 b = *bp;
  a = a + b;
  a = a - b;
  a = a * b;
  a = a / b;
  a = a % b;
  a = a + c;
  a = a - c;
  a = a * c;
  a = a / c;
  a = a % c;
  a += b;
  a -= b;
  a *= b;
  a /= b;
  a %= b;
  a += c;
  a -= c;
  a *= c;
  a /= c;
  a %= c;
  int4 cmp;
  cmp = a < b;
  cmp = a <= b;
  cmp = a > b;
  cmp = a >= b;
  cmp = a == b;
  cmp = a != b;
}
void test8(float4 *ap, float4 *bp, int c) {
  float4 a = *ap;
  float4 b = *bp;
  int4 cmp;
  cmp = a < b;
  cmp = a <= b;
  cmp = a > b;
  cmp = a >= b;
  cmp = a == b;
  cmp = a != b;
}
int test9(int4 V) {
  return V.xy.x;
}
int test10(int4 V) {
  return (V+V).x;
}
int4 test11a();
int test11() {
  return test11a().x;
}
int4 test12(int4 V) {
  V.xyz = V.zyx;
  return V;
}
int4 test13(int4 *V) {
  return V->zyxw;
}
void test14(uint4 *ap, uint4 *bp, unsigned c) {
  uint4 a = *ap;
  uint4 b = *bp;
  int4 d;
  a = a / b;
  a = a % b;
  a = a / c;
  a = a % c;
  d = a < b;
  d = a <= b;
  d = a > b;
  d = a >= b;
  d = a == b;
  d = a != b;
}
int4 test15(uint4 V0) {
  int4 V = !V0;
  V = V && V;
  V = V || V;
  return V;
}
void test16(float2 a, float2 b) {
  float2 t0 = (a + b) / 2;
}
typedef char char16 __attribute__((ext_vector_type(16)));
void test17(void) {
  char16 valA;
  char valB;
  char valC;
  char16 destVal = valC ? valA : valB;
}
typedef __attribute__(( ext_vector_type(16) )) float float16;
float16 vec16, vec16_2;
void test_rgba() {
  vec4_2 = vec4.abgr + vec4;
  vec2 = vec4.rg;
  vec2_2 = vec4.ba;
  f = vec4.b;
  vec4_2 = vec4_2.bbbb;
  vec2.r = f;
  vec2.gr = vec2;
  f = vec4_2.rg.r;
  vec4.rgb = vec4.bgr;
  vec4.b = vec16.sb;
  vec4_2 = vec16.sabcd;
}
