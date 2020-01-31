static unsigned int __attribute__((noinline))
foo (unsigned int *x)
{
  int i, j;
  unsigned int sum = 0;

  for (j = 0; j < 111; ++j)
    for (i = 0; i < 111; ++i)
      sum += x[111 * i + j];

  return sum;
}

extern void abort ();

int
main (void)
{
  unsigned int A[111*111];
  int i;
  unsigned int res;

  for (i = 0; i < 111*111; i++)
    A[i] = 2;

  res = foo (A);





  if (res != 24642)
    abort ();

  return 0;
}
