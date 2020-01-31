extern int isinf(double);
extern int isinff(float);
extern int isinfl(long double);

int test1(double x)
{
  return isinf(x);
}

int test1f(float x)
{
  return isinff(x);
}

int test1l(long double x)
{
  return isinfl(x);
}
