


extern void baz (void);

static void __attribute__ ((constructor))
bar (void)
{
  baz ();
}

void
foo (void)
{
  bar ();
}
