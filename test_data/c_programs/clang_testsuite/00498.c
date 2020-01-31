struct P1 { char x[6]; } g1 = { "foo" };
struct LP1 { struct P1 p1; };
struct P2 { int a, b, c; } g2 = { 1, 2, 3 };
struct LP2 { struct P2 p2; };
struct LP2P2 { struct P2 p1, p2; };
union UP2 { struct P2 p2; };
struct LP3 { struct P1 p1[2]; } g3 = { { "dog" }, { "cat" } };
struct LLP3 { struct LP3 l3; };
union ULP3 { struct LP3 l3; };
void test1(void)
{
  struct LP1 l = { .p1 = g1, .p1.x[2] = 'x' };
}
void test2(void)
{
  struct LP1 l = { .p1 = g1, .p1.x[1] = 'r' };
}
void test3(void)
{
  struct LP2 l = { .p2 = g2, .p2.b = 10 };
}
struct P2 get235()
{
  struct P2 p = { 2, 3, 5 };
  return p;
}
struct LP2P2 get456789()
{
  struct LP2P2 l = { { 4, 5, 6 }, { 7, 8, 9 } };
  return l;
}
union UP2 get123()
{
  union UP2 u = { { 1, 2, 3 } };
  return u;
}
void test4(void)
{
  struct LUP2 { union UP2 up; } var = { get123(), .up.p2.a = 100 };
}
void test5(void)
{
  struct LLP3 var = { .l3 = g3, .l3.p1 = { [0] = g1 }, .l3.p1[1].x[1] = 'x' };
}
void test6(void)
{
  struct LLP2P2 { struct LP2P2 lp; } var = { get456789(),
                                              .lp.p1 = get235(),
                                              .lp.p1.b = 10 };
}
