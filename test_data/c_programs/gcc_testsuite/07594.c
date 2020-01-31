



int
foo (int a, int b)
{
  if (a > 3 || a < 0)
    return a;
  a &= 3;
  return a & 3;
}

int
bar (int a)
{
  if (a & ~3)
    return a;
  return a & 3;
}
