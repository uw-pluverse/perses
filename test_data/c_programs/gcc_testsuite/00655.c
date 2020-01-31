


double
foo (int x)
{
  return (double) (float) ((x & -16) | (int) 0xf0000000);
}
