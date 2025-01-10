



__attribute__((target_clones ("avx", "default")))
void
foo (void)
{
  static void *p = &&lab;
  asm volatile ("" : "+m" (p) : : "memory");
lab:;
}
