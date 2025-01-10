


void
foo (long double x)
{
  asm("# %0" : "+fm"(x));
}
