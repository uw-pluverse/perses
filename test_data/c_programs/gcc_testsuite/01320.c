



long long int
foo (long long x, int in)
{
  short a = in & 0xffff;
  short b = (in & 0xffff0000) >> 16;

  return x + b * a;
}
