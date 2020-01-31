





extern void abort (void);
extern void exit (int);

void
bar (int a, int b, int c, int d, int e)
{
  if (d != 1)
    abort ();
}

void
foo (int a, int b, int c, int d, int e)
{
  bar (a, b, c, d, e);
}

int
main ()
{
  foo (0, 0, 0, 1, 2);
  exit (0);
}
