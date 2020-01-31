void f0(int) __attribute__((availability(ios,introduced=2.0,deprecated=2.1)));
void f1(int) __attribute__((availability(ios,introduced=2.1)));
void f2(int) __attribute__((availability(ios,introduced=2.0,deprecated=3.0)));
void f3(int) __attribute__((availability(ios,introduced=3.0)));
void f4(int) __attribute__((availability(macosx,introduced=10.1,deprecated=10.3,obsoleted=10.5), availability(ios,introduced=2.0,deprecated=2.1,obsoleted=3.0)));
void f5(int) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(ios,deprecated=3.0)));
void f6(int) __attribute__((availability(ios,deprecated=12.1)));
void f7(int) __attribute__((availability(ios,deprecated=8.3)));
void f8(int) __attribute__((availability(ios,introduced=2.0,obsoleted=10.0)));
void test() {
  f0(0);
  f1(0);
  f2(0);
  f3(0);
  f4(0);
  f5(0);
  f6(0);
  f7(0);
  f8(0);
}
void f0_watchos(int) __attribute__((availability(watchos,introduced=2.0,deprecated=2.1)));
void f1_watchos(int) __attribute__((availability(watchos,introduced=2.1)));
void f2_watchos(int) __attribute__((availability(watchos,introduced=2.0,deprecated=3.0)));
void f3_watchos(int) __attribute__((availability(watchos,introduced=3.0)));
void f4_watchos(int) __attribute__((availability(macosx,introduced=10.1,deprecated=10.3,obsoleted=10.5), availability(watchos,introduced=2.0,deprecated=2.1,obsoleted=3.0)));
void f5_watchos(int) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(ios,deprecated=3.0)));
void f5_attr_reversed_watchos(int) __attribute__((availability(ios, deprecated=3.0))) __attribute__((availability(watchos,introduced=2.0)));
void f5b_watchos(int) __attribute__((availability(watchos,introduced=2.0))) __attribute__((availability(watchos,deprecated=3.0)));
void f5c_watchos(int) __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(ios,deprecated=3.0)));
void f6_watchos(int) __attribute__((availability(watchos,deprecated=3.0)));
void f6_watchos(int) __attribute__((availability(watchos,introduced=2.0)));
void test_watchos() {
  f0_watchos(0);
  f1_watchos(0);
  f2_watchos(0);
  f3_watchos(0);
  f4_watchos(0);
  f5_watchos(0);
  f5_attr_reversed_watchos(0);
  f5b_watchos(0);
  f5c_watchos(0);
  f6_watchos(0);
}
