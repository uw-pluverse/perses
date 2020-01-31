void clang_analyzer_eval(int);
void f(int i) {
  __builtin_assume(i < 10);
  clang_analyzer_eval(i < 15);
}
