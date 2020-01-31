static int unused_func(void) {
  return 1;
}
int foo(void) {
  (void)unused_func;
  return 2;
}
