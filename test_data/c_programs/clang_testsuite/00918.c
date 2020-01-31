struct s0 {
  int x, y;
};
int f0() {
  struct s0 x = {0};
  return x.y;
}
int f1() {
  struct s0 x[2] = { {0} };
  return x[1].x;
}
int f2() {
  int x[2] = { 0 };
  return x[1];
}
