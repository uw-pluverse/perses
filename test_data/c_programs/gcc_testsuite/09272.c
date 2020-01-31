




short mask1(short x)
{
  short y = 0x7fff;
  return x & y;
}

short mask2(short ssx)
{
  short ssy;
  short ssz;

  ssz = ((int)ssx) & 0x7fff;
  ssy = ((int)ssx) | 0x7fff;
  ssz = ((int)ssx) ^ 0x7fff;
  return ssx & 0x7fff;
}

short mask3(int si, unsigned int ui)
{
  short ss;
  unsigned short us;

  ss = si & 0x7fff;
  ss = si & 0xAAAA;
  ss = ui & 0x7fff;
  ss = ui & 0xAAAA;

  us = si & 0x7fff;
  us = si & 0xAAAA;
  us = ui & 0x7fff;
  us = ui & 0xAAAA;


  return ss;
}

short mask4(int x, int y)
{
  return x & y;
}

short mask5(int x)
{
  return x & -1;
}

short mask6(short x)
{
  return x & -1;
}
