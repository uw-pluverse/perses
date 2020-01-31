void null_deref(int *a) {
  if (a)
    return;
  *a = 1;
}
void test1() {
  null_deref(0);
}
void test2(int *p) {
  null_deref(p);
}
