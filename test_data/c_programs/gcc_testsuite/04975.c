



int
foo (int x, int y)
{
  int r;
  return __builtin_sadd_overflow (x, y, &r);
}
