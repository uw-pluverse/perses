


struct X { int a[256]; };

int foo(struct X *p, long unsigned int i)
{
  int *q = &p->a[0];
  int *q2 = (int *)((void *)q + i*4 + 32);
  return *q2;
}

int bar(struct X *p, int i)
{
  return *((int *)p + i + 8);
}
