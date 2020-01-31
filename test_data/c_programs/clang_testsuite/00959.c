struct a { int b; };
struct a test __attribute__((signal));
__attribute__((signal(12))) void foo(void) { }
__attribute__((signal)) void food() {}
