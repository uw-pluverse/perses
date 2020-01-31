




double
foo (double x, double y)
{
  volatile int i = 0;
  return i != 0 ? x : y;
}
