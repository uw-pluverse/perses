void testA() {
  int *p = 0;
  *p = 1;
}
void testB(int *q) {
  if (q)
    return;
  *q = 1;
}
