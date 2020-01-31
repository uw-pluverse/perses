


inline int f (void) { return 0; }

int
main (void)
{
  extern int f();
  return f ();
}
