


long __attribute__((noinline, noclone))
foo (long a)
{
  return a + 5;
}

static long g __attribute__ ((used));

long __attribute__((noinline, noclone))
bar (long a)
{
  long r;

  if (a)
    {
      r = foo (a);
      g = r + a;
    }
  else
    r = a+1;
  return r;
}
