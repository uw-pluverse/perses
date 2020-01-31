void bar() {
}
__forceinline void foo() {
  bar();
}
void i_want_bar() {
  foo();
}
