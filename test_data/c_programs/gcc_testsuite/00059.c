



void fn1 (int *, ...);
int fn2 (int p1)
{
  fn1 (0, (short)(int)&p1);
  return 0;
}
