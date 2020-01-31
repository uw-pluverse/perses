int
main (void)
{
  volatile int j = (-2147483647 - 1);
  volatile int i = 1;
  volatile int k = j - i;
  j--;
  j = (-2147483647 - 1) + 100;
  j -= (1 << 10);

  j = (-2147483647 - 1);
  i = -1;
  k = j - -i;

  i = (-2147483647 - 1) + 1000;
  i -= (1 << 20);

  volatile long int l = (-9223372036854775807L - 1L);
  volatile long int m = 1;
  volatile long int n = l - m;
  l--;
  l = (-9223372036854775807L - 1L) + 100;
  l -= (1 << 10);

  l = (-9223372036854775807L - 1L);
  m = -1;
  n = l - -m;

  m = (-9223372036854775807L - 1L) + 1000;
  m -= (1 << 20);

  return 0;
}
