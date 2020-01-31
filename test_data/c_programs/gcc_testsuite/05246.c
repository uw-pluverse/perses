


double test1 (double x, double y, double z, double weight)
{
  double tmp1 = x / weight;
  double tmp2 = y / weight;
  double tmp3 = -x / weight;
  return tmp1 + tmp2 + tmp3;
}
