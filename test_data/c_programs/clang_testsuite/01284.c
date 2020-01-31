struct c {int x;};
int a(struct c x, long long y) {
  void const* l1_ptr = &&l1;
  goto *l1_ptr;
l1:
  goto *x;
  goto *y;
}
