typedef const struct __CFNumber *CFNumberRef;
void takes_int(int);
void bad(CFNumberRef p) {
  if (p) {}
  if (!p) {}
  p ? 1 : 2;
  if (p == 0) {}
  if (p > 0) {}
  int x = p;
  x = p;
  takes_int(p);
  takes_int(x);
}
typedef long intptr_t;
typedef unsigned long uintptr_t;
typedef long fintptr_t;
void test_intptr_t(CFNumberRef p) {
  (long)p;
  (intptr_t)p;
  (unsigned long)p;
  (uintptr_t)p;
  (fintptr_t)p;
}
