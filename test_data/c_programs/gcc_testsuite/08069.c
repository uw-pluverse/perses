static unsigned int x[2000], a[2000][2000];

static unsigned int __attribute__((noinline))
mvt (long N)
{
  int i,j;


  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      x[i] += a[j][i];

  return x[1];
}

extern void abort ();

int
main (void)
{
  int i, j;
  unsigned int res;

  for (i = 0; i < 2000; i++)
    for (j = 0; j < 2000; j++)
      a[i][j] = j;

  for (i = 0; i < 2000; i++)
    x[i] = i;

  res = mvt (2000);





  if (res != 2001)
    abort ();

  return 0;
}
