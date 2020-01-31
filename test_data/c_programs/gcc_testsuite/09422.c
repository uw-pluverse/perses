


unsigned int
foo (int *a, unsigned int n)
{
  unsigned int i;
  for (i = 0; i < n; ++i)
    a[i] = 1;

  return i;
}
