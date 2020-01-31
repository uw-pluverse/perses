int callee0(int a) __attribute__((not_tail_called)) {
  return a + 1;
}
int callee1(int) __attribute__((not_tail_called));
int callee2(int);
typedef int (*FuncTy)(int);
int foo0(int a) {
  if (a > 1)
    return callee0(a);
  if (a == 1)
    return callee1(a);
  if (a < 0) {
    FuncTy F = callee1;
    return (*F)(a);
  }
  return callee2(a);
}
