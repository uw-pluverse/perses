



unsigned char g;

unsigned long long
foo (void)
{
  return ((long long) ((g & 0x80) != 0)) << 7;
}
