


unsigned int
foo(unsigned int a, unsigned int b, unsigned int c, unsigned int d,
    unsigned int e, unsigned int f, unsigned int g, unsigned int h)
{

  unsigned int i = (a + 9) + (c + d);
  unsigned int j = (e + 4) + (2 + g);
  e = i + j;
  return e;
}
