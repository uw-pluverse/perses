void foo(unsigned a) {
}
void foo1() {
  unsigned f = 0xffffffe0;
  foo(f);
}
