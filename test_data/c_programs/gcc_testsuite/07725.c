


void foo()
{
  extern void bar () __attribute__ ((__alias__ ("BAR")));
  bar ();
}
