void assembly() {
  int added;
  __asm__ __volatile__("addl %%ebx,%%eax" : "=a" (added) : "a" (1), "b" (2) );
}
