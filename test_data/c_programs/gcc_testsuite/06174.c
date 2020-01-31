



extern int fn (void);

void
foo (int i)
{
  unsigned int f = 9;


  f += fn () || i;
  f += fn () && i;
  f += ! fn ();
  f -= fn () == i;
  f |= fn () != i;
  f &= fn () < i;
  f ^= fn () > i;
  f &= fn () <= i;
  f ^= fn () >= i;


  f += fn ();
  f += fn () | i;
  f += fn () & i;
  f += fn () ^ i;
}
