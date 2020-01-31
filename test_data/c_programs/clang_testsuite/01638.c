void f1a() __asm("f1");
void f1a() {}
void f1() __attribute__((ifunc("f1_ifunc")));
void* f1_ifunc() { return 0; }
void* f6_ifunc(int i);
void __attribute__((ifunc("f6_ifunc"))) f6() {}
