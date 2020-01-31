


int
main (void)
{
  volatile float a = 1.3f;
  volatile double b = 0.0;
  volatile int c = 4;
  volatile float res;

  res = a / b;
  res = a / 0.0;
  res = 2.7f / b;
  res = 3.6 / (b = 0.0, b);
  res = c / b;
  res = b / c;

  return 0;
}
