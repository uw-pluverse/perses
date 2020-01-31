


int f(unsigned len, int buflen)
{
  unsigned taillen;
  unsigned slen;
  unsigned i;
  int b[17];
  int j = 0;

  b[0] = 0;
  taillen= buflen & 7;

  if(taillen) {
      slen= 8 - taillen;
      if (len<slen)
 slen=len;
      for(i=0; i<slen; i++) {
   j = b[taillen];
   taillen++;
      }
  }
  return j;
}
