


long
foo (long x)
{
  if ((x & 0xffff0000L) == 0xabcd0000L)
    return x & 0xffffL;
  return 1;
}

int
main (void)
{
  if (foo (0xabcd0000L) != 0 || foo (0) != 1)
    abort ();

  exit (0);
}
