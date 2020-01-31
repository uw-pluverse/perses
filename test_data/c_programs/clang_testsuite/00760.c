int __attribute__((target("sse"), always_inline)) foo(int a) {
  return a + 4;
}
int bar() {
  return foo(4);
}
