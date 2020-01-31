#pragma clang system_header
typedef __builtin_va_list va_list;
int vprintf (const char *restrict format, va_list arg);
int vsprintf (char *restrict s, const char *restrict format, va_list arg);
int some_library_function(int n, va_list arg);
inline void __impl_detail(int fst, ...) {
  va_list va;
  (void)__builtin_va_arg(va, int);
}
void inlined_uses_arg(va_list arg) {
  (void)__builtin_va_arg(arg, int);
}
void call_inlined_uses_arg(int fst, ...) {
  va_list va;
  inlined_uses_arg(va);
}
void f6(va_list *fst, ...) {
  __builtin_va_start(*fst, fst);
  (void)__builtin_va_arg(*fst, int);
  __builtin_va_end(*fst);
}
void call_vprintf_bad(int isstring, ...) {
  va_list va;
  vprintf(isstring ? "%s" : "%d", va);
}
void call_vsprintf_bad(char *buffer, ...) {
  va_list va;
  __builtin_va_start(va, buffer);
  __builtin_va_end(va);
  vsprintf(buffer, "%s %d %d %lf %03d", va);
}
