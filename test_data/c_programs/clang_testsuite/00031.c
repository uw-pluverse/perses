int foo();
int test() {
  int a = 1;
  a = 34 / 12;
  if (foo())
    return a;
  a /= 4;
  return a;
}
