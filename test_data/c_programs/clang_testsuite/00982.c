void test(void) {
  unsigned r;
  const char * c;
  float f;
  const unsigned q;
  __builtin_add_overflow();
  __builtin_add_overflow(1, 1, 1, 1);
  __builtin_add_overflow(c, 1, &r);
  __builtin_add_overflow(1, c, &r);
  __builtin_add_overflow(1, 1, 3);
  __builtin_add_overflow(1, 1, &f);
  __builtin_add_overflow(1, 1, &q);
}
