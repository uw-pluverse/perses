



static inline int bar (char *c, int i)
{
  return c + i > c;
}

int foo ()
{
  char c[100];
  return (bar (c, 1));
}
