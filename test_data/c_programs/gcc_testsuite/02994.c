typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

f (int n, ...)
{
  va_list args;

  __builtin_va_start(args, n);

  if (__builtin_va_arg(args, int) != 10)
    abort ();
  if (__builtin_va_arg(args, long long) != 10000000000LL)
    abort ();
  if (__builtin_va_arg(args, int) != 11)
    abort ();
  if (__builtin_va_arg(args, long double) != 3.14L)
    abort ();
  if (__builtin_va_arg(args, int) != 12)
    abort ();
  if (__builtin_va_arg(args, int) != 13)
    abort ();
  if (__builtin_va_arg(args, long long) != 20000000000LL)
    abort ();
  if (__builtin_va_arg(args, int) != 14)
    abort ();
  if (__builtin_va_arg(args, double) != 2.72)
    abort ();

  __builtin_va_end(args);
}

main ()
{
  f (4, 10, 10000000000LL, 11, 3.14L, 12, 13, 20000000000LL, 14, 2.72);
  exit (0);
}
