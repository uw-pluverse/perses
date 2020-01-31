



extern const unsigned char mode_size[];
unsigned int
subreg_highpart_offset (outermode, innermode)
     int outermode, innermode;
{
  unsigned int offset = 0;
  int difference = (mode_size[innermode] - mode_size[outermode]);
  if (difference > 0)
    {
        offset += difference % (0 ? 8 : 4);
 offset += difference / 4 * 4;
    }
  return offset;
}
