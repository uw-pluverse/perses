void clang_analyzer_eval(int);
void testComparisons (int a) {
  int b = a;
  clang_analyzer_eval(b == a);
  clang_analyzer_eval(b >= a);
  clang_analyzer_eval(b <= a);
  clang_analyzer_eval(b != a);
  clang_analyzer_eval(b > a);
  clang_analyzer_eval(b < a);
}
void testSelfOperations (int a) {
  clang_analyzer_eval((a|a) == a);
  clang_analyzer_eval((a&a) == a);
  clang_analyzer_eval((a^a) == 0);
  clang_analyzer_eval((a-a) == 0);
}
void testIdempotent (int a) {
  clang_analyzer_eval((a*1) == a);
  clang_analyzer_eval((a/1) == a);
  clang_analyzer_eval((a+0) == a);
  clang_analyzer_eval((a-0) == a);
  clang_analyzer_eval((a<<0) == a);
  clang_analyzer_eval((a>>0) == a);
  clang_analyzer_eval((a^0) == a);
  clang_analyzer_eval((a&(~0)) == a);
  clang_analyzer_eval((a|0) == a);
}
void testReductionToConstant (int a) {
  clang_analyzer_eval((a*0) == 0);
  clang_analyzer_eval((a&0) == 0);
  clang_analyzer_eval((a|(~0)) == (~0));
}
void testSymmetricIntSymOperations (int a) {
  clang_analyzer_eval((2+a) == (a+2));
  clang_analyzer_eval((2*a) == (a*2));
  clang_analyzer_eval((2&a) == (a&2));
  clang_analyzer_eval((2^a) == (a^2));
  clang_analyzer_eval((2|a) == (a|2));
}
void testAsymmetricIntSymOperations (int a) {
  clang_analyzer_eval(((~0) >> a) == (~0));
  clang_analyzer_eval((0 >> a) == 0);
  clang_analyzer_eval((0 << a) == 0);
  clang_analyzer_eval(((~0U) >> a) != (~0U));
}
void testLocations (char *a) {
  char *b = a;
  clang_analyzer_eval(b == a);
  clang_analyzer_eval(b >= a);
  clang_analyzer_eval(b <= a);
  clang_analyzer_eval(b != a);
  clang_analyzer_eval(b > a);
  clang_analyzer_eval(b < a);
}
void testMixedTypeComparisons (char a, unsigned long b) {
  if (a != 0) return;
  if (b != 0x100) return;
  clang_analyzer_eval(a <= b);
  clang_analyzer_eval(b >= a);
  clang_analyzer_eval(a != b);
}
