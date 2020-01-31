



long f(long a, long b) {
  if (__builtin_expect(b == 1, 1)) return a;
  return a / b;
}
