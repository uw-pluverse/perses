void has_bug(int *p) {
  *p = 0xDEADBEEF;
}
void test_call_macro() {
  has_bug(0);
}
