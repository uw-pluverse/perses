#pragma clang system_header
typedef __builtin_va_list va_list;
int vprintf (const char *restrict format, va_list arg);
int vsprintf (char *restrict s, const char *restrict format, va_list arg);
int some_library_function(int n, va_list arg);
inline void __impl_detail(int fst, ...) {
  va_list va;
  (void)__builtin_va_arg(va, int);
}
void f1(int fst, ...) {
  va_list va;
  (void)__builtin_va_arg(va, int);
}
int f2(int fst, ...) {
  va_list va;
  __builtin_va_start(va, fst);
  __builtin_va_end(va);
  return __builtin_va_arg(va, int);
}
void f3(int fst, ...) {
  va_list va, va2;
  __builtin_va_start(va, fst);
  __builtin_va_copy(va2, va);
  __builtin_va_end(va);
  (void)__builtin_va_arg(va2, int);
  __builtin_va_end(va2);
}
void f4(int cond, ...) {
  va_list va;
  if (cond) {
    __builtin_va_start(va, cond);
    (void)__builtin_va_arg(va, int);
  }
  __builtin_va_end(va);
}
void f5(va_list fst, ...) {
  __builtin_va_start(fst, fst);
  (void)__builtin_va_arg(fst, int);
  __builtin_va_end(fst);
}
void f7(int *fst, ...) {
  va_list x;
  va_list *y = &x;
  __builtin_va_start(*y, fst);
  (void)__builtin_va_arg(x, int);
  __builtin_va_end(x);
}
void f8(int *fst, ...) {
  va_list x;
  va_list *y = &x;
  __builtin_va_start(*y, fst);
  __builtin_va_end(x);
  (void)__builtin_va_arg(*y, int);
}
void reinit(int *fst, ...) {
  va_list va;
  __builtin_va_start(va, fst);
  __builtin_va_start(va, fst);
  (void)__builtin_va_arg(va, int);
}
void reinitOk(int *fst, ...) {
  va_list va;
  __builtin_va_start(va, fst);
  (void)__builtin_va_arg(va, int);
  __builtin_va_end(va);
  __builtin_va_start(va, fst);
  (void)__builtin_va_arg(va, int);
  __builtin_va_end(va);
}
void reinit3(int *fst, ...) {
  va_list va;
  __builtin_va_start(va, fst);
  (void)__builtin_va_arg(va, int);
  __builtin_va_end(va);
  __builtin_va_start(va, fst);
  (void)__builtin_va_arg(va, int);
  __builtin_va_end(va);
  (void)__builtin_va_arg(va, int);
}
void copyself(int fst, ...) {
  va_list va;
  __builtin_va_start(va, fst);
  __builtin_va_copy(va, va);
  __builtin_va_end(va);
}
void copyselfUninit(int fst, ...) {
  va_list va;
  __builtin_va_copy(va, va);
}
void copyOverwrite(int fst, ...) {
  va_list va, va2;
  __builtin_va_start(va, fst);
  __builtin_va_copy(va, va2);
}
void copyUnint(int fst, ...) {
  va_list va, va2;
  __builtin_va_copy(va, va2);
}
void g1(int fst, ...) {
  va_list va;
  __builtin_va_end(va);
}
void g2(int fst, ...) {
  va_list va;
  __builtin_va_start(va, fst);
  __builtin_va_end(va);
  __builtin_va_end(va);
}
void is_sink(int fst, ...) {
  va_list va;
  __builtin_va_end(va);
  *((volatile int *)0) = 1;
}
void ends_arg(va_list arg) {
  __builtin_va_end(arg);
}
void uses_arg(va_list arg) {
  (void)__builtin_va_arg(arg, int);
}
void call_vprintf_ok(int isstring, ...) {
  va_list va;
  __builtin_va_start(va, isstring);
  vprintf(isstring ? "%s" : "%d", va);
  __builtin_va_end(va);
}
void call_some_other_func(int n, ...) {
  va_list va;
  some_library_function(n, va);
}
void inlined_uses_arg_good(va_list arg) {
  (void)__builtin_va_arg(arg, int);
}
void call_inlined_uses_arg_good(int fst, ...) {
  va_list va;
  __builtin_va_start(va, fst);
  inlined_uses_arg_good(va);
  __builtin_va_end(va);
}
void va_copy_test(va_list arg) {
  va_list dst;
  __builtin_va_copy(dst, arg);
  __builtin_va_end(dst);
}
