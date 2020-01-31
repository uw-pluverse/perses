int leading, trailing, pop;
void test_i16(short P) {
  leading = __builtin_clzs(P);
  trailing = __builtin_ctzs(P);
}
void test_i32(int P) {
  leading = __builtin_clz(P);
  trailing = __builtin_ctz(P);
  pop = __builtin_popcount(P);
}
void test_i64(float P) {
  leading = __builtin_clzll(P);
  trailing = __builtin_ctzll(P);
  pop = __builtin_popcountll(P);
}
