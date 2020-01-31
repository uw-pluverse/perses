extern void abort ();

int
main (void)
{
  int i, j;
  int sum = 0;
  int A[100 * 100];
  int B[100 * 100];


  for (i = 0; i < 100; i++)
    for (j = 0; j < 100; j++)
      {
 A[i*100 + j] = j;
 B[i*100 + j] = j;
      }


  for (i = 0; i < 100; i++)
    for (j = 0; j < 100; j++)
      A[i*100 + j] += B[j*100 + i];


  for(i = 0; i < 100; i++)
    for(j = 0; j < 100; j++)
      sum += A[i*100 + j];





  if (sum != 990000)
    abort ();

  return 0;
}
