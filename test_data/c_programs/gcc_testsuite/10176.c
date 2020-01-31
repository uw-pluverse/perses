




short
foo (short x)
{
  int i;

  for (i = 0; i < 3; i++)
    if (x > 0)
      x--;

  return x;
}
