





void fn (void *);

void f2 (void)
{
  unsigned long long a __attribute__((aligned (8)));
  fn (&a);
}

void f3 (void)
{
  typedef unsigned long long L __attribute__((aligned (8)));
  L a;
  fn (&a);
}

void f4 (void)
{
  unsigned long long a __attribute__((aligned (16)));
  fn (&a);
}

void f5 (void)
{
  typedef unsigned long long L __attribute__((aligned (16)));
  L a;
  fn (&a);
}
