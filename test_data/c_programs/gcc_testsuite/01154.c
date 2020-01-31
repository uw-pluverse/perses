




unsigned char ldb (unsigned char *p)
{
  return p[7];
}

unsigned short ldh (unsigned short *p)
{
  return p[7];
}

unsigned int ldw (unsigned int *p)
{
  return p[7];
}

void stb (unsigned char *p, unsigned char x)
{
  p[15] = x;
}

void sth (unsigned short *p, unsigned short x)
{
  p[15] = x;
}

void stw (unsigned int *p, unsigned int x)
{
  p[15] = x;
}

void no_cdx_stb (unsigned char *p, unsigned char x)
{
  p[16] = x;
}

void no_cdx_sth (unsigned short *p, unsigned short x)
{
  p[16] = x;
}

void no_cdx_stw (unsigned int *p, unsigned int x)
{
  p[16] = x;
}
