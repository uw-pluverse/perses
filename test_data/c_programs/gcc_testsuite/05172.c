


struct C { int i; };
int *g(struct C *p)
{
  if (p)
    return &p->i;
  return (int *)0;
}
