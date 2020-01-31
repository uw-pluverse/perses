




__attribute__((always_inline)) void f1() {}
__attribute__((always_inline)) void f2(char x) {}
void f3() { f1(); f2(0); }
