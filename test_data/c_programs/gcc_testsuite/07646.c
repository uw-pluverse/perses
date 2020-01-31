


int test1(int a, int b)
{
  return (a ^ b) & a;
}

int test2(int c, int d)
{
  return (c ^ d) & d;
}

int test3(int e, int f)
{
  return e & (e ^ f);
}

int test4(int g, int h)
{
  return g & (h ^ g);
}
