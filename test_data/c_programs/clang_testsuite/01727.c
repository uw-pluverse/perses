void bar();
static void static_func();
int main() {
  for(int i = 0; i < 10; ++i) {
    bar();
  }
  static_func();
  return 0;
}
void foo() {
  if(1) {
    int i = 0;
  }
}
void bar() {
}
void static_func() { }
static void func() { }
