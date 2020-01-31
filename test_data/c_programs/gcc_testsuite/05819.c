




int test (unsigned int a, int b, int c)
{
  if ((a - 43) <= 3 || (a - 75) <= 3)
    return b;
  else
    return c;
}
int
main ()
{
  volatile int n43, n47, n75, n79;
  n43 = 43; n47 = n43 + 4; n75 = 75; n79 = n75 + 4;
  int i;
  for (i = -10; i <= 100; i++)
    if (test (i, 2, 3) != 3 - ((i >= n43 && i < n47) || (i >= n75 && i < n79)))
      __builtin_abort ();
  return 0;
}
