char* foo(char *fmt, __builtin_va_list ap)
{
  return __builtin_va_arg((ap), char *);
}
typedef __builtin_va_list va_list;
static void f (char * (*g) (char **, int), char **p, ...) {
  char *s;
  va_list v;
  s = g (p, __builtin_va_arg(v, int));
}
