



int
foo (void)
{
  int a, b, c, d, e, f;
  asm ("# Magic instruction" : "=r" (a), "=r" (d) : "r" (0) : "eax");
  asm ("# Magic instruction" : "=r" (b), "=r" (e) : "r" (0) : "edx");
  asm ("# Magic instruction" : "=r" (c), "=r" (f) : "r" (0) : "ecx");
  return a + b + c;
}
