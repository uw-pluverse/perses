int r[];
int (*a)[] = &r;
struct s0;
struct s0 x;
struct s0 y;
struct s0 *f0() {
  return &y;
}
struct s0 {
  int x;
};
int b[];
int *f1() {
  return b;
}
int c[];
int c[4];
static int c5[];
static int func() { return c5[0]; }
int callfunc() { return func(); }
