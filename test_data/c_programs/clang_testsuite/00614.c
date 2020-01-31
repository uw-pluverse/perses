struct s {
  char filler [128];
  volatile int x;
};
struct s gs;
void foo (void) {
  struct s ls;
  ls = ls;
  gs = gs;
  ls = gs;
}
struct s1 {
  struct s y;
};
struct s1 s;
void fee (void) {
  s = s;
  s.y = gs;
}
