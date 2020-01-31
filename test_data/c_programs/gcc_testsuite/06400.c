


int test1(int a, int b)
{
  return ~a == ~b;
}

int test2(int c, int d)
{
  return -c == -d;
}

int test3(int e)
{
  return -e == 5;
}

int test4(int f)
{
  return ~f == 5;
}

int test5(int g, int h)
{
  return ~g < ~h;
}

int test6(int i, int j)
{
  return ~i >= ~j;
}

int test7(int k)
{
  return ~k < 3;
}

int test8(int l)
{
  return ~l >= 2;
}
