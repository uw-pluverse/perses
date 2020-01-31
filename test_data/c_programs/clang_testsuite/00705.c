struct s {
  unsigned long long u33: 33;
} a, b;
_Bool test(void) {
  return a.u33 + b.u33 != 0;
}
