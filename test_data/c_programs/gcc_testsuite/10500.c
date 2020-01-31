



void foo(int n, int *a, int *b, int *c, int *d, int *e) {
  int i, j;
#pragma GCC ivdep
 for (i = 0; ; ++i) {
    a[i] = b[i] + c[i];
  }
}
