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
int test4(int *a, int b) {
  a = __builtin_assume_aligned(a, 32, b);
  return a[0];
}
int *m1() __attribute__((assume_aligned(64)));
int test5() {
  return *m1();
}
int *m2() __attribute__((assume_aligned(64, 12)));
int test6() {
  return *m2();
}
