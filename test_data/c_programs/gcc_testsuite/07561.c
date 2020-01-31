



__attribute__((noinline, noclone)) void
fn1 (int x)
{
  __asm volatile ("" : "+r" (x) : : "memory");
}

static int
fn2 (int x, int y, int z)
{
  int a = 8;
  if (x != z)
    {
      fn1 (x);
      fn1 (x);
      if (x == 36)
 fn1 (x);
      fn1 (x);
      if (x == 98)
 fn1 (x);
      fn1 (x);
      fn1 (x + a);
    }
  return y;
}

int (*p) (int, int, int) = fn2;

int
main ()
{
  __asm volatile ("" : : : "memory");
  int (*q) (int, int, int) = p;
  __asm volatile ("" : : : "memory");
  q (36, 25, 6);
  q (98, 117, 8);
  q (0, 0, 0);
  return 0;
}
