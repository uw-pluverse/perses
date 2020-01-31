typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

int
bar (int a, va_list ap)
{
  int b;

  do
    b = __builtin_va_arg(ap, int);
  while (b > 10);

  return a + b;
}

int
foo (int a, ...)
{
  va_list ap;

  __builtin_va_start(ap, a);
  return bar (a, ap);
}

int
main ()
{
  if (foo (1, 2, 3) != 3)
    abort ();
  return 0;
}
