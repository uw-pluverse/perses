struct X {
  double D;
};
struct Y {
  struct X x;
};
struct Y bar();
void foo(struct Y *P) {
  *P = bar();
}
struct Y bar() {
  struct Y a;
  a.x.D = 0;
  return a;
}
