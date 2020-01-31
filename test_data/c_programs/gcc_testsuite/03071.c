



struct S {
  int a, b;
  void (*f) (long, int);
};

void foo (struct S *x)
{
  long c = x->a * 50;
  c /= (long) x->b;
  c *= (long) x->b;
  x->f (c, 0);
}
