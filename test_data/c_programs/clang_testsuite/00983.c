double f1(void) {
  return 1.4;
}
extern double g;
void f2(void) {
  g = f1();
}
void take_double(double);
void pass_double(void) {
}
