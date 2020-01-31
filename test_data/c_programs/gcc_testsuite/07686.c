


int
foo (int a, int b, int c)
{
  return ((a & ~b) | (~a & b)) & c;
}
