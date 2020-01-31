void foo(int, double, float);
void bar(int x) {
  foo(x, x ? 1.0 : 12.5, 1.0f);
}
