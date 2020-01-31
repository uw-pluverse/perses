



extern void abort (void);

int
bics_si_test1 (int a, int b, int c)
{
  int d = a & ~b;



  if (d <= 0)
    return a + c;
  else
    return b + d + c;
}

int
bics_si_test2 (int a, int b, int c)
{
  int d = a & ~(b << 3);



  if (d <= 0)
    return a + c;
  else
    return b + d + c;
}

int
main ()
{
  int x;

  x = bics_si_test1 (29, ~4, 5);
  if (x != ((29 & 4) + ~4 + 5))
    abort ();

  x = bics_si_test1 (5, ~2, 20);
  if (x != 25)
    abort ();

  x = bics_si_test2 (35, ~4, 5);
  if (x != ((35 & ~(~4 << 3)) + ~4 + 5))
    abort ();

  x = bics_si_test2 (96, ~2, 20);
  if (x != 116)
    abort ();

  return 0;
}
