







int foo (int *p, int n)
{
  int i, r;
  for (i = 0; i < n; i++)
    r += p[i];
  return r;
}
