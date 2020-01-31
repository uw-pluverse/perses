




const unsigned int in[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
unsigned int out[16];

__attribute__ ((noinline)) int
main1 (void)
{
  const unsigned int *pin = &in[1];
  unsigned int *pout = &out[0];


  *pout++ = *pin++;
  *pout++ = *pin++;
  *pout++ = *pin++;
  *pout++ = *pin++;

  return 0;
}
