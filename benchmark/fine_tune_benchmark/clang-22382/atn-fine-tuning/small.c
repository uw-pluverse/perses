typedef short i;
typedef int n;
typedef long t;
typedef unsigned u;
struct S {
  signed f;
  t f1;
  unsigned f3;
};
u g;
static struct S f(u, i, u, u, struct S);
u c(p) {
  struct S l;
  n _;
  f(_, g, p, 3, l);
  for (;;) {
    struct S _;
    l = _ = l;
  }
}
struct S f(u p, i _, u _2, u _3, struct S _4) {
  _4.f;
  for (;;)
    ;
}
int main() {}
