






double a[1000000];

double test(void)
{
  unsigned i;
  double sum = 0;

  for (i = 0; i < 1000000; i += 2)
    sum += (a[i] * a[i+1]);

  return sum;
}
