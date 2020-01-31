




struct A { char c[10]; };
extern void baz (struct A *);

void
foo (void)
{
  struct A a = { "abcdefghi" };
  baz (&a);
}

void
bar (void)
{
  struct A a;
  __builtin_strcpy (&a.c[0], "abcdefghi");
  baz (&a);
}
