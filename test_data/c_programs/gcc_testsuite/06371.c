extern double log10(double);
extern double log2(double);
extern double log1p(double);
extern float log10f(float);
extern float log2f(float);
extern float log1pf(float);
extern long double log10l(long double);
extern long double log2l(long double);
extern long double log1pl(long double);


double test1(double x)
{
  return log10(x);
}

double test2(double x)
{
  return log2(x);
}

double test3(double x)
{
  return log1p(x);
}

float test1f(float x)
{
  return log10f(x);
}

float test2f(float x)
{
  return log2f(x);
}

float test3f(float x)
{
  return log1pf(x);
}

long double test1l(long double x)
{
  return log10l(x);
}

long double test2l(long double x)
{
  return log2l(x);
}

long double test3l(long double x)
{
  return log1pl(x);
}
