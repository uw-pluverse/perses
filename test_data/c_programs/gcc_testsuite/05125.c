





int
f (int n, int x, int stride)
{
  int a, x1, x2, x3;

  a = x * stride;

  if (n > 64)
    {
      x1 = x - 1;
      a += x1 * stride;
      x2 = x1 - 1;
      a += x2 * stride;
    }
  else
    {
      x3 = x - 1;
      a += x3 * stride;
    }

  return a;
}
