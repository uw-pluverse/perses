void foo_irrelevant(int c) {
    if (c)
        return;
    c++;
    return;
}
void foo(int c, int *x) {
    if (c)
        return;
    *x = 5;
}
int use(int c) {
    int xx;
    int *y = &xx;
    foo (c, y);
    foo_irrelevant(c);
    return xx+3;
}
void initArray(int x, double XYZ[3]) {
    if (x <= 0)
        return;
    XYZ[0] = 1;
    XYZ[1] = 1;
    XYZ[2] = 1;
}
int testPassingParentRegionArray(int x) {
    double XYZ[3];
    initArray(x, XYZ);
    return 1 * XYZ[1];
}
double *getValidPtr();
struct WithFields {
  double *f1;
};
void initStruct(int x, struct WithFields *X) {
  if (x <= 0)
    return;
  X->f1 = getValidPtr();
}
double testPassingParentRegionStruct(int x) {
  struct WithFields st;
  st.f1 = 0;
  initStruct(x, &st);
  return (*st.f1);
}
