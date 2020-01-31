static struct A {
  int p1, p2;
  int e[32];
} a, b, c;

int foo(void)
{
  for (int i = 0; i < 32; i++)
    a.e[i] = b.e[i] + c.e[i];

   return a.e[0];
}
