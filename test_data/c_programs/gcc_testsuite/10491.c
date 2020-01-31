




extern void abort (void) __attribute__ ((__noreturn__));

int
foo1 (int i)
{
  if (i)
    return i;

  abort ();
}

__inline__ int
foo2 (int i)
{
  if (i)
    return i;

  abort ();
}

static int
foo3 (int i)
{
  if (i)
    return i;

  abort ();
}

static __inline__ int
foo4 (int i)
{
  if (i)
    return i;

  abort ();
}

int bar (int i)
{
  return foo1 (i) + foo2 (i) + foo3 (i) + foo4 (i);
}
