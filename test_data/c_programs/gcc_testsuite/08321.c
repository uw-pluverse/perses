



int test1(int a)
{
  return a + ~a;
}

int test2(int b)
{
  return ~b + b;
}

unsigned int test3(unsigned int c)
{
  return c + ~c;
}

unsigned int test4(unsigned int d)
{
  return ~d + d;
}
