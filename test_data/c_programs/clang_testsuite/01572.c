struct a {
  int b;
};
struct a test __attribute__((interrupt));
__attribute__((interrupt)) int foo1(void) { return 0; }
__attribute__((interrupt)) void foo2(void) {}
__attribute__((interrupt)) void foo3(void *a, unsigned b, int c) {}
__attribute__((interrupt)) void foo4(int a) {}
__attribute__((interrupt)) void foo5(void *a, float b) {}
__attribute__((interrupt)) void foo6(float *a, int b) {}
__attribute__((interrupt)) void foo7(int *a, unsigned b) {}
__attribute__((interrupt)) void foo8(int *a) {}
void g(void (*fp)(int *));
int main(int argc, char **argv) {
  void *ptr = (void *)&foo7;
  g(foo8);
  (void)ptr;
  foo7((int *)argv, argc);
  foo8((int *)argv);
  return 0;
}
