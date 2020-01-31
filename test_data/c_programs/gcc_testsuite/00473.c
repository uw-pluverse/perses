




long
do_ext_add (int *p, long a, long b)
{
  long l = *p;
  long l2 = l << 4;
  return l2 + ((l2 == 0) ? a : b);
}

long
do_ext (int *p, long a, long b)
{
  long l = *p;
  long l2 = l << 4;
  return ((l2 == 0) ? a : b);
}
