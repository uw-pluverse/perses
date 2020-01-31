



typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

int
foo (int a, ...)
{
  int b = 0, c = 0;
  va_list ap;
  __builtin_va_start(ap, a);
  if (a > 1)
    b = __builtin_va_arg(ap, double);
  if (a > 2)
    c = __builtin_va_arg(ap, long long);
  __builtin_va_end(ap);
  return a + b + c;
}
