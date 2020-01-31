







extern void abort (void);

void
testc (unsigned char c, int ok)
{
  if ((c>=1) && (c<=127))
    {
      if (!ok) abort ();
    }
  else
    if (ok) abort ();
}

void
tests (unsigned short s, int ok)
{
  if ((s>=1) && (s<=32767))
    {
      if (!ok) abort ();
    }
  else
    if (ok) abort ();
}

void
testi (unsigned int i, int ok)
{
  if ((i>=1) && (i<=2147483647))
    {
      if (!ok) abort ();
    }
  else
    if (ok) abort ();
}

void
testl (unsigned long l, int ok)
{
  if ((l>=1) && (l<=9223372036854775807L))
    {
      if (!ok) abort ();
    }
  else
    if (ok) abort ();
}

int
main ()
{
  testc (0, 0);
  testc (1, 1);
  testc (127, 1);
  testc (127 +1, 0);
  testc ((127*2 +1), 0);

  tests (0, 0);
  tests (1, 1);
  tests (32767, 1);
  tests (32767 +1, 0);
  tests ((32767 *2 +1), 0);

  testi (0, 0);
  testi (1, 1);
  testi (2147483647, 1);
  testi (2147483647 +1U, 0);
  testi ((2147483647 *2U +1U), 0);

  testl (0, 0);
  testl (1, 1);
  testl (9223372036854775807L, 1);
  testl (9223372036854775807L +1UL, 0);
  testl ((9223372036854775807L *2UL+1UL), 0);

  return 0;
}
