char *foo(void) {
  static char p __attribute__((aligned(32)));
  return &p;
}
void bar(long n) {
  char p[n] __attribute__((aligned(32)));
}
