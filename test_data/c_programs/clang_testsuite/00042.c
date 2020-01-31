void clang_analyzer_eval(int);
void testPersistentConstraints(int x, int y) {
  if (!(x)) return; clang_analyzer_eval(x);
  if (!(x & 1)) return; clang_analyzer_eval(x & 1);
  if (!(1 - x)) return; clang_analyzer_eval(1 - x);
  if (!(x & y)) return; clang_analyzer_eval(x & y);
}
int testConstantShifts_PR18073(int which) {
  switch (which) {
  case 1:
    return 0ULL << 63;
  case 2:
    return 0ULL << 64;
  case 3:
    return 0ULL << 65;
  default:
    return 0;
  }
}
