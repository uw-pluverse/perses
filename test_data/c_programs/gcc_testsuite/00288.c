







extern int target_flags;
extern char fixed_regs[53];
extern char call_used_regs[53];

void init_reg_sets_1(void)
{
  int i;
  for (i = 0; i < 53; i++)
    fixed_regs[i] = call_used_regs[i] = (call_used_regs[i] &((target_flags & 0x02000000) ? 2 : 1)) != 0;
}
