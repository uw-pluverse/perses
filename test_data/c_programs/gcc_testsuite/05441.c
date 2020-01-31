




int foo (int x, int a, int b)
{
  int c = 1 << a;
  if (x & c)
    if (x & (1 << b))

      return 2;
  return 0;
}
