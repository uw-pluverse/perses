int x;
inline void f0(int y) { x = y; }
void test() {
  f0(17);
}
inline int __attribute__((always_inline)) f1(int x) {
  int blarg = 0;
  for (int i = 0; i < x; ++i)
    blarg = blarg + x * i;
  return blarg;
}
int test1(int x) {
  return f1(x);
}
