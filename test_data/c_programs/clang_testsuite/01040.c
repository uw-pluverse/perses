struct s0 {
  int f0 : 2;
  _Bool f1 : 1;
  unsigned f2 : 2;
};
int g0();
void f0(void) {
  struct s0 s;
  if ((s.f0 = 3) != -1) g0();
}
void f1(void) {
  struct s0 s;
  if ((s.f1 = 3) != 1) g0();
}
void f2(void) {
  struct s0 s;
  if ((s.f2 = 3) != 3) g0();
}
void f3(void) {
  struct s0 s;
  s.f0 += 3;
}
