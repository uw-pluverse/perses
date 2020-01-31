

typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

struct S { int i; double d; };

struct S
test (char *x, va_list ap)
{
  struct S s;
  s = __builtin_va_arg(ap, struct S);
  return s;
}
