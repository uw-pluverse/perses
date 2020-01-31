




static void __attribute__ ((noreturn))
bar ()
{
}

void
foo ()
{
  bar ();
}

int
main (void)
{
  foo ();
}
