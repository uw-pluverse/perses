


extern void baz (void) __attribute__((noreturn));

void
foo (void)
{
 for (;;)
    ;
}

void
bar (void)
{
 baz ();
}
