void foo(int a, int *b) {
  do {
  } while (__builtin_arm_strex(a, b));
}
