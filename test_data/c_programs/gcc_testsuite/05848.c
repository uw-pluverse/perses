



int
foo (int a, int b)
{
  int t;

  if (b)
    {
      if (a)
 t = 3;
      else
 t = 5;

      a = 0;
    }
  else
    t = 7;

  return t;
}
