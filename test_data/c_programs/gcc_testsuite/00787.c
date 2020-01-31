


double
foo (unsigned int x)
{
  return (double) (float) (x & 0xffffff00);
}
