


struct X { int i; };
struct X foo(int b)
{
  struct X x;
  if (b)
    x.i = 0;
  x.i = 1;
  return x;
}
