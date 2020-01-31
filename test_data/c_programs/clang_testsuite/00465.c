void caller(void (*f)()) {
  f();
}
static void g(void) {}
void h(void);
typedef void (*Fn)(void);
Fn g1() {
  return &g;
}
Fn h1() {
  return &h;
}
inline void foo() {}
void bar() { foo(); }
