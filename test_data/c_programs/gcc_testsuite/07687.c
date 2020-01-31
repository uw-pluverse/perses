





extern void abort (void);

int __attribute__((noinline))
foo (int a, int b)
{
  int max = (b > 0) ? b : 0;
  return max - a;
}

int
main (void)
{
  if (foo (3, -1) != -3)
    abort ();
  return 0;
}
