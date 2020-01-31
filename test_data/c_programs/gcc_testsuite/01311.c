



unsigned short foo (unsigned short x)
{
  x ^= 0x4002;
  x >>= 1;
  x |= 0x8000;
  return x;
}
