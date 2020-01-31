

double cos (double) __attribute__ ((const));
double sin (double) __attribute__ ((const));
double f(double a)
{
  double b;
  double c,d;
  double (*fp) (double) __attribute__ ((const));

  if (a < 2.0)
    {
      fp = sin;
      c = fp (a);
    }
  else
    {
      c = 1.0;
      fp = cos;
    }
  d = fp (a);
  return d + c;
}
