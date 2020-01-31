int foo()
{
  int c = 0xffbbccdd;
  int *p = &c;
  int out = 0;
  __asm volatile (
    "lwl %0, 1 + %1\n\t"
    "lwr %0, 2 + %1\n\t"
    : "=r"(out)
    : "R"(*p)
    );
  return 0;
}
