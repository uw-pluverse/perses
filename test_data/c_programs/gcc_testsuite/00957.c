



unsigned char *p = (unsigned char *) 0x7f14;

unsigned char yData = 0x12;

void
Do (void)
{
  yData = (*((volatile unsigned char*)0x7f14));
}

int
main (void)
{
  *p = 0x34;
  Do ();
  return (yData == 0x34) ? 0 : 1;
}
