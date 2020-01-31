


extern void foo (void) __attribute__ ((error (0)));
extern void bar (void) __attribute__ ((warning (0)));
int var __attribute__ ((error ("foo")));

int
main ()
{
  foo ();
  bar ();
  var++;
  return 0;
}
