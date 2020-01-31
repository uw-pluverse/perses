




void abort (void);

int
foo (void)
{
  int a, i;

  for (i = 1; i <= 10; i++)
    {
      if (i < 3)
 a = 1;
      else
 break;
      a = 5;
    }
  return a;
}

int
main (void)
{
  if (foo () != 5)
    abort ();
  return 0;
}
