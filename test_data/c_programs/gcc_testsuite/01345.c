



long long int
foo (long long x, int in1, int in2)
{
  short a = (in1 & 0xffff0000) >> 16;
  short b = (in2 & 0xffff0000) >> 16;

  return x + b * a;
}
