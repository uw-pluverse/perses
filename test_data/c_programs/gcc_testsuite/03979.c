



void
foo (long x)
{
  if (((x >> -2) & 1) != 0)
    bar ();
}
