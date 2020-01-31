typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
double callee(int a, ...) {
  va_list vl;
  __builtin_va_start(vl,a);
  double result = __builtin_va_arg(vl,struct { double a; }).a;
  __builtin_va_end(vl);
  return result;
}
