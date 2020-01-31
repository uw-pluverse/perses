int
main (void)
{
  volatile int j = 2147483647;
  volatile int i = 1;
  volatile int k = j + i;
  k = i + j;
  j++;
  j = 2147483647 - 100;
  j += (1 << 10);

  j = (-2147483647 - 1);
  i = -1;
  k = i + j;
  k = j + i;
  j = (-2147483647 - 1) + 100;
  j += -(1 << 10);

  volatile long int m = 9223372036854775807L;
  volatile long int n = 1;
  volatile long int o = m + n;
  o = n + m;
  m++;
  m = 9223372036854775807L - 100;
  m += (1 << 10);

  m = (-9223372036854775807L - 1L);
  n = -1;
  o = m + n;
  o = n + m;
  m = (-9223372036854775807L - 1L) + 100;
  m += -(1 << 10);

  return 0;
}
