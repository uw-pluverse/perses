expand_to_ascii (int *i, int *o)
{
  unsigned x, y, out;
  unsigned x1;



  x = *i++;

  y = x >> (32 - 13);
  out = (y / 91);
  out = (out << 8) | (y % 91);

  x <<= 13;
  y = x >> (32 - 13);
  out = (out << 8) | (y / 91);
  out = (out << 8) | (y % 91);

  *o++ = out + 0x20202020;



  x1 = *i++;
  x = (x << 26) | (x1 >> 6);
}
