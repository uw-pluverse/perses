


int
foo (unsigned int i, unsigned int j)
{
  i &= 15;
  j &= 15;
  i += 1024;
  j += 2048;
  i |= j;
  return i >= 1024 + 2048;
}
