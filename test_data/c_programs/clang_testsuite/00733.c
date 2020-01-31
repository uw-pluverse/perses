void f0(int x) {
  int *p = &x;
  if (x > 10) {
    if (x == 22)
      p = 0;
  }
  *p = 10;
}
