


int *
fx (int *a, int sz)
{
  int *b = a + sz;
  b = b - sz;

  return b;
}
