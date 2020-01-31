static struct A {
  int p1, p2;
  int e[3];
} a, b, c;

int foo(void)
{
  for (int i = 0; i < 3; i++)
    a.e[i] = b.e[i] + c.e[i];

   return a.e[0];
}
