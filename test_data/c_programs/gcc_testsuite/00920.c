


typedef struct
{
  unsigned char b0:1;
  unsigned char b1:1;
  unsigned char b2:1;
  unsigned char b3:1;
  unsigned char b4:1;
  unsigned char b5:1;
  unsigned char b6:1;
  unsigned char b7:1;
} BitField;


unsigned char *p = (unsigned char *) 0x7f14;

void
Do (void)
{
  (*((volatile BitField*)0x7f14)).b0 = 1;
}

int
main (void)
{
  *p = 0x34;
  Do ();
  return (*p == 0x35) ? 0 : 1;
}
