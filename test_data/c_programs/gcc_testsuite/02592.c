typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

double f (float f1, float f2, float f3, float f4,
   float f5, float f6, ...)
{
  va_list ap;
  double d;

  __builtin_va_start(ap, f6);
  d = __builtin_va_arg(ap, double);
  __builtin_va_end(ap);
  return d;
}

int main ()
{
  if (f (1, 2, 3, 4, 5, 6, 7.0) != 7.0)
    abort ();
  exit (0);
}
