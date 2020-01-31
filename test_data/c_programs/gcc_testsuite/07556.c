



__attribute__((noinline, noclone)) void
fn1 (int x)
{
  __asm volatile ("" : "+r" (x) : : "memory");
}

static int
fn2 (int x, int y)
{
  if (y)
    {
      fn1 (x);
      fn1 (x);
      fn1 (x);
      fn1 (x);
      y = -2 + x;
      y = y * y * y + y;
      fn1 (x + y);
    }
  return x;
}

int (*p) (int, int) = fn2;

int
main ()
{
  __asm volatile ("" : : : "memory");
  int (*q) (int, int) = p;
  __asm volatile ("" : : : "memory");
  q (6, 25);
  q (4, 117);
  q (0, 0);
  return 0;
}
