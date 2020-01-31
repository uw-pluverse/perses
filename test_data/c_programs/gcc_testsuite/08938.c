



extern void baz ();
extern void qux (int, ...);

void
foo (float f)
{
  bar (f);
  baz (f);
  qux (42, f);
}
