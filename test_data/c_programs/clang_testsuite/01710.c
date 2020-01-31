void test_clear_cache_chars(char *start, char *end) {
  __clear_cache(start, end);
}
void test_clear_cache_voids(void *start, void *end) {
  __clear_cache(start, end);
}
void test_clear_cache_no_args() {
  __clear_cache();
}
