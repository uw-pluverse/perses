






int
main (void)
{
  int e = 1, f = -1;
  volatile int i = (-2147483647 - 1);
  volatile int i2 = i & (((((((-i) + 1) - 1) + 1) - 1) + 1) - 1);
  i2 = -(i + e + f);
  i = -i;

  volatile long int li = (-9223372036854775807L - 1L);
  volatile long int li2 = li & (((((((-li) + 1) - 1) + 1) - 1) + 1) - 1);
  li2 = -(li + e + f);
  li = -li;

  volatile long long int lli = (-9223372036854775807LL - 1LL);
  volatile long long int lli2 = lli & (((((((-lli) + 1) - 1) + 1) - 1) + 1) - 1);
  lli2 = -(lli + e + f);
  lli = -lli;

  return 0;
}
