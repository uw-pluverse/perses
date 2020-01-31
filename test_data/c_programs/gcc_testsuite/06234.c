



struct S { volatile int i; volatile int j; };

int
bar (struct S *x, int y)
{
  int r;
  if (y)
    r = x->i;
  else
    r = x->j;
  return r;
}
