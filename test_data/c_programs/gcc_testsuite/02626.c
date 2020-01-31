






extern void abort (void);

int
foo (int x, int y)
{

  return (x<=y) && ((unsigned int)x >= (unsigned int)y);
}

int
main ()
{
  if (! foo (-1,0))
    abort ();
  return 0;
}
