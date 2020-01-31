



extern void abort (void);

int count = 0;

int
foo (void)
{
  count++;
  return 0;
}

int
bar (void)
{
  count++;
  return 0;
}

int
main ()
{
  if ((foo () == 1) & (bar () == 1))
    abort ();
  if (count != 2)
    abort ();
  return 0;
}
