



typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

int
foo (va_list ap)
{
  return __builtin_va_arg(ap, int);
}
