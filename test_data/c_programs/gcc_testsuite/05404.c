


static int x;
void
foo (int n, int *A)
{
  int i;
  for (i = 0; i < n; i++)
    {
      if (A[i])
 x = 2;
      if (A[i + 1])
 x = 1;
    }
}
