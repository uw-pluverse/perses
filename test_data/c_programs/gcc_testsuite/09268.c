



extern double round(double);
extern double floor(double);
extern double ceil(double);

unsigned long long test1(double x)
{
  return (unsigned long long) round(x);
}

unsigned long long test2(double x)
{
  return (unsigned long long) floor(x);
}
unsigned long long test3(double x)
{
  return (unsigned long long) ceil(x);
}
