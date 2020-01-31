void clang_analyzer_dump(int x);
void clang_analyzer_printState();
void clang_analyzer_numTimesReached();
void foo(int x) {
  clang_analyzer_dump(x);
  int y = 1;
  clang_analyzer_printState();
  for (; y < 3; ++y)
    clang_analyzer_numTimesReached();
}
