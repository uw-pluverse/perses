




double
foo (double *x, int n)
{
  double p = 0.0;
  int i;
  x = __builtin_assume_aligned (x, 128);
  if (n % 128)
    __builtin_unreachable ();
  for (i = 0; i < n; i++)
    p += x[i];
  return p;
}
