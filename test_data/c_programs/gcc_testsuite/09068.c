int foo (int b, int c, int d)
{
  static __thread int a=1;
  a += b;
  a -= c;
  a += d;
  return a;
}
