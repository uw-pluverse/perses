void f0(int);
__attribute__((availability(macosx,unavailable)))
__attribute__((availability(ios,unavailable)))
void f1(int);
void test() {
  f0(1);
  f1(1);
}
