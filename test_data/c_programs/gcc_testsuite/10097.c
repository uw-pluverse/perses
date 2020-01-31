#pragma weak foo

int
main (void)
{
  extern int foo (void);
  if (&foo)
    return foo ();
  return 0;
}
