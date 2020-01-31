

int a[100];

int
foo (int bar, int n, int k)
{
  int i;

  for (i = 0; i < n; i++)
    if (i == k)
      a[i] = bar;

  for (i = 0; i < n; i++)
    if (i == k)
      a[i] = bar;

  return a[bar];
}
