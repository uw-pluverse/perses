void __attribute__((sysv_abi)) foo(int a, ...) {
  __builtin_va_list ap;
  __builtin_va_start(ap, a);
}
