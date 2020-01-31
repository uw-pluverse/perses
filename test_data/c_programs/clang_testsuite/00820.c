void food(double *d);
void fooll(long long *ll);
void fooull(unsigned long long *ull);
void foold(long double *ld);
void testdouble() {
  double d = 2.0;
  food(&d);
}
void testlonglong() {
  long long ll = 2;
  fooll(&ll);
}
void testunsignedlonglong() {
  unsigned long long ull = 2;
  fooull(&ull);
}
void testlongdouble() {
  long double ld = 2.0;
  foold(&ld);
}
