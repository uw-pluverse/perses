struct A
{
  char *a;
  unsigned int b : 1;
  unsigned int c : 31;
};


struct B
{
  struct A *d;
};

void
foo (struct B *x, unsigned long y)
{
  if (x->d[y].c)
    return;
  if (x->d[y].b)
    x->d[y].a = 0;
}
