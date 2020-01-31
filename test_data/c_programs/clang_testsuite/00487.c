int X;
static int Y = 12;
static void foo(int Z) {
  Y = Z;
}
void *test() {
  foo(12);
  return &Y;
}
