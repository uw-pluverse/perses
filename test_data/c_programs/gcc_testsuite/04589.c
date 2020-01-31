





int
main (void)
{
  volatile int j = 2147483647;
  volatile int i = 2;
  volatile int k = j * i;
  k = i * j;

  volatile long int m = 9223372036854775807L;
  volatile long int n = 2;
  volatile long int o = m * n;
  o = n * m;

  return 0;
}
