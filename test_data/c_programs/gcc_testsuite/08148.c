int a[200][200];
int b[200][200];

static int __attribute__((noinline))
foo (void)
{
  int i, j;
  int res = 0;


  for (j = 1; j < 200; j++)
    for (i = 0; i < 200; i++)
      a[i][j] = a[i][j-1] + b[i][j];

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
      {
 a[i][j] = i + j;
 b[i][j] = i - j;
      }

  res = foo ();





  if (res != 1333300)
    abort ();

  return 0;
}
