void clang_analyzer_eval(int);
void clang_analyzer_warnIfReached();
void f(void) {
  void (*p)(void);
  p = f;
  p = &f;
  p();
  (*p)();
}
void g(void (*fp)(void));
void f2() {
  g(f);
}
void f3(void (*f)(void), void (*g)(void)) {
  clang_analyzer_eval(!f);
  f();
  clang_analyzer_eval(!f);
  clang_analyzer_eval(!g);
  (*g)();
  clang_analyzer_eval(!g);
}
void nullFunctionPointerConstant() {
  void (*f)(void) = 0;
  f();
  clang_analyzer_warnIfReached();
}
void nullFunctionPointerConstraint(void (*f)(void)) {
  if (f)
    return;
  f();
  clang_analyzer_warnIfReached();
}
