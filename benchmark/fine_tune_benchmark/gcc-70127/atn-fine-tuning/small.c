typedef signed i;
typedef unsigned u;
void p(u c, int f) { printf("%X", c); }
u c;
void r(b) { c = b; }
void c2(v) { r(v); }
void t(u v, char *n, int f) { c2(v); }
struct S {
  i f;
  signed f1 : 22;
};
struct S g;
u _;
struct S _7[1];
struct S _6 = {0x1, 8};
u f(u, i, u, u, u);
i n() { f(g.f, 3, 2, g.f, 9); }
u f(u p, i _1, u _17, u _8, u _9) {
  struct S l = {8, 6};
  for (_1 = 0; _1 >= 0; _1 -= 1)
    for (; _ <= 1; _ += 1) {
      l = _7[_1] = _6;
      _7[_1] = l;
    }
}
int main() {
  int i;
  int r = 0;
  n();
  for (i = 0; i < 1; i++)
    t(_7[i].f1, "", r);
  p(c, r);
  return 0;
}
