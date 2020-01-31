



typedef struct A
{
  struct A *s, *t;
  unsigned int u;
} A;

void bar (A *);

void
foo (A *x, A *y, A *z)
{
  while (y
  && (((y && y->t && y->t->u) ? y : z)->t
      == ((x && x->t && x->t->u) ? x : z)->t))
    y = y->s;

  if (y)
    bar (y);
}
