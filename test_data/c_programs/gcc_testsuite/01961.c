







extern void abort (void);

__attribute__ ((noinline))
unsigned __int128
foo (__int128 ixi, unsigned ctr)
{
  unsigned __int128 irslt = 1;
  __int128 ix = ixi;

  for (; ctr; ctr--)
    {
      irslt *= ix;
      ix *= ix;
    }

  if (irslt != 14348907)
    abort ();
  return irslt;
}

int
main ()
{
  unsigned __int128 res;

  res = foo (3, 4);
  return 0;
}
