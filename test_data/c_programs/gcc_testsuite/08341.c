


typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

void
foo (va_list ap)
{
  __builtin_va_arg(ap, _Bool);
}
