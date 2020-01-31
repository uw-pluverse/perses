


struct f
{
  int i;
  int j;
};

struct g
{
  int i;
  struct f j;
  struct f *k;
};

int foo(struct f *x, struct f *y)
{
  return &x->j == &y->j;
}

struct f y;
int bar(struct f *x)
{
  return &x->j == &y.j;
}

struct g yy;
int foobar(struct g *x)
{
  return &x->j.i == &yy.j.i;
}
int foobar2(struct g *x)
{
  return &x->k->i == &yy.k->i;
}
