


extern void foo();

void test1(int a)
{
  if ((a >> 3) & 1)
    foo ();
}

void test2(int b)
{
  if ((b >> 3) & 4)
    foo ();
}

int test3(int c)
{
  return (c >> 3) & 1;
}

int test4(int d)
{
  return (d >> 3) & 4;
}
void test5(int e)
{
  if ((e >> (32 - 1)) & 64)
    foo();
}

void test6(unsigned int f)
{
  if ((f >> (32 - 1)) & 64)
    foo();
}
