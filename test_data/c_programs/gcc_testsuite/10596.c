extern double asin(double);
extern double acos(double);
extern float asinf(float);
extern float acosf(float);
extern long double asinl(long double);
extern long double acosl(long double);


double test1(double x)
{
  return asin(x);
}

double test2(double x)
{
  return acos(x);
}

float test1f(float x)
{
  return asinf(x);
}

float test2f(float x)
{
  return acosf(x);
}

long double test1l(long double x)
{
  return asinl(x);
}

long double test2l(long double x)
{
  return acosl(x);
}
