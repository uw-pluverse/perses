






long p;

long foo(void)
{
  if (1)
    {
      long xyzzy = 0;
      if (p)
        xyzzy = 2;
      return xyzzy;
    }
  else
    {
      int x = 0;
      return x;
    }
}
