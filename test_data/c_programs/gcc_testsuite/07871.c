



int bar (int);

void
foo (void)
{
  int b = 0;
  b = bar (b);
  b = bar (b);
  b = bar (b);
  b = bar (b);
  bar (b);
}
