



static inline int foo ()
{
  return 42;
}

void bar (int *);

void baz ()
{
  int a[foo ()];
  bar (a);
}
