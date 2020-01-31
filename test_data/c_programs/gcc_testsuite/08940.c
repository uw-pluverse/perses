



extern void abort (void);
extern void exit (int);

int
foo (unsigned int i)
{
  switch (i)
  {
    case 123456123456ULL:
      return 0;
    default:
      return 3;
  }
}

int
main (void)
{
  if (foo (10) != 3)
    abort ();
  exit (0);
}
