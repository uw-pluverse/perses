typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

void foo(register short paramN, ...)
{
  va_list ap;

  __builtin_va_start(ap, paramN);


  (void) __builtin_va_arg(ap, char);



  __builtin_va_end(ap);
}
