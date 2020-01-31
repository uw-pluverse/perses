


void foo(int *p, double *x, int n)
{
  int i;
  for (i = 0; i < n; ++i)
    *(x + *p * i) = 0.0;
}
