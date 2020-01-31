






typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

extern void foo (int, va_list);
extern void bar (int);
long x;
double d;



void
f1 (int i, ...)
{
  va_list ap;
  __builtin_va_start(ap, i);
  while (i-- > 0)
    x = __builtin_va_arg(ap, long);
  __builtin_va_end(ap);
}
void
f2 (int i, ...)
{
  va_list ap;
  __builtin_va_start(ap, i);
  while (i-- > 0)
    d = __builtin_va_arg(ap, double);
  __builtin_va_end(ap);
}
void
f3 (int i, ...)
{
  va_list ap;
  int j = i;
  while (j-- > 0)
    {
      __builtin_va_start(ap, i);
      x = __builtin_va_arg(ap, long);
      __builtin_va_end(ap);
      bar (x);
    }
}
void
f4 (int i, ...)
{
  va_list ap;
  int j = i;
  while (j-- > 0)
    {
      __builtin_va_start(ap, i);
      d = __builtin_va_arg(ap, double);
      __builtin_va_end(ap);
      bar (d + 2.5);
    }
}
