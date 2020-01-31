


struct A
{
  int a,b;
};

int foo (int x, int y)
{
  int i, j;
  struct A a,b;

  a.a = x;
  b.b = y;
  j = a.a;
  i = b.b;
  return i + j;
}
