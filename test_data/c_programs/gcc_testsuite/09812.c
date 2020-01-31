




int bar (void);

void
foo (int i)
{
  while (i)
    i = bar ();
}
