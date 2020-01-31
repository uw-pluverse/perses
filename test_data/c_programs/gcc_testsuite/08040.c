




extern void abort (void);



int main1 (int n)
{
  int i, j, k;
  int a[16], b[16];

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

  for (i = 0; i < n; i++)
    if (b[i] != i + n)
      abort();

  return 0;
}

int main (void)
{
  main1 (16);
  main1 (0);
  main1 (1);
  main1 (2);
  main1 (16 -1);

  return 0;
}
