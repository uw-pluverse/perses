int foo __attribute__((address_space(1)));
int ban[10] __attribute__((address_space(1)));
int a __attribute__((address_space(0)));
int test1() { return foo; }
int test2(int i) { return ban[i]; }
__attribute__((address_space(2))) int *A, *B;
void test3() {
  *A = *B;
}
typedef struct {
  float aData[1];
} MyStruct;
void test4(MyStruct __attribute__((address_space(2))) *pPtr) {
  MyStruct s = pPtr[0];
  pPtr[0] = s;
}
