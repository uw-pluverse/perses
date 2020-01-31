typedef long intptr_t;
int test(void *b) {
 intptr_t a;
 __asm__ __volatile__ ("%0 %1 " : "=r" (a): "0" (b));
  return a;
}
