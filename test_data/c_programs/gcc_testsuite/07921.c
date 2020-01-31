unsigned int
foo (unsigned long port)
{
  unsigned int v;
  __asm__ __volatile__ ("" : "=S" (v) : "Nd" (port));
  return v;
}

void
bar (void)
{
  foo (0);
}
