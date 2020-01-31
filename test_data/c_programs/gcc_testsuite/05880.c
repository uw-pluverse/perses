


void bar (void);

void
foo1 (unsigned int a)
{
  if (a & 1)
    goto heaven;
  if (a & 4)
    goto heaven;
  return;

 heaven:
  bar ();
}

void
foo2 (unsigned int a)
{
  if (a & 1)
    if (a & 4)
      goto heaven;
  return;

 heaven:
  bar ();
}
