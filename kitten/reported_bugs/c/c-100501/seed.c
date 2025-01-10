


void
foo (void)
{
  __asm__ ("" : : "m" (({ static int a; a; })));
}
