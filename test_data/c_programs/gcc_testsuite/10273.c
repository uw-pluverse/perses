



void bar (void);

void foo (unsigned int a)
{
  if ((a >> 2) & 1)
    bar ();
}

void baz (unsigned int b)
{
  if ((~b >> 2) & 1)
    bar ();
}
