




int
foo (int a, int b, volatile int *c, volatile int *d)
{
  if (a > b)
    return c[0];
  else
    return d[0];
}
