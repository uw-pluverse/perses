void clang_analyzer_eval(int);
void testAnd(int i, int *p) {
  int *nullP = 0;
  int *knownP = &i;
  clang_analyzer_eval((knownP && knownP) == 1);
  clang_analyzer_eval((knownP && nullP) == 0);
  clang_analyzer_eval((knownP && p) == 1);
}
void testOr(int i, int *p) {
  int *nullP = 0;
  int *knownP = &i;
  clang_analyzer_eval((nullP || knownP) == 1);
  clang_analyzer_eval((nullP || nullP) == 0);
  clang_analyzer_eval((nullP || p) == 1);
}
int testTypeIsInt(int i, void *p) {
  if (i | (p && p))
    return 1;
  return 0;
}
int between(char *x) {
  extern char start[];
  extern char end[];
  return x >= start && x < end;
}
int undef(void) {}
void useUndef(void) { 0 || undef(); }
void testPointer(void) { (void) (1 && testPointer && 0); }
