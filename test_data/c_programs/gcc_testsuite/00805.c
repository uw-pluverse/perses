



extern void non_existent(int);

__attribute__ ((__optimize__ ("O2")))
static void hooray ()
{
  non_existent (1);
}

__attribute__ ((__optimize__ ("O2")))
static void hiphip (void (*f)())
{
  non_existent (2);
  f ();
}

__attribute__ ((__optimize__ ("O2")))
int test (void)
{
  hiphip (hooray);
  return 0;
}
