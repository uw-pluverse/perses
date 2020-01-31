static inline int foo(double) __attribute__ ((always_inline));
static inline int foo(double __x) { return __x; }
void bar(double x) {
  foo(x);
}
