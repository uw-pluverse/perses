void baz(int arg);
void foo(int arg) {
  bar(arg);
  baz(arg);
}
void qux(int arg, ...) { }
void quux(int a1, int a2, int a3) {
  qux(a1, a2, a3);
}
