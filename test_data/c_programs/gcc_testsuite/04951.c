



void
f1 (unsigned char * x, int y, int z)
{
  x[z / 8] |= (unsigned char) (0x80 >> y);
}

unsigned char
f2 (unsigned char x, int y)
{
  x = x | (unsigned char) (0x80 >> y);
  return x;
}

unsigned char
f3 (unsigned char x, int y)
{
  x = x | (unsigned char) (y & 255);
  return x;
}

unsigned char
f4 (unsigned char x, unsigned char y)
{
  x = x | (unsigned char) (y & 255);
  return x;
}

unsigned char
f5 (unsigned char x, int y)
{
  x = (unsigned char) (y & 255);
  return x;
}
