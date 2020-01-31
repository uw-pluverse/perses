


void f (long *p) {
  *p = 42;
  p[4] = 42;
  __builtin_memset (p, 0, 100);
}
