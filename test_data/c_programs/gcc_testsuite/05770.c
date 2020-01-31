



void bar (char *);
int i;

static void
foo (void)
{
  char *p = __builtin_alloca (i);
  bar (p);
}

int
baz (void)
{
  foo ();
  return 6;
}
