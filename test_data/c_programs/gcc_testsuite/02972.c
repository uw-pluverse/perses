






typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

extern void exit (int);
extern void abort (void);

va_list ap;
float f;

va_list *
foo (void)
{
  exit (0);
  return &ap;
}

void
bar (int i, ...)
{
  __builtin_va_start(ap, i);
  f = __builtin_va_arg(*foo (), float);
  __builtin_va_end(ap);
}

int
main (void)
{
  bar (1, 0);
  abort ();
}
