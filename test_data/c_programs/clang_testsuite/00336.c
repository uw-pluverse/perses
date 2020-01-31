void f2();
void f2() { }
void f3() __attribute__((availability(macosx,introduced=10.5)));
void f3() { }
void f0() __attribute__((availability(macosx,introduced=10.5)));
void f1() __attribute__((availability(macosx,introduced=10.6)));
void test() {
  f0();
  f1();
  f2();
}
