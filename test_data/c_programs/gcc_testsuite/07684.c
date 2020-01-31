


int
foo (unsigned long a, long b)
{
  return (a & !a) | (b & (b == 0));
}
