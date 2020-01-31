int A[100][100][100], B[100][100], C[100][100];

static int __attribute__((noinline))
foo (void)
{
  int i, j, k;


  for (i = 0; i < 24; i++)
    for (j = 0; j < 24; j++)
      for (k = 0; k < 24; k++)
        A[i][j][k] = B[i][k] * C[k][j];


  for (i = 0; i < 100; i++)
    for (j = 0; j < 100; j++)
      for (k = 0; k < 100; k++)
        A[i][j][k] = B[i][k] * C[k][j];

  return A[0][0][0] + A[100 -1][100 -1][100 -1];
}

extern void abort ();

int
main (void)
{
  int i, j, res;

  for (i = 0; i < 100; i++)
    for (j = 0; j < 100; j++)
      {
 B[i][j] = i;
 C[i][j] = j;
      }

  res = foo ();





  if (res != 9801)
    abort ();

  return 0;
}
