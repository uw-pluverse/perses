



unsigned long long
foo (unsigned int x)
{
  return ((unsigned long long) x & 0x00ff000000000000ULL) >> 40;
}
