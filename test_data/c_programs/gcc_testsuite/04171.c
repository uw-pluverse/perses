


foo (a)
     unsigned a;
{
  return ((a & ((1 << 20) - 1)) << 1) > 0;
}
