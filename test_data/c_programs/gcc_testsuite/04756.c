


inline int foo(int x)
{
  return x;
}
static void bar(int a, int *ptr)
{
  do
  {
    int b;
    if (b < 40) {
      ptr[0] = b;
    }
    b += 1;
    ptr++;
  }
  while (--a != 0);
}
void foobar(int a, int *ptr)
{
  bar(foo(a), ptr);
}
