struct foo {
  int x;
  float y;
  char z;
};
void __attribute__((ms_abi)) f1(void);
void __attribute__((sysv_abi)) f2(void);
void f3(void) {
  f1();
  f2();
}
void __attribute__((ms_abi)) f4(int a, ...) {
  __builtin_ms_va_list ap;
  __builtin_ms_va_start(ap, a);
  int b = __builtin_va_arg(ap, int);
  double _Complex c = __builtin_va_arg(ap, double _Complex);
  struct foo d = __builtin_va_arg(ap, struct foo);
  __builtin_ms_va_list ap2;
  __builtin_ms_va_copy(ap2, ap);
  __builtin_ms_va_end(ap);
}
void f5(int a, ...) {
  __builtin_va_list ap;
  __builtin_va_start(ap, a);
  int b = __builtin_va_arg(ap, int);
  double _Complex c = __builtin_va_arg(ap, double _Complex);
  struct foo d = __builtin_va_arg(ap, struct foo);
  __builtin_va_list ap2;
  __builtin_va_copy(ap2, ap);
  __builtin_va_end(ap);
}
void __attribute__((sysv_abi)) f6(__builtin_ms_va_list ap) {
  int b = __builtin_va_arg(ap, int);
  double _Complex c = __builtin_va_arg(ap, double _Complex);
  struct foo d = __builtin_va_arg(ap, struct foo);
  __builtin_ms_va_list ap2;
  __builtin_ms_va_copy(ap2, ap);
}
