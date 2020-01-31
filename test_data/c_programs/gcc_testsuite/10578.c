



struct S { char *a; unsigned b; unsigned c; };
extern int foo (const char *);
extern void bar (int, int);

static void
baz (void)
{
  struct S cs[1];
  switch (cs->b)
    {
    case 101:
      if (foo (cs->a))
 bar (cs->c, cs->b);
    }
}

void
test (void)
{
  baz ();
}
