





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
    if (__builtin_va_arg(va, alignedint) != i)
      abort ();
  __builtin_va_end(va);
}

int
main (int argc, char **argv)
{
  foo (5, 4, 3, 2, 1, 0);
  return 0;
}
