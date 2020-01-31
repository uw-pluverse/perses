






double
f1 (double a, double b, double c)
{
  double y0;
  double y1;

  if (a == 0.0)
    {
      y0 = -c / b;
      return y0;
    }
  y0 = c / b;
  y1 = a / b;
  return y0 * y1;
}


double
f2 (double a, double b, double c)
{
  double y0;
  double y1;

a_label:
another_label:
  if (a == 0.0)
    {
      y0 = -c / b;
      return y0;
    }
  y0 = c / b;
  y1 = a / b;
  return y0 * y1;
}


double
f3 (double a, double b, double c)
{
  double y0;
  double y1;

  y0 = -c / b;
  if (a == 0.0)
    {
      return y0;
    }
  y0 = c / b;
  y1 = a / b;
  return y0 * y1;
}
