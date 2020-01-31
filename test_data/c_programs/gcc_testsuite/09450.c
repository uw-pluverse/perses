



extern int *b, *e[8], d;

void
foo (void)
{
  int i;
  for (i = 0; i < 8; ++i)
    while (--d)
      e[i] = 0;
}
