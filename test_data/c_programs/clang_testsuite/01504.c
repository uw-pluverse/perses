int test1(int *a) {
  a = __builtin_assume_aligned(a, 32, 0ull);
  return a[0];
}
int test2(int *a) {
  a = __builtin_assume_aligned(a, 32, 0);
  return a[0];
}
int test3(int *a) {
  a = __builtin_assume_aligned(a, 32);
  return a[0];
}
int test4(int *a) {
  a = __builtin_assume_aligned(a, -32);
  return a[0];
}
int test5(int *a, unsigned *b) {
  a = __builtin_assume_aligned(a, 32, b);
  return a[0];
}
int test6(int *a) {
  a = __builtin_assume_aligned(a, 32, 0, 0);
  return a[0];
}
int test7(int *a) {
  a = __builtin_assume_aligned(a, 31);
  return a[0];
}
int test8(int *a, int j) {
  a = __builtin_assume_aligned(a, j);
  return a[0];
}
void test_void_assume_aligned(void) __attribute__((assume_aligned(32)));
int test_int_assume_aligned(void) __attribute__((assume_aligned(16)));
void *test_ptr_assume_aligned(void) __attribute__((assume_aligned(64)));
int j __attribute__((assume_aligned(8)));
void *test_no_fn_proto() __attribute__((assume_aligned(32)));
void *test_with_fn_proto(void) __attribute__((assume_aligned(128)));
void *test_no_fn_proto() __attribute__((assume_aligned(31)));
void *test_no_fn_proto() __attribute__((assume_aligned(32, 73)));
void *test_no_fn_proto() __attribute__((assume_aligned));
void *test_no_fn_proto() __attribute__((assume_aligned()));
void *test_no_fn_proto() __attribute__((assume_aligned(32, 45, 37)));
