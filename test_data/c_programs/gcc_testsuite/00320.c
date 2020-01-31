int
f(int a, int b, int c)
{
  a += (b >> 16) * (c >> 16);
  if (!a)
    return 10;
  return a;
}
