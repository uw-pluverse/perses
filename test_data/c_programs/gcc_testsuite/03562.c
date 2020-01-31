



void abort (void) __attribute__ ((noreturn));

void
foo (char *d, unsigned long int n)
{
  if (d + n > d)
    abort ();
}
