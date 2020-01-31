



unsigned int foo(long long high, int unsigned_p)
{
  int i;
  if (high < 0)
    if (!unsigned_p)
    {
      i = 1;
      goto t;
    }
  i = 0;
t:
  return i;
}
