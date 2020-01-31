int foo (void)
{
  int i;
  if (0) i = 1; else i
    = 26;
  return i;
}

int main ()
{
  if (foo () != 26)
    abort ();
  exit (0);
}
