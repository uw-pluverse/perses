extern p(int *);
int q(void) {
  int x __attribute__ ((aligned (16)));
  p(&x);
  return x;
}
