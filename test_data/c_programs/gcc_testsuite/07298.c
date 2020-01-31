






unsigned
rol (unsigned a, unsigned b)
{
  return ~((~a) << (b) | (~a) >> ((sizeof (int) * 8) - (b)));
}

unsigned int
ror (unsigned a, unsigned b)
{
  return ~((~a) >> (b) | (~a) << ((sizeof (int) * 8) - (b)));
}

int
rol_conv1 (int a, unsigned b)
{
  return ~(int)(((unsigned)~a) << (b) | ((unsigned)~a) >> ((sizeof (int) * 8) - (b)));
}

int
rol_conv2 (int a, unsigned b)
{
  return ~(((unsigned)~a) << (b) | ((unsigned)~a) >> ((sizeof (int) * 8) - (b)));
}

int
rol_conv3 (unsigned a, unsigned b)
{
  return ~(int)((~a) << (b) | (~a) >> ((sizeof (int) * 8) - (b)));
}





unsigned long
roll (unsigned long a, unsigned long b)
{
  return ~((~a) << (b) | (~a) >> ((sizeof (long) * 8) - (b)));
}

unsigned long
rorl (unsigned long a, unsigned long b)
{
  return ~((~a) >> (b) | (~a) << ((sizeof (long) * 8) - (b)));
}
