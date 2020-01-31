


struct X { int i; int j; };
void bar (struct X *);
int foo (struct X *p)
{
  struct X x;
  p->i = 1;
  x = *p;
  x.j = 2;
  return p->i - x.i;
}
