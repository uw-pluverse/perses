void clang_analyzer_eval(int);
unsigned foo();
typedef struct bf { unsigned x:2; } bf;
void bar() {
  bf y;
  *(unsigned*)&y = foo();
  y.x = 1;
}
struct s {
  int n;
};
void f() {
  struct s a;
  int *p = &(a.n) + 1;
}
typedef struct {
  int x,y;
} Point;
Point getit(void);
void test() {
  Point p;
  (void)(p = getit()).x;
}
typedef _Bool bool;
void testLazyCompoundVal() {
  Point p = {42, 0};
  Point q;
  clang_analyzer_eval((q = p).x == 42);
  clang_analyzer_eval(q.x == 42);
}
struct Bits {
  unsigned a : 1;
  unsigned b : 2;
  unsigned c : 1;
  bool x;
  struct InnerBits {
    bool y;
    unsigned d : 16;
    unsigned e : 6;
    unsigned f : 2;
  } inner;
};
void testBitfields() {
  struct Bits bits;
  if (foo() && bits.b)
    return;
  if (foo() && bits.inner.e)
    return;
  bits.c = 1;
  clang_analyzer_eval(bits.c == 1);
  if (foo() && bits.b)
    return;
  if (foo() && bits.x)
    return;
  bits.x = ((bool)1);
  clang_analyzer_eval(bits.x == ((bool)1));
  bits.b = 2;
  clang_analyzer_eval(bits.x == ((bool)1));
  if (foo() && bits.c)
    return;
  bits.inner.e = 50;
  if (foo() && bits.inner.e)
    return;
  if (foo() && bits.inner.y)
    return;
  if (foo() && bits.inner.f)
    return;
  extern struct InnerBits getInner();
  bits.inner = getInner();
  if (foo() && bits.inner.e)
    return;
  if (foo() && bits.inner.y)
    return;
  if (foo() && bits.inner.f)
    return;
  bits.inner.f = 1;
  if (foo() && bits.inner.e)
    return;
  if (foo() && bits.inner.y)
    return;
  if (foo() && bits.inner.f)
    return;
  if (foo() && bits.a)
    return;
}
void testTruncation() {
  struct Bits bits;
  bits.c = 0x11;
  clang_analyzer_eval(bits.c == 1);
}
