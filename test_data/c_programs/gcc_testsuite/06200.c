




typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

int f(int t, ...)
{
  va_list a;
  __builtin_va_start(a, t);
  __builtin_va_arg(a, int);
  int t1 = __builtin_va_arg(a, int);
  __builtin_va_end(a);
  return t1;
}
