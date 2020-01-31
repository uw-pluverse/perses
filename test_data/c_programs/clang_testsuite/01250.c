__attribute__((interrupt(IRQ))) void foo() {}
__attribute__((interrupt("irq"))) void foo1() {}
__attribute__((interrupt("IRQ", 1))) void foo2() {}
__attribute__((interrupt("IRQ"))) void foo3() {}
__attribute__((interrupt("FIQ"))) void foo4() {}
__attribute__((interrupt("SWI"))) void foo5() {}
__attribute__((interrupt("ABORT"))) void foo6() {}
__attribute__((interrupt("UNDEF"))) void foo7() {}
__attribute__((interrupt)) void foo8() {}
__attribute__((interrupt())) void foo9() {}
__attribute__((interrupt(""))) void foo10() {}
void callee1();
__attribute__((interrupt("IRQ"))) void callee2();
void caller1() {
  callee1();
  callee2();
}
__attribute__((interrupt("IRQ"))) void caller2() {
  callee1();
  callee2();
}
void (*callee3)();
__attribute__((interrupt("IRQ"))) void caller3() {
  callee3();
}
