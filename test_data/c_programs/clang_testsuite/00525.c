struct Bar {
 float f1;
 float f2;
 unsigned u;
};
struct Bar foo(__builtin_va_list ap) {
  return __builtin_va_arg(ap, struct Bar);
}
