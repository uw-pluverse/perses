



double x = -0x1.0p53;
double y = 1;
int
main (void)
{
  while (y > 0)
    y += x;
  if (y != x + 1)
    abort ();
  exit (0);
}
