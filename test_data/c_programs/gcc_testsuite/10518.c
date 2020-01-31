

extern int *bar (void) __attribute__ ((__pure__));
extern char *baz;
void
foo (void)
{
  baz = (char *) bar ();
}
