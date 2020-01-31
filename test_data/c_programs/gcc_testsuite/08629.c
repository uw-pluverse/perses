



__attribute__ ((weak))
__attribute__ ((noinline))
int a(int v)
{
  return v;
}
__attribute__ ((noinline))
static int b(int v) __attribute__ ((alias("a")));
int
main()
{
  int c = a(1)==a(1);
  int d = b(1)==b(1);
  if (__builtin_constant_p (c))
    __builtin_abort ();
  if (!__builtin_constant_p (d))
    __builtin_abort ();
  return 0;
}
