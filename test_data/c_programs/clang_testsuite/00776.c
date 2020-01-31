int callee0() __attribute__((not_tail_called,always_inline));
int callee1() __attribute__((always_inline,not_tail_called));
int foo(int a) {
  return a ? callee0() : callee1();
}
int g0 __attribute__((not_tail_called));
int foo2(int a) __attribute__((not_tail_called("abc")));
