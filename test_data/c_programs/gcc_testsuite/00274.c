

struct test
  {
    long a __attribute__((aligned (16)));
  };

void test (struct test a)
{
}
