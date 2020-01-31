extern struct T {
  int b0 : 8;
  int b1 : 24;
  int b2 : 1;
} g;
int func() {
  return g.b1;
}
