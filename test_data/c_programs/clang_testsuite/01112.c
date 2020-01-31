typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
void testva (int n, ...)
{
  va_list ap;
  _Complex int i = __builtin_va_arg(ap,_Complex int);
  _Complex short s = __builtin_va_arg(ap,_Complex short);
  _Complex char c = __builtin_va_arg(ap,_Complex char);
  _Complex float f = __builtin_va_arg(ap,_Complex float);
}
