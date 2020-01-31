int foo(int) __attribute__ ((ifunc("foo_ifunc")));
static int f1(int i) {
  return i + 1;
}
static int f2(int i) {
  return i + 2;
}
typedef int (*foo_t)(int);
int global;
static foo_t foo_ifunc() {
  return global ? f1 : f2;
}
int bar() {
  return foo(1);
}
extern void goo(void);
void bar2(void) {
  goo();
}
extern void goo(void) __attribute__ ((ifunc("goo_ifunc")));
void* goo_ifunc(void) {
  return 0;
}
