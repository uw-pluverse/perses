




int bar (float);

struct A {
  float a1;
  int a2;
} a;

int b;

void foo (void)
{
  a.a2 = bar (a.a1);
  a.a2 = a.a2 < b - 1 ? a.a2 : b - 1;
  if (a.a2 >= b - 1)
    abort ();
}

int bar (float x)
{
  return 2241;
}

int main()
{
  a.a1 = 1.0f;
  b = 3384;
  foo ();
  return 0;
}
