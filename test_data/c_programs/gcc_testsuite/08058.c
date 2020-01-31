int A[100];

extern void abort ();

int
main (void)
{
  int i;

  for (i = 0; i < 100; i++)
    A[i] = i;
  for(int i=0; i<100; i++)
    A[i] ^= 4;
  for(int i=0; i<100; i++)
    A[i] ^= 8;

  for (i = 0; i < 100; i++)
    if (A[i] != (i ^ 12))
      abort ();

  return 0;
}
