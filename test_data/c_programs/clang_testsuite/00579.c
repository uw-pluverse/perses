void test_inlineasm_i() {
  __asm__ __volatile__("int %0" :: "i"(1 + 1));
}
void test_inlineasm_I() {
  __asm__ __volatile__("int %0" :: "I"(1 + 1));
  static const int N = 1;
  __asm__ __volatile__("int %0" :: "I"(N + 2));
}
