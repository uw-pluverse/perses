


typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

enum E { A };

extern void f2 (int);
void
f1 (int n, ...)
{
  va_list ap;

  __builtin_va_start(ap, n);
  f2 (__builtin_va_arg(ap, int));
  f2 (__builtin_va_arg(ap, _Bool));
  f2 (__builtin_va_arg(ap, enum E));
}
