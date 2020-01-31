void clang_analyzer_eval(int);
struct S {
  int x, y;
  int z[2];
};
void testOffsets(struct S *s, int coin) {
  if (s != 0)
    return;
  clang_analyzer_eval(s == 0);
  clang_analyzer_eval(&(s->x) == 0);
  clang_analyzer_eval(&(s->y) == 4);
  clang_analyzer_eval(&(s->z[0]) == 8);
  clang_analyzer_eval(&(s->z[1]) == 12);
  clang_analyzer_eval(&(s->y) == 0);
  clang_analyzer_eval(&(s->z[0]) == 0);
  clang_analyzer_eval(&(s->z[1]) == 0);
  if (coin)
    s->y = 5;
  else
    s->z[1] = 6;
}
