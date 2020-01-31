




extern void abort (void);



int main1 (int *a)
{
  int i, j, k;
  int b[16];

  for (i = 0; i < 16; i++)
    {
      for (j = 0; j < 16; j++)
 {
   k = i + 16;
   a[j] = k;
 }
      b[i] = k;
    }


  for (j = 0; j < 16; j++)
    if (a[j] != i + 16 - 1)
      abort();

  for (j = 0; j < 16; j++)
    if (b[j] != j + 16)
      abort();

  return 0;
}

int main (void)
{
  int a[16] __attribute__ ((__aligned__(16)));

  main1 (a);

  return 0;
}
