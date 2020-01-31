double f(int b, int i) {
  double a[b];
  return a[i];
}
void f2() {
  int a[2];
  a[1] = 42;
  short *b = malloc(64);
  b[5] = *a + a[1] + 2;
}
void f3() {
  int a[1];
  a[2] = 1;
}
