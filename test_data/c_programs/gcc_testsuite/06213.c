



struct A { int i; };

static inline struct A *
bar (struct A *x)
{
  return x;
}

void *
foo (struct A *x, int y)
{
  void *p = (void *) 0;
  if (__builtin_expect (y >= 6, 0))
    p = bar (x);
  return p;
}
