



struct X { int a[5]; };
int foo(struct X *q)
{
  int (*pointer)[5] = &q->a;
  return (*pointer)[0];
}
