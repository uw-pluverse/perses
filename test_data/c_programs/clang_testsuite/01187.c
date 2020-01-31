struct X {
  int wibble;
};
void f(struct X *x) {
  x->wobble = 17;
  x->wabble = 17;
}
int printf(const char *restrict, ...);
void f2() {
  unsigned long index;
  printf("%d", index);
}
