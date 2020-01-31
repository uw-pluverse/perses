

unsigned int foo (unsigned int x)
{
  return ((x >> 16) & 0xffff) | ((x & 0xffff) << 16);
}
