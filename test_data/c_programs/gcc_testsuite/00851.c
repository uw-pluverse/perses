






unsigned char * a_ptr = (unsigned char *) 0x7f14;
unsigned char * b_ptr = (unsigned char *) 0x7f10;

int
foo (void)
{
  if ((*((volatile unsigned char *) 0x7f14)) & 0x08)
    {
      if ((*((volatile unsigned char *) 0x7f10)) & 0x08)
 return -1;

      return 0;
    }

  return -1;
}

int
bar (void)
{
  *a_ptr = 0x08;
  *b_ptr = 0xf7;

  return foo ();
}
