static inline bug(int *p) {
  *p = 0xDEADBEEF;
}
void test_bug_1() {
  int *p = 0;
  bug(p);
}
void test_bug_2() {
  int *p = 0;
  bug(p);
}
