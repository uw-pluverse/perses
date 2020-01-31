inline int
foo (int i)
{
  if (i)
    return 1;
  return 0;
}

void baz (void);

void
bar (void)
{
  int j;
  for (; foo (j); ++j)
    baz ();
}
