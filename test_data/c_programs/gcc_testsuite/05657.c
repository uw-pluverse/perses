






unsigned bar(void);

void foo(unsigned *p, unsigned n)
{
  unsigned i;

  for (i = 0; i < n; i++)
    p[i] = bar ();
}
