


struct S
{
  int a, b, c;
  int z[20];
};

int foo (int d)
{
  struct S s;

  s.a = d;
  return s.a + s.b;
}
