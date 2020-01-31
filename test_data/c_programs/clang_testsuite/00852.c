void test1_f(void);
static void test1_g(void) __attribute__((weakref("test1_f")));
void test1_h(void) {
  test1_g();
}
void test2_f(void) {}
static void test2_g(void) __attribute__((weakref("test2_f")));
void test2_h(void) {
  test2_g();
}
void test3_f(void);
static void test3_g(void) __attribute__((weakref("test3_f")));
void test3_foo(void) {
  test3_f();
}
void test3_h(void) {
  test3_g();
}
void test4_f(void);
static void test4_g(void) __attribute__((weakref("test4_f")));
void test4_h(void) {
  test4_g();
}
void test4_f(void) {}
void test5_f(void);
static void test5_g(void) __attribute__((weakref("test5_f")));
void test5_h(void) {
  test5_g();
}
void test5_foo(void) {
  test5_f();
}
void test6_f(void) __attribute__((weak));
static void test6_g(void) __attribute__((weakref("test6_f")));
void test6_h(void) {
  test6_g();
}
void test6_foo(void) {
  test6_f();
}
static void test8_g(void) __attribute__((weakref("test8_f")));
void test8_h(void) {
  if (test8_g)
    test8_g();
}
void test7_f(void);
static void test7_g(void) __attribute__((weakref("test7_f")));
static void *const test7_zed = (void *) &test7_g;
void* test7_h(void) {
  return test7_zed;
}
