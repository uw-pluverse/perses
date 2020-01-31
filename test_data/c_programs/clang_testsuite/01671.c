void f1(void) __attribute__((ownership_takes("foo")));
void *f2(void) __attribute__((ownership_returns(foo, 1, 2)));
void f3(void) __attribute__((ownership_holds(foo, 1)));
void *f4(void) __attribute__((ownership_returns(foo)));
void f5(void) __attribute__((ownership_holds(foo)));
void f6(void) __attribute__((ownership_holds(foo, 1, 2, 3)));
void f7(void) __attribute__((ownership_takes(foo)));
void f8(int *i, int *j, int k) __attribute__((ownership_holds(foo, 1, 2, 4)));
int f9 __attribute__((ownership_takes(foo, 1)));
void f10(int i) __attribute__((ownership_holds(foo, 1)));
void *f11(float i) __attribute__((ownership_returns(foo, 1)));
void *f12(float i, int k, int f, int *j) __attribute__((ownership_returns(foo, 4)));
void f13(int *i, int *j) __attribute__((ownership_holds(foo, 1))) __attribute__((ownership_takes(foo, 2)));
void f14(int i, int j, int *k) __attribute__((ownership_holds(foo, 3))) __attribute__((ownership_takes(foo, 3)));
void f15(int, int)
  __attribute__((ownership_returns(foo, 1)))
  __attribute__((ownership_returns(foo, 2)));
void f16(int *i, int *j) __attribute__((ownership_holds(foo, 1))) __attribute__((ownership_holds(foo, 1)));
void f17(void*) __attribute__((ownership_takes(__, 1)));
void f18() __attribute__((ownership_takes(foo, 1)));
