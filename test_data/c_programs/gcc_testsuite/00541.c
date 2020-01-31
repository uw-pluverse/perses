int
f(int b, int c)
{
  int a = (short)b * (short)c;
  if (!a)
    return 10;
  return a;
}
