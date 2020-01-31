float fma_test1(float a, float b, float c) {
#pragma STDC FP_CONTRACT ON
  float x = a * b + c;
  return x;
}
float fma_test2(float a, float b, float c) {
  float x = a * b + c;
  return x;
}
