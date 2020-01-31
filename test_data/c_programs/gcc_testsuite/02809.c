typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

typedef double L;
void f (L p0, L p1, L p2, L p3, L p4, L p5, L p6, L p7, L p8, ...)
{
  va_list select;

  __builtin_va_start(select, p8);

  if (__builtin_va_arg(select, int) != 10)
    abort ();
  if (__builtin_va_arg(select, int) != 11)
    abort ();
  if (__builtin_va_arg(select, int) != 12)
    abort ();

  __builtin_va_end(select);
}

int main ()
{
  f (1., 2., 3., 4., 5., 6., 7., 8., 9., 10, 11, 12);
  exit (0);
}
