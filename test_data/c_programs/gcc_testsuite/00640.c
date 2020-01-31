


unsigned char byte = 0;

void
set_bit (unsigned int bit, unsigned char value)
{
  unsigned char mask = (unsigned char) (1 << (bit & 7));

  if (! value)
    byte &= (unsigned char)~mask;
  else
    byte |= mask;

}
