


void
scale (long *alpha, long *x, int n)
{
  int i, ix;

  if (*alpha != 1)
    for (i = 0, ix = 0; i < n; i++, ix += 2)
      {
 long tmpr, tmpi;
 tmpr = *alpha * x[ix];
 tmpi = *alpha * x[ix + 1];
 x[ix] = tmpr;
 x[ix + 1] = tmpi;
      }
}

int
main (void)
{
  int i;
  long x[10];
  long alpha = 2;

  for (i = 0; i < 10; i++)
    x[i] = i;

  scale (&alpha, x, 5);

  if (x[9] != 18)
    abort ();

  return 0;
}
