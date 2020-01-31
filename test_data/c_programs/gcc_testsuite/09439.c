







extern void abort (void);

__attribute__ ((noinline))
unsigned long long
foo (long long ixi, unsigned ctr)
{
  unsigned long long irslt = 1;
  long long ix = ixi;

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
  unsigned long long res;

  res = foo (3, 4);
  return 0;
}
