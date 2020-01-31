void ip(int *aPtr) {}
void i(int a) {}
void ii(int a) {}
void fp(float *aPtr) {}
void f(float a) {}
void f2(int *aPtr, int a, float *bPtr, char c) {
  float fl = 0;
  ip(a);
  i(aPtr);
  ii(&a);
  fp(*bPtr);
  f(bPtr);
  a = aPtr;
  fl = bPtr + a;
  bPtr = bPtr[a];
}
