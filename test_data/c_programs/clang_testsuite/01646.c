struct a { int b; };
struct a test __attribute__((interrupt));
__attribute__((interrupt(12))) void foo(void) { }
__attribute__((interrupt)) void food() {}
