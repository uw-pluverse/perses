__attribute__((interrupt)) void test_generic_interrupt() {
}
__attribute__((interrupt("IRQ"))) void test_irq_interrupt() {
}
__attribute__((interrupt("FIQ"))) void test_fiq_interrupt() {
}
__attribute__((interrupt("SWI"))) void test_swi_interrupt() {
}
__attribute__((interrupt("ABORT"))) void test_abort_interrupt() {
}
__attribute__((interrupt("UNDEF"))) void test_undef_interrupt() {
}
