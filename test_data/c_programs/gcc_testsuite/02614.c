
int
sub ()
{
  int dummy = 0, a = 16;

  if (a / 2147483647 / 16 == 0)
    return 0;
  else
    return a / 2147483647 / 16;
}

int
main ()
{
  if (sub () != 0)
    abort ();

  exit (0);
}
