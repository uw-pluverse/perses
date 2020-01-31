


char acDummy[0xf0] __attribute__ ((__BELOW100__));
unsigned char B100 __attribute__ ((__BELOW100__)) = 0x34;
unsigned char *p = &B100;

unsigned char yData = 0x12;

void
Do (void)
{
  B100 = yData;
}

int
main (void)
{
  Do ();
  return (*p == 0x12) ? 0 : 1;
}
