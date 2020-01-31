


char acDummy[0xf0] __attribute__ ((__BELOW100__));
unsigned short B100 __attribute__ ((__BELOW100__)) = 0xedcb;
unsigned short *p = &B100;

void
Do (void)
{
  B100 &= ~0x0100;
}

int
main (void)
{
  Do ();
  return (*p == 0xeccb) ? 0 : 1;
}
