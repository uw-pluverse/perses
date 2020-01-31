void capture(void *);
void test_alloca(int n) {
  capture(_alloca(n));
}
void test_alloca_with_align(int n) {
  capture(__builtin_alloca_with_align(n, 64));
}
