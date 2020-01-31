



int g;

void foo (int x)
{
  g = x;
}

void bar (double d)
{
  foo (d == 1);
}

void baz (int a)
{
  bar (1);
}
