int
foo (long unsigned int x)
{
  int a = 6;
  int *b = &a;
  if (x)
    for (a = 0; a; a++)
      ;
  return a;
}

void
bar (void)
{
  foo ((long unsigned int) foo);
}
