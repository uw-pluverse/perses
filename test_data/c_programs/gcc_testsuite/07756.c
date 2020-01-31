



typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

int
foo (void *a)
{
  va_list *b = a;
  return __builtin_va_arg(*b, int);
}
