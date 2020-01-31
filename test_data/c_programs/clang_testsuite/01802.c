void clang_analyzer_crash(void);
void inlined() {
  clang_analyzer_crash();
}
void test() {
  inlined();
}
