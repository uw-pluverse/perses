int g();
int foo(int i) {
  return g(i);
}
int g(int i) {
  return g(i);
}
typedef void T(void);
void test3(T f) {
  f();
}
int a(int);
int a() {return 1;}
void f0() {}
void f1();
void f2(void) {
  f1(1, 2, 3);
}
void f1() {}
struct foo { int X, Y, Z; } f3() {
  while (1) {}
}
void f4() {}
void f5() { f4(42); }
static void f6(const float f, const float g) {
}
void f7(float f, float g) {
  f6(f, g);
}
struct Incomplete;
void f8_callback(struct Incomplete);
void f8_user(void (*callback)(struct Incomplete));
void f8_test() {
  f8_user(&f8_callback);
}
static void test9_helper(void) {}
void test9() {
  (void) test9_helper;
}
