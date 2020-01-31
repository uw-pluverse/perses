



unsigned char *p = (unsigned char *) 0x7f14;

void
Do (void)
{
  (*((volatile unsigned char*)0x7f14)) &= ~0x80;
}

int
main (void)
{
  *p = 0xcb;
  Do ();
  return (*p == 0x4b) ? 0 : 1;
}
