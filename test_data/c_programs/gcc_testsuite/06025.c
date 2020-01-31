






int
f (int s, int c, int i)
{
  int a1, a2, a3, x1, x2, x3, x;

  a1 = i * s;
  x1 = c + a1;

  i = i - 2;
  a2 = i * s;
  x2 = c + a2;

  if (x2 > 6)
    i = i - 2;

  i = i - 2;
  a3 = i * s;
  x3 = c + a3;

  x = x1 + x2 + x3;
  return x;
}
