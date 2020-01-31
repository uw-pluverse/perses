







int a[200][200];

static int __attribute__((noinline))
foo (void)
{
  int i, j;
  int res = 0;


  for (i = 1; i < 200; i++)
    for (j = 1; j < 200 - 1; j++)
      a[i][j] = a[i-1][j+1] * a[i-1][j+1] / 2;

  for (i = 0; i < 200; i++)
    res += a[i][i];

  return res;
}

extern void abort ();

int
main (void)
{
  int i, j, res;

  for (i = 0; i < 200; i++)
    for (j = 0; j < 200; j++)
      a[i][j] = i + j;

  res = foo ();





  if (res != 204007516)
    abort ();

  return 0;
}
