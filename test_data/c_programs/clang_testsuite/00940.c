static unsigned char dwarf_reg_size_table[102+1];
int test() {
  __builtin_init_dwarf_reg_size_table(dwarf_reg_size_table);
  return __builtin_dwarf_sp_column();
}
