




extern void abort (void);



int main1 (int n, int *a)
{
  int i, j, k;
  int b[16];

  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
 {
   k = i + n;
   a[j] = k;
 }
      b[i] = k;
    }


  for (j = 0; j < n; j++)
    if (a[j] != i + n - 1)
      abort();

  for (j = 0; j < n; j++)
    if (b[j] != j + n)
      abort();

  return 0;
}

int main (void)
{
  int a[16] __attribute__ ((__aligned__(16)));

  main1 (16, a);
  main1 (0, a);
  main1 (1, a);
  main1 (2, a);
  main1 (16 -1, a);

  return 0;
}
