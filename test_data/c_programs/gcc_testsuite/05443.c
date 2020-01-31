


int
f1 (int x)
{
  x &= 0xff;
  x += 0x400;
  x &= 0x7ff;
  return x;
}

int
f2 (int x)
{
  x &= 0xff;
  x += 0x5400;
  x |= 0x4400;
  return x;
}
