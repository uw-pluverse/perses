







struct A
{
  int a : 4;
  int : 2;
  int b : 2;
  int : 2;
  int c : 2;
  int d : 1;
  int e;
};
struct B
{
  int a : 4;
} *a;
void bar (struct A);

void
foo (void)
{
  struct B b = a[0];
  struct A c;
  c.a = b.a;
  c.b = 1;
  c.c = 1;
  c.d = 0;
  bar (c);
}
