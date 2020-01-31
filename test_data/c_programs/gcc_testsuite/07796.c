


extern int bar (int);

int
foo (void)
{
  extern int bar (int);
  return bar (5);
}
