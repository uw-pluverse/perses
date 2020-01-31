unsigned int
f(unsigned int a, unsigned int b, unsigned int c)
{
  a += (unsigned short)b * (unsigned short)c;
  if (!a)
    return 10;
  return a;
}
