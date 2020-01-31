





static void
fn1 (void)
{
  __builtin_abort ();
}

__attribute__ ((noreturn))
static void
fn2 (void)
{
  __builtin_abort ();
}

__attribute__ ((volatile))
static void
fn3 (void)
{
  __builtin_abort ();
}
