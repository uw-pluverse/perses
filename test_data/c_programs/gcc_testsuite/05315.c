

int g2;
struct A {
    int a; int b;
}g1;
int foo(int a, int b)
{
  if (a > 0)
    {
      g1.a = a+ b;
    }
  else
    g1.a = b;

  g2 = a+b;

  return g1.a;
}
