



typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

void bar (int x, va_list *ap);

void
foo (int x, ...)
{
  va_list ap;
  int n;

  __builtin_va_start(ap, x);
  n = __builtin_va_arg(ap, int);
  bar (x, (va_list *) ((n == 0) ? ((void *) 0) : &ap));
  __builtin_va_end(ap);
}
