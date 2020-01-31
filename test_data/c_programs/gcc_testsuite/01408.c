





typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

extern void abort (void);

typedef __attribute__((aligned (8))) int alignedint;

void
foo (int i, ...)
{
  va_list va;
  __builtin_va_start(va, i);

  while (i-- > 0)
    if (__builtin_va_arg(va, int) != i)
      abort ();
  __builtin_va_end(va);
}

int
main (int argc, char **argv)
{
  alignedint a = 5;
  alignedint b = 4;
  alignedint c = 3;
  alignedint d = 2;
  alignedint e = 1;
  alignedint f = 0;
  foo (a, b, c, d, e, f);
  return 0;
}
