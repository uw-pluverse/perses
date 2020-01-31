int
clearb (int x, int *y)
{
  return *y & 0xff00;
}

int
andb (int x, int *y)
{
  return *y & 0x3f;
}

int
andw (int x, int *y)
{
  return *y & 0xfff;
}

int
andq (int x, int *y)
{
  return *y & 0xf0;
}

int
andq2 (int x, int *y)
{
  return *y & 0xfff0;
}
