


int b;
unsigned a;

static inline int *g(void)
{
  a = 1;
  return (int*)&a;
}
void test2(void)
{
  b = *g();
}
