extern void foo_alias (void) __asm ("foo");
inline void foo (void) {
  return foo_alias ();
}
extern int abs_alias (int) __asm ("abs");
inline __attribute__ ((__always_inline__)) int abs (int x) {
  return abs_alias(x);
}
extern char *strrchr_foo (const char *__s, int __c) __asm ("strrchr");
extern inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__)) char * strrchr_foo (const char *__s, int __c) {
  return __builtin_strrchr (__s, __c);
}
extern inline void __attribute__((always_inline, __gnu_inline__))
prefetch(void) {
  __builtin_prefetch(0, 0, 1);
}
extern inline __attribute__((__always_inline__, __gnu_inline__)) void *memchr(void *__s, int __c, long unsigned int __n) {
  return __builtin_memchr(__s, __c, __n);
}
void f(void) {
  foo();
  abs(0);
  strrchr_foo("", '.');
  prefetch();
  memchr("", '.', 0);
}
