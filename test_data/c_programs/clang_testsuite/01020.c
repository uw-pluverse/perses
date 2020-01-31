int test() {
  int x = 3;
  int *volatile p = &x;
  return *p;
}
