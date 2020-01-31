


extern void abort (void);

void __attribute__ ((noinline))
foo_s32 (int a, int b)
{
  if (a == -b)
    abort ();
}


void __attribute__ ((noinline))
foo_s64 (long long a, long long b)
{
  if (a == -b)
    abort ();
}



int
main (void)
{
  int a = 30;
  int b = 42;
  foo_s32 (a, b);
  foo_s64 (a, b);
  return 0;
}
