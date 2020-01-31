



void
foo (int x)
{
  __asm__ __volatile__ ("" : : "n" (-1 * (int) sizeof (&x)));
}
