







double
foo (double *x, double *y)
{
  double z[2];
  int i;

  for (i = 0; i < 2; i++)
    z[i] = x[i] + y[i];
  return z[0] * z[1];
}
