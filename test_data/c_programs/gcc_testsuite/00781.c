


double
foo (int x)
{
  return (double) (float) (x | (int) 0xff000000);
}
