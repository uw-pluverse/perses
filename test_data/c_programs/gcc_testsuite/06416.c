



void main1 (float *pa, float *pc)
{
  int i;
  float b[256];
  float c[256];
  for (i = 0; i < 256; i++)
    b[i] = c[i] = pc[i];
  for (i = 0; i < 256; i++)
    pa[i] = b[i] * c[i];
}
