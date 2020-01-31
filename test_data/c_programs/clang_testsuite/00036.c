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
  __builtin_va_start(va, fst);
  return;
}
void f2(int fst, ...) {
  va_list va;
  __builtin_va_start(va, fst);
  __builtin_va_end(va);
  __builtin_va_start(va, fst);
}
void f3(int fst, ...) {
  va_list va, va2;
  __builtin_va_start(va, fst);
  __builtin_va_copy(va2, va);
  __builtin_va_end(va);
}
void f4(va_list *fst, ...) {
  __builtin_va_start(*fst, fst);
  return;
}
void f5(va_list fst, ...) {
  __builtin_va_start(fst, fst);
}
void f6(va_list *fst, ...) {
  __builtin_va_start(*fst, fst);
  (void)__builtin_va_arg(*fst, int);
  __builtin_va_end(*fst);
}
void f7(int *fst, ...) {
  va_list x;
  va_list *y = &x;
  __builtin_va_start(*y, fst);
}
void f8(int *fst, ...) {
  va_list x;
  va_list *y = &x;
  __builtin_va_start(*y, fst);
  __builtin_va_end(x);
}
void reinit(int *fst, ...) {
  va_list va;
  __builtin_va_start(va, fst);
  __builtin_va_start(va, fst);
}
void reinitOk(int *fst, ...) {
  va_list va;
  __builtin_va_start(va, fst);
  __builtin_va_end(va);
  __builtin_va_start(va, fst);
  __builtin_va_end(va);
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
void recopy(int fst, ...) {
  va_list va, va2;
  __builtin_va_start(va, fst);
  __builtin_va_copy(va2, va);
  __builtin_va_copy(va2, va);
  __builtin_va_end(va);
  __builtin_va_end(va2);
}
void doublemsg(int fst, ...) {
  va_list va, va2;
  __builtin_va_start(va, fst), __builtin_va_start(va2, fst);
}
void in_array(int fst, ...) {
  va_list va_array[8];
  __builtin_va_start(va_array[3], fst);
}
struct containing_a_valist {
  va_list vafield;
  int foobar;
};
void in_struct(int fst, ...) {
  struct containing_a_valist s;
  __builtin_va_start(s.vafield, fst);
}
void casting(int fst, ...) {
  char mem[sizeof(va_list)];
  __builtin_va_start(*(va_list *) mem, fst);
}
void castingOk(int fst, ...) {
  char mem[sizeof(va_list)];
  __builtin_va_start(*(va_list *) mem, fst);
  __builtin_va_end(*(va_list *) mem);
}
