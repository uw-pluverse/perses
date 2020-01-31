struct foo {
  int x;
};
void copy(volatile struct foo *p, struct foo *q) {
  *p = *q;
}
