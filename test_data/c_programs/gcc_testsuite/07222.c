


long __attribute__((noinline, noclone))
foo (long a)
{
  return a + 5;
}

static long g;

long __attribute__((noinline, noclone))
bar (long a)
{
  long r;

  if (a)
    {
      r = a;
      while (r < 500)
 if (r % 2)
   r = foo (r);
 else
   r = foo (r+1);
      g = r + a;
    }
  else
    r = g+1;
  return r;
}
