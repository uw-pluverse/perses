void test_signed() {
  extern volatile int a, b, c;
  a = b + c;
}
void test_unsigned() {
  extern volatile unsigned x, y, z;
  x = y + z;
}
