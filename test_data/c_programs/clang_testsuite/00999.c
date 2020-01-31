int foo;
int ban[10];
int *A;
int *B;
int test1() { return foo; }
int test2(int i) { return ban[i]; }
void test3() {
  *A = *B;
}
void test4(int *a) {
  a[0] = 0;
}
