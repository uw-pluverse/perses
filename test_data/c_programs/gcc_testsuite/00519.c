




int a[26];
__attribute__ ((noinline, noclone))
     int main1 (int X)
{
  int s = X;
  int i;
  for (i = 0; i < 26; i++)
    s += (i + a[i]);
  return s;
}

int
main (void)
{
  int s, i;
  for (i = 0; i < 26; i++)
    a[i] = 2 * i;
  s = main1 (3);
  if (s != 978)
    __builtin_abort ();
  return 0;
}
