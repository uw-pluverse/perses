struct Simple {
  char a, b;
};
int test_ldrex(char *addr) {
  int sum = 0;
  sum += __builtin_arm_ldrex(addr);
  sum += __builtin_arm_ldrex((short *)addr);
  sum += __builtin_arm_ldrex((int *)addr);
  sum += __builtin_arm_ldrex((long long *)addr);
  sum += __builtin_arm_ldrex((__int128 *)addr);
  sum += __builtin_arm_ldrex((float *)addr);
  sum += __builtin_arm_ldrex((double *)addr);
  sum += *__builtin_arm_ldrex((int **)addr);
  sum += __builtin_arm_ldrex((struct Simple **)addr)->a;
  sum += __builtin_arm_ldrex((volatile char *)addr);
  sum += __builtin_arm_ldrex((const volatile char *)addr);
  sum += __builtin_arm_ldrex((struct Simple *)addr).a;
  __builtin_arm_ldrex();
  __builtin_arm_ldrex(1, 2);
  return sum;
}
int test_strex(char *addr) {
  int res = 0;
  struct Simple var = {0};
  res |= __builtin_arm_strex(4, addr);
  res |= __builtin_arm_strex(42, (short *)addr);
  res |= __builtin_arm_strex(42, (int *)addr);
  res |= __builtin_arm_strex(42, (long long *)addr);
  res |= __builtin_arm_strex(42, (__int128 *)addr);
  res |= __builtin_arm_strex(2.71828f, (float *)addr);
  res |= __builtin_arm_strex(3.14159, (double *)addr);
  res |= __builtin_arm_strex(&var, (struct Simple **)addr);
  res |= __builtin_arm_strex(42, (volatile char *)addr);
  res |= __builtin_arm_strex(42, (char *const)addr);
  res |= __builtin_arm_strex(42, (const char *)addr);
  res |= __builtin_arm_strex(var, (struct Simple *)addr);
  res |= __builtin_arm_strex(var, (struct Simple **)addr);
  res |= __builtin_arm_strex(&var, (struct Simple **)addr).a;
  __builtin_arm_strex(1);
  __builtin_arm_strex(1, 2, 3);
  return res;
}
int test_ldaex(char *addr) {
  int sum = 0;
  sum += __builtin_arm_ldaex(addr);
  sum += __builtin_arm_ldaex((short *)addr);
  sum += __builtin_arm_ldaex((int *)addr);
  sum += __builtin_arm_ldaex((long long *)addr);
  sum += __builtin_arm_ldaex((__int128 *)addr);
  sum += __builtin_arm_ldaex((float *)addr);
  sum += __builtin_arm_ldaex((double *)addr);
  sum += *__builtin_arm_ldaex((int **)addr);
  sum += __builtin_arm_ldaex((struct Simple **)addr)->a;
  sum += __builtin_arm_ldaex((volatile char *)addr);
  sum += __builtin_arm_ldaex((const volatile char *)addr);
  sum += __builtin_arm_ldaex((struct Simple *)addr).a;
  __builtin_arm_ldaex();
  __builtin_arm_ldaex(1, 2);
  return sum;
}
int test_stlex(char *addr) {
  int res = 0;
  struct Simple var = {0};
  res |= __builtin_arm_stlex(4, addr);
  res |= __builtin_arm_stlex(42, (short *)addr);
  res |= __builtin_arm_stlex(42, (int *)addr);
  res |= __builtin_arm_stlex(42, (long long *)addr);
  res |= __builtin_arm_stlex(42, (__int128 *)addr);
  res |= __builtin_arm_stlex(2.71828f, (float *)addr);
  res |= __builtin_arm_stlex(3.14159, (double *)addr);
  res |= __builtin_arm_stlex(&var, (struct Simple **)addr);
  res |= __builtin_arm_stlex(42, (volatile char *)addr);
  res |= __builtin_arm_stlex(42, (char *const)addr);
  res |= __builtin_arm_stlex(42, (const char *)addr);
  res |= __builtin_arm_stlex(var, (struct Simple *)addr);
  res |= __builtin_arm_stlex(var, (struct Simple **)addr);
  res |= __builtin_arm_stlex(&var, (struct Simple **)addr).a;
  __builtin_arm_stlex(1);
  __builtin_arm_stlex(1, 2, 3);
  return res;
}
void test_clrex() {
  __builtin_arm_clrex();
  __builtin_arm_clrex(1);
}
