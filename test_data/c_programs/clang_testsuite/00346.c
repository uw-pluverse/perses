struct foo {
  int x;
  int *y;
};
struct foo Foo[1];
int * bar(unsigned int ix) {
  return &Foo->y[ix];
}
