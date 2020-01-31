unsigned int
andwlsr (unsigned int x)
{
  return (x >> 17) & 0x7ff;
}

unsigned int
andblsr (unsigned int x)
{
  return (x >> 25) & 0x5f;
}

int
andwasr (int x)
{
  return (x >> 17) & 0x7ff;
}

int
andbasr (int x)
{
  return (x >> 25) & 0x5f;
}
