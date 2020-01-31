



unsigned short b;
int bar (unsigned);

void
baz (void)
{
  if (bar (0))
    for (b = 0; b < 30; b++)
      ;
}

int
bar (unsigned z)
{
  unsigned short c;
  for (; ; z += 1)
l1:
    if (z)
      goto l2;
l2:
  for (z = 0; z < 9; z++)
    if (z)
      goto l1;
  for (c = 0; c; c = (long unsigned int) baz)
    ;
  return 0;
}
