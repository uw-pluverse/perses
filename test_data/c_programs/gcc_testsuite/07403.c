







struct S
{
  int e[32];
};

static struct A {
  int p1, p2;
  struct S s;
} a, b, c;

int foo(void)
{
  for (int i = 0; i < 32; i++)
    a.s.e[i] = b.s.e[i] + c.s.e[i];

   return a.s.e[0];
}
