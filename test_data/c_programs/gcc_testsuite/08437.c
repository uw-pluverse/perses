


int
main ()
{
  if (__builtin_strcmp ("Jun 18 2016", "Dec 22 1989") != 0
      || __builtin_strcmp ("04:07:46", "12:34:56") != 0)
    __builtin_abort ();
  return 0;
}
