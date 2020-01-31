



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

__attribute__((noinline, noclone)) int
fn3 (int x, int y)
{
  return fn2 (x, y) + y;
}

__attribute__((noinline, noclone)) int
fn4 (int x, int y)
{
  return fn2 (x, y) + y;
}

int
main ()
{
  fn3 (6, 25);
  fn4 (4, 117);
  return 0;
}
