static inline int
foo (void *x, unsigned y)
{
  unsigned z = *(unsigned long *) x % y;
  *(unsigned long *) x = *(unsigned long *) x / y;
  return z;
}

struct S
{
  unsigned t;
};

void
bar (struct S *x, int *y)
{
  int a = 0;
  unsigned long b = x->t;
  foo (&b, x->t);
  for (;; a++)
    if (b)
      *y = 1;
}
