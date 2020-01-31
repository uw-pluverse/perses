


extern void abort (void);




int
foonegsi (int a)
{
  return a ? 30 : -30;
}




int
fooinvsi (int a)
{
  return a ? 30 : ~30;
}




long long
foonegdi (long long a)
{
  return a ? 30 : -30;
}

long long
largefooneg (long long a)
{
  return a ? 25089992 : -25089992;
}



long long
fooinvdi (long long a)
{
  return a ? 30 : ~30;
}

long long
largefooinv (long long a)
{
  return a ? 25089992 : ~25089992;
}




int
main (void)
{
  if (foonegsi (1) != 30)
    abort ();

  if (foonegsi (0) != -30)
    abort ();

  if (fooinvsi (1) != 30)
    abort ();

  if (fooinvsi (0) != ~30)
    abort ();

  if (foonegdi (1) != 30)
    abort ();

  if (foonegdi (0) != -30)
    abort ();

  if (fooinvdi (1) != 30)
    abort ();

  if (fooinvdi (0) != ~30)
    abort ();

  if (largefooinv (0) != ~25089992)
    abort ();

  if (largefooneg (0) != -25089992)
    abort ();

  if (largefooinv (1) != 25089992)
    abort ();

  if (largefooneg (1) != 25089992)
    abort ();

  return 0;
}
