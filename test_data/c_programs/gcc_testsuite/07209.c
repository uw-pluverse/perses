


struct ints { int a, b, c; } foo();
void bar(int a, int b);

void func() {
  volatile struct ints s = foo();
  bar(s.a, s.b);
}
