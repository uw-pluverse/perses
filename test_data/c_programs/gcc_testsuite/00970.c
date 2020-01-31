



unsigned short *p = (unsigned short *) 0x7f14;

unsigned short wData = 0x9876;

void
Do (void)
{
  wData = (*((volatile unsigned short*)0x7f14));
}

int
main (void)
{
  *p = 0x1234;
  Do ();
  return (wData == 0x1234) ? 0 : 1;
}
