


typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

typedef struct {
  char a[32];
} big;

void
f (big x, char *s, ...)
{
  va_list ap;

  if (x.a[0] != 'a' || x.a[1] != 'b' || x.a[2] != 'c')
    abort ();
  __builtin_va_start(ap, s);
  if (__builtin_va_arg(ap, int) != 42)
    abort ();
  if (__builtin_va_arg(ap, int) != 'x')
    abort ();
  if (__builtin_va_arg(ap, int) != 0)
    abort ();
  __builtin_va_end(ap);
}

main ()
{
  static big x = { "abc" };

  f (x, "", 42, 'x', 0);
  exit (0);
}
