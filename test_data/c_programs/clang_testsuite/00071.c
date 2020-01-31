int foo(int x, int y) __attribute__((always_inline));
int foo(int x, int y) { return x + y; }
float foz(int x, int y) __attribute__((noinline));
float foz(int x, int y) { return x * y; }
int bar(int j) {
  return foo(j, j - 2) * foz(j - 2, j);
}
