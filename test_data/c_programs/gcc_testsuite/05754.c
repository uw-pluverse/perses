


struct A {
  int i;
  int j;
};
struct B {
  struct A a1;
  struct A a2;
};
struct C {
  struct A a1;
  struct B b;
};
int foo(struct C *c, struct B *b)
{
  c->a1.i = 1;
  b->a1.i = 0;
  return c->a1.i;
}
