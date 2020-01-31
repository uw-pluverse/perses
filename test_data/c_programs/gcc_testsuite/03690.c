


extern int bar ();
extern void baz ();

void foo ()
{
  int x;

  do
    {
      if ((x = bar ()) == 1)
 baz ();
    }
  while (x == 1);
}
