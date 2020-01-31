


double
foo (int x)
{
  return (double) (float) (x | (int) 0xfe000000);
}
