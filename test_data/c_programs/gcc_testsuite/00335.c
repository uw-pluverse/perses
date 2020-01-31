unsigned int
f(unsigned int a, unsigned int b, unsigned int c)
{
  a += (b >> 16) * (c >> 16);
  if (!a)
    return 10;
  return a;
}
