static int foo(int i) {
  struct {
    int f0 : 2;
  } x;
  return (x.f0 = i);
}
int bar() {
  return foo(-5) == -1;
}
