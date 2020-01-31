



unsigned short *p = (unsigned short *) 0x7f14;

void
Do (void)
{
  (*((volatile unsigned short*)0x7f14)) &= ~0x8000;
}

int
main (void)
{
  *p = 0xedcb;
  Do ();
  return (*p == 0x6dcb) ? 0 : 1;
}
