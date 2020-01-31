



void
foo (double *a, double *b, double *c, double d, double e, int n)
{
  int i;
  for (i = 1; i < n - 1; i++)
    a[i] = d * (b[i] + c[i] + a[i - 1] + a[i + 1]) + e * a[i];
}
