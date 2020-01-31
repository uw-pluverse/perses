







extern void exit (int);
static short iclip[1024];
static short *iclp;

void
idct_int32(short *const block)
{
  static short *blk;
  static long i;
  static long X0, X1, X2, X3, X4, X5, X6, X7, X8;

  for (i = 0; i < 8; i++)
    {
      blk = block + i;

      if (! ((X1 = (blk[8 * 4] << 8)) | (X2 = blk[8 * 6])
      | (X3 = blk[8 * 2]) | (X4 = blk[8 * 1]) | (X5 = blk[8 * 7])
      | (X6 = blk[8 * 5]) | (X7 = blk[8 * 3])))
 {
   blk[8 * 0] = blk[8 * 1] = blk[8 * 2] =
     blk[8 * 3] = blk[8 * 4] =
     blk[8 * 5] = blk[8 * 6] = blk[8 * 7] =
     iclp[(blk[8 * 0] + 32) >> 6];
   continue;
 }
      X0 = (blk[8 * 0] << 8) + 8192;


      X8 = 565 * (X4 + X5) + 4;
      X4 = (X8 + (2841 - 565) * X4) >> 3;
      X5 = (X8 - (2841 + 565) * X5) >> 3;
      X8 = 2408 * (X6 + X7) + 4;
      X6 = (X8 - (2408 - 1609) * X6) >> 3;
      X7 = (X8 - (2408 + 1609) * X7) >> 3;


      X8 = X0 + X1;
      X0 -= X1;
      X1 = 1108 * (X3 + X2) + 4;
      X2 = (X1 - (2676 + 1108) * X2) >> 3;
      X3 = (X1 + (2676 - 1108) * X3) >> 3;
      X1 = X4 + X6;
      X4 -= X6;
      X6 = X5 + X7;
      X5 -= X7;


      X7 = X8 + X3;
      X8 -= X3;
      X3 = X0 + X2;
      X0 -= X2;
      X2 = (181 * (X4 + X5) + 128) >> 8;
      X4 = (181 * (X4 - X5) + 128) >> 8;


      blk[8 * 0] = iclp[(X7 + X1) >> 14];
      blk[8 * 1] = iclp[(X3 + X2) >> 14];
      blk[8 * 2] = iclp[(X0 + X4) >> 14];
      blk[8 * 3] = iclp[(X8 + X6) >> 14];
      blk[8 * 4] = iclp[(X8 - X6) >> 14];
      blk[8 * 5] = iclp[(X0 - X4) >> 14];
      blk[8 * 6] = iclp[(X3 - X2) >> 14];
      blk[8 * 7] = iclp[(X7 - X1) >> 14];
    }
}


int main(void) {
  int i;
  unsigned short tab[64];

  for (i = 0 ; i < 64 ; ++i)
    {
      tab[i] = (1+(int) (65535)*8000/(2147483647+1.0));
    }

  iclp = iclip + 512;
  for (i = -512; i < 512; i++)
    iclp[i] = (i < -256) ? -256 : ((i > 255) ? 255 : i);

  idct_int32((short *) tab);
  exit (0);
}
