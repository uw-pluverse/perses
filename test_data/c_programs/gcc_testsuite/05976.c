


struct X { struct A { int a[2]; } b[10]; };
void foo (struct X *x, int i)
{
  struct A a;


  a.a[i] = 3;
  a.a[1] = 0;

  x->b[i].a[0] = 1;
  x->b[i] = a;
}
