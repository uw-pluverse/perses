
extern void abort (void);

static __attribute__((noinline)) void foo (int a)
{
  int b = (a - 1) + (-2147483647 -1);

  if (b != (-2147483647 -1))
    abort ();
}

int main (void)
{
  foo (1);
  return 0;
}
