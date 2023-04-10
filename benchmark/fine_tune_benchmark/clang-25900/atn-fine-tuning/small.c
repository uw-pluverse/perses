typedef signed i;
typedef short n;
typedef long t;
typedef unsigned u;
u s(u l, int r) { return r; }
struct S {
  u f;
};
struct S1 {
  signed f : 18;
  signed f5 : 1;
};
i g;
struct S _;
static i _6 = -5;
u _0;
u _8;
i f(i, struct S1, struct S, struct S, i);
n c(u);
t _1() {
  struct S1 l;
  f(g, l, _, _, _.f);
}
i f(i p, struct S1 _, struct S _7, struct S _8, i _9) { c(_9); }
n c(u p) {
  struct S1 l = {1};
  l.f5 = s(_8, 5);
  i b;
  i a = _0;
  b = l.f5;
  l.f = g;
  g = a % (~_6 / b);
  l.f;
}
int main() { _1(); }
