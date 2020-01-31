





extern int bar ();
extern int com ();
extern int baz ();
void
foo (a,b)
     int a, b;
{
  if (a)
    if (b)
      bar ();
    else
      com ();
  else
    baz ();
}
