






extern void abort (void);

int
foo (double x, double y)
{

  return (x > y) && ((int)x == (int)y);
}

int
main ()
{
  if (! foo (1.3,1.0))
    abort ();
  return 0;
}
