extern void abort(void);
extern double pow(double, double);
extern double sqrt(double);
extern double cbrt(double);

void test(double x)
{
  if (pow(x,-1.0) != 1.0/x)
    abort ();

  if (pow(x,2.0) != x*x)
    abort ();

  if (pow(x,-2.0) != 1.0/(x*x))
    abort ();

  if (pow(x,0.5) != sqrt(x))
    abort ();





}

int main()
{
  test (1.0);
  test (2.0);
  return 0;
}
