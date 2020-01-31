


typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

static void __attribute__((noinline,noclone))
foo (int i, ...)
{
  va_list ap;
  int *p;
  __builtin_va_start(ap, i);
  p = __builtin_va_arg(ap, int *);
  *p = 1;
  __builtin_va_end(ap);
}
extern void abort (void);
int main()
{
  int i = 0;
  foo (0, &i);
  if (i != 1)
    abort ();
  return 0;
}
