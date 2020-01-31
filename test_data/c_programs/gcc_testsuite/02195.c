typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

va_double (int n, ...)
{
  va_list args;

  __builtin_va_start(args, n);

  if (__builtin_va_arg(args, double) != 3.141592)
    abort ();
  if (__builtin_va_arg(args, double) != 2.71827)
    abort ();
  if (__builtin_va_arg(args, double) != 2.2360679)
    abort ();
  if (__builtin_va_arg(args, double) != 2.1474836)
    abort ();

  __builtin_va_end(args);
}

va_long_double (int n, ...)
{
  va_list args;

  __builtin_va_start(args, n);

  if (__builtin_va_arg(args, long double) != 3.141592L)
    abort ();
  if (__builtin_va_arg(args, long double) != 2.71827L)
    abort ();
  if (__builtin_va_arg(args, long double) != 2.2360679L)
    abort ();
  if (__builtin_va_arg(args, long double) != 2.1474836L)
    abort ();

  __builtin_va_end(args);
}

main ()
{
  va_double (4, 3.141592, 2.71827, 2.2360679, 2.1474836);
  va_long_double (4, 3.141592L, 2.71827L, 2.2360679L, 2.1474836L);
  exit (0);
}
