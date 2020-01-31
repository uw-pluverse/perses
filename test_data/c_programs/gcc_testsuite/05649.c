



int f(int *p, int n)
{
  int (*a)[n] = (int (*)[n])p;
  int *q = &(*a)[0];
  return q[1];
}

int g(int *p, int n)
{
  int (*a)[n] = (int (*)[n])p;
  int *q = &(*a)[2];
  return q[-1];
}
