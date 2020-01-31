


int bar (int);
void baz (int);

int foo (int y)
{
  int a, b;
  a = bar (7) + 6;
  b = bar (7) + 6;
  return a + b;
}
