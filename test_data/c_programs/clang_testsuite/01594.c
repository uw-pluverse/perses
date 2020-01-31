void f0(int) __attribute__((availability(ios,introduced=2.0,deprecated=2.1)));
void f1(int) __attribute__((availability(ios,introduced=2.1)));
void f2(int) __attribute__((availability(ios,introduced=2.0,deprecated=3.0)));
void f3(int) __attribute__((availability(ios,introduced=3.0)));
void f4(int) __attribute__((availability(macosx,introduced=10.1,deprecated=10.3,obsoleted=10.5), availability(ios,introduced=2.0,deprecated=2.1,obsoleted=3.0)));
void f5(int) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(ios,deprecated=3.0)));
void f6(int) __attribute__((availability(ios,deprecated=3.0)));
void f6(int) __attribute__((availability(ios,introduced=2.0)));
void test() {
  f0(0);
  f1(0);
  f2(0);
  f3(0);
  f4(0);
  f5(0);
  f6(0);
}
