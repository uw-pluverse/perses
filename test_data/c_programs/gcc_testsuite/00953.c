



unsigned short *p = (unsigned short *) 0x7f14;

void
Do (void)
{
  (*((volatile unsigned short*)0x7f14)) &= ~0x0008;
}

int
main (void)
{
  *p = 0xedcb;
  Do ();
  return (*p == 0xedc3) ? 0 : 1;
}
