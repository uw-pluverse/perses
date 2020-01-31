int undef(void);

inline static void
f1 (int i __attribute__((unused)))
{
}

inline static void
f2 (void)
{
  f1 (__extension__ ({ int t1 __attribute__((unused)); undef (); }));
}

inline static void
f3 (void)
{
  int v1 __attribute__((unused));
  int v2 __attribute__((unused));

  __extension__ ({ int t2 __attribute__((unused)); if (0) undef (); 0; })
    && __extension__ ({ int t3 __attribute__((unused)); if (0) undef (); 0; });

  if (1)
    {
      undef ();
      if (1)
        f2 ();
    }

  {
    undef ();
  }
}

inline static void
f4 (void)
{
  __extension__ ({ undef (); 1; }) && __extension__ ({ int t4 __attribute__((unused)) = ({ 1; }); 1; });

  { }

  __extension__ ({ int t5 __attribute__((unused)); if (0) undef (); 0; });

  f4 ();

  undef ();
  f3 ();

  return;
}

int
main ()
{
    int foo = 1;
    f4 ();
}
