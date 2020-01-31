


extern int foo (void);

void bar (int c, int *p)
{
  int *q = p;

  if (c)
    *p = foo ();
  else
    *q = foo ();
}
