





extern void abort (void);

void __attribute__((noinline))
foo (long x)
{
  if (x >= 1024)
    abort ();
}

int
main ()
{
  foo ((-9223372036854775807L -1L));
  foo ((-9223372036854775807L -1L) + 10000);
  return 0;
}
