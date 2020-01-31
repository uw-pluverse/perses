







int
main (void)
{
  volatile __int128 i = (__int128) (((unsigned __int128) 1 << ((16 * 8) - 1)) - 1);
  volatile __int128 j = 1;
  volatile __int128 k = i + j;
  k = j + i;
  i++;
  j = (__int128) (((unsigned __int128) 1 << ((16 * 8) - 1)) - 1) - 100;
  j += (1 << 10);

  j = (-(__int128) (((unsigned __int128) 1 << ((16 * 8) - 1)) - 1) - 1);
  i = -1;
  k = i + j;
  k = j + i;
  j--;
  j = (-(__int128) (((unsigned __int128) 1 << ((16 * 8) - 1)) - 1) - 1) + 100;
  j += -(1 << 10);

  i = (__int128) (((unsigned __int128) 1 << ((16 * 8) - 1)) - 1);
  j = 2;
  k = i * j;

  i = (-(__int128) (((unsigned __int128) 1 << ((16 * 8) - 1)) - 1) - 1);
  i = -i;

  return 0;
}
