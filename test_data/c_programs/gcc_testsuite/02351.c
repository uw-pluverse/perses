

typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

extern void abort (void);

void
h (int x, va_list ap)
{
  switch (x)
    {
    case 1:
      if (__builtin_va_arg(ap, int) != 3 || __builtin_va_arg(ap, int) != 4)
 abort ();
      return;
    case 5:
      if (__builtin_va_arg(ap, int) != 9 || __builtin_va_arg(ap, int) != 10)
 abort ();
      return;
    default:
      abort ();
    }
}

void
f1 (int i, long long int j, ...)
{
  va_list ap;
  __builtin_va_start(ap, j);
  h (i, ap);
  if (i != 1 || j != 2)
    abort ();
  __builtin_va_end(ap);
}

void
f2 (int i, int j, int k, long long int l, ...)
{
  va_list ap;
  __builtin_va_start(ap, l);
  h (i, ap);
  if (i != 5 || j != 6 || k != 7 || l != 8)
    abort ();
  __builtin_va_end(ap);
}

int
main ()
{
  f1 (1, 2, 3, 4);
  f2 (5, 6, 7, 8, 9, 10);
  return 0;
}
