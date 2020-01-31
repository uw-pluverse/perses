






float f1(float x, unsigned short y)
{
  return x * y;
}

float f2(float x, short y)
{
  return x * y;
}

float f3(float x, char y)
{
  return x * y;
}

float f4(float x, unsigned char y)
{
  return x * y;
}

float f5(float x, int y)
{
  return x * y;
}

double c1(float x, unsigned short y, int z)
{
  return z ? x + x : y;
}

double c2(float x, short y, int z)
{
  return z ? x + x : y;
}

double c3(float x, char y, int z)
{
  return z ? x + x : y;
}

double c4(float x, unsigned char y, int z)
{
  return z ? x + x : y;
}

double c5(float x, int y, int z)
{
  return z ? x + x : y;
}
