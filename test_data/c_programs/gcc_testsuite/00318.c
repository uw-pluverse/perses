int
f(int b, int c)
{
  int a = (b >> 16) * (c >> 16);
  if (!a)
    return 10;
  return a;
}
