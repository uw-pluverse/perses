



extern void bar (void);
static int foo (void) __attribute__ ((__noreturn__, __used__));

static int
foo (void)
{
  while (1)
    bar ();
}
