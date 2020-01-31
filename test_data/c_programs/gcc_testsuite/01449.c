



extern void abort (void);

int
bics_si_test (int a, int b)
{
  if (a & ~b)
    return 1;
  else
    return 0;
}

int
bics_si_test2 (int a, int b)
{
  if (a & ~ (b << 2))
    return 1;
  else
    return 0;
}

int
main (void)
{
  int a = 5;
  int b = 5;
  int c = 20;
  if (bics_si_test (a, b))
    abort ();
  if (bics_si_test2 (c, b))
    abort ();
  return 0;
}
