void foo(const int *p) {
  __builtin_prefetch(p, 0 + 1, 0 + 3);
  __builtin_prefetch(p, 1 - 0, 3 - 0);
  __builtin_prefetch(p, 1 * 1, 1 * 3);
  __builtin_prefetch(p, 1 / 1, 3 / 1);
  __builtin_prefetch(p, 3 % 2, 3 % 1);
  __builtin_prefetch(p, 0U + 1U, 0U + 3U);
  __builtin_prefetch(p, 1U - 0U, 3U - 0U);
  __builtin_prefetch(p, 1U * 1U, 1U * 3U);
  __builtin_prefetch(p, 1U / 1U, 3U / 1U);
  __builtin_prefetch(p, 3U % 2U, 3U % 1U);
}
void ub_constant_arithmetic() {
  int INT_MIN = 0xffffffff;
  int INT_MAX = 0x7fffffff;
  INT_MAX + 1;
  INT_MAX + -1;
  -INT_MIN;
  -INT_MAX - 2;
  INT_MAX * INT_MAX;
  INT_MIN * INT_MIN;
  1 / 0;
  INT_MIN / -1;
  1 % 0;
  INT_MIN % -1;
  1.0 / 0.0;
}
