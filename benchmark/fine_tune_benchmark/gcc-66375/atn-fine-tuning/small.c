typedef char i;
typedef short n;
typedef int t;
typedef unsigned u;
void p(u c, int f) { printf("%X", c); }
i s(i l, int r) { return l; }
u f(u i, u u) { return i + u; }
u c;
void r(b) { c = b; }
void c2(v) { r(v); }
void e(u v, char *n, int f) { c2(v); }
u g;
u _[1][4];
u _2(i, t);
u _22(u, u, t, u, t);
t _3(t, u, u, t);
n _1() {
  i l = 0xF;
  t _ = 0;
  _2(g, l);
  return _;
}
u _2(i p, t _) {
  _22(_, _, g, 1, g);
  return p;
}
u _22(u p, u _, t _5, u _6, t _7) {
  u l = 2;
  _3(6, l, 1, p);
  return _;
}
t _3(t p, u _4, u _5, t _6) {
  t l = 2;
  for (; g < 51; ++g) {
    u _0[9];
    int i;
    for (i = 0; i < 9; i++)
      _0[i] = 0x9;
    l = f(s(_[0][3] = l, 3), _0[0]);
  }
  return 3;
}
int main() {
  int i, j;
  int r = 0;
  _1();
  for (i = 0; i < 1; i++)
    for (j = 0; j < 4; j++)
      e(_[i][j], "", r);
  p(c, r);
  return 0;
}
