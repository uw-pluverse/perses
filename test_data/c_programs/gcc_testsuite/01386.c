





void
foo (double *p, double a, double b, int n)
{
  double c = a + b;
  do
    *p++ = c;
  while (n--);
}
