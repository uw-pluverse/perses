




void func(void);
void func(void) __attribute__((deprecated ("Do not use")));

void f(void) {
  func();
}
