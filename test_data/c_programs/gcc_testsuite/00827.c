



__attribute__ ((target ("no-general-regs-only")))
int
foo (int a)
{
  return a + 1;
}
