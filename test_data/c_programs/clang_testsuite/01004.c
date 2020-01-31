struct Simple {
  char a, b;
};
int test_ldrex(char *addr, long long *addr64, float *addrfloat) {
  int sum = 0;
  sum += __builtin_arm_ldrex(addr);
  sum += __builtin_arm_ldrex((short *)addr);
  sum += __builtin_arm_ldrex((int *)addr);
  sum += __builtin_arm_ldrex((long long *)addr);
  sum += __builtin_arm_ldrex(addr64);
  sum += __builtin_arm_ldrex(addrfloat);
  sum += __builtin_arm_ldrex((double *)addr);
  sum += *__builtin_arm_ldrex((int **)addr);
  sum += __builtin_arm_ldrex((struct Simple **)addr)->a;
  return sum;
}
int test_ldaex(char *addr, long long *addr64, float *addrfloat) {
  int sum = 0;
  sum += __builtin_arm_ldaex(addr);
  sum += __builtin_arm_ldaex((short *)addr);
  sum += __builtin_arm_ldaex((int *)addr);
  sum += __builtin_arm_ldaex((long long *)addr);
  sum += __builtin_arm_ldaex(addr64);
  sum += __builtin_arm_ldaex(addrfloat);
  sum += __builtin_arm_ldaex((double *)addr);
  sum += *__builtin_arm_ldaex((int **)addr);
  sum += __builtin_arm_ldaex((struct Simple **)addr)->a;
  return sum;
}
int test_strex(char *addr) {
  int res = 0;
  struct Simple var = {0};
  res |= __builtin_arm_strex(4, addr);
  res |= __builtin_arm_strex(42, (short *)addr);
  res |= __builtin_arm_strex(42, (int *)addr);
  res |= __builtin_arm_strex(42, (long long *)addr);
  res |= __builtin_arm_strex(2.71828f, (float *)addr);
  res |= __builtin_arm_strex(3.14159, (double *)addr);
  res |= __builtin_arm_strex(&var, (struct Simple **)addr);
  return res;
}
int test_stlex(char *addr) {
  int res = 0;
  struct Simple var = {0};
  res |= __builtin_arm_stlex(4, addr);
  res |= __builtin_arm_stlex(42, (short *)addr);
  res |= __builtin_arm_stlex(42, (int *)addr);
  res |= __builtin_arm_stlex(42, (long long *)addr);
  res |= __builtin_arm_stlex(2.71828f, (float *)addr);
  res |= __builtin_arm_stlex(3.14159, (double *)addr);
  res |= __builtin_arm_stlex(&var, (struct Simple **)addr);
  return res;
}
void test_clrex() {
  __builtin_arm_clrex();
}
