


int foo (int x, int b)
{
  int cst;
  if (b)
    cst = -2147483647 - 1;
  else
    cst = -2147483647;
  x = x | cst;
  if (x >= 0)
    return 12345;
  return x;
}

int bar (int x, int b)
{
  int cst;
  if (b)
    cst = 2147483647;
  else
    cst = 2147483647 - 1;
  x = x & cst;
  if (x < 0)
    return 12345;
  return x;
}
