





extern double sqrt(double);
extern float sqrtf(float);

double foo(double x)
{
  return 1.0/sqrt(x);
}

double bar(double x)
{
  return sqrt(1.0/x);
}

float foof(float x)
{
  return 1.0f/sqrtf(x);
}

float barf(float x)
{
  return sqrtf(1.0f/x);
}
