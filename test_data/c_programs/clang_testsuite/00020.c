void helper() {
  extern void foo();
  foo();
}
void test() {
  helper();
  *(volatile int *)0 = 1;
}
