unsigned int
f(unsigned int a, unsigned int b, unsigned int c)
{
  a += (unsigned short)b * (c >> 16);
  if (!a)
    return 10;
  return a;
}
