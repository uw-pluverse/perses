


unsigned int x = 1;
int
main (void)
{
  long long int a = -2LL;
  int t = 1 <= (a / x);
  if (t != 0)
    __builtin_abort ();

  return 0;
}
