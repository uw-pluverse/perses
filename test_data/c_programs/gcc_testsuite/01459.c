



unsigned short foo (unsigned short x)
{
  unsigned char i = 0;
  for (i = 0; i < 8; i++)
    {
      x >>= 1;
      x &= 0x7fff;
    }
  return x;
}
