



extern void abort ();
extern void exit (int);
extern void *foo (void);

int
main ()
{
  if (foo () != __builtin_return_address (0))
    abort ();

  exit (0);
}
