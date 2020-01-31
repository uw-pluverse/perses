void test_diamond(int i, float f, double d, char c) {
  top(&i);
  left(&f);
  right(&d);
  bottom(&c);
  bottom(&d);
  top_left(&c);
  left_and_right(&i);
  struct left_and_right lr;
  lr.left = 17;
}
