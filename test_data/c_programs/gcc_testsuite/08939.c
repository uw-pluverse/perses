



extern void bar (void);

void
foo (int i)
{
  if (i >> 3)
    bar ();
}
