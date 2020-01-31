




unsigned int output[4];

void test (unsigned short *p)
{
  unsigned int x = *p;
  if (x)
    {
      output[0] = x << 1;
      output[1] = x << 1;
      output[2] = x << 1;
      output[3] = x << 1;
    }
}
