void zero(int **p) {
  *p = 0;
}
void testZero(int *a) {
  zero(&a);
  *a = 1;
}
void testCheck(int *a) {
  if (a) {
    ;
  }
  *a = 1;
}
int *getPointer();
void testInitCheck() {
  int *a = getPointer();
  if (a) {
    ;
  }
  *a = 1;
}
void testStoreCheck(int *a) {
  a = getPointer();
  if (a) {
    ;
  }
  *a = 1;
}
int *getZero() {
  int *p = 0;
  return p;
}
void testReturnZero() {
  *getZero() = 1;
}
int testReturnZero2() {
  return *getZero();
}
void testInitZero() {
  int *a = getZero();
  *a = 1;
}
void testStoreZero(int *a) {
  a = getZero();
  *a = 1;
}
void usePointer(int *p) {
  *p = 1;
}
void testUseOfNullPointer() {
  usePointer(getZero());
}
struct X { char *p; };
void setFieldToNull(struct X *x) {
 x->p = 0;
}
int testSetFieldToNull(struct X *x) {
  setFieldToNull(x);
  return *x->p;
}
struct Outer {
  struct Inner {
    int *p;
  } inner;
};
void test(struct Outer *wrapperPtr) {
  wrapperPtr->inner.p = 0;
  *wrapperPtr->inner.p = 1;
}
void test4(int **p) {
  if (*p) return;
  **p = 1;
}
