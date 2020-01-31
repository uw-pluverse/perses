

int test1(int a)
{
  return !(a & 1);
}

int test2(int b)
{
  return (b & 1) == 0;
}

int test3(int c)
{
  return (c & 1) ^ 1;
}

int test4(int d)
{
  return (d ^ 1) & 1;
}

int test5(int e)
{
  return ~e & 1;
}
