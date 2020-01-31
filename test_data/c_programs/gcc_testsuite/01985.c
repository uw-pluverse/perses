



int __attribute__ ((noinline, noclone))
fooctz (int i)
{
  return (i == 0) ? (8 * sizeof (int)) : __builtin_ctz (i);
}

int __attribute__ ((noinline, noclone))
fooctz2 (int i)
{
  return (i != 0) ? __builtin_ctz (i) : (8 * sizeof (int));
}

unsigned int __attribute__ ((noinline, noclone))
fooctz3 (unsigned int i)
{
  return (i > 0) ? __builtin_ctz (i) : (8 * sizeof (int));
}

int __attribute__ ((noinline, noclone))
fooclz (int i)
{
  return (i == 0) ? (8 * sizeof (int)) : __builtin_clz (i);
}

int __attribute__ ((noinline, noclone))
fooclz2 (int i)
{
  return (i != 0) ? __builtin_clz (i) : (8 * sizeof (int));
}

unsigned int __attribute__ ((noinline, noclone))
fooclz3 (unsigned int i)
{
  return (i > 0) ? __builtin_clz (i) : (8 * sizeof (int));
}

int
main (void)
{
  if (fooctz (0) != (8 * sizeof (int)) || fooctz2 (0) != (8 * sizeof (int)) || fooctz3 (0) != (8 * sizeof (int))
      || fooclz (0) != (8 * sizeof (int)) || fooclz2 (0) != (8 * sizeof (int)) || fooclz3 (0) != (8 * sizeof (int)))
    __builtin_abort ();

  return 0;
}
