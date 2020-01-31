void f1() {
  const __builtin_va_list args2;
  (void)__builtin_va_arg(args2, int);
}
void f2(int a, ...) {
  __builtin_ms_va_list ap;
  __builtin_ms_va_start(ap, a);
}
void __attribute__((ms_abi)) g1(int a) {
  __builtin_ms_va_list ap;
  __builtin_ms_va_start(ap, a, a);
  __builtin_ms_va_start(ap, a);
}
void __attribute__((ms_abi)) g2(int a, int b, ...) {
  __builtin_ms_va_list ap;
  __builtin_ms_va_start(ap, 10);
  __builtin_ms_va_start(ap, a);
  __builtin_ms_va_start(ap, b);
}
void __attribute__((ms_abi)) g3(float a, ...) {
  __builtin_ms_va_list ap;
  __builtin_ms_va_start(ap, a);
  __builtin_ms_va_start(ap, (a));
}
void __attribute__((ms_abi)) g5() {
  __builtin_ms_va_list ap;
  __builtin_ms_va_start(ap, ap);
}
void __attribute__((ms_abi)) g6(int a, ...) {
  __builtin_ms_va_list ap;
  __builtin_ms_va_start(ap);
}
void __attribute__((ms_abi))
bar(__builtin_ms_va_list authors, ...) {
  __builtin_ms_va_start(authors, authors);
  (void)__builtin_va_arg(authors, int);
  __builtin_ms_va_end(authors);
}
void __attribute__((ms_abi)) g7(int a, ...) {
  __builtin_ms_va_list ap;
  __builtin_ms_va_start(ap, a);
  __builtin_va_arg(ap, int) = 1;
  int *x = &__builtin_va_arg(ap, int);
  __builtin_ms_va_end(ap);
}
void __attribute__((ms_abi)) g8(int a, ...) {
  __builtin_ms_va_list ap;
  __builtin_ms_va_start(ap, a);
  (void)__builtin_va_arg(ap, void);
  __builtin_ms_va_end(ap);
}
enum E { x = -1, y = 2, z = 10000 };
void __attribute__((ms_abi)) g9(__builtin_ms_va_list args) {
  (void)__builtin_va_arg(args, float);
  (void)__builtin_va_arg(args, enum E);
  (void)__builtin_va_arg(args, short);
  (void)__builtin_va_arg(args, char);
}
void __attribute__((ms_abi)) g10(int a, ...) {
  __builtin_va_list ap;
  __builtin_va_start(ap, a);
}
