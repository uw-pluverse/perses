


struct S { float f; int i; };
struct R { int x; int i; };


int bar(struct S *s, int *i)
{
  *i = 0;
  s->f = 1.0;
  return *i;
}


int foo(struct S *s, struct R *r)
{
  r->i = 0;
  s->i = 1;
  return r->i;
}
