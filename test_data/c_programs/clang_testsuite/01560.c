enum {
  X = 1 << 0,
  Y = 1 << 1,
  Z = 1 << 2
};
void test() {
  char c;
  c = 0 << 0;
  c = 0 << 1;
  c = 1 << 0;
  c = 1 << -0;
  c = 1 >> -0;
  c = 1 << -1;
  c = 1 >> -1;
  c = 1 << c;
  c <<= 0;
  c >>= 0;
  c <<= 1;
  c >>= 1;
  c <<= -1;
  c >>= -1;
  c <<= 999999;
  c >>= 999999;
  c <<= 8;
  c >>= 8;
  c <<= 8 +1;
  c >>= 8 +1;
  (void)((long)c << 8);
  int i;
  i = 1 << ((sizeof(int) * 8) - 2);
  i = 2 << ((sizeof(int) * 8) - 1);
  i = 1 << ((sizeof(int) * 8) - 1);
  i = -1 << ((sizeof(int) * 8) - 1);
  i = -1 << 0;
  i = 0 << ((sizeof(int) * 8) - 1);
  i = (char)1 << ((sizeof(int) * 8) - 2);
  unsigned u;
  u = 1U << ((sizeof(int) * 8) - 1);
  u = 5U << ((sizeof(int) * 8) - 1);
  long long int lli;
  lli = (-0x7fffffff - 1) << 2;
  lli = 1LL << (sizeof(long long) * 8 - 2);
}
enum { b = (0 << 8) };
void test_pr5544() {
  (void) (((1) > 63 && (1) < 128 ? (((unsigned long long) 1)<<((1)-64)) : (unsigned long long) 0));
}
void test_shift_too_much(char x) {
  if (0)
    (void) (x >> 80);
  (void) (x >> 80);
}
typedef unsigned vec16 __attribute__((vector_size(16)));
typedef unsigned vec8 __attribute__((vector_size(8)));
void vect_shift_1(vec16 *x) { *x = *x << 4; }
void vect_shift_2(vec16 *x, vec16 y) { *x = *x << y; }
void vect_shift_3(vec16 *x, vec8 y) {
  *x = *x << y;
}
