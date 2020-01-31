int
f(unsigned int b, unsigned int c)
{
  unsigned int a = (unsigned short)b * (c >> 16);
  if (!a)
    return 10;
  return a;
}
