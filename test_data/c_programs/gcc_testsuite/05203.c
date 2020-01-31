


struct X { int i; };

int foo (int x)
{
  struct X a;
  struct X b;
  struct X *p;
  a.i = 1;
  b.i = 2;
  if (x)
    p = &a;
  else
    p = &b;
  return p->i;
}
