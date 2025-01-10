



_Noreturn extern void exit (int);
_Noreturn extern void abort (void);

void
check (int n)
{
  if (n)
    abort ();
}

int
main (void)
{
  int n = 0;

  check (_Generic (n++, int: 0));

  check (n);

  check (_Generic (n, double: n++, default: 0));
  check (n);


  const int cn = 0;
  check (_Generic (cn, int: 0, default: n++));
  check (n);
  check (_Generic ((const int) n, int: 0, default: n++));
  check (n);


  int a[1];
  const int ca[1];
  check (_Generic (a, int *: 0, const int *: n++));
  check (n);
  check (_Generic (ca, const int *: 0, int *: n++));
  check (n);


  extern void f (void);
  check (_Generic (f, void (*) (void): 0, default: n++));
  check (n);


  check (_Generic (&abort, void (*) (void): 0, default: n++));
  check (n);


  short s;
  check (_Generic (s, short: 0, int: n++));
  check (n);

  exit (0);
}
