int
f(int b, int c)
{
  int a = (short)b * (c >> 16);
  if (!a)
    return 10;
  return a;
}
