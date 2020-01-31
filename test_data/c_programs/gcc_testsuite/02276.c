


__attribute__((noinline, noclone)) unsigned int
foo (int x)
{
  unsigned long long y = -1ULL >> x;
  return (unsigned int) y >> 31;
}


int
main ()
{

  if (foo (15) != 1 || foo (32) != 1 || foo (33) != 0)
    __builtin_abort ();

  return 0;
}
