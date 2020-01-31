extern int *stepsizeTable;

void
adpcm_coder (signed char *outdata, int len)
{
  signed char *outp;
  int delta;
  int outputbuffer;
  int bufferstep = 0;
  outp = (signed char *) outdata;
  int step = 0;
  int index = 0;
  int diff = 0;
  for (; len > 0; len--)
    {
      delta = 0;
      if (diff >= step)
 delta = 4;
      step = stepsizeTable[index];
      if (bufferstep)
 outputbuffer = (delta << 4) & 0xf0;
      else
 *outp++ = (delta & 0x0f) | outputbuffer;
      bufferstep = !bufferstep;
    }
}
