


int b;
unsigned a;
static inline int *g(void)
{
  a = 1;
  return (int*)&a;
}
void f(void)
{
   b = *g();
}
