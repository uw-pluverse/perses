int
f(int a, int b, int c)
{
  a += (short)b * (short)c;
  if (!a)
    return 10;
  return a;
}
