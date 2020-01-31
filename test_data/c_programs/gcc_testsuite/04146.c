

unsigned int
foo (int x, unsigned int y, unsigned int z)
{
  z &= (x == -2147483647 - 1 ? x : -x) > y;
  z &= (x == -2147483647 - 1 ? x : -x) > y;
  z &= (x == -2147483647 - 1 ? x : -x) > y;
  z &= (x == -2147483647 - 1 ? x : -x) > y;
  return z;
}
