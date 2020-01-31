


struct A
{
  int a,b;
};

int foo (int x, int y)
{
  int i, j;
  struct A a;

  a.a = x;
  a.b = y;
  j = a.a;
  i = a.b;
  return i + j;
}
