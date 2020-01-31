





int a[10];
extern void abort(void) __attribute__((noreturn));

int __attribute__((__noinline__, __noclone__))
foo (void)
{
  double d;
  int i;
  for (i = 0, d = 0; i < 64; i++)
    d--;
  return (int) d;
}

int
main (void)
{
  if (foo () != -64)
    abort ();
  return 0;
}
