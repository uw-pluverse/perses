


unsigned short
test1 (unsigned short a)
{
  a ^= 0x4002;
  a >>= 1;
  a |= 0x8000;
  return a;
}


unsigned short
test2 (unsigned short a)
{
  a |= 0x4002;
  a <<= 1;
  a ^= 0x0001;
  return a;
}


unsigned short
test3 (unsigned short a)
{
  a &= 0xd123;
  a ^= 0x6040;
  a |= 0xc031;
  return a;
}


unsigned short
test4 (unsigned short a)
{
  a ^= 0x8002;
  a >>= 1;
  a |= 0x8000;
  return a;
}


unsigned short
test5 (unsigned short a)
{
  a ^= 0x8002;
  a >>= 1;
  a |= 0x8001;
  return a;
}



short
test6 (short a)
{
  a &= 0x7fff;
  a >>= 2;
  return a;
}


short
test7 (short a)
{
  a &= 0x8fff;
  a >>= 2;
  return a;
}
