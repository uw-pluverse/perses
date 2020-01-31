




struct S { int (*s) (void); };
int bar (void);

void
foo (struct S *x)
{
  if (x->s != bar)
    bar ();
}
