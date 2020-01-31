float test(int X, ...) {
  __builtin_va_list ap;
  float F;
  __builtin_va_start(ap, X);
  F = __builtin_va_arg(ap, float);
  return F;
}
