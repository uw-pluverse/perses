





extern void *bar (void);

int
foo (unsigned int *p, unsigned int *q)
{
  const void *r = bar ();

  if (r >= (const void *) *p
      && r < (const void *) *q)
    return 1;

  return 0;
}
