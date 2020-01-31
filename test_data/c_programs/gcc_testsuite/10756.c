

extern void fn3 (void);

void fn2(void)
{
  fn3();
}

void fn1(void)
{
  fn2();
}

void fn4(void)
{
  fn2();
}
