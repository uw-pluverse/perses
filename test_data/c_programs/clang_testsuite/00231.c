int f0(int x0, int y0, ...) { return x0 + y0; }
float *test_f1(int val, double x, double y) {
  if (val > 5)
    return f1(x, y);
  else
    return f1(x);
}
void test_g0(int *x, float * y) {
  g0(y);
  g0(x);
}
void __attribute__((noreturn)) test_abort(int code) {
  do_abort(code);
}
