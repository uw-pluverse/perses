



typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

extern void abort (void);

typedef __attribute__ ((__aligned__ (16))) long alignedlong;

void
test_pass_overaligned_long_vaargs (long l, ...)
{
  va_list va;
  __builtin_va_start(va, l);

  while (l-- > 0)
    if (__builtin_va_arg(va, long) != l)
      abort ();
  __builtin_va_end(va);
}

int
main (int argc, char **argv)
{
  alignedlong a = 9;
  alignedlong b = 8;
  alignedlong c = 7;
  alignedlong d = 6;
  alignedlong e = 5;
  alignedlong f = 4;
  alignedlong g = 3;
  alignedlong h = 2;
  alignedlong i = 1;
  alignedlong j = 0;
  test_pass_overaligned_long_vaargs (a, b, c, d, e, f, g, h, i, j);
  return 0;
}
