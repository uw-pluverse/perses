


extern void abort (void);

int j;

void
__attribute__((noinline))
foo (int n)
{
  int npairs, i;
  npairs = n - (-2147483647 - 1);

  if (npairs > 0)
    for (i = 0; i < npairs; i++)
      j++;
}

int
main ()
{
  foo (5 - 2147483647 - 1);

  if (j != 5)
    abort ();

  return 0;
}
