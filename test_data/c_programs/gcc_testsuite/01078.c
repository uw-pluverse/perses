



int foo(double x, double y)
{
  if (__builtin_fabs(x) > __builtin_fabs(y))
    return 0;
}
