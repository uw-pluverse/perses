


unsigned long long
muld (unsigned long long X, unsigned long long Y)
{
  unsigned long long mask = 0xffffffffull;
  return (X & mask) * (Y & mask);
}
