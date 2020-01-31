



struct S
{
  int n;
};

int
foo (struct S s, double a)
{
  return s.n * a;
}
