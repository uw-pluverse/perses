



typedef struct rs6000_stack {
  int first_gp_reg_save;
} rs6000_stack_t;
extern char regs_ever_live[113];
extern rs6000_stack_t *rs6000_stack_info (void);
extern void gen_rtx_REG (int);
void
rs6000_emit_prologue (int i, rs6000_stack_t *info)
{
  if (regs_ever_live[info->first_gp_reg_save + i] || i+info->first_gp_reg_save)
    gen_rtx_REG (info->first_gp_reg_save + i);
}
