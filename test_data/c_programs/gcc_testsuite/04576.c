


int
main (void)
{
  volatile const unsigned long int o = 1UL;
  int zero = 0;

  o / 0;
  1UL / 0;
  1UL / zero;
  o / zero;
  o / (++zero - 1);

  return 0;
}
