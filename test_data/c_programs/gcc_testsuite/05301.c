




int
f (int s, int c)
{
  int a1, a2, a3, x1, x2, x3, x;

  a1 = 2 * s;
  x1 = c - a1;
  a2 = 4 * s;
  x2 = c - a2;
  a3 = 6 * s;
  x3 = c - a3;
  x = x1 + x2 + x3;
  return x;
}
