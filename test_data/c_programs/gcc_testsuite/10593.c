


int f(unsigned a, unsigned b, unsigned *c)
{
  if (a > -1 / b)
    return -1;
  *c = a * b;
  return 0;
}

void g(unsigned long long a, unsigned long long b, unsigned long long *c)
{
  if (a <= -1 / b)
    *c = a * b;
}
