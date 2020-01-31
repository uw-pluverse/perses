void test_clear_cache_chars(char *start, char *end) {
  __clear_cache(start, end);
}
void test_clear_cache_voids(void *start, void *end) {
  __clear_cache(start, end);
}
void test_clear_cache_no_args() {
  __clear_cache();
}
void test_memory_barriers() {
  __builtin_arm_dmb(16);
  __builtin_arm_dsb(17);
  __builtin_arm_isb(18);
}
void test_prefetch() {
  __builtin_arm_prefetch(0, 2, 0, 0, 0);
  __builtin_arm_prefetch(0, 0, 3, 0, 0);
  __builtin_arm_prefetch(0, 0, 0, 2, 0);
  __builtin_arm_prefetch(0, 0, 0, 0, 2);
}
