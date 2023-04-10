typedef int i;
typedef char u;
struct S {
  i f;
};
struct S g;
u f() {
  i l = 6;
  if (g.f)
    goto l;
  f();
  u _;
  return _;
l:
  g.f = l;
  f();
  _ = 0xE;
  return _;
}
int main() {}
