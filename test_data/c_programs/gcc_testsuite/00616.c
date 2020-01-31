


int
foo (char *fmt, ...)
{
  int d;
  __builtin_va_list ap;

  __builtin_va_start (ap, fmt);
  d = __builtin_va_arg (ap, int);
  __builtin_va_end (ap);


  return d;
}
