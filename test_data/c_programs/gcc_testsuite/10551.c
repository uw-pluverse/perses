




void func(void);
void func(void) __attribute__((deprecated));

void f(void) {
  func();
}
