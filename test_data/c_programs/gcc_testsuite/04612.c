


__attribute__((noinline, noclone)) int
foo1 (int x, int y)
{
  return x - y;
}

__attribute__((noinline, noclone)) int
foo2 (int x, int y)
{
  unsigned int xa = (unsigned int) x - (2147483647 - 3);
  xa &= 3;
  x = 2147483647 - 3 + xa;
  unsigned int ya = y + 1U;
  ya &= 1;
  y = ya - 1;
  return x - y;
}

int
main ()
{
  int xm1, y;
  for (xm1 = 2147483647 - 4; xm1 < 2147483647; xm1++)
    for (y = -1; y <= 0; y++)
      if (foo1 (xm1 + 1, y) != (int) (xm1 + 1U - y)
   || foo2 (xm1 + 1, y) != (int) (xm1 + 1U - y))
 __builtin_abort ();
  return 0;
}
