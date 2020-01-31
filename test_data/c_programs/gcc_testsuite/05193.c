


unsigned int test1(unsigned int a)
{
  return (a & 1) | 1;
}

int test2(int b)
{
  return (b & 1) | 1;
}

unsigned int test3(unsigned int c)
{
  return (c | 1) & 1;
}

int test4(int d)
{
  return (d | 1) & 1;
}

unsigned int test5(unsigned int e)
{
  return (e | 4) & 6;
}

int test6(int f)
{
  return (f | 4) & 6;
}

unsigned int test7(unsigned int g)
{
  return (g & -2) | 1;
}

int test8(int h)
{
  return (h & -2) | 1;
}

unsigned int test9(unsigned int i)
{
  return (i & 3) | 1;
}

int test10(int j)
{
  return (j & 3) | 1;
}
