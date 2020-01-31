





__attribute__ ((target ("arch=armv8-a+crc")))
int
bar (int a)
{
  return a - 6;
}

__attribute__ ((target ("arch=armv8-a+nocrc")))
int
bam (int a)
{
  return a - bar (a);
}
