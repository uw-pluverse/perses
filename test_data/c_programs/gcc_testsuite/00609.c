


int fixed_regs[0x00200000];

int
foo()
{
  return fixed_regs[0x00080000];
}
