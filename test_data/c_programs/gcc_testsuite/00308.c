unsigned int
f(unsigned int b, unsigned int c)
{
  unsigned int a = (unsigned short)b * (unsigned short)c;
  if (!a)
    return 10;
  return a;
}
