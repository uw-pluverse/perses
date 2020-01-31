

struct S
{
  int w, x, y, z;
};
struct T
{
  int r;
  struct S s;
};
void bar (struct S, int);
void
foo (int a, struct T b)
{
  struct S x;
  struct S *c = &x;
  if (a)
    c = &b.s;
  bar (*c, a);
}
