




void bar (void);

void
foo (int **pp)
{
  int *p = 0;
  if (pp)
    p = *pp;
  if (p && *p)
    bar ();
}
