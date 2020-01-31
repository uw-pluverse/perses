typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
unsigned foo(int x, ...) {
  va_list valist;
  __builtin_va_start(valist,x);
  unsigned a;
  a = __builtin_va_arg(valist,unsigned);
  return a;
}
void foo1() {
  unsigned f = 0xffffffe0;
  foo(1,f);
}
