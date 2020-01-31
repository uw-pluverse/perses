extern double pow (double, double);
extern float powf (float, float);
extern long double powl (long double, long double);
extern double tan (double);
extern float tanf (float);
extern long double tanl (long double);
extern double atan (double);
extern float atanf (float);
extern long double atanl (long double);

extern void link_error(void);

void test(double x)
{
  if (pow (x, 1.0) != x)
    link_error ();
  if (tan (atan (x)) != x)
    link_error ();
}

void testf(float x)
{
  if (powf (x, 1.0f) != x)
    link_error ();
  if (tanf (atanf (x)) != x)
    link_error ();
}

void testl(long double x)
{
  if (powl (x, 1.0l) != x)
    link_error ();
  if (tanl (atanl (x)) != x)
    link_error ();
}

int main()
{
  test (2.0);
  testf (2.0f);
  testl (2.0l);

  return 0;
}
