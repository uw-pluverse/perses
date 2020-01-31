void f() {
}
void xf();
void g(int b) {
  void (*fp)() = b ? f : xf;
  fp();
}
