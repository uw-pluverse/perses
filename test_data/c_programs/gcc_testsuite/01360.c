




struct S
{
  void *s;
  struct T { unsigned short a; unsigned char b[4], c[4]; } *t;
} s;
void bar (void *);

void
foo (struct S *x, int *y)
{
  if (*y > 0)
    return;
  else if (x->t->b[0] == 0x43 && x->t->b[1] == 0x6d && x->t->c[0] == 1)
    x->s = &s;
  else
    *y = 16384;
  if (*y > 0)
    bar (x);
}
