


struct S
{
  int w, x, y, z;
};

struct T
{
  int r;
  struct S s;
};

void link_error (void);
int bar (struct S, int);

void
foo (int a, struct T b)
{
  struct S *c = 0;

  if (a)
    c = &b.s;

  b.s.w = 3;







  bar (*c, a);

  if (b.s.w != 3)
    link_error ();
}

int main ()
{
  struct T b;
  foo (3, b);
  return 0;
}

int X;

int bar (struct S x, int i)
{
  X = 3;
}
