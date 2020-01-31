
extern void abort ();

int test1(int x)
{
  return (x ^ (-2147483647 -1)) ^ 0x1234;
}

unsigned int test1u(unsigned int x)
{
  return (x ^ (unsigned int)(-2147483647 -1)) ^ 0x1234;
}

int test2(int x)
{
  return (x ^ 0x1234) ^ (-2147483647 -1);
}

unsigned int test2u(unsigned int x)
{
  return (x ^ 0x1234) ^ (unsigned int)(-2147483647 -1);
}

int test3(int x)
{
  return (x + (-2147483647 -1)) ^ 0x1234;
}

unsigned int test3u(unsigned int x)
{
  return (x + (unsigned int)(-2147483647 -1)) ^ 0x1234;
}

int test4(int x)
{
  return (x ^ 0x1234) + (-2147483647 -1);
}

unsigned int test4u(unsigned int x)
{
  return (x ^ 0x1234) + (unsigned int)(-2147483647 -1);
}

int test5(int x)
{
  return (x - (-2147483647 -1)) ^ 0x1234;
}

unsigned int test5u(unsigned int x)
{
  return (x - (unsigned int)(-2147483647 -1)) ^ 0x1234;
}

int test6(int x)
{
  return (x ^ 0x1234) - (-2147483647 -1);
}

unsigned int test6u(unsigned int x)
{
  return (x ^ 0x1234) - (unsigned int)(-2147483647 -1);
}

int test7(int x)
{
  int y = (-2147483647 -1);
  int z = 0x1234;
  return (x ^ y) ^ z;
}

unsigned int test7u(unsigned int x)
{
  unsigned int y = (unsigned int)(-2147483647 -1);
  unsigned int z = 0x1234;
  return (x ^ y) ^ z;
}

int test8(int x)
{
  int y = 0x1234;
  int z = (-2147483647 -1);
  return (x ^ y) ^ z;
}

unsigned int test8u(unsigned int x)
{
  unsigned int y = 0x1234;
  unsigned int z = (unsigned int)(-2147483647 -1);
  return (x ^ y) ^ z;
}

int test9(int x)
{
  int y = (-2147483647 -1);
  int z = 0x1234;
  return (x + y) ^ z;
}

unsigned int test9u(unsigned int x)
{
  unsigned int y = (unsigned int)(-2147483647 -1);
  unsigned int z = 0x1234;
  return (x + y) ^ z;
}

int test10(int x)
{
  int y = 0x1234;
  int z = (-2147483647 -1);
  return (x ^ y) + z;
}

unsigned int test10u(unsigned int x)
{
  unsigned int y = 0x1234;
  unsigned int z = (unsigned int)(-2147483647 -1);
  return (x ^ y) + z;
}

int test11(int x)
{
  int y = (-2147483647 -1);
  int z = 0x1234;
  return (x - y) ^ z;
}

unsigned int test11u(unsigned int x)
{
  unsigned int y = (unsigned int)(-2147483647 -1);
  unsigned int z = 0x1234;
  return (x - y) ^ z;
}

int test12(int x)
{
  int y = 0x1234;
  int z = (-2147483647 -1);
  return (x ^ y) - z;
}

unsigned int test12u(unsigned int x)
{
  unsigned int y = 0x1234;
  unsigned int z = (unsigned int)(-2147483647 -1);
  return (x ^ y) - z;
}


void test(int a, int b)
{
  if (test1(a) != b)
    abort();
  if (test2(a) != b)
    abort();
  if (test3(a) != b)
    abort();
  if (test4(a) != b)
    abort();
  if (test5(a) != b)
    abort();
  if (test6(a) != b)
    abort();
  if (test7(a) != b)
    abort();
  if (test8(a) != b)
    abort();
  if (test9(a) != b)
    abort();
  if (test10(a) != b)
    abort();
  if (test11(a) != b)
    abort();
  if (test12(a) != b)
    abort();
}

void testu(unsigned int a, unsigned int b)
{
  if (test1u(a) != b)
    abort();
  if (test2u(a) != b)
    abort();
  if (test3u(a) != b)
    abort();
  if (test4u(a) != b)
    abort();
  if (test5u(a) != b)
    abort();
  if (test6u(a) != b)
    abort();
  if (test7u(a) != b)
    abort();
  if (test8u(a) != b)
    abort();
  if (test9u(a) != b)
    abort();
  if (test10u(a) != b)
    abort();
  if (test11u(a) != b)
    abort();
  if (test12u(a) != b)
    abort();
}


int main()
{

  test(0x00000000,0x80001234);
  test(0x00001234,0x80000000);
  test(0x80000000,0x00001234);
  test(0x80001234,0x00000000);
  test(0x7fffffff,0xffffedcb);
  test(0xffffffff,0x7fffedcb);

  testu(0x00000000,0x80001234);
  testu(0x00001234,0x80000000);
  testu(0x80000000,0x00001234);
  testu(0x80001234,0x00000000);
  testu(0x7fffffff,0xffffedcb);
  testu(0xffffffff,0x7fffedcb);
  return 0;
}
