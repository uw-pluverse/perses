



void foo (int b)
{
  extern void bar (void);
  extern void baz (void);
  void *p;
  if (b)
    p = bar;
  else
    p = baz;
  *(char *)p = 1;
}
