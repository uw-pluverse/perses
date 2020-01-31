

volatile unsigned long long *a;

unsigned char
foo (void)
{
  unsigned char b = (*a != 0);
  return b;
}
