typedef union {
  void *f0;
} transp_t0 __attribute__((transparent_union));
void f0(transp_t0 obj);
void f1_0(int *a0) {
  void (*f0p)(void *) = f0;
  f0(a0);
  f0p(a0);
}
void f1_1(int *a0) {
  f0((transp_t0) { a0 });
}
