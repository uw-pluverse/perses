void f(void) {}
__attribute__((noinline)) void ni(void) {}
__attribute__((flatten))
void g(void) {
  f();
  ni();
}
void h(void) {
  f();
}
