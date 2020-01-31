float powf(float, float);
double pow(double, double);
long double powl(long double, long double);
void test_pow(float a0, double a1, long double a2) {
  float l0 = powf(a0, a0);
  double l1 = pow(a1, a1);
  long double l2 = powl(a2, a2);
}
