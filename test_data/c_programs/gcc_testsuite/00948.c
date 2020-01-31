


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


unsigned char *pA = (unsigned char *) 0x7f14;

unsigned char *pB = (unsigned char *) 0x7f10;

char *
Do (void)
{
  if (!(*((volatile BitField*)0x7f14)).b7)
    {
      if (!(*((volatile BitField*)0x7f10)).b7)
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
  *pA = 0x34;
  *pB = 0xcb;
  return Do ()[0] == 'F';
}
