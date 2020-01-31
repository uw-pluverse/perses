


unsigned short data;
void foo ()
{
  unsigned char x16;
  unsigned int i;
  for (i = 0; i < 8; i++)
    {
      x16 = data & 1;
      data >>= 1;
      if (x16 == 1)
 {
   data ^= 0x4;
 }
      data >>= 1;
    }
}
