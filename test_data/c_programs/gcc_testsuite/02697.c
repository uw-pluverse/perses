typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;




void
test (int n, ...)
{
  va_list ap;
  int i;

  __builtin_va_start(ap, n);
  for (i = 2; i <= n; i++)
    {
      if (__builtin_va_arg(ap, int) != i)
 abort ();
    }

  if (__builtin_va_arg(ap, long long) != 0x123456789abcdefLL)
    abort ();

  if (__builtin_va_arg(ap, int) != 0x55)
    abort ();

  __builtin_va_end(ap);
}

int
main ()
{
  test (1, 0x123456789abcdefLL, 0x55);
  test (2, 2, 0x123456789abcdefLL, 0x55);
  test (3, 2, 3, 0x123456789abcdefLL, 0x55);
  test (4, 2, 3, 4, 0x123456789abcdefLL, 0x55);
  test (5, 2, 3, 4, 5, 0x123456789abcdefLL, 0x55);
  test (6, 2, 3, 4, 5, 6, 0x123456789abcdefLL, 0x55);
  test (7, 2, 3, 4, 5, 6, 7, 0x123456789abcdefLL, 0x55);
  test (8, 2, 3, 4, 5, 6, 7, 8, 0x123456789abcdefLL, 0x55);
  exit (0);
}
