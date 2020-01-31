


int foo (int n)
{
  while (n >= 45)
    n -= 45;

  return n;
}

int bar (int n)
{
  while (n >= 64)
    n -= 64;

  return n;
}

int bla (int n)
{
  int i = 0;

  while (n >= 45)
    {
      i++;
      n -= 45;
    }

  return i;
}

int baz (int n)
{
  int i = 0;

  while (n >= 64)
    {
      i++;
      n -= 64;
    }

  return i;
}
