



unsigned short *p = (unsigned short *) 0x7f14;

unsigned short wData = 0x1234;

void
Do (void)
{
  (*((volatile unsigned short*)0x7f14)) = wData;
}

int
main (void)
{
  *p = 0x9876;
  Do ();
  return (*p == 0x1234) ? 0 : 1;
}
