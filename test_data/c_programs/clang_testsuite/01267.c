void __llvm_profile_reset_counters(void);
void foo(int);
int main(void) {
  foo(0);
  __llvm_profile_reset_counters();
  foo(1);
  return 0;
}
void foo(int N) {
  if (N) {}
}
