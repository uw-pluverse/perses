


void unscrunch (unsigned char *, int *);

int DES_CBCUpdate(unsigned char * output, int len)
{
  int work[2];
  unsigned int i;
  for(i = 0;i < len/8;i++)
    unscrunch (&output[8*i], work);
}
