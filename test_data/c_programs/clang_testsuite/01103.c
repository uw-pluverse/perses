int printf(const char *, ...);
int foo(void) {
  return printf(printf);
}
