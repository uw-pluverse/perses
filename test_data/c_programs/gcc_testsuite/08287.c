



extern void foo (int *);
extern void bar (int);

void
baz (void)
{
  int i;
  if (i)
    bar (i);
  foo (&i);
}
