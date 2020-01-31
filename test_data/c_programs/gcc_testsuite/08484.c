







int
main (void)
{
  if (__builtin_memcmp ("", "//", 3) != 0)
    __builtin_abort ();
  return 0;
}
