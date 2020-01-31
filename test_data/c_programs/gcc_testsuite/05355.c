





int
f (int n, int x, int stride)
{
  int a, x1, x2, x3;

  a = x * stride;
  x1 = x + 3;
  a += x1 * stride;

  if (n > 64)
    {
      x2 = x1 + 3;
      a += x2 * stride;
      x3 = x2 + 3;
      a += x3 * stride;
    }

  return a;
}
