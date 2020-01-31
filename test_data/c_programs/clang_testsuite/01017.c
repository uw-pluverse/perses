struct X { int x[6]; };
struct Y { char x[13]; struct X y; } __attribute((packed));
struct Y g;
void f(struct X);
struct X foo(void);
struct X test1() {
  return g.y;
}
struct X test2() {
  struct X a = g.y;
  return a;
}
void test3(struct X a) {
  g.y = a;
}
void test4() {
  f(g.y);
}
int test5() {
  return g.y.x[0];
}
void test6() {
  g.y = foo();
}
struct XBitfield {
  unsigned b1 : 10;
  unsigned b2 : 12;
  unsigned b3 : 10;
};
struct YBitfield {
  char x;
  struct XBitfield y;
} __attribute((packed));
struct YBitfield gbitfield;
unsigned test7() {
  return gbitfield.y.b2;
}
void test8(unsigned x) {
  gbitfield.y.b2 = x;
}
struct TBitfield
{
  long a;
  char b;
  unsigned c:15;
};
struct TBitfield tbitfield;
unsigned test9() {
  return tbitfield.c;
}
void test10(unsigned x) {
  tbitfield.c = x;
}
