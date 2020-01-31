
extern void abort (void);
extern double sqrt (double);

int test1(double x)
{
  return sqrt(x) < -9.0;
}

int test2(double x)
{
  return sqrt(x) > -9.0;
}

int test3(double x)
{
  return sqrt(x) < 9.0;
}

int test4(double x)
{
  return sqrt(x) > 9.0;
}

int test5(double x)
{
  return sqrt(x) < 1.7976931348623157e+308;
}

int test6(double x)
{
  return sqrt(x) > 1.7976931348623157e+308;
}

int main()
{
  double x;

  x = 80.0;
  if (test1 (x))
    abort ();
  if (! test2 (x))
    abort ();
  if (! test3 (x))
    abort ();
  if (test4 (x))
    abort ();
  if (! test5 (x))
    abort ();
  if (test6 (x))
    abort ();

  x = 100.0;
  if (test1 (x))
    abort ();
  if (! test2 (x))
    abort ();
  if (test3 (x))
    abort ();
  if (! test4 (x))
    abort ();
  if (! test5 (x))
    abort ();
  if (test6 (x))
    abort ();

  return 0;
}
