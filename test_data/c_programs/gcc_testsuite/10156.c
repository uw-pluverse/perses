



extern void abort (void);

static inline int
foo (void)
{
  return 0;
}

int
main ()
{
  if ((foo () == 1) & (foo () == 1))
    abort ();
  return 0;
}
