


int bla(int p)
{
  unsigned i, s = 1;

  for (i = 4; i < 100; i++)
    {
      if (p)
 s += i/2;
      else
 s *= i/2;
    }

  return s;
}
