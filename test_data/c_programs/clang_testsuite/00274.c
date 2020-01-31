static int __attribute__((always_inline)) f0() {
  return 1;
}
int f1() {
  return f0();
}
inline int f2() __attribute__((always_inline));
int f2() { return 7; }
int f3(void) { return f2(); }
