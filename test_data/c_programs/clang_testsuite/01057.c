struct s { int x; long double y; };
long double foo(struct s x, int i, struct s y) {
  return bar(&x, &y);
}
