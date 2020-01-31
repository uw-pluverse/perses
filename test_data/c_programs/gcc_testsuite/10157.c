




int f(int c, int b, int d)
{
  int r, r2, e;

  if (c)
    {
      r = b + d;
      r2 = d - b;
    }
  else
    {
      r2 = d - b;
      e = d + b;
      r = e;
    }

  return r - r2;
}
