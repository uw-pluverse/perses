static int __attribute__((noinline))
foo (int A[100][200])
{
  int i, j;


  for(j = 0; j < 200; j++)
    for(i = 0; i < 100; i++)
      A[i][j] = A[i][j] + A[i][j];

  return A[0][0] + A[100 -1][200 -1];
}

extern void abort ();

int
main (void)
{
  int A[100][200];
  int i, j, res;

  for (i = 0; i < 100; i++)
    for (j = 0; j < 200; j++)
      A[i][j] = 2;

  res = foo (A);





  if (res != 8)
    abort ();

  return 0;
}
