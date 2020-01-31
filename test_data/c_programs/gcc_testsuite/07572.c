



__attribute__((noinline, noclone)) void
bar (char *a, int b)
{
  __asm volatile ("" : "+r" (a), "+r" (b) : : "memory");
}

__attribute__((noinline, noclone)) void
foo (int a, int b)
{
  int c = a;
  char d[b];
  bar (d, 2);
  bar (d, 4);
}

int
main ()
{
  foo (5, 6);
  return 0;
}
