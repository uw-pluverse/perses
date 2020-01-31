int test (double a, double b) __attribute__ ((noinline));
int test (double a, double b)
{
  return a <= b;
}

int main (void)
{
  double x = 0.0;
  double y = 0.0/0.0;
  return test (x, y);
}
