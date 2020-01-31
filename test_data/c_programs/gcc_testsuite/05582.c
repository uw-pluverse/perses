

void bar (void);

void
foo (unsigned int a)
{
  if ((a >> 5) & 1)
    bar ();
}
