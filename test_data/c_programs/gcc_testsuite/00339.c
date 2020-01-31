int
f(int a, int b, int c)
{
  a -= (b >> 16) * (c >> 16);
  return a;
}
