



__attribute__ ((target ("general-regs-only=+crc")))
int
foo (int a)
{
  return a + 1;
}
