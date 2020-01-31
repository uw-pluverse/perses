



struct S { unsigned f : 1; };
int a, d;

int
foo (void)
{
  unsigned b = 0;
  struct S c;
  d = ((1 && b) < c.f) & c.f;
  return a;
}

int
bar (_Bool c)
{
  unsigned b = 0;
  d = ((1 && b) < c) & c;
  return a;
}
