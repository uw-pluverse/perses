



typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

extern void abort (void);

void foo (int x, ...)
{
  va_list ap;
  if (x != 21)
    abort ();
  __builtin_va_start(ap, x);
  __builtin_va_end(ap);
}

void bar (int x, ...)
{
  va_list ap;
  x++;
  __builtin_va_start(ap, x);
  __builtin_va_end(ap);
}

void baz (int x, ...)
{
  va_list ap;
  x = 0;
  __builtin_va_start(ap, x);
  __builtin_va_end(ap);
}
