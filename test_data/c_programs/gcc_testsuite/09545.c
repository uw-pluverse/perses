


extern void foo (int *);
extern void bar (int);

void
baz (void)
{
  int i;
  foo (&i);
  if (i)
    bar (i);
}
