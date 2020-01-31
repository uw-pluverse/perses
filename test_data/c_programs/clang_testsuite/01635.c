void bar() {}
void func() {
  int i = 0;
  return; bar();
  i = 2;
}
void func2() {
  int i = 0;
  return; bar();
  i = 2;
}
void func3() {
  bar();
  bar();
}
void func4() {
  int i = 0;
  while (i++ < 10)
    if (i < 5)
      bar();
}
void func5() {
  int i = 0;
  if (i > 5)
    bar();
}
int main(int argc, const char *argv[]) {
  func();
  func2();
  func3();
  func4();
}
