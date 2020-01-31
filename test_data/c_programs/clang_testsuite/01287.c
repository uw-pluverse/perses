void foo1();
void foo2(void);
void foo1() {}
void foo2(void) {}
typedef void foo3();
void (*foo4)();
struct { void (*foo5)(); } s;
void bar2(void (*foo6)()) {
  void (*foo7)() = 0;
  void (*foo8[2])() = {0};
}
void bar3(void) {
  (void)(void(*)()) foo1;
  (void)(void(*)(void)) foo1;
}
int foo9(a, b)
  int a, b;
{
  return a + b;
}
void foo10();
void foo10(p, p2) void *p; {}
void foo11(int p, int p2);
void foo11(p, p2) int p; int p2; {}
void __attribute__((cdecl)) foo12(d)
  short d;
{}
