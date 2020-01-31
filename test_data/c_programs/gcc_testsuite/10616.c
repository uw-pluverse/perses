




void foo(unsigned u, int i, unsigned char uc, signed char sc) {
  __builtin_printf("%d\n", u);
  __builtin_printf("%u\n", i);
  __builtin_printf("%c\n", sc);
  __builtin_printf("%c\n", uc);
}
