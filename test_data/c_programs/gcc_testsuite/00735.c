



typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

extern void abort (void);

typedef __attribute__ ((__aligned__ (16))) int alignedint;

void
test_pass_overaligned_int_vaargs (int i, ...)
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
  test_pass_overaligned_int_vaargs (9, 8, 7, 6, 5, 4, 3, 2, 1, 0);
  return 0;
}
