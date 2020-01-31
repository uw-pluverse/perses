double
builtin_fma (double b, double c, double d)
{
  return __builtin_fma (b, c, d);
}

float
builtin_fmaf (float b, float c, float d)
{
  return __builtin_fmaf (b, c, -d);
}
