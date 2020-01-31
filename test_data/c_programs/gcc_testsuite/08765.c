



typedef int TItype __attribute__ ((mode (TI)));





typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

extern void abort(void);


void foo(int i, ...)
{
  TItype q;
  va_list va;

  __builtin_va_start(va, i);
  q = __builtin_va_arg(va, TItype);
  __builtin_va_end(va);

  if (q != 5)
    abort();
}

int main(void)
{
  TItype q = 5;

  foo(1, q);
  return 0;
}
