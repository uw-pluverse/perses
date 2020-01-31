extern unsigned int x (unsigned int a);

unsigned int f (unsigned int a, unsigned int b)
{
  return x (a) & b;
}

unsigned int g (unsigned int a)
{
  return a & 31;
}

unsigned int h (unsigned int a, unsigned int b)
{
  return x (a) | b;
}

unsigned int i (unsigned int a, unsigned int b)
{
  return x (a) ^ b;
}

unsigned int j (unsigned int a)
{
  return ~a;
}
