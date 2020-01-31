void test() {
  extern volatile unsigned x, y, z;
  x = y + z;
}
void foo() {
  union { int i; } u;
  u.i=1;
}
