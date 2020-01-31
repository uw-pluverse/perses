



extern int a, b;

double
foo (double x)
{
  for (; a > b; a--)
    x *= (double) a;
  return x;
}
