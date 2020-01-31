typedef unsigned int uint32_t;
unsigned t(uint32_t *ptr, uint32_t val) {
  return __sync_lock_test_and_set(ptr, val);
}
