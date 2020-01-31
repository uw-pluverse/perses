





static unsigned short equot[(6 +3)];
int
foo (num)
     unsigned short num[];
{
  unsigned short *p = &equot[0];
  *p++ = num[0];
  *p++ = num[1];
}
