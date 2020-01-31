



typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

extern void baz (int, va_list) __attribute__ ((__noreturn__));

__attribute__ ((__noreturn__))
void
foo (int s, ...)
{
  va_list ap;
  __builtin_va_start(ap, s);
  baz (s, ap);
  __builtin_va_end(ap);
}

__attribute__ ((__noreturn__))
void
bar (int s, ...)
{
  va_list ap1;
  __builtin_va_start(ap1, s);
  {
    va_list ap2;
    __builtin_va_start(ap2, s);
    baz (s, ap1);
    baz (s, ap2);
    __builtin_va_end(ap2);
  }
  __builtin_va_end(ap1);
}
