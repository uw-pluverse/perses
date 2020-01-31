typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
struct x {
  long a;
  double b;
};
void testva (int n, ...)
{
  va_list ap;
  struct x t = __builtin_va_arg(ap,struct x);
  int v = __builtin_va_arg(ap,int);
}
