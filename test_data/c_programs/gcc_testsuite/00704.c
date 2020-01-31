


int fixed_regs[0x200000000ULL];

int
foo()
{
  return fixed_regs[0x100000000ULL];
}
