



static void
foo (int *x)
{
}

void
bar (int *x)
{
  int i;
  for (i = 0; i == 1; ++i)
    x = 0;
  foo (x);
}
