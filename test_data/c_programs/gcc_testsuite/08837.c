double test(__complex__ double x)
{
  return __builtin_cabs (x);
}

float testf(__complex__ float x)
{
  return __builtin_cabsf (x);
}

long double testl(__complex__ long double x)
{
  return __builtin_cabsl (x);
}
