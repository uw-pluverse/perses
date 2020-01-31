void test_basic_inline_asm_with_k_regs() {
    asm("kandw %k1, %k2, %k3\t");
    asm("kandw %k4, %k5, %k6\t");
    asm("kandw %k7, %k0, %k1\t");
}
