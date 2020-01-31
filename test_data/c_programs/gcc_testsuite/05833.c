


struct A
{
  int a;
  int b;
};

int
foo (struct A *p, struct A *q)
{
  int x = p->a;
  if (p == q)
    return q->a;




  if (p)
    return x + p->b;
}
