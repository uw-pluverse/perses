void f(void *a, void *b) {
  __clear_cache();
  __clear_cache(a);
  __clear_cache(a, b);
}
void __clear_cache(char*, char*);
void __clear_cache(void*, void*);
void test1() {
  __builtin_va_list ptr;
  ptr.__ap = "x";
  *(ptr.__ap) = '0';
}
void test2() {
  __builtin_va_list ptr = "x";
  *ptr = '0';
}
void test3() {
  __builtin_arm_dsb(16);
  __builtin_arm_dmb(17);
  __builtin_arm_isb(18);
}
void test4() {
  __builtin_arm_prefetch(0, 2, 0);
  __builtin_arm_prefetch(0, 0, 2);
}
void test5() {
  __builtin_arm_dbg(16);
}
void test6(int a, int b, int c) {
  __builtin_arm_ldc(1, 2, &a);
  __builtin_arm_ldc(a, 2, &a);
  __builtin_arm_ldc(1, a, &a);
  __builtin_arm_ldcl(1, 2, &a);
  __builtin_arm_ldcl(a, 2, &a);
  __builtin_arm_ldcl(1, a, &a);
  __builtin_arm_ldc2(1, 2, &a);
  __builtin_arm_ldc2(a, 2, &a);
  __builtin_arm_ldc2(1, a, &a);
  __builtin_arm_ldc2l(1, 2, &a);
  __builtin_arm_ldc2l(a, 2, &a);
  __builtin_arm_ldc2l(1, a, &a);
  __builtin_arm_stc(1, 2, &a);
  __builtin_arm_stc(a, 2, &a);
  __builtin_arm_stc(1, a, &a);
  __builtin_arm_stcl(1, 2, &a);
  __builtin_arm_stcl(a, 2, &a);
  __builtin_arm_stcl(1, a, &a);
  __builtin_arm_stc2(1, 2, &a);
  __builtin_arm_stc2(a, 2, &a);
  __builtin_arm_stc2(1, a, &a);
  __builtin_arm_stc2l(1, 2, &a);
  __builtin_arm_stc2l(a, 2, &a);
  __builtin_arm_stc2l(1, a, &a);
  __builtin_arm_cdp(a, 2, 3, 4, 5, 6);
  __builtin_arm_cdp(1, a, 3, 4, 5, 6);
  __builtin_arm_cdp(1, 2, a, 4, 5, 6);
  __builtin_arm_cdp(1, 2, 3, a, 5, 6);
  __builtin_arm_cdp(1, 2, 3, 4, 5, a);
  __builtin_arm_cdp2(a, 2, 3, 4, 5, 6);
  __builtin_arm_cdp2(1, a, 3, 4, 5, 6);
  __builtin_arm_cdp2(1, 2, a, 4, 5, 6);
  __builtin_arm_cdp2(1, 2, 3, a, 5, 6);
  __builtin_arm_cdp2(1, 2, 3, 4, 5, a);
  __builtin_arm_mrc( a, 0, 13, 0, 3);
  __builtin_arm_mrc(15, a, 13, 0, 3);
  __builtin_arm_mrc(15, 0, a, 0, 3);
  __builtin_arm_mrc(15, 0, 13, a, 3);
  __builtin_arm_mrc(15, 0, 13, 0, a);
  __builtin_arm_mrc2( a, 0, 13, 0, 3);
  __builtin_arm_mrc2(15, a, 13, 0, 3);
  __builtin_arm_mrc2(15, 0, a, 0, 3);
  __builtin_arm_mrc2(15, 0, 13, a, 3);
  __builtin_arm_mrc2(15, 0, 13, 0, a);
  __builtin_arm_mcr( a, 0, b, 13, 0, 3);
  __builtin_arm_mcr(15, a, b, 13, 0, 3);
  __builtin_arm_mcr(15, 0, b, a, 0, 3);
  __builtin_arm_mcr(15, 0, b, 13, a, 3);
  __builtin_arm_mcr(15, 0, b, 13, 0, a);
  __builtin_arm_mcr2( a, 0, b, 13, 0, 3);
  __builtin_arm_mcr2(15, a, b, 13, 0, 3);
  __builtin_arm_mcr2(15, 0, b, a, 0, 3);
  __builtin_arm_mcr2(15, 0, b, 13, a, 3);
  __builtin_arm_mcr2(15, 0, b, 13, 0, a);
  __builtin_arm_mcrr(15, 0, b, 0);
  __builtin_arm_mcrr( a, 0, b, 0);
  __builtin_arm_mcrr(15, a, b, 0);
  __builtin_arm_mcrr(15, 0, b, a);
  __builtin_arm_mcrr2(15, 0, b, 0);
  __builtin_arm_mcrr2( a, 0, b, 0);
  __builtin_arm_mcrr2(15, a, b, 0);
  __builtin_arm_mcrr2(15, 0, b, a);
  __builtin_arm_mrrc(15, 0, 0);
  __builtin_arm_mrrc( a, 0, 0);
  __builtin_arm_mrrc(15, a, 0);
  __builtin_arm_mrrc(15, 0, a);
  __builtin_arm_mrrc2(15, 0, 0);
  __builtin_arm_mrrc2( a, 0, 0);
  __builtin_arm_mrrc2(15, a, 0);
  __builtin_arm_mrrc2(15, 0, a);
}
