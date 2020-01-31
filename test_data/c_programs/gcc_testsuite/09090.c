double cabs (__complex__ double);
float cabsf (__complex__ float);
long double cabsl (__complex__ long double);
double fabs (double);
float fabsf (float);
long double fabsl (long double);

void link_error (void);

void test (double x)
{
  if (cabs (x) != fabs (x))
    link_error ();
}

void testf (float x)
{
  if (cabsf (x) != fabsf (x))
    link_error ();
}

void testl (long double x)
{
  if (cabsl (x) != fabsl (x))
    link_error ();
}

int main ()
{
  test (1.0);
  testf (1.0f);
  testl (1.0l);
  return 0;
}
