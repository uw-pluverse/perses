const unsigned char val = 0;
int foo() {
  __asm__ volatile("foo %0, 1" : : "fo" (val));
  __asm__ volatile("foo %0, 1" : : "Nd" (val));
}
