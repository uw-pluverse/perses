


int bar (void);

int foo1 (int x, int y)
{
  if (y < 10) return bar ();
  if (x > 9) return bar ();

  return x < y ? x : y;
}

int foo2 (int x, int y)
{
  if (y < 10) return bar ();
  if (x > 9) return bar ();

  return x > y ? x : y;
}
