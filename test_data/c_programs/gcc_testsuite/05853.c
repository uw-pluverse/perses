


extern void abort (void);

int
foo1 (int x, int y)
{
  int z;

  if (x >= y)
    return 1;

  z = y - x;
  if (z <= 0)
    abort ();

  return z;
}

unsigned int
foo2 (unsigned int x, unsigned int y)
{
  unsigned int z;

  if (x >= y)
    return 1;

  z = y - x;
  if (z == 0)
    abort ();

  return z;
}
