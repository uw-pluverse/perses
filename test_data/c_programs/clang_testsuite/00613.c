typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
void test(char *fmt, ...) {
  va_list ap;
  __builtin_va_start(ap,fmt);
  __builtin_va_arg(ap,double);
  __builtin_va_end(ap);
}
void foo() {
  double a;
  test("test",a);
}
