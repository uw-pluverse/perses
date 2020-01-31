




int
main1 (int n, int *a)
{
  int i, j;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      a[j] = i + n;

  for (j = 0; j < n; j++)
    if (a[j] != i + n - 1)
      __builtin_abort ();

  return 0;
}

int
main ()
{
  int a[16];
  main1 (16, a);
  return 0;
}
