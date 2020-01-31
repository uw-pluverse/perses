



unsigned
foo (int x)
{
  unsigned a = ((x & 1) | 2) & 0x80000000;
  unsigned b = ((x & 2) | 2) & 0x80000000;
  unsigned c = ((x & 4) | 2) & 0x80000000;
  return a + b + c;
}
