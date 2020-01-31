



extern int bar ();

void
foo (int *p, int i)
{
  p[0] = (bar (), 1, bar ());
  p[1] = (1, bar ());
  bar (), 1, bar ();
  bar (), 1;
  1, bar ();
  (bar (), 1);
  bar (), 5 * i;
  (bar (), 5 * i);
  (bar (), (bar (), (bar (), (bar (), (bar (), (bar (), (bar (), 7)))))));
  bar (), (bar (), (bar (), (bar (), (bar (), (bar (), (bar (), 7))))));
  bar (), (bar (), (bar (), (bar (), (bar (), (bar (), (7, bar ()))))));
  (bar (), (bar (), (bar (), (bar (), (bar (), (bar (), (7, bar ())))))));
}
