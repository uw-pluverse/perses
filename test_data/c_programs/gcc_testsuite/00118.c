


extern void fatal (void) __attribute__ ((__noreturn__));
extern void exit (int) __attribute__ ((__noreturn__));

void
fatal (void)
{
  exit (1);
}
