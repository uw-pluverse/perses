


extern const int srcshift;

void foo (int *srcdata, int *dstdata)
{
  int i;

  for (i = 0; i < 256; i++)
    dstdata[i] = srcdata[i] << srcshift;
}
