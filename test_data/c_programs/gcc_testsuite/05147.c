






int
f (int c, int i)
{
  int a1, a3, x1, x3, x;

  a1 = i * 16;
  x1 = c + a1;

  if (x1 > 6)
    i = i + 2;

  i = i + 2;
  a3 = i * 16;
  x3 = c + a3;

  x = x1 + x3;
  return x;
}
