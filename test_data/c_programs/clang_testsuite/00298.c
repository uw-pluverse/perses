struct S {
  int a, b;
  void *c;
  unsigned d : 8;
  unsigned e : 8;
};
void f0(struct S *a) {
  a->e = 0;
}
