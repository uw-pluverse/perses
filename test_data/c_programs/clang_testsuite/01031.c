int x() { return 1; }
int f() __attribute__((weak, alias("x")));
int f();
int h() {
  return f();
}
