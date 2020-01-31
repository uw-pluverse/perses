int x __attribute__((sentinel));
void f1(int a, ...) __attribute__ ((sentinel));
void f2(int a, ...) __attribute__ ((sentinel(1)));
void f3(int a, ...) __attribute__ ((sentinel("hello")));
void f4(int a, ...) __attribute__ ((sentinel(1, 2, 3)));
void f4(int a, ...) __attribute__ ((sentinel(-1)));
void f4(int a, ...) __attribute__ ((sentinel(0, 2)));
void f5(int a) __attribute__ ((sentinel));
void f6() __attribute__((__sentinel__));
void g() {
  f1(1, 0);
}
