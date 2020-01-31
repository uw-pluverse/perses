


struct S { int i, j; };

int foo (int l)
{
  struct S s;
  s.j = l - 22;
  return s.i + s.j;
}
