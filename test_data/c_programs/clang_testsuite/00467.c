void foo() {
  __asm__ volatile("/* " "pickANumber" ": %c0 */"::"i"(0xC0C0A));
   __asm__ volatile("/* " "pickANumber2 " ": %0 */"::"i"(123));
}
