






extern void abort (void);
extern void exit (int);

int
f (int n)
{
  return (n << 24) / (1 << 23);
}

volatile int x = 128;

int
main (void)
{
  if (f(x) != -256)
    abort ();
  exit (0);
}
