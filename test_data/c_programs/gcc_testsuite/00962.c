



unsigned char *pA = (unsigned char *) 0x7f14;

unsigned char *pB = (unsigned char *) 0x7f10;

char *
Do (void)
{
  if ((*((volatile unsigned char*)0x7f14)) & 0x80)
    {
      if ((*((volatile unsigned char*)0x7f10)) & 0x80)
 return "Fail";
      else
 return "Success";
    }
  else
    return "Fail";
}

int
main (void)
{
  *pA = 0xcb;
  *pB = 0x34;
  return Do ()[0] == 'F';
}
