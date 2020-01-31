int
sub ()
{
  int i = 0;
  int j = 0;
  int k;

  while (i == 0 && j == 0)
    {
      k = 10;
      i = sub ();
    }

  return k;
}
