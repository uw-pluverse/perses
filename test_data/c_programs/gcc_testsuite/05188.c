






int foo (void);

struct A {
  struct B {
    struct B *n;
  } *p;
};

static inline void baz (struct A *a)
{
  a->p = a->p->n;
}

void bar (struct A a)
{
  while (foo ())
    baz (&a);
  while (foo ());
}
