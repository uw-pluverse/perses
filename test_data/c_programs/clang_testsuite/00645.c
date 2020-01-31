void test1(long int *r, int code, long int *a, long int *b) {
  r[0] = __builtin_tbegin (0);
  r[1] = __builtin_tbegin (1);
  r[2] = __builtin_tend (0);
  r[3] = __builtin_tendall ();
  r[4] = __builtin_tabort (code);
  r[5] = __builtin_tabort (0x1);
  r[6] = __builtin_tabortdc (0xf, a[0], b[0]);
  r[7] = __builtin_tabortdci (0xf, a[1], 0x1);
  r[8] = __builtin_tabortwc (0xf, a[2], b[2]);
  r[9] = __builtin_tabortwci (0xf, a[3], 0x1);
  r[10] = __builtin_tcheck ();
  r[11] = __builtin_trechkpt ();
  r[12] = __builtin_treclaim (0);
  r[13] = __builtin_tresume ();
  r[14] = __builtin_tsuspend ();
  r[15] = __builtin_tsr (0);
  r[16] = __builtin_ttest ();
  r[17] = __builtin_get_texasr ();
  r[18] = __builtin_get_texasru ();
  r[19] = __builtin_get_tfhar ();
  r[20] = __builtin_get_tfiar ();
  __builtin_set_texasr (a[21]);
  __builtin_set_texasru (a[22]);
  __builtin_set_tfhar (a[23]);
  __builtin_set_tfiar (a[24]);
}
