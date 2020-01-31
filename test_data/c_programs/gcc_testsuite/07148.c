



extern void bar0 (int, int, int, int, int, int, int, int, int)
   __attribute__ ((no_caller_saved_registers));

void
foo (void)
{
  bar0 (0, 1, 2, 3, 4, 5, 6, 7, 8);
}

void
bad (void)
{
  __builtin_abort ();
}
