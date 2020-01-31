


extern void abort (void);

int
main (void)
{
  int halfmaxval = 2147483647 / 2 + 1;
  int maxval = halfmaxval - 1 + halfmaxval;
  if (maxval != 2147483647)
    abort ();
  return 0;
}
