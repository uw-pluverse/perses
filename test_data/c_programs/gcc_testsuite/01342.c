



unsigned int
test (const short p16[6 * 64])
{
  unsigned int i = 6;
  unsigned int ret = 0;

  do
    {
      unsigned long long *p64 = (unsigned long long*) p16;
      unsigned int *p32 = (unsigned int*) p16;
      ret += ret;
      if (p16[1] || p32[1])
 ret++;
      else if (p64[1] | p64[2] | p64[3])
 ret++;
      p16 += 64;
      i--;
    } while (i != 0);

  return ret;
}
