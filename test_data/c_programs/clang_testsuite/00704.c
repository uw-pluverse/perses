unsigned int ui, uj, uk;
int i, j, k;
void test0() {
  ui = uj + uk;
  i = j + k;
}
void test1() {
  extern void opaque(int);
  opaque(i++);
}
void test2() {
  extern void opaque(int);
  opaque(++i);
}
void test3(int a, int b, float c, float d) {
  (void)(a / b);
  (void)(a % b);
  (void)(c / d);
}
