





extern unsigned int x (unsigned int a);

unsigned int f (unsigned int a, unsigned int b)
{
  return x (a) << b;
}

unsigned int g (unsigned int a)
{
  return x (a) << 24;
}

unsigned int h (unsigned int a, unsigned int b)
{
  return x (a) >> b;
}

unsigned int i (unsigned int a, unsigned int b)
{
  return x (a) >> 24;
}
