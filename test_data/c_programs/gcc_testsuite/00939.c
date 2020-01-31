


typedef struct
{
  unsigned short b0:1;
  unsigned short b1:1;
  unsigned short b2:1;
  unsigned short b3:1;
  unsigned short b4:1;
  unsigned short b5:1;
  unsigned short b6:1;
  unsigned short b7:1;
  unsigned short b8:1;
  unsigned short b9:1;
  unsigned short b10:1;
  unsigned short b11:1;
  unsigned short b12:1;
  unsigned short b13:1;
  unsigned short b14:1;
  unsigned short b15:1;
} BitField;


unsigned short *pA = (unsigned short *) 0x7f14;

unsigned short *pB = (unsigned short *) 0x7f10;

char *
Do (void)
{
  if ((*((volatile BitField*)0x7f14)).b11)
    {
      if ((*((volatile BitField*)0x7f10)).b11)
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
