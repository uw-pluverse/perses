



void
foo (int i)
{
  int j = 0;
  i = 1;
  j = j + 1;
}

int
main (void)
{
  foo (0);
  return 0;
}
