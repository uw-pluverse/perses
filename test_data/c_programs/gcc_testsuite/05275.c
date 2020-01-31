


double test2 (double x, double y, double ddj, int b)
{
  double tmp1, tmp2, sum;
  sum = 0.0;
  if (b)
    sum = 1.0;
  tmp1 = sum/ddj;
  tmp2 = x/ddj;
  return tmp1 + y + tmp2;
}
