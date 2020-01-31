



unsigned short *p = (unsigned short *) 0x7f14;

void
Do (void)
{
  (*((volatile unsigned short*)0x7f14)) &= ~0x0100;
}

int
main (void)
{
  *p = 0xedcb;
  Do ();
  return (*p == 0xeccb) ? 0 : 1;
}
