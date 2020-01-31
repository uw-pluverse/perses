


void bar (void);

void
foo (int x)
{
  if (x != 2 && x != 3 && x != 10 && x != 11 && x != 17 && x != 18 && x != 23)
    bar ();
}
