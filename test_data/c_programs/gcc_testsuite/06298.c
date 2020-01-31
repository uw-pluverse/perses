


int
foo (int a, int b)
{
  return (a & !a) | (b & (b == 0));
}
