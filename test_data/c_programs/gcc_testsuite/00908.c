


char acDummy[0xf0] __attribute__ ((__BELOW100__));
unsigned char B100 __attribute__ ((__BELOW100__));
unsigned char *p = &B100;

unsigned char yData = 0x12;

void
Do (void)
{
  yData = B100;
}

int
main (void)
{
  *p = 0x34;
  Do ();
  return (yData == 0x34) ? 0 : 1;
}
