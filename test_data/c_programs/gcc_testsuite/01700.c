typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

void fdouble (double one, ...)
{
  double value;
  va_list ap;

  __builtin_va_start(ap, one);
  value = __builtin_va_arg(ap, double);
  __builtin_va_end(ap);

  if (one != 1.0 || value != 2.0)
    abort ();
}

int main ()
{
  fdouble (1.0, 2.0);
  exit (0);
}
