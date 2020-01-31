


struct A {
    struct B {
 int i;
    } b;
} a;

int foo (void)
{
  struct B *p = &a.b;
  struct A *q = (struct A *) p;
  return q->b.i;
}

int bar (void)
{
  struct A *p = &a;
  struct B *q = (struct B *) p;
  return q->i;
}
