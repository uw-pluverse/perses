void test0() {
  extern volatile _Complex float test0_v;
  float f = (float) test0_v;
}
void test1() {
  extern volatile _Complex float test1_v;
  test1_v = test1_v;
}
