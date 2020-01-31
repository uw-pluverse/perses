


int glob;

void
fn2(int ** q)
{
  *q = &glob;
}

void test()
{
  int *p;

  fn2(&p);

  *p=42;
}

int main()
{
  test();
  if (glob != 42) abort();
  exit (0);
}
