extern void f(int *);
int e(int m, int n) {
  int x[n];
  f(x);
  return x[m];
}
