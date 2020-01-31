struct S {
  int z;
};
void clang_analyzer_explain_int(int);
void clang_analyzer_explain_voidp(void *);
void clang_analyzer_explain_S(struct S);
int glob;
void test_1(int param, void *ptr) {
  clang_analyzer_explain_voidp(&glob);
  clang_analyzer_explain_int(param);
  clang_analyzer_explain_voidp(ptr);
  if (param == 42)
    clang_analyzer_explain_int(param);
}
void test_2(struct S s) {
  clang_analyzer_explain_S(s);
  clang_analyzer_explain_voidp(&s);
  clang_analyzer_explain_int(s.z);
}
