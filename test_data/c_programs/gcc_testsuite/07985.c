static int __attribute__((noinline))
foo (double *a)
{
  int i,j;
  int r = 0;

  for (i = 0; i < 111; ++i)
    for (j = 0; j < 1111; ++j)
      r += a[j * 111 + i];

  return r;
}

extern void abort ();

int
main (void)
{
  double A[111*1111];
  int i, res;

  for (i = 0; i < 111*1111; i++)
    A[i] = 2;

  res = foo (A);





  if (res != 246642)
    abort ();

  return 0;
}
