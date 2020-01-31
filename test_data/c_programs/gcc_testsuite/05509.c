


union X { int i; double x; };

int foo (union X *p)
{
  union X x = *p;
  return x.x;
}
