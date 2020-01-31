unsigned int
andwlsr (unsigned int x)
{
  return (x >> 16) & 0xff77;
}

unsigned int
andblsr (unsigned int x)
{
  return (x >> 24) & 0xc0;
}

int
andwasr (int x)
{
  return (x >> 16) & 0xff75;
}

int
andbasr (int x)
{
  return (x >> 24) & 0xc1;
}
