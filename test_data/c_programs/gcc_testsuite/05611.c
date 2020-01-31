




int foo (unsigned b)
{
  unsigned t = -1;
  int x = b <= t;
  long l = __builtin_expect (x, 0);
  return l;
}
