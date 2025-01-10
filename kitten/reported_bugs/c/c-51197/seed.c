





void __attribute__((naked))
foo(int n)
{
  __asm__ volatile ("frob r0\n");
}
