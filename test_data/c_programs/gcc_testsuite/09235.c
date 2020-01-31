


typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

int
foo (int i, ...)
{
  short e;
  va_list ap;
  __builtin_va_start(ap, i);
  e = __builtin_va_arg(ap, short);
  __builtin_va_end(ap);
  return e;
}
