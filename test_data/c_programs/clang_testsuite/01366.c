_Atomic(int) t1;
_Atomic(int) *t2 = &t1;
void testf(void*);
void f(void) {
  _Atomic(_Atomic(int)*) t3;
  _Atomic(_Atomic(int)*) *t4[2] = { &t3, 0 };
  testf(t4);
}
extern _Atomic(int (*)(int(*)[], int(*)[10])) mergetest;
extern _Atomic(int (*)(int(*)[10], int(*)[])) mergetest;
extern _Atomic(int (*)(int(*)[10], int(*)[10])) mergetest;
_Atomic(int()) error1;
_Atomic(struct ErrorS) error2;
_Atomic(int[10]) error3;
_Atomic(const int) error4;
_Atomic(_Atomic(int)) error5;
