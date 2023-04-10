typedef char i;
typedef short n;
typedef int t;
typedef unsigned char u;
typedef unsigned t2;
u s(u l, int r) { return l > r ? l : l << r; }
struct S {
  i f;
  i f1;
  t f3;
};
t g[4];
struct S _[2];
t _3[3];
struct S f(t, struct S, t2, n);
u c(p) {
  u l[7][7];
  t _;
  struct S _7;
  if (f(_, _7, _, l[0][0]), p)
    ;
  return p;
}
struct S f(t p, struct S _1, t2 _2, n _33) {
  struct S l = {0x1, -5};
  t _5;
  t _4;
  if (_33 ^ l.f1)
    ;
  else
    l = _[1];
  for (; _5; _5 += 1)
    for (_2 = 0; _2 <= 3; ++_2)
      for (_1.f = 0; _1.f <= 2; _1.f += 1) {
        _[0] = l;
        l.f3 = g[_1.f];
        if (!_[0].f)
          ;
        else {
          _5 = s(_[0].f3, 2) && _1.f1;
          for (; _4; _4 += 1)
            _3[2]++;
        }
      }
  return _1;
}
int main() {}
