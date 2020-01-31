


typedef char char16[16] __attribute__ ((aligned (16)));
char16 c16[4] __attribute__ ((aligned (4)));

int f5 (int i)
{
  long unsigned int s = (long unsigned int)&c16[i];

  return 3 & s;
}
