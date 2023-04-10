typedef signed i;
struct S {
  signed f : 18;
};
struct S g;
i f() {
  struct S l;
  i B = g.f;
  l.f = B;
  i r = g.f && f;
  i c = l.f;
  i _ = c | -(f && l.f) - r;
  g.f = _;
}
int main() {}
