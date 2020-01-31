



int ldrb(unsigned char* p)
{
  if (p[8] <= 0x7F)
    return 2;
  else
    return 5;
}
