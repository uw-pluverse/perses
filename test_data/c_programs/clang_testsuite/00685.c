void foo() {
  int a = 3;
  __builtin_mips_wrdsp(2052, a);
  __builtin_mips_rddsp(a);
  __builtin_mips_wrdsp(2052, -1);
  __builtin_mips_rddsp(-1);
  __builtin_mips_wrdsp(2052, 64);
  __builtin_mips_rddsp(64);
  __builtin_mips_append(1, 2, a);
  __builtin_mips_balign(1, 2, a);
  __builtin_mips_precr_sra_ph_w(1, 2, a);
  __builtin_mips_precr_sra_r_ph_w(1, 2, a);
  __builtin_mips_prepend(1, 2, a);
  __builtin_mips_append(1, 2, -1);
  __builtin_mips_append(1, 2, 32);
  __builtin_mips_balign(1, 2, -1);
  __builtin_mips_balign(1, 2, 4);
  __builtin_mips_precr_sra_ph_w(1, 2, -1);
  __builtin_mips_precr_sra_ph_w(1, 2, 32);
  __builtin_mips_precr_sra_r_ph_w(1, 2, -1);
  __builtin_mips_precr_sra_r_ph_w(1, 2, 32);
  __builtin_mips_prepend(1, 2, -1);
  __builtin_mips_prepend(1, 2, -1);
}
