

typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

va_list v;
volatile int i;

void foo()
{
  i = __builtin_va_arg(v, char);
  i = __builtin_va_arg(v, short);
  i = __builtin_va_arg(v, float);
}
