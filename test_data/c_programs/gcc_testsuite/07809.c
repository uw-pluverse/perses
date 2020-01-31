long p;

long foo(void)
{
  {
    long xyzzy = 0;
    if (p)
      xyzzy = 2;
    return xyzzy;
  }
}
