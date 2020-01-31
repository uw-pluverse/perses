int opaque();
int test0(void) {
  return opaque();
}
int test1(void) {
  return 0;
}
__attribute__((weak)) int test2(void) {
  return 0;
}
