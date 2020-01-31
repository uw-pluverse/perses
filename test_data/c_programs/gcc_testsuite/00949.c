



unsigned short *pA = (unsigned short *) 0x7f14;

unsigned short *pB = (unsigned short *) 0x7f10;

char *
Do (void)
{
  if (!((*((volatile unsigned short*)0x7f14)) & 0x8000))
    {
      if (!((*((volatile unsigned short*)0x7f10)) & 0x8000))
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
  *pA = 0x1234;
  *pB = 0xedcb;
  return Do ()[0] == 'F';
}
