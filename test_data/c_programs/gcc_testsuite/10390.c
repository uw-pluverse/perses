




int i;

void bar (char *);

void
foo (void)
{
  void *l;
  char c[64];
  bar (c);
  i = 1;
  if (i)
    l = &&l1;
  else
    l = &&l2;
  goto *l;
l2:
  __builtin_abort ();
l1:;
}
