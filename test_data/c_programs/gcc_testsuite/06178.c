


extern void abort (void) __attribute__ ((__noreturn__));

void noreturn (int x) __attribute__ ((__noreturn__));

void
noreturn (int x)
{
  abort ();
}
