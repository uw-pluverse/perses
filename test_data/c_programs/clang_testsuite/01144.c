int f();
int f(int x) { return x; }
static int g(int x) { return x; }
int h(int x) { return x; }
static int g2();
int g2(int x) { return x; }
void test(void);
int h3();
int h4(int);
int h4();
void test(void) {
  int h2(int x);
  int h3(int x);
  int h4();
}
int h2(int x) { return x; }
int h3(int x) { return x; }
int h4(int x) { return x; }
int f2(int);
int f2();
int f2(int x) { return x; }
int main(void) { return 0; }
void not_a_prototype_test();
void not_a_prototype_test() { }
