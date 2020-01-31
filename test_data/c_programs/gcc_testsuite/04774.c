


struct A {
  char x[7];
};

void f(struct A *x, struct A *y) {
  *x = *y;
}
