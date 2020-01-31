




extern long bar (unsigned int);

long
foo (long x, unsigned int y)
{
  return *(((long *) (bar (y) - 1)) + 1 + (x >> 2) % 359);
}
