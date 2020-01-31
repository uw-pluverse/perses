

typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

static int
foo (int a, ...)
{
  va_list va;
  int i, res;

  __builtin_va_start(va, a);

  for (i = 0; i < 4; ++i)
    (void) __builtin_va_arg(va, int);

  res = __builtin_va_arg(va, int);

  __builtin_va_end(va);

  return res;
}

int
main (void)
{
  if (foo (5, 4, 3, 2, 1, 0))
    abort ();
  exit (0);
}
