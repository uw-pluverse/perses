


struct A {
  int i;
  int j;
  float x;
};
struct B {
  struct A a;
  int k;
};

int g;

int test0 (struct A *p, struct A *q)
{
  p->i = 0;
  q->j = -1;
  return p->i;
}

int test1 (struct A *p, struct B *q)
{
  p->i = 1;
  q->k = -1;
  return p->i;
}

int test2 (struct A *p, struct B *q)
{
  p->i = 2;
  q->a.i = -1;
  return p->i;
}

int test3 (struct A *p, struct B *q)
{
  p->i = 3;
  q->a.j = -1;
  return p->i;
}

int test4 (struct A *p)
{
  g = 4;
  p->i = -1;
  return g;
}

int test5 (struct A *p)
{
  p->i = 5;
  g = -1;
  return p->i;
}

int test6 (struct A *p, int *q)
{
  p->i = 6;
  *q = -1;
  return p->i;
}

int test7 (struct A *p, int *q)
{
  p->j = 7;
  *q = -1;
  return p->j;
}

int test8 (struct A *p, int *q)
{
  *q = 8;
  p->x = -1;
  return *q;
}
