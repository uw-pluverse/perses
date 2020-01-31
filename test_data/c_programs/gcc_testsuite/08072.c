double u[25];

static int __attribute__((noinline))
foo (int N)
{
  int i, j;
  double sum = 0.0;


  for (i = 0; i < N; i++)
    {
      for (j = 0; j < N; j++)
 sum = sum + u[i + 5 * j];

      u[6 * i] *= 2;
    }

  return sum + N + u[6];
}

extern void abort ();

int
main (void)
{
  int i, j, res;

  for (i = 0; i < 25; i++)
    u[i] = 2;

  res = foo (5);





  if (res != 59)
    abort ();

  return 0;
}
