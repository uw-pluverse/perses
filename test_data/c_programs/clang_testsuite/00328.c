struct x { int a[100]; };
void foo(struct x *P, struct x *Q) {
  *P = *Q;
}
