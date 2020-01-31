typedef __attribute__(( ext_vector_type(4) )) int int4;
static int4 test1() {
  int4 vec, rv;
  return vec == vec;
  return vec != vec;
  return vec < vec;
  return vec <= vec;
  return vec > vec;
  return vec >= vec;
}
typedef __attribute__(( ext_vector_type(4) )) float float4;
static int4 test2() {
  float4 vec, rv;
  return vec == vec;
  return vec != vec;
  return vec < vec;
  return vec <= vec;
  return vec > vec;
  return vec >= vec;
}
