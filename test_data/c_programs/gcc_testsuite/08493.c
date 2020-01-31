


extern int foo (void) __attribute__((pure));

int bar()
{
  int a = foo ();
  a += foo ();
  return a;
}
