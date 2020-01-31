



unsigned short *pA = (unsigned short *) 0x7f14;

unsigned short *pB = (unsigned short *) 0x7f10;

char *
Do (void)
{
  if ((*((volatile unsigned short*)0x7f14)) & 0x0001)
    {
      if ((*((volatile unsigned short*)0x7f10)) & 0x0001)
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
  *pA = 0xedcb;
  *pB = 0x1234;
  return Do ()[0] == 'F';
}
