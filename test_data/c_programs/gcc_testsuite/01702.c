typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

typedef double TYPE;

void vafunction (char *dummy, ...)
{
  va_list ap;

  __builtin_va_start(ap, dummy);
  if (__builtin_va_arg(ap, TYPE) != 1.)
    abort();
  if (__builtin_va_arg(ap, TYPE) != 2.)
    abort();
  if (__builtin_va_arg(ap, TYPE) != 3.)
    abort();
  if (__builtin_va_arg(ap, TYPE) != 4.)
    abort();
  if (__builtin_va_arg(ap, TYPE) != 5.)
    abort();
  if (__builtin_va_arg(ap, TYPE) != 6.)
    abort();
  if (__builtin_va_arg(ap, TYPE) != 7.)
    abort();
  if (__builtin_va_arg(ap, TYPE) != 8.)
    abort();
  if (__builtin_va_arg(ap, TYPE) != 9.)
    abort();
  __builtin_va_end(ap);
}


int main (void)
{
  vafunction( "", 1., 2., 3., 4., 5., 6., 7., 8., 9. );
  exit(0);
  return 0;
}
